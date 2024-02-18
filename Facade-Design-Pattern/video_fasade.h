#pragma once
#include "third_party_video_library.h"
#include <string>

class VideoFacade : private ThirdPartyVideoLibrary {
    public:
        VideoFacade(VideoFormat format) : ThirdPartyVideoLibrary(format) {
            loadDependencies();
            loadGraphis();
        }
        void playVideo(const std::string& filename) {
            ThirdPartyVideoLibrary::playVideo(filename);
        }
        void convertVideo(const std::string& filename, VideoFormat format) {
            ThirdPartyVideoLibrary::convertVideo(filename, format);
        }
        ~VideoFacade() {
            releaseGraphics();
            releaseDependencies();
        }
};
