#pragma once
#include "dynamic_list_strategy.h"
class MdDynamicListStrategy : public DynamicListStrategy {
public:
  MdDynamicListStrategy(){};
  void add_list_item(std::ostringstream &oss,
                     const std::vector<std::string_view> &items) override;
};
