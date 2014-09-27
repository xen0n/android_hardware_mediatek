#ifndef ANDROID_AUDIO_POLICY_PARAMETERS_H
#define ANDROID_AUDIO_POLICY_PARAMETERS_H

enum PolicyParameters
{
    POLICY_LOAD_VOLUME =         0,
    POLICY_SET_FM_SPEAKER,
    POLICY_CHECK_FM_PRIMARY_KEY_ROUTING,
    POLICY_SET_FM_PRESTOP,
    POLICY_SET_A2DP_FORCE_IGNORE,
};

// for User Case Manager
#ifndef __MTK_AUDIO_USER_CASE_MANAGER_CONSTANTS_DEFINED
#define __MTK_AUDIO_USER_CASE_MANAGER_CONSTANTS_DEFINED
static const char *keyInitVoume = "VolumeInit";
static const char *keySetVoumeIndex = "SetVolumeIndex";
static const char *keySetStreamStart = "SetStreamStart";
static const char *keySetStreamStop = "SetStreamStop";
static const char *keySetRecordStreamStart = "SetRecordStreamStart";
static const char *keySetRecordStreamStop = "SetRecordStreamStop";
#endif

//!  BESLOUDNESS_CONTROL_CALLBACK_STRUCT interface
/*!
this structure is hold for flinger callback funtion
*/
typedef struct _BESLOUDNESS_CONTROL_CALLBACK_STRUCT
{
    void (*callback)(void *data);
} BESLOUDNESS_CONTROL_CALLBACK_STRUCT;

#endif // end of ANDROID_AUDIO_POLICY_PARAMETERS_H
