#include "movie.h"
#include <iostream>

void HollywoodActionMovie::showName() {
    std::cout << "Save Private Ryan" << std::endl;
}

void HollywoodComedyMovie::showName() {
    std::cout << "The Hangover" << std::endl;
}

void BollywoodActionMovie::showName() {
    std::cout << "RRR" << std::endl;
}

void BollywoodComedyMovie::showName() {
    std::cout << "Hera Pheri" << std::endl;
}