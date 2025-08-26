library(ggplot2)

calculate_spectral_efficiency <- function(throughput_mbps, bandwidth_khz) {
  # Convert throughput from Mbps to bps
  throughput_bps <- throughput_mbps * 10^6
  
  # Convert bandwidth from kHz to Hz
  bandwidth_hz <- bandwidth_khz * 10^3
  
  # Calculate spectral efficiency
  spectral_efficiency <- throughput_bps / bandwidth_hz
  
  return(spectral_efficiency)
}

small_box <- function(text, x_left, y_bottom, x_right, y_top, padding, angle, color){

    rect(xleft = x_left, ybottom = y_bottom, xright = x_right, ytop = y_top, border = "black", lwd = 2)
    
    if(angle > 0){
        segments(x_left, y_bottom, x_right, y_top, col = color, lwd = 2)
    }
    else { 
        segments(x_left, y_top, x_right, y_bottom, col = color, lwd = 2)
    }

    text(x = x_right + padding, y = (y_top + y_bottom) / 2, labels = c(text), col = "black", cex = 2, font = 2)

}
    
pdf("plot.pdf", width = 20, height = 20)

###################### Compare Throughput for 2, 3, and 4 UE Connections without HARQ ######################

par(mar = c(30, 9, 30, 11)) # Margins 

df <- read.csv("static/thoughput.csv")
df <- df[df$Retransmissions == "no-harq", ]

low_noise_df <- df[df$Channel.Quality == "low-noise", ]
average_noise_df <- df[df$Channel.Quality == "average", ]
high_noise_df <- df[df$Channel.Quality == "high-noise", ]

low_noise_mean_throughput <- low_noise_df$Average.Throughput..Mbps.
average_noise_mean_throughput <- average_noise_df$Average.Throughput..Mbps.
high_noise_mean_throughput <- high_noise_df$Average.Throughput..Mbps.

low_noise_std_throughput <- low_noise_df$Throughput.STD..Mbps.
average_noise_std_throughput <- average_noise_df$Throughput.STD..Mbps.
high_noise_std_throughput <- high_noise_df$Throughput.STD..Mbps.

bar_heights <- barplot(
    height = cbind(low_noise_mean_throughput, average_noise_mean_throughput, high_noise_mean_throughput), 
    beside = TRUE,         # Side-by-side bars
    density = c(5, 5, 5, 5), 
    col = c("blue", "red"), 
    angle = c(-45, 45), 
    ylim = c(0, 40),
    width = 0.1,           # Bar width
    las = 1,               # Axis labels orientation
    space = c(0.1, 2),       # Space between the groups (increase the second value for more gap)
    xaxt = 'n',             # Suppress x-axis labels
    yaxt = 'n',             # Suppress x-axis labels
    cex.axis = 2,
)

arrows(
    x0 = bar_heights,                              # X-coordinates of the bars
    y0 = cbind(low_noise_mean_throughput, average_noise_mean_throughput, high_noise_mean_throughput) - 
         cbind(low_noise_std_throughput, average_noise_std_throughput, high_noise_std_throughput), # Lower end of error bars
    x1 = bar_heights,                              # X-coordinates of the bars
    y1 = cbind(low_noise_mean_throughput, average_noise_mean_throughput, high_noise_mean_throughput) + 
         cbind(low_noise_std_throughput, average_noise_std_throughput, high_noise_std_throughput), # Upper end of error bars
    angle = 90,                                    # Angle of the arrow heads
    code = 3,                                      # Draw arrows on both ends
    length = 0.1,                                  # Length of the arrow heads
    lwd = 2                                        # Line width of the error bars
)


legend(
    x = grconvertX(1, from = "npc") - 0.5,                          # Position of the legend
    y = grconvertY(1, from = "npc"),
    legend = c("PTM", "PTP"),               # Legend labels
    fill = c("blue", "red"),                # Colors for the legend
    density = c(5, 5),                    # Density of the fill patterns
    angle = c(-45, 45),                     # Angles of the fill patterns
    bty = "n",                              # No box around the legend
    cex = 4,                                # Size of the legend text
    x.intersp = 0.2,                        # Horizontal spacing between items
    y.intersp = 1,                        # Vertical spacing between items
    seg.len = 2                             # Length of the lines in the legend
)


mtext("Throughput (Mbps)", side = 2, line = 6, cex = 4, font = 2)
axis(side=2, at = seq(0, 40, by=5), las = 1, cex.axis = 4)

# This is the right side Y axis (Dual-Axis)
spectral_efficiency_axis_labels <- round(calculate_spectral_efficiency(seq(0, 40, by = 4), 38160), 1)
mtext("Spectral Efficiency (bps/Hz)", side = 4, line = 8.5, cex = 4, font = 2)
axis(side=4, at = seq(0, 40, by=4), labels = spectral_efficiency_axis_labels, las = 1, cex.axis = 4)


x_axis_labels <- c("")
x_axis_labels2 <- c("")
x_axis_label_positions = c(-1)
for (j in 1:ncol(bar_heights)){
    for (i in seq(1, nrow(bar_heights), by = 2)){
        unicast <- bar_heights[i, j]
        multicast <- bar_heights[i + 1, j]
        x_axis_label_positions <- c(x_axis_label_positions, colMeans(matrix(c(unicast, multicast), nrow = 2, ncol = 1)))
    }
    x_axis_labels <- c(x_axis_labels, 2, 3, 4)
    x_axis_labels2 <- c(x_axis_labels2, "", "", "")
}

x_axis_label_positions <- c(100, x_axis_label_positions)
x_axis_labels <- c("", x_axis_labels)
x_axis_labels2 <- c("", x_axis_labels2)
axis(side = 1, at = x_axis_label_positions, labels = x_axis_labels2, las = 1, xlim = xlim, cex.axis = 4)
axis(side = 1, at = x_axis_label_positions, labels = x_axis_labels, las = 1, xlim = xlim, cex.axis = 4, line=1.5, col = "transparent")

x_axis_labels <- c("", expression("" < "1%"), expression("" %~~% "12.5%"), expression("" %~~% "25%"), "")
axis(side = 1, at = c(-1, colMeans(bar_heights), 100), labels = x_axis_labels, las = 1, xlim = xlim, line = 5.5, cex.axis = 4, col = "transparent")

mtext("Packet Loss (%) and MBS Group Size", side = 1, line = 10, cex = 4, font = 2)


###################### RB allocation for 2, 3, and 4 UE Connections without HARQ ######################

par(mar = c(30, 13, 30, 2)) # Margins 

df <- read.csv("static/rb.csv")
df <- df[df$Retransmissions == "no-harq", ]
low_noise_df <- df[df$Channel.Quality == "low-noise", ]
average_noise_df <- df[df$Channel.Quality == "average", ]
high_noise_df <- df[df$Channel.Quality == "high-noise", ]


low_noise_mean_rb_allocation <- low_noise_df$Average.RB.Allocation....
average_noise_mean_rb_allocation <- average_noise_df$Average.RB.Allocation....
high_noise_mean_rb_allocation <- high_noise_df$Average.RB.Allocation....

low_noise_std_rb_allocation <- low_noise_df$RB.Allocation.STD....
average_noise_std_rb_allocation <- average_noise_df$RB.Allocation.STD....
high_noise_std_rb_allocation <- high_noise_df$RB.Allocation.STD....


bar_heights <- barplot(
    height = cbind(low_noise_mean_rb_allocation, average_noise_mean_rb_allocation, high_noise_mean_rb_allocation), 
    beside = TRUE,         # Side-by-side bars
    density = c(5, 5, 5, 5), 
    col = c("blue", "red"), 
    angle = c(-45, 45), 
    ylim = c(0, 120),
    width = 0.1,           # Bar width
    las = 1,               # Axis labels orientation
    space = c(0.1, 2),       # Space between the groups (increase the second value for more gap)
    xaxt = 'n',             # Suppress x-axis labels
    yaxt = 'n',             # Suppress x-axis labels
    cex.axis = 2,
)


arrows(
    x0 = bar_heights,                              # X-coordinates of the bars
    y0 = cbind(low_noise_mean_rb_allocation, average_noise_mean_rb_allocation, high_noise_mean_rb_allocation) - 
         cbind(low_noise_std_rb_allocation, average_noise_std_rb_allocation, high_noise_std_rb_allocation), # Lower end of error bars
    x1 = bar_heights,                              # X-coordinates of the bars
    y1 = cbind(low_noise_mean_rb_allocation, average_noise_mean_rb_allocation, high_noise_mean_rb_allocation) + 
         cbind(low_noise_std_rb_allocation, average_noise_std_rb_allocation, high_noise_std_rb_allocation), # Upper end of error bars
    angle = 90,                                    # Angle of the arrow heads
    code = 3,                                      # Draw arrows on both ends
    length = 0.1,                                  # Length of the arrow heads
    lwd = 2                                        # Line width of the error bars
)

axis(side=2, at = seq(0, 100, by=20), las = 1, cex.axis = 4)


# Legend
legend(
    x = grconvertX(1, from = "npc") - 1,                          # Position of the legend
    y = grconvertY(1, from = "npc"),
    legend = c("PTM"),               # Legend labels
    fill = c("blue"),                # Colors for the legend
    density = c(5, 5),                    # Density of the fill patterns
    angle = c(-45),                     # Angles of the fill patterns
    bty = "n",                              # No box around the legend
    cex = 4,                                # Size of the legend text
    x.intersp = 0.2,                        # Horizontal spacing between items
    y.intersp = 1,                        # Vertical spacing between items
    seg.len = 2                             # Length of the lines in the legend
)


legend(
    x = grconvertX(1, from = "npc") - 0.5,                          # Position of the legend
    y = grconvertY(1, from = "npc"),
    legend = c("PTP"),               # Legend labels
    fill = c("red"),                # Colors for the legend
    density = c(5, 5),                    # Density of the fill patterns
    angle = c(45),                     # Angles of the fill patterns
    bty = "n",                              # No box around the legend
    cex = 4,                                # Size of the legend text
    x.intersp = 0.2,                        # Horizontal spacing between items
    y.intersp = 1,                        # Vertical spacing between items
    seg.len = 2                             # Length of the lines in the legend
)

mtext("Resource Block\nAllocation (%)", side = 2, line = 6, cex = 4, font = 2)

x_axis_labels <- c("")
x_axis_labels2 <- c("")
x_axis_label_positions = c(-1)
for (j in 1:ncol(bar_heights)){
    for (i in seq(1, nrow(bar_heights), by = 2)){
        unicast <- bar_heights[i, j]
        multicast <- bar_heights[i + 1, j]
        x_axis_label_positions <- c(x_axis_label_positions, colMeans(matrix(c(unicast, multicast), nrow = 2, ncol = 1)))
    }
    x_axis_labels <- c(x_axis_labels, 2, 3, 4)
    x_axis_labels2 <- c(x_axis_labels2, "", "", "")

}

x_axis_label_positions <- c(100, x_axis_label_positions)
x_axis_labels <- c("", x_axis_labels)
x_axis_labels2 <- c("", x_axis_labels2)
axis(side = 1, at = x_axis_label_positions, labels = x_axis_labels2, las = 1, xlim = xlim, cex.axis = 4)
axis(side = 1, at = x_axis_label_positions, labels = x_axis_labels, las = 1, xlim = xlim, cex.axis = 4, line=1.5, col = "transparent")

x_axis_labels <- c("", expression("" < "1%"), expression("" %~~% "12.5%"), expression("" %~~% "25%"), "")
axis(side = 1, at = c(-1, colMeans(bar_heights), 100), labels = x_axis_labels, las = 1, xlim = xlim, line = 5.5, cex.axis = 4, col = "transparent")

mtext("Packet Loss (%) and MBS Group Size", side = 1, line = 10, cex = 4, font = 2)



###################### Compare Throughput for 2, 4, 6, 8 UE Connections with HARQ ######################

par(mar = c(30, 9, 30, 11)) # Margins 

df <- read.csv("static/thoughput.csv")
df <- df[df$Retransmissions == "harq", ]
low_noise_df <- df[df$Channel.Quality == "low-noise", ]
average_noise_df <- df[df$Channel.Quality == "average", ]
high_noise_df <- df[df$Channel.Quality == "high-noise", ]

low_noise_mean_throughput <- low_noise_df$Average.Throughput..Mbps.
average_noise_mean_throughput <- average_noise_df$Average.Throughput..Mbps.
high_noise_mean_throughput <- high_noise_df$Average.Throughput..Mbps.

low_noise_std_throughput <- low_noise_df$Throughput.STD..Mbps.
average_noise_std_throughput <- average_noise_df$Throughput.STD..Mbps.
high_noise_std_throughput <- high_noise_df$Throughput.STD..Mbps.


bar_heights <- barplot(
    height = cbind(low_noise_mean_throughput, average_noise_mean_throughput, high_noise_mean_throughput), 
    beside = TRUE,         # Side-by-side bars
    density = c(5, 5, 5, 5), 
    col = c("blue", "red"), 
    angle = c(-45, 45), 
    ylim = c(0, 28),
    width = 0.1,           # Bar width
    las = 1,               # Axis labels orientation
    space = c(0.1, 2),       # Space between the groups (increase the second value for more gap)
    xaxt = 'n',             # Suppress x-axis labels
    yaxt = 'n',             # Suppress x-axis labels
    cex.axis = 2,
)

arrows(
    x0 = bar_heights,                              # X-coordinates of the bars
    y0 = cbind(low_noise_mean_throughput, average_noise_mean_throughput, high_noise_mean_throughput) - 
         cbind(low_noise_std_throughput, average_noise_std_throughput, high_noise_std_throughput), # Lower end of error bars
    x1 = bar_heights,                              # X-coordinates of the bars
    y1 = cbind(low_noise_mean_throughput, average_noise_mean_throughput, high_noise_mean_throughput) + 
         cbind(low_noise_std_throughput, average_noise_std_throughput, high_noise_std_throughput), # Upper end of error bars
    angle = 90,                                    # Angle of the arrow heads
    code = 3,                                      # Draw arrows on both ends
    length = 0.1,                                  # Length of the arrow heads
    lwd = 2                                        # Line width of the error bars
)


legend(
    x = grconvertX(1, from = "npc") - 0.7,                          # Position of the legend
    y = grconvertY(1, from = "npc"),
    legend = c("PTM", "PTP"),               # Legend labels
    fill = c("blue", "red"),                # Colors for the legend
    density = c(5, 5),                    # Density of the fill patterns
    angle = c(-45, 45),                     # Angles of the fill patterns
    bty = "n",                              # No box around the legend
    cex = 4,                                # Size of the legend text
    x.intersp = 0.2,                        # Horizontal spacing between items
    y.intersp = 1,                        # Vertical spacing between items
    seg.len = 2                             # Length of the lines in the legend
)


mtext("Throughput (Mbps)", side = 2, line = 6, cex = 4, font = 2)
axis(side=2, at = seq(0, 28, by=2), las = 1, cex.axis = 4)


# This is the right side Y axis (Dual-Axis)
spectral_efficiency_axis_labels <- round(calculate_spectral_efficiency(seq(0, 32, by = 4), 38160), 1)
mtext("Spectral Efficiency (bps/Hz)", side = 4, line = 8.5, cex = 4, font = 2)
axis(side=4, at = seq(0, 32, by=4), labels = spectral_efficiency_axis_labels, las = 1, cex.axis = 4)


x_axis_labels <- c("")
x_axis_labels2 <- c("")
x_axis_label_positions = c(-1)
for (j in 1:ncol(bar_heights)){
    for (i in seq(1, nrow(bar_heights), by = 2)){
        unicast <- bar_heights[i, j]
        multicast <- bar_heights[i + 1, j]
        x_axis_label_positions <- c(x_axis_label_positions, colMeans(matrix(c(unicast, multicast), nrow = 2, ncol = 1)))
    }
    x_axis_labels <- c(x_axis_labels, 2, 4, 8, 16)
    x_axis_labels2 <- c(x_axis_labels2, "", "", "", "")
}

x_axis_label_positions <- c(100, x_axis_label_positions)
x_axis_labels <- c("", x_axis_labels)
x_axis_labels2 <- c("", x_axis_labels2)

axis(side = 1, at = x_axis_label_positions, labels = x_axis_labels2, las = 1, xlim = xlim, cex.axis = 4)
axis(side = 1, at = x_axis_label_positions, labels = x_axis_labels, las = 1, xlim = xlim, cex.axis = 3.8, line=1.5, col = "transparent")


x_axis_labels <- c("", expression("" < "1%"), expression("" %~~% "12.5%"), expression("" %~~% "25%"), "")
axis(side = 1, at = c(-1, colMeans(bar_heights), 100), labels = x_axis_labels, las = 1, xlim = xlim, line = 5.5, cex.axis = 4, col = "transparent")

mtext("Retransmission Rate (%) and MBS Group Size", side = 1, line = 10, cex = 4, font = 2)




###################### Compare RB Allocation for 2, 4, 6, 8 UE Connections with HARQ ######################

par(mar = c(30, 13, 30, 2)) # Margins 

df <- read.csv("static/rb.csv")
df <- df[df$Retransmissions == "harq", ]
low_noise_df <- df[df$Channel.Quality == "low-noise", ]
average_noise_df <- df[df$Channel.Quality == "average", ]
high_noise_df <- df[df$Channel.Quality == "high-noise", ]

low_noise_mean_rb_allocation <- low_noise_df$Average.RB.Allocation....
low_noise_mean_rb_reallocation <- low_noise_df$Average.RB.Reallocation....

average_noise_mean_rb_allocation <- average_noise_df$Average.RB.Allocation....
average_noise_mean_rb_reallocation <- average_noise_df$Average.RB.Reallocation....

high_noise_mean_rb_allocation <- high_noise_df$Average.RB.Allocation....
high_noise_mean_rb_reallocation <- high_noise_df$Average.RB.Reallocation....


bar_heights <- barplot(
    height = cbind(low_noise_mean_rb_allocation, average_noise_mean_rb_allocation, high_noise_mean_rb_allocation), 
    beside = TRUE,         # Side-by-side bars
    density = c(5, 5, 5, 5), 
    col = c("blue", "red"), 
    angle = c(-45, 45), 
    ylim = c(0, 80),
    width = 0.1,           # Bar width
    las = 1,               # Axis labels orientation
    space = c(0.1, 2),       # Space between the groups (increase the second value for more gap)
    xaxt = 'n',             # Suppress x-axis labels
    yaxt = 'n',             # Suppress x-axis labels
    cex.axis = 2,
)
axis(side=2, at = seq(0, 100, by=20), las = 1, cex.axis = 4)


bar_heights <- barplot(
    height = cbind(
        low_noise_mean_rb_allocation + low_noise_mean_rb_reallocation, 
        average_noise_mean_rb_allocation + average_noise_mean_rb_reallocation, 
        high_noise_mean_rb_allocation + high_noise_mean_rb_reallocation
    ), 
    beside = TRUE,         # Side-by-side bars
    density = c(5, 5, 5, 5), 
    col = rgb(0, 0, 0, alpha = 0), 
    angle = c(0), 
    ylim = c(0, 60),
    width = 0.1,           # Bar width
    las = 1,               # Axis labels orientation
    space = c(0.1, 2),       # Space between the groups (increase the second value for more gap)
    xaxt = 'n',             # Suppress x-axis labels
    cex.axis = 4,
    add = TRUE,
)

legend(
    x = grconvertX(1, from = "npc") - 1.6,                          # Position of the legend
    y = grconvertY(1, from = "npc") + 2.5,
    legend = c("PTM", "PTP (Retransmissions)"),               # Legend labels
    fill = c("blue", "white"),                # Colors for the legend
    density = c(5, 5),                    # Density of the fill patterns
    angle = c(-45, 45),                     # Angles of the fill patterns
    bty = "n",                              # No box around the legend
    cex = 4,                                # Size of the legend text
    x.intersp = 0.2,                        # Horizontal spacing between items
    y.intersp = 1,                        # Vertical spacing between items
    seg.len = 2                             # Length of the lines in the legend
)

legend(
    x = grconvertX(1, from = "npc") - 1,                          # Position of the legend
    y = grconvertY(1, from = "npc") + 2.5,
    legend = c("PTP"),               # Legend labels
    fill = c("red"),                # Colors for the legend
    density = c(5, 5),                    # Density of the fill patterns
    angle = c(45),                     # Angles of the fill patterns
    bty = "n",                              # No box around the legend
    cex = 4,                                # Size of the legend text
    x.intersp = 0.2,                        # Horizontal spacing between items
    y.intersp = 1,                        # Vertical spacing between items
    seg.len = 2                             # Length of the lines in the legend
)

mtext("Resource Block\nAllocation (%)", side = 2, line = 6, cex = 4, font = 2)

x_axis_labels <- c("")
x_axis_labels2 <- c("")
x_axis_label_positions = c(-1)
for (j in 1:ncol(bar_heights)){
    for (i in seq(1, nrow(bar_heights), by = 2)){
        unicast <- bar_heights[i, j]
        multicast <- bar_heights[i + 1, j]
        x_axis_label_positions <- c(x_axis_label_positions, colMeans(matrix(c(unicast, multicast), nrow = 2, ncol = 1)))
    }
    x_axis_labels <- c(x_axis_labels, 2, 4, 8, 16)
    x_axis_labels2 <- c(x_axis_labels2, "", "", "", "")
}

x_axis_label_positions <- c(100, x_axis_label_positions)
x_axis_labels <- c("", x_axis_labels)
x_axis_labels2 <- c("", x_axis_labels2)
axis(side = 1, at = x_axis_label_positions, labels = x_axis_labels2, las = 1, xlim = xlim, cex.axis = 4)
axis(side = 1, at = x_axis_label_positions, labels = x_axis_labels, las = 1, xlim = xlim, cex.axis = 4, line=1.5, col = "transparent")

x_axis_labels <- c("", expression("" < "1%"), expression("" %~~% "12.5%"), expression("" %~~% "25%"), "")
axis(side = 1, at = c(-1, colMeans(bar_heights), 100), labels = x_axis_labels, las = 1, xlim = xlim, line = 5.5, cex.axis = 4, col = "transparent")

mtext("Retransmission Rate (%) and MBS Group Size", side = 1, line = 10, cex = 4, font = 2)



###################### Compare RB Allocation ######################

par(mar = c(30, 10, 30, 11)) # Margins 

df <- read.csv("realistic/thoughput.csv")

four_ues_no_harq <- subset(df, UE.Count == 4 & Retransmissions == "no-harq")
four_ues_with_harq <- subset(df, UE.Count == 4 & Retransmissions == "harq")
eight_ues_with_harq <- subset(df, UE.Count == 8 & Retransmissions == "harq")


average_throughput_four_ues_no_harq <- four_ues_no_harq$Average.Throughput..Mbps.
average_throughput_four_ues_with_harq <- four_ues_with_harq$Average.Throughput..Mbps.
average_throughput_eight_ues_with_harq <- eight_ues_with_harq$Average.Throughput..Mbps.

std_throughput_four_ues_no_harq <- four_ues_no_harq$Throughput.STD..Mbps.
std_throughput_four_ues_with_harq <- four_ues_with_harq$Throughput.STD..Mbps.
std_throughput_eight_ues_with_harq <- eight_ues_with_harq$Throughput.STD..Mbps.


bar_heights <- barplot(
    height = cbind(average_throughput_four_ues_no_harq, average_throughput_four_ues_with_harq, average_throughput_eight_ues_with_harq), 
    beside = TRUE,         # Side-by-side bars
    density = c(5, 5, 5, 5), 
    col = c(
        "blue", "blue",
        "red", "red",
        "darkgray", "darkgray"
    ), 
    angle = c(
        -45, -45, 
        45, 45, 
        0, 0
    ), 
    ylim = c(0, 20),
    width = 0.1,           # Bar width
    las = 1,               # Axis labels orientation
    space = c(0.1, 2),       # Space between the groups (increase the second value for more gap)
    xaxt = 'n',             # Suppress x-axis labels
    yaxt = 'n',             # Suppress x-axis labels
    cex.axis = 4,
)

arrows(
    x0 = bar_heights,                              # X-coordinates of the bars
    y0 = cbind(average_throughput_four_ues_no_harq, average_throughput_four_ues_with_harq, average_throughput_eight_ues_with_harq) - 
         cbind(std_throughput_four_ues_no_harq, std_throughput_four_ues_with_harq, std_throughput_eight_ues_with_harq), # Lower end of error bars
    x1 = bar_heights,                              # X-coordinates of the bars
    y1 = cbind(average_throughput_four_ues_no_harq, average_throughput_four_ues_with_harq, average_throughput_eight_ues_with_harq) + 
         cbind(std_throughput_four_ues_no_harq, std_throughput_four_ues_with_harq, std_throughput_eight_ues_with_harq), # Upper end of error bars
    angle = 90,                                    # Angle of the arrow heads
    code = 3,                                      # Draw arrows on both ends
    length = 0.1,                                  # Length of the arrow heads
    lwd = 2                                        # Line width of the error bars
)


legend(
    x = grconvertX(1, from = "npc") - 0.7,                          # Position of the legend
    y = grconvertY(1, from = "npc") - 1,
    legend = c("4 UE Group / No-ACK", "4 UE Group / HARQ-ACK", "8 UE Group / HARQ-ACK"),               # Legend labels
    fill = c("blue", "red", "black"),                # Colors for the legend
    density = c(5, 5, 7),                    # Density of the fill patterns
    angle = c(-45, 45, 0),                     # Angles of the fill patterns
    bty = "n",                              # No box around the legend
    cex = 4,                                # Size of the legend text
    x.intersp = 0.2,                        # Horizontal spacing between items
    y.intersp = 1,                        # Vertical spacing between items
    seg.len = 2                             # Length of the lines in the legend
)

x_axis_labels <- c()
x_axis_labels2 <- c()
x_axis_label_positions = c(-1)
for (j in 1:ncol(bar_heights)){
    x_axis_labels <- c(x_axis_labels, "Approach 1", "Approach 2")
    x_axis_labels2 <- c(x_axis_labels2, "", "")
}

x_axis_label_positions <- c(100, x_axis_label_positions)
# x_axis_labels <- c("", x_axis_labels)
axis(side = 1, at = c(-1, bar_heights, 100), labels = NA, las = 2, xlim = xlim, cex.axis = 2)
text(
  x = bar_heights + 0.02,  # X positions for labels (adjust as needed)
  y = par("usr")[3] - 0.9,     # Y position for labels (just below the axis)
  labels = x_axis_labels,      # Labels to display
  srt = 25,                   # Rotate labels by 45 degrees
  adj = 1,                    # Adjust alignment (1 = right, 0 = left)
  xpd = TRUE,                 # Allow drawing outside the plot area
  cex = 4                     # Adjust label size
)

# This is the right side Y axis (Dual-Axis)
spectral_efficiency_axis_labels <- round(calculate_spectral_efficiency(seq(0, 20, by = 4), 38160), 1)
mtext("Spectral Efficiency (bps/Hz)", side = 4, line = 8.5, cex = 4, font = 2)
axis(side=4, at = seq(0, 20, by=4), labels = spectral_efficiency_axis_labels, las = 1, cex.axis = 4)

mtext("Throughput (Mbps)", side = 2, line = 6, cex = 4, font = 2)
axis(side=2, at = seq(0, 20, by=2), las = 1, cex.axis = 4)

mtext("MCS Selection Approach", side = 1, line = 14, cex = 4, font = 2)






################################################# RB Allocation #################################################

par(mar = c(30, 13, 30, 2)) # Margins 

df <- read.csv("realistic/rb.csv")

four_ues_with_harq <- subset(df, UE.Count == 4 & Retransmissions == "harq")
eight_ues_with_harq <- subset(df, UE.Count == 8 & Retransmissions == "harq")


average_rb_four_ues_with_harq <- four_ues_with_harq$Average.RB.Allocation....
average_rb_eight_ues_with_harq <- eight_ues_with_harq$Average.RB.Allocation....


average_rb_four_ues_with_harq_realloc <- four_ues_with_harq$Average.RB.Reallocation....
average_rb_eight_ues_with_harq_realloc <- eight_ues_with_harq$Average.RB.Reallocation....


bar_heights <- barplot(
    height = cbind(average_rb_four_ues_with_harq, average_rb_eight_ues_with_harq), 
    beside = TRUE,         # Side-by-side bars
    density = c(5, 5, 5, 5), 
    col = c(
        "red", "red",
        "darkgray", "darkgray"
    ), 
    angle = c(
        45, 45, 
        0, 0
    ), 
    ylim = c(0, 70),
    width = 0.1,           # Bar width
    las = 1,               # Axis labels orientation
    space = c(0.1, 2),       # Space between the groups (increase the second value for more gap)
    xaxt = 'n',             # Suppress x-axis labels
    yaxt = 'n',             # Suppress x-axis labels
    cex.axis = 4,
)


bar_heights <- barplot(
    height = cbind(
        average_rb_four_ues_with_harq + average_rb_four_ues_with_harq_realloc, 
        average_rb_eight_ues_with_harq + average_rb_eight_ues_with_harq_realloc
    ), 
    beside = TRUE,         # Side-by-side bars
    density = c(5, 5, 5, 5), 
    col = rgb(0, 0, 0, alpha = 0), 
    angle = c(0), 
    ylim = c(0, 70),
    width = 0.1,           # Bar width
    las = 1,               # Axis labels orientation
    space = c(0.1, 2),       # Space between the groups (increase the second value for more gap)
    xaxt = 'n',             # Suppress x-axis labels
    yaxt = 'n',             # Suppress x-axis labels
    cex.axis = 2,
    add = TRUE,
)


legend(
    x = grconvertX(1, from = "npc") - 0.4,                          # Position of the legend
    y = grconvertY(1, from = "npc") - 1,
    legend = c("4 UE Group / HARQ-ACK", "8 UE Group / HARQ-ACK", "PTP (Retransmissions)"),               # Legend labels
    fill = c("red", "black", "white"),                # Colors for the legend
    density = c(5,7),                    # Density of the fill patterns
    angle = c(45, 0),                     # Angles of the fill patterns
    bty = "n",                              # No box around the legend
    cex = 4,                                # Size of the legend text
    x.intersp = 0.2,                        # Horizontal spacing between items
    y.intersp = 1,                        # Vertical spacing between items
    seg.len = 2                             # Length of the lines in the legend
)

x_axis_labels <- c()
x_axis_label_positions = c(-1)
for (j in 1:ncol(bar_heights)){
    x_axis_labels <- c(x_axis_labels, "Approach 1", "Approach 2")
}

x_axis_label_positions <- c(100, x_axis_label_positions)
axis(side = 1, at = c(-1, bar_heights, 100), labels = NA, las = 2, xlim = xlim, cex.axis = 2)

text(
  x = bar_heights + 0.01,  # X positions for labels (adjust as needed)
  y = par("usr")[3] - 4,     # Y position for labels (just below the axis)
  labels = x_axis_labels,      # Labels to display
  srt = 25,                   # Rotate labels by 45 degrees
  adj = 1,                    # Adjust alignment (1 = right, 0 = left)
  xpd = TRUE,                 # Allow drawing outside the plot area
  cex = 4                     # Adjust label size
)


mtext("Resource Block\nAllocation (%)", side = 2, line = 6, cex = 4, font = 2)
axis(side=2, at = seq(0, 70, by=10), las = 1, cex.axis = 4)


mtext("MCS Selection Approach", side = 1, line = 14, cex = 4, font = 2)


# Close the PDF device
dev.off()