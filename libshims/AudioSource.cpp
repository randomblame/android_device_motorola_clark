/*
 * Copyright (C) 2018 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <system/audio.h>
#include <utils/String16.h>

// Shim for frameworks/av/media/libstagefright/AudioSource

namespace android {

    // This is the constructor prototype for android::AudioSource in Pie which has an extra parameter
    extern "C" void _ZN7android11AudioSourceC1E14audio_source_tRKNS_8String16Ejjjjii(audio_source_t inputSource, const String16 &opPackageName,
            uint32_t sampleRate, uint32_t channels, uint32_t outSampleRate, uid_t uid, pid_t pid,
            audio_port_handle_t selectedDeviceId);

    // This is the constructor prototype for android::AudioSource we need to create
    extern "C" void _ZN7android11AudioSourceC1E14audio_source_tRKNS_8String16Ejjjji(audio_source_t inputSource, const String16 &opPackageName,
        uint32_t sampleRate, uint32_t channelCount, uint32_t outSampleRate, uid_t uid, pid_t pid);


    // Define the missing constructor symbol
    extern "C" void _ZN7android11AudioSourceC1E14audio_source_tRKNS_8String16Ejjjji(audio_source_t inputSource, const String16 &opPackageName,
        uint32_t sampleRate, uint32_t channelCount, uint32_t outSampleRate, uid_t uid, pid_t pid)
    {
        // Invoke the Pie android::AudioSource constructor with the extra parameter
        _ZN7android11AudioSourceC1E14audio_source_tRKNS_8String16Ejjjjii(inputSource, opPackageName, sampleRate, channelCount, outSampleRate, uid, pid, 0);
    }

}
