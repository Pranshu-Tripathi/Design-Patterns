#include "text_processor.h"
#include "html_dynamic_list_strategy.h"
#include "md_dynamic_list_strategy.h"
#include <stdexcept>
#include <vector>

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

template <typename ListStrategy>
void StaticTextProcessor<ListStrategy>::append_list(
    const std::vector<std::string_view> &items) {
  list_strategy.start(oss);
  list_strategy.add_list_item(oss, items);
  list_strategy.end(oss);
}

template <typename ListStrategy>
void StaticTextProcessor<ListStrategy>::clear_list() {
  oss.str("");
  oss.clear();
}

template <typename ListStrategy>
std::string StaticTextProcessor<ListStrategy>::str() const {
  return oss.str();
}

template class StaticTextProcessor<HTMLDynamicListStrategy>;
template class StaticTextProcessor<MdDynamicListStrategy>;
