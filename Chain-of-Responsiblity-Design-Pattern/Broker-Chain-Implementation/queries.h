#pragma once
#include <string>
enum class QueryArg { attack, defense };

class Query {
public:
  Query(std::string creature_name, const QueryArg argument, int result)
      : creature_name{creature_name}, argument{argument}, result{result} {}
  ~Query() = default;
  std::string creature_name;
  QueryArg argument;
  int result;
};
