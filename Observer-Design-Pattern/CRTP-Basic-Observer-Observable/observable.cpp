#include "observable.h"
#include "observer.h"
#include "person.h"
#include <algorithm>

template <typename T> void Observable<T>::subscribe(Observer<T> *observer) {
  observers.push_back(observer);
}

template <typename T> void Observable<T>::unsubscribe(Observer<T> *observer) {
  auto observer_it =
      std::find(std::begin(observers), std::end(observers), observer);
  if (observer_it != std::end(observers)) {
    observers.erase(observer_it);
  }
}

template <typename T>
void Observable<T>::notify_all(const T &source, const Platform platform) const {
  const auto send_notification = [platform,
                                  &source](const Observer<T> *observer) {
    observer->notify(source, platform);
  };
  std::for_each(observers.begin(), observers.end(), send_notification);
}

template class Observable<Person>;
