#include "structure.h"
#include <iostream>

int main(){
    Structure s;
    /**
     * Client code is not aware of how the secretiveStructureCalculation is implemented.
     * It only gets the final result for getSomeStructureCalculation.
     */
    std::cout << s.getSomeStructureCalculation() << std::endl;
    return 0;
}