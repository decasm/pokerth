/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "POKERTH-PROTOCOL"
 * 	found in "../../../docs/pokerth.asn1"
 */

#ifndef	_ErrorMessage_H_
#define	_ErrorMessage_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum errorReason {
	errorReason_errorReserved	= 0,
	errorReason_errorInitVersionNotSupported	= 1,
	errorReason_errorInitServerFull	= 2,
	errorReason_errorInitAuthFailure	= 3,
	errorReason_errorInitPlayerNameInUse	= 4,
	errorReason_errorInitInvalidPlayerName	= 5,
	errorReason_errorInitServerMaintenance	= 6,
	errorReason_errorAvatarTooLarge	= 7,
	errorReason_errorAvatarUploadBlocked	= 8,
	errorReason_errorInvalidPacket	= 256,
	errorReason_errorInvalidState	= 257,
	errorReason_errorKickedFromServer	= 258,
	errorReason_errorBannedFromServer	= 259,
	errorReason_errorSessionTimeout	= 260
} e_errorReason;

/* ErrorMessage */
typedef struct ErrorMessage {
	long	 errorReason;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ErrorMessage_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_errorReason_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_ErrorMessage;

#ifdef __cplusplus
}
#endif

#endif	/* _ErrorMessage_H_ */