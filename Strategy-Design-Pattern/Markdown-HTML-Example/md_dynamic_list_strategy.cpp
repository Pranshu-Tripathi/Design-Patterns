#include "md_dynamic_list_strategy.h"
#include <algorithm>
#include <iterator>

void MdDynamicListStrategy::add_list_item(
    std::ostringstream &oss, const std::vector<std::string_view> &items) {

  const auto add_item = [&oss](const std::string_view &item) {
    oss << "*   " << item << "\n";
  };
  std::for_each(std::begin(items), std::end(items), add_item);
}
