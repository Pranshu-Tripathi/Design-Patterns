#include <functional>

class SingletonTester {
    public:
    template <typename T>
    bool is_singleton(std::function<T*()> factory){
        return factory() == factory();
    }
};

class Singleton{
    public:
    static Singleton* get_instance(){
        if(!instance){
            instance = new Singleton();
        }
        return instance;
    }
    private:
    Singleton(){}
    static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

int main(){
    SingletonTester tester;
    bool res = tester.is_singleton<Singleton>([](){return Singleton::get_instance();});
    return 0;
}