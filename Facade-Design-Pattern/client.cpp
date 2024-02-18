#include "third_party_video_library.h"
#include "video_fasade.h"

int main()
{
    /**
     * We are using a third party video operations library.
     * Our entire use case is to convert to a particular format.
    */
   ThirdPartyVideoLibrary library(VideoFormat::MP4);

    /**
     * Direct using of the library is complex and requires a lot of steps,
     * that client doesn't wants to worry about.
    */
    library.loadDependencies();
    library.loadGraphis();
    library.convertVideo("input.mkv", VideoFormat::MP4);
    library.releaseGraphics();
    library.releaseDependencies();


    /**
     * We can use a facade to simplify the process.
    */
    VideoFacade facade(VideoFormat::MP4);
    facade.convertVideo("input.mkv", VideoFormat::MP4);
}