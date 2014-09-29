// MtkAudioSrc implementation reverse-engineered by looking at its usage and
// comparing with the original blisrc-based ones.

#define LOG_TAG "MtkAudioSrc-xen0n"
#include <utils/Log.h>

#include "MtkAudioSrc.h"


namespace android {
MtkAudioSrc::MtkAudioSrc(
        const unsigned int inSR,
        const unsigned int inChannel,
        const unsigned int outSR,
        const unsigned int outChannel,
        const int dummy
        ) : mInSR(inSR), mInChannels(inChannel), mOutSR(outSR), mOutChannels(outChannel), bliHandle(NULL), buf(NULL) {
    ALOGD(
            "[%p] ctor: inSR=%u inChannel=%u outSR=%u outChannel=%u dummy=%d",
            this,
            inSR,
            inChannel,
            outSR,
            outChannel,
            dummy
            );
    BLI_GetMemSize(inSR, inChannel, outSR, outChannel, &bufSize);
    ALOGD("ctor: bufSize=%u", bufSize);
}

MtkAudioSrc::~MtkAudioSrc()
{
    ALOGD("[%p] dtor", this);
    if (bliHandle != NULL) {
        BLI_Close(bliHandle, NULL);
        bliHandle = NULL;
    }

    if (buf != NULL) {
        delete buf;
        buf = NULL;
    }
}

void MtkAudioSrc::Open()
{
    if (bliHandle != NULL) {
        ALOGW("[%p] Open: already opened...", this);
        return;
    }

    if (buf != NULL) {
        ALOGW("[%p] Open: buf already allocated? (buf=%p)", this, buf);
        delete buf;
    }

    ALOGD("[%p] Open", this);
    buf = new char[bufSize];

    bliHandle = BLI_Open(mInSR, mInChannels, mOutSR, mOutChannels, buf, NULL);
    if (!bliHandle) {
        ALOGE("[%p] Open: BLI_Open failed", this);
    } else {
        ALOGD("[%p] Open: succeeded, bliHandle=%p", this, bliHandle);
    }
}

void MtkAudioSrc::Close()
{
    if (bliHandle == NULL) {
        ALOGW("[%p] Close: not opened", this);
        return;
    }

    if (buf != NULL) {
        delete buf;
        buf = NULL;
    } else {
        ALOGW("[%p] Close: bliHandle != NULL but buf == NULL", this);
    }

    BLI_Close(bliHandle, NULL);
    bliHandle = NULL;
}

void MtkAudioSrc::Process(
        short *inBuf,
        unsigned int *inLength,
        short *outBuf,
        unsigned int *outLength
        )
{
    BLI_Convert(bliHandle, inBuf, inLength, outBuf, outLength);
}

}


// vim:set ai et ts=4 sw=4 sts=4 fenc=utf-8:
