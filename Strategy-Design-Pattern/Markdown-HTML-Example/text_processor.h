#pragma once

#include "dynamic_list_strategy.h"
#include <memory>
#include <sstream>

enum class Format { HTML, MARKDOWN };

class DynamicTextProcessor {
  std::ostringstream oss;
  std::unique_ptr<DynamicListStrategy> list_strategy;

public:
  DynamicTextProcessor() {}
  ~DynamicTextProcessor() = default;

  void append_list(const std::vector<std::string_view> &items);
  void clear_list();
  std::string str() const;
  void set_format(const Format format);
};
