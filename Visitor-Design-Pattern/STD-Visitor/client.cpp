#include <iostream>
#include <string>
#include <type_traits>
#include <variant>

class AddressPrinter {
public:
  AddressPrinter(){};
  ~AddressPrinter() = default;
  void operator()(std::string add) {
    std::cout << "A house named : " << add << std::endl;
  }
  void operator()(int add) {
    std::cout << "House numer : " << add << std::endl;
  }
};

int main() {

  std::variant<std::string, int> address;

  std::cout << "+++++++ USING CLASS OVERLOADING ++++++++_" << std::endl;
  address = 123;
  AddressPrinter ap;
  std::visit(ap, address);
  address = "A House Name";
  std::visit(ap, address);

  std::cout << "+++++++ USING LAMBDA ++++++++_" << std::endl;

  address = 007;
  std::visit(
      [](auto &arg) {
        if constexpr (std::is_same_v<std::decay_t<decltype(arg)>,
                                     std::string>) {
          std::cout << "A Lambda infered house name : " << arg << std::endl;
        }
        if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, int>) {
          std::cout << "A Lambda infered house number : " << arg << std::endl;
        }
      },
      address);
}
