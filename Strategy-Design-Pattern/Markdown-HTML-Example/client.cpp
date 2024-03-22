#include "text_processor.h"
#include <iostream>
#include <vector>

int main() {
  {
    std::cout << " ------------- DYNAMIC STRATEGY ---------------" << std::endl;
    std::vector<std::string_view> input_list = {"Item 1", "Item 2", "Item 3"};

    DynamicTextProcessor txtprocessor;
    txtprocessor.set_format(Format::HTML);
    txtprocessor.append_list(input_list);
    std::cout << txtprocessor.str() << std::endl;

    txtprocessor.clear_list();
    txtprocessor.set_format(Format::MARKDOWN);
    txtprocessor.append_list(input_list);
    std::cout << txtprocessor.str() << std::endl;
  }

  {
    std::cout << " ------------- STATIC STRATEGY ----------------" << std::endl;
  }
}
