#pragma once
#include "image.h"
#include <string>

/**
 * Legacy Bitmap did some computationaly heavy initialization
 * which we dont care about till we call the draw method.
*/
class LegacyBitmap : public Image {
    public:
        LegacyBitmap(const std::string& filename);
        void draw() override;
    private:
        std::string filename;
};
