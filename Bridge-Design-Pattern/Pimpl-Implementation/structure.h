#include <memory>
class Structure {
private:
    class StructureImpl; /*Forward Declaration of Implementation Class*/
    std::unique_ptr<StructureImpl> pimpl; /*Implementation Class Pointer*/

public:
    Structure();
    ~Structure();
    int getSomeStructureCalculation();
};