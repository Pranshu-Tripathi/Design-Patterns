#include <iostream>
#include "square_peg_round_hole_adapter.h"

int main(){
    auto round_hole = RoundHole(5);
    auto round_peg = RoundPeg(5);
    auto square_peg = SquarePeg(5);

    if(round_hole.fits(&round_peg)){
        std::cout << "Round Peg fits to Round Hole" << std::endl; 
    }


    // Now we want to see if sqaure peg fits into the hole.
    // if(round_hole.fits(&square_peg)) -> this is not compatible as we want a round peg.


    // We need to create an adapter that will make square peg compatible with round hole.
    auto sqaure_adapter = SquarePegAdapter(&square_peg);
    if(round_hole.fits(&sqaure_adapter)){
        std::cout << "Square Peg fits to Round Hole" << std::endl; 
    }
}