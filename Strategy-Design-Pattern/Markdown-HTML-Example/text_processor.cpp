#include "text_processor.h"
#include "html_dynamic_list_strategy.h"
#include "md_dynamic_list_strategy.h"
#include <stdexcept>

void DynamicTextProcessor::clear_list() {
  oss.str("");
  oss.clear();
}

std::string DynamicTextProcessor::str() const { return oss.str(); }

void DynamicTextProcessor::set_format(const Format format) {
  switch (format) {
  case Format::HTML:
    list_strategy = std::make_unique<HTMLDynamicListStrategy>();
    break;
  case Format::MARKDOWN:
    list_strategy = std::make_unique<MdDynamicListStrategy>();
    break;
  default:
    throw std::runtime_error("Undefined format provided!\n");
  }
}

void DynamicTextProcessor::append_list(
    const std::vector<std::string_view> &items) {
  list_strategy->start(oss);
  list_strategy->add_list_item(oss, items);
  list_strategy->end(oss);
}
