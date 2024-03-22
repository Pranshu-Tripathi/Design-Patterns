#include "html_dynamic_list_strategy.h"
#include <algorithm>

void HTMLDynamicListStrategy::start(std::ostringstream &oss) {
  oss << "<ul>\n";
}

void HTMLDynamicListStrategy::end(std::ostringstream &oss) { oss << "</ul>\n"; }

void HTMLDynamicListStrategy::add_list_item(
    std::ostringstream &oss, const std::vector<std::string_view> &items) {
  const auto add_item = [&oss](const std::string_view &item) {
    oss << "    <li>" << item << "</li>\n";
  };

  std::for_each(std::begin(items), std::end(items), add_item);
}
