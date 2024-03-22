#pragma once
#include "dynamic_list_strategy.h"

class HTMLDynamicListStrategy : public DynamicListStrategy {
public:
  void start(std::ostringstream &oss) override;
  void end(std::ostringstream &oss) override;
  void add_list_item(std::ostringstream &oss,
                     const std::vector<std::string_view> &items) override;
};
