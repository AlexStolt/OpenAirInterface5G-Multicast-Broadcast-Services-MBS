/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-Containers"
 * 	found in "e42ap_v3_01.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_ProtocolIE_Container_H_
#define	_ProtocolIE_Container_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RICsubscriptionRequest_IEs;
struct RICsubscriptionResponse_IEs;
struct RICsubscriptionFailure_IEs;
struct RICsubscriptionDeleteRequest_IEs;
struct E42RICsubscriptionRequest_IEs;
struct E42RICsubscriptionDeleteRequest_IEs;
struct RICsubscriptionDeleteResponse_IEs;
struct RICsubscriptionDeleteFailure_IEs;
struct RICsubscriptionDeleteRequired_IEs;
struct RICsubscriptionModificationRequest_IEs;
struct RICsubscriptionModificationResponse_IEs;
struct RICsubscriptionModificationFailure_IEs;
struct RICsubscriptionModificationRequired_IEs;
struct RICsubscriptionModificationConfirm_IEs;
struct RICsubscriptionModificationRefuse_IEs;
struct RICindication_IEs;
struct RICcontrolRequest_IEs;
struct E42RICcontrolRequest_IEs;
struct RICcontrolAcknowledge_IEs;
struct RICcontrolFailure_IEs;
struct RICQueryRequest_IEs;
struct RICQueryResponse_IEs;
struct RICQueryFailure_IEs;
struct ErrorIndication_IEs;
struct E2setupRequestIEs;
struct E42setupRequestIEs;
struct E2setupResponseIEs;
struct E42setupResponseIEs;
struct E2setupFailureIEs;
struct E2connectionUpdate_IEs;
struct E2connectionUpdateAck_IEs;
struct E2connectionUpdateFailure_IEs;
struct E2nodeConfigurationUpdate_IEs;
struct E2nodeConfigurationUpdateAcknowledge_IEs;
struct E2nodeConfigurationUpdateFailure_IEs;
struct ResetRequestIEs;
struct ResetResponseIEs;
struct RICserviceUpdate_IEs;
struct E2nodeConnected_ItemIEs;
struct RICserviceUpdateAcknowledge_IEs;
struct RICserviceUpdateFailure_IEs;
struct RICserviceQuery_IEs;
struct E2RemovalRequestIEs;
struct E2RemovalResponseIEs;
struct E2RemovalFailureIEs;

/* ProtocolIE-Container */
typedef struct ProtocolIE_Container_2691P0 {
	A_SEQUENCE_OF(struct RICsubscriptionRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P0_t;
typedef struct ProtocolIE_Container_2691P1 {
	A_SEQUENCE_OF(struct RICsubscriptionResponse_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P1_t;
typedef struct ProtocolIE_Container_2691P2 {
	A_SEQUENCE_OF(struct RICsubscriptionFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P2_t;
typedef struct ProtocolIE_Container_2691P3 {
	A_SEQUENCE_OF(struct RICsubscriptionDeleteRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P3_t;
typedef struct ProtocolIE_Container_2691P4 {
	A_SEQUENCE_OF(struct E42RICsubscriptionRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P4_t;
typedef struct ProtocolIE_Container_2691P5 {
	A_SEQUENCE_OF(struct E42RICsubscriptionDeleteRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P5_t;
typedef struct ProtocolIE_Container_2691P6 {
	A_SEQUENCE_OF(struct RICsubscriptionDeleteResponse_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P6_t;
typedef struct ProtocolIE_Container_2691P7 {
	A_SEQUENCE_OF(struct RICsubscriptionDeleteFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P7_t;
typedef struct ProtocolIE_Container_2691P8 {
	A_SEQUENCE_OF(struct RICsubscriptionDeleteRequired_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P8_t;
typedef struct ProtocolIE_Container_2691P9 {
	A_SEQUENCE_OF(struct RICsubscriptionModificationRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P9_t;
typedef struct ProtocolIE_Container_2691P10 {
	A_SEQUENCE_OF(struct RICsubscriptionModificationResponse_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P10_t;
typedef struct ProtocolIE_Container_2691P11 {
	A_SEQUENCE_OF(struct RICsubscriptionModificationFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P11_t;
typedef struct ProtocolIE_Container_2691P12 {
	A_SEQUENCE_OF(struct RICsubscriptionModificationRequired_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P12_t;
typedef struct ProtocolIE_Container_2691P13 {
	A_SEQUENCE_OF(struct RICsubscriptionModificationConfirm_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P13_t;
typedef struct ProtocolIE_Container_2691P14 {
	A_SEQUENCE_OF(struct RICsubscriptionModificationRefuse_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P14_t;
typedef struct ProtocolIE_Container_2691P15 {
	A_SEQUENCE_OF(struct RICindication_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P15_t;
typedef struct ProtocolIE_Container_2691P16 {
	A_SEQUENCE_OF(struct RICcontrolRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P16_t;
typedef struct ProtocolIE_Container_2691P17 {
	A_SEQUENCE_OF(struct E42RICcontrolRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P17_t;
typedef struct ProtocolIE_Container_2691P18 {
	A_SEQUENCE_OF(struct RICcontrolAcknowledge_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P18_t;
typedef struct ProtocolIE_Container_2691P19 {
	A_SEQUENCE_OF(struct RICcontrolFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P19_t;
typedef struct ProtocolIE_Container_2691P20 {
	A_SEQUENCE_OF(struct RICQueryRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P20_t;
typedef struct ProtocolIE_Container_2691P21 {
	A_SEQUENCE_OF(struct RICQueryResponse_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P21_t;
typedef struct ProtocolIE_Container_2691P22 {
	A_SEQUENCE_OF(struct RICQueryFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P22_t;
typedef struct ProtocolIE_Container_2691P23 {
	A_SEQUENCE_OF(struct ErrorIndication_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P23_t;
typedef struct ProtocolIE_Container_2691P24 {
	A_SEQUENCE_OF(struct E2setupRequestIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P24_t;
typedef struct ProtocolIE_Container_2691P25 {
	A_SEQUENCE_OF(struct E42setupRequestIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P25_t;
typedef struct ProtocolIE_Container_2691P26 {
	A_SEQUENCE_OF(struct E2setupResponseIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P26_t;
typedef struct ProtocolIE_Container_2691P27 {
	A_SEQUENCE_OF(struct E42setupResponseIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P27_t;
typedef struct ProtocolIE_Container_2691P28 {
	A_SEQUENCE_OF(struct E2setupFailureIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P28_t;
typedef struct ProtocolIE_Container_2691P29 {
	A_SEQUENCE_OF(struct E2connectionUpdate_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P29_t;
typedef struct ProtocolIE_Container_2691P30 {
	A_SEQUENCE_OF(struct E2connectionUpdateAck_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P30_t;
typedef struct ProtocolIE_Container_2691P31 {
	A_SEQUENCE_OF(struct E2connectionUpdateFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P31_t;
typedef struct ProtocolIE_Container_2691P32 {
	A_SEQUENCE_OF(struct E2nodeConfigurationUpdate_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P32_t;
typedef struct ProtocolIE_Container_2691P33 {
	A_SEQUENCE_OF(struct E2nodeConfigurationUpdateAcknowledge_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P33_t;
typedef struct ProtocolIE_Container_2691P34 {
	A_SEQUENCE_OF(struct E2nodeConfigurationUpdateFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P34_t;
typedef struct ProtocolIE_Container_2691P35 {
	A_SEQUENCE_OF(struct ResetRequestIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P35_t;
typedef struct ProtocolIE_Container_2691P36 {
	A_SEQUENCE_OF(struct ResetResponseIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P36_t;
typedef struct ProtocolIE_Container_2691P37 {
	A_SEQUENCE_OF(struct RICserviceUpdate_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P37_t;
typedef struct ProtocolIE_Container_2691P38 {
	A_SEQUENCE_OF(struct E2nodeConnected_ItemIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P38_t;
typedef struct ProtocolIE_Container_2691P39 {
	A_SEQUENCE_OF(struct RICserviceUpdateAcknowledge_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P39_t;
typedef struct ProtocolIE_Container_2691P40 {
	A_SEQUENCE_OF(struct RICserviceUpdateFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P40_t;
typedef struct ProtocolIE_Container_2691P41 {
	A_SEQUENCE_OF(struct RICserviceQuery_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P41_t;
typedef struct ProtocolIE_Container_2691P42 {
	A_SEQUENCE_OF(struct E2RemovalRequestIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P42_t;
typedef struct ProtocolIE_Container_2691P43 {
	A_SEQUENCE_OF(struct E2RemovalResponseIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P43_t;
typedef struct ProtocolIE_Container_2691P44 {
	A_SEQUENCE_OF(struct E2RemovalFailureIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_2691P44_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P0_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P0_specs_1_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P0_1_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P0_constr_1_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P1_specs_3_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P1_3_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P1_constr_3_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P2_specs_5_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P2_5_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P2_constr_5_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P3_specs_7_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P3_7_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P3_constr_7_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P4_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P4_specs_9_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P4_9_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P4_constr_9_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P5_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P5_specs_11_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P5_11_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P5_constr_11_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P6_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P6_specs_13_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P6_13_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P6_constr_13_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P7_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P7_specs_15_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P7_15_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P7_constr_15_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P8_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P8_specs_17_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P8_17_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P8_constr_17_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P9_e2ap_v3_01;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P9_specs_19_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P9_19_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P9_constr_19_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_010;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P10_specs_21_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P10_21_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P10_constr_21_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_011;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P11_specs_23_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P11_23_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P11_constr_23_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_012;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P12_specs_25_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P12_25_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P12_constr_25_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_013;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P13_specs_27_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P13_27_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P13_constr_27_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_014;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P14_specs_29_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P14_29_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P14_constr_29_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_015;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P15_specs_31_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P15_31_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P15_constr_31_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_016;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P16_specs_33_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P16_33_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P16_constr_33_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_017;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P17_specs_35_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P17_35_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P17_constr_35_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_018;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P18_specs_37_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P18_37_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P18_constr_37_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P1_e2ap_v3_019;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P19_specs_39_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P19_39_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P19_constr_39_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_010;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P20_specs_41_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P20_41_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P20_constr_41_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_011;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P21_specs_43_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P21_43_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P21_constr_43_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_012;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P22_specs_45_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P22_45_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P22_constr_45_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_013;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P23_specs_47_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P23_47_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P23_constr_47_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_014;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P24_specs_49_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P24_49_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P24_constr_49_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_015;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P25_specs_51_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P25_51_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P25_constr_51_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_016;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P26_specs_53_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P26_53_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P26_constr_53_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_017;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P27_specs_55_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P27_55_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P27_constr_55_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_018;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P28_specs_57_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P28_57_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P28_constr_57_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P2_e2ap_v3_019;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P29_specs_59_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P29_59_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P29_constr_59_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_010;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P30_specs_61_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P30_61_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P30_constr_61_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_011;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P31_specs_63_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P31_63_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P31_constr_63_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_012;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P32_specs_65_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P32_65_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P32_constr_65_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_013;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P33_specs_67_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P33_67_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P33_constr_67_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_014;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P34_specs_69_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P34_69_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P34_constr_69_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_015;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P35_specs_71_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P35_71_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P35_constr_71_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_016;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P36_specs_73_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P36_73_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P36_constr_73_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_017;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P37_specs_75_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P37_75_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P37_constr_75_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_018;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P38_specs_77_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P38_77_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P38_constr_77_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P3_e2ap_v3_019;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P39_specs_79_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P39_79_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P39_constr_79_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P4_e2ap_v3_010;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P40_specs_81_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P40_81_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P40_constr_81_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P4_e2ap_v3_011;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P41_specs_83_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P41_83_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P41_constr_83_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P4_e2ap_v3_012;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P42_specs_85_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P42_85_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P42_constr_85_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P4_e2ap_v3_013;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P43_specs_87_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P43_87_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P43_constr_87_e2ap_v3_01;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_2691P4_e2ap_v3_014;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_2691P44_specs_89_e2ap_v3_01;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_2691P44_89_e2ap_v3_01[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_2691P44_constr_89_e2ap_v3_01;

#ifdef __cplusplus
}
#endif

#endif	/* _ProtocolIE_Container_H_ */
#include <asn_internal.h>
