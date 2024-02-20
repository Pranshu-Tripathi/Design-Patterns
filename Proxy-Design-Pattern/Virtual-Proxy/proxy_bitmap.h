#pragma once

#include "image.h"
#include <string>


class LegacyBitmap;

/**
 * This is a mimicing simulation on Legacy bitmap that works
 * as a efficient proxy for the actual bitmap.
*/
class ProxyBitmap : public Image {
    public:
        ProxyBitmap(const std::string& filename);
        void draw() override;
    private:
        std::string filename;
        LegacyBitmap* bitmap{nullptr};
};