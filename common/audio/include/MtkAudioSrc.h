// MtkAudioSrc implementation reverse-engineered by looking at its usage and
// comparing with the original blisrc-based ones.
#ifndef _MTK_AUDIOSRC_H_
#define _MTK_AUDIOSRC_H_

#include "bli_exp.h"


namespace android {
// so what's this?
enum {
    SRC_IN_Q1P15_OUT_Q1P15 = 0,
};


class MtkAudioSrc {
    public:
        MtkAudioSrc(
                const unsigned int inSR,
                const unsigned int inChannel,
                const unsigned int outSR,
                const unsigned int outChannel,
                const int dummy
                );

        ~MtkAudioSrc();

        explicit operator bool() const
        {
            return bliHandle != NULL;
        }

        void Open();
        void Close();
        void Process(
                short *inBuf,
                unsigned int *inLength,
                short *outBuf,
                unsigned int *outLength
                );

    private:
        unsigned int mInSR;
        unsigned int mInChannels;
        unsigned int mOutSR;
        unsigned int mOutChannels;

        BLI_HANDLE *bliHandle;
        unsigned int bufSize;
        char *buf;
};
}

#endif


// vim:set ai et ts=4 sw=4 sts=4 fenc=utf-8:
