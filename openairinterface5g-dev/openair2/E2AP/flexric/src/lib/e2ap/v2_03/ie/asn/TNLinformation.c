/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "e42ap_v2_03.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "TNLinformation.h"

static int
memb_tnlAddress_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size >= 1UL && size <= 160UL)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_tnlPort_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if(size == 16UL) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_tnlAddress_constr_2_e2ap_v2_03 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  8,  8,  1,  160 }	/* (SIZE(1..160,...)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_tnlPort_constr_3_e2ap_v2_03 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  16,  16 }	/* (SIZE(16..16)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_TNLinformation_1_e2ap_v2_03[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct TNLinformation, tnlAddress),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING_e2ap_v2_03,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_tnlAddress_constr_2_e2ap_v2_03,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_tnlAddress_constraint_1
		},
		0, 0, /* No default value */
		"tnlAddress"
		},
	{ ATF_POINTER, 1, offsetof(struct TNLinformation, tnlPort),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING_e2ap_v2_03,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_tnlPort_constr_3_e2ap_v2_03,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_tnlPort_constraint_1
		},
		0, 0, /* No default value */
		"tnlPort"
		},
};
static const int asn_MAP_TNLinformation_oms_1_e2ap_v2_03[] = { 1 };
static const ber_tlv_tag_t asn_DEF_TNLinformation_e2ap_v2_03_tags_1_e2ap_v2_03[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_TNLinformation_tag2el_1_e2ap_v2_03[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* tnlAddress */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* tnlPort */
};
asn_SEQUENCE_specifics_t asn_SPC_TNLinformation_specs_1_e2ap_v2_03 = {
	sizeof(struct TNLinformation),
	offsetof(struct TNLinformation, _asn_ctx),
	asn_MAP_TNLinformation_tag2el_1_e2ap_v2_03,
	2,	/* Count of tags in the map */
	asn_MAP_TNLinformation_oms_1_e2ap_v2_03,	/* Optional members */
	1, 0,	/* Root/Additions */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_TNLinformation_e2ap_v2_03 = {
	"TNLinformation",
	"TNLinformation",
	&asn_OP_SEQUENCE_e2ap_v2_03,
	asn_DEF_TNLinformation_e2ap_v2_03_tags_1_e2ap_v2_03,
	sizeof(asn_DEF_TNLinformation_e2ap_v2_03_tags_1_e2ap_v2_03)
		/sizeof(asn_DEF_TNLinformation_e2ap_v2_03_tags_1_e2ap_v2_03[0]), /* 1 */
	asn_DEF_TNLinformation_e2ap_v2_03_tags_1_e2ap_v2_03,	/* Same as above */
	sizeof(asn_DEF_TNLinformation_e2ap_v2_03_tags_1_e2ap_v2_03)
		/sizeof(asn_DEF_TNLinformation_e2ap_v2_03_tags_1_e2ap_v2_03[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint_e2ap_v2_03
	},
	asn_MBR_TNLinformation_1_e2ap_v2_03,
	2,	/* Elements count */
	&asn_SPC_TNLinformation_specs_1_e2ap_v2_03	/* Additional specs */
};

