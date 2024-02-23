#include "legacy_bitmap.h"

#include <iostream>

LegacyBitmap::LegacyBitmap(const std::string &filename) : filename(filename) {
  std::cout << "Loading image from (Computationally heavy) " << filename
            << std::endl;
}

void LegacyBitmap::draw() {
  std::cout << "Drawing image from " << filename << std::endl;
}
