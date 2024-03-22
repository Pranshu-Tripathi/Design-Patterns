#include "html_dynamic_list_strategy.h"
#include "md_dynamic_list_strategy.h"
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
    std::vector<std::string_view> input_list = {"Item 1", "Item 2", "Item 3"};
    StaticTextProcessor<HTMLDynamicListStrategy> html_txtprocessor;
    html_txtprocessor.append_list(input_list);
    std::cout << html_txtprocessor.str() << std::endl;

    StaticTextProcessor<MdDynamicListStrategy> md_txtprocessor;
    md_txtprocessor.append_list(input_list);
    std::cout << md_txtprocessor.str() << std::endl;
  }
}
