#include<memory>
#include<map>
#include<iostream>

enum class Importance{
    primary,
    secondary,
    tertiary
};


template <typename T, typename Key = Importance>
class Multiton{
    public:
    std::shared_ptr<T> get(const Importance importance){

        if(auto it = instances.find(importance); it != instances.end()){
            return it->second;
        }
        auto instance = std::make_shared<T>();
        instances[importance] = instance;
    }
    private:
    static std::map<Key, std::shared_ptr<T>> instances;
};

template <typename T, typename Key> std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::instances;

class Printer{
    public:
    Printer(){
        ++Printer::totalInstanceCount;
        std::cout << "A total of " << Printer::totalInstanceCount << " instances created so far\n";
    }
    private:
    static int totalInstanceCount;
};

int Printer::totalInstanceCount = 0;

int main(){
    typedef Multiton<Printer, Importance> mt;
    mt multiton; // Create an instance of Multiton
    auto main = multiton.get(Importance::primary);  // A total of 1 instances created so far
    auto aux = multiton.get(Importance::secondary); // A total of 2 instances created so far
    auto aux2 = multiton.get(Importance::secondary); // No new instance created
    return 0;
}
