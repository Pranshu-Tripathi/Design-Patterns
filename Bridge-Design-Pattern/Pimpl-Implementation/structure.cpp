#include "structure.h"
#include <iostream>

class Structure::StructureImpl {
    public:
        /**
         * Since Binary Executable is given to client. We can change this implementation,
         * without changing the provided interface, that client is using.
        */
        int secretiveStructureCalculation(){
            std::cout << "entry:: secretiveStructureCalculation()";
            return 7;
        }
};

Structure::Structure() : pimpl(new StructureImpl) {}

Structure::~Structure() = default;

int Structure::getSomeStructureCalculation(){
    std::cout << "entry:: getSomeStructureCalculation()";
    auto result = pimpl->secretiveStructureCalculation();
    return result;
}