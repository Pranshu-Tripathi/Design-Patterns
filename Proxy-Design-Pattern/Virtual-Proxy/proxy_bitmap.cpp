#include "proxy_bitmap.h"
#include "legacy_bitmap.h"

#include <iostream>

ProxyBitmap::ProxyBitmap(const std::string &filename) : filename(filename) {
  /**
   * Avoided the computationally heavy initialization in legacy.
   */
}

void ProxyBitmap::draw() {
  /**
   * Lazy initialization of the actual bitmap.
   */
  if (!bitmap) {
    bitmap = new LegacyBitmap(filename);
  }
  bitmap->draw();
}
