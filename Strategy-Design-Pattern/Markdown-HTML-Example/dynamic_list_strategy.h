#pragma once

#include <sstream>
#include <string_view>
#include <vector>

class DynamicListStrategy {
public:
  virtual void start(std::ostringstream &oss){};
  virtual void add_list_item(std::ostringstream &oss,
                             const std::vector<std::string_view> &items) = 0;
  virtual void end(std::ostringstream &oss){};
};
