#pragma once
#include <string>

enum class VideoFormat {
    MP4,
    AVI,
    MKV
};

/**
 * Internally this library has a lot of dependencies and graphics,
 * which are to be called in specific order to work coprrectly.
*/
class ThirdPartyVideoLibrary {

    public:
        ThirdPartyVideoLibrary(VideoFormat format) {};
        void loadDependencies() {};
        void loadGraphis() {};
        void playVideo(const std::string& filename) {};
        void closeVideo() {};
        void releaseDependencies() {};
        void releaseGraphics() {};
        void convertVideo(const std::string& filename, VideoFormat format) {};
};