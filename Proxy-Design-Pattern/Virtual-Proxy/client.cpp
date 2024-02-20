#include "legacy_bitmap.h"
#include "proxy_bitmap.h"
#include <iostream>

int main() {
    std::cout << "legacy instantiation" << std::endl;
    LegacyBitmap bitmap{"pokemon.png"};
    std::cout << "legacy draw" << std::endl;
    bitmap.draw();

    std::cout << "proxy instantiation" << std::endl;
    ProxyBitmap proxy{"pokemon.png"};
    std::cout << "proxy draw" << std::endl;
    proxy.draw();
    return 0;
}