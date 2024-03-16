#pragma once

#include <string>

enum class Platform;

template <typename T> class Observer {
public:
  virtual void notify(T &source, const Platform platform) const = 0;
};
