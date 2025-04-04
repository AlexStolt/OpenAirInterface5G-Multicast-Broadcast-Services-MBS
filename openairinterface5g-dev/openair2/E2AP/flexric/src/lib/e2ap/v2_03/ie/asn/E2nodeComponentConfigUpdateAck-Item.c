/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "e42ap_v2_03.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "E2nodeComponentConfigUpdateAck-Item.h"

asn_TYPE_member_t asn_MBR_E2nodeComponentConfigUpdateAck_Item_1_e2ap_v2_03[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2nodeComponentConfigUpdateAck_Item, e2nodeComponentInterfaceType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2nodeComponentInterfaceType_e2ap_v2_03,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"e2nodeComponentInterfaceType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2nodeComponentConfigUpdateAck_Item, e2nodeComponentID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2nodeComponentID_e2ap_v2_03,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"e2nodeComponentID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2nodeComponentConfigUpdateAck_Item, e2nodeComponentConfigurationAck),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2nodeComponentConfiguration_e2ap_v2_03Ack_e2ap_v2_03,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"e2nodeComponentConfigurationAck"
		},
};
static const ber_tlv_tag_t asn_DEF_E2nodeComponentConfigUpdateAck_Item_e2ap_v2_03_tags_1_e2ap_v2_03[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2nodeComponentConfigUpdateAck_Item_tag2el_1_e2ap_v2_03[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* e2nodeComponentInterfaceType */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* e2nodeComponentID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* e2nodeComponentConfigurationAck */
};
asn_SEQUENCE_specifics_t asn_SPC_E2nodeComponentConfigUpdateAck_Item_specs_1_e2ap_v2_03 = {
	sizeof(struct E2nodeComponentConfigUpdateAck_Item),
	offsetof(struct E2nodeComponentConfigUpdateAck_Item, _asn_ctx),
	asn_MAP_E2nodeComponentConfigUpdateAck_Item_tag2el_1_e2ap_v2_03,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2nodeComponentConfigUpdateAck_Item_e2ap_v2_03 = {
	"E2nodeComponentConfigUpdateAck-Item",
	"E2nodeComponentConfigUpdateAck-Item",
	&asn_OP_SEQUENCE_e2ap_v2_03,
	asn_DEF_E2nodeComponentConfigUpdateAck_Item_e2ap_v2_03_tags_1_e2ap_v2_03,
	sizeof(asn_DEF_E2nodeComponentConfigUpdateAck_Item_e2ap_v2_03_tags_1_e2ap_v2_03)
		/sizeof(asn_DEF_E2nodeComponentConfigUpdateAck_Item_e2ap_v2_03_tags_1_e2ap_v2_03[0]), /* 1 */
	asn_DEF_E2nodeComponentConfigUpdateAck_Item_e2ap_v2_03_tags_1_e2ap_v2_03,	/* Same as above */
	sizeof(asn_DEF_E2nodeComponentConfigUpdateAck_Item_e2ap_v2_03_tags_1_e2ap_v2_03)
		/sizeof(asn_DEF_E2nodeComponentConfigUpdateAck_Item_e2ap_v2_03_tags_1_e2ap_v2_03[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint_e2ap_v2_03
	},
	asn_MBR_E2nodeComponentConfigUpdateAck_Item_1_e2ap_v2_03,
	3,	/* Elements count */
	&asn_SPC_E2nodeComponentConfigUpdateAck_Item_specs_1_e2ap_v2_03	/* Additional specs */
};

