#ifndef ANDROID_SPEECH_LOOPBACK_CONTROLLER_H
#define ANDROID_SPEECH_LOOPBACK_CONTROLLER_H

#include "SpeechPhoneCallController.h"

namespace android
{

class SpeechLoopbackController : public SpeechPhoneCallController // class adaptor pattern
{
    public:
        virtual ~SpeechLoopbackController();

        static SpeechLoopbackController *GetInstance();

        status_t OpenModemLoopbackControlFlow(const modem_index_t modem_index, const audio_devices_t input_device, const audio_devices_t output_device);
        status_t CloseModemLoopbackControlFlow(const modem_index_t modem_index);

    protected:
        SpeechLoopbackController();

        float mVoiceVolumeCopy;

    private:
        static SpeechLoopbackController *mSpeechLoopbackController; // singleton
};

} // end namespace android

#endif // end of ANDROID_SPEECH_LOOPBACK_CONTROLLER_H
