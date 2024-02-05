#include "renderer.h"
#include <iostream>

void VectorRenderer::render_shape(){
    std::cout << "Drawing Shape using vector rendering" << std::endl;
}

void RasterRenderer::render_shape(){
    std::cout << "Drawing Shape using raster rendering" << std::endl;
}