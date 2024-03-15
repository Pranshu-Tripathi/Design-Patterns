#pragma once
#include "observer.h"
#include <vector>
template <typename T> class Observable {
  std::vector<Observer<T> *> observers;

public:
  void subscribe(Observer<T> *observer);
  void unsubscribe(Observer<T> *observer);
  void notify_all(const T &source, const Platform platform) const;
};
