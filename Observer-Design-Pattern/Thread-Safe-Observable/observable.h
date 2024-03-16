#pragma once
#include "observer.h"
#include <mutex>
#include <vector>
template <typename T> class Observable {
  std::vector<Observer<T> *> observers;
  /**
  recursive mutex is better than a normal mutex,
  when we have situation of re-enterance. Example
  in notify of an observer if it wants to unsubscribe,
  the mutex will throw error of resource already in use.
  But the recursive mutex handles it. Though recursive mutex
  is hated across the cpp community.

  Possible Reasons:

  Potential for Deadlocks: Recursive mutexes allow a thread to lock the same
  mutex multiple times. While this can be useful in certain scenarios, it also
  increases the risk of deadlocks if not used carefully. For example, if a
  thread acquires a mutex recursively and then waits for another thread to
  release the same mutex, it can result in a deadlock.

  Complexity and Maintainability: Code that relies heavily on recursive mutexes
  can be harder to understand and maintain, especially in large codebases or
  when multiple developers are involved. It's easier to introduce subtle bugs
  related to locking and unlocking behavior.

  Performance Overhead: Recursive mutexes typically come with a performance
  overhead compared to non-recursive mutexes. This overhead is due to the need
  to keep track of the lock count and additional bookkeeping associated with
  recursive locking.

  Design Considerations: In many cases, the need for recursive locking can be an
  indication of a design flaw or architectural issue. Relying on recursive
  mutexes to manage shared resources may indicate that the code could be
  restructured to reduce the need for nested locking.

  Alternatives: In modern C++ and concurrent programming, alternatives to
  recursive mutexes exist, such as using non-recursive mutexes along with
  different design patterns like the "pass the mutex" idiom or using
  higher-level concurrency constructs provided by libraries like the C++
  Standard Library or third-party libraries.
  */
  std::recursive_mutex mutex;

public:
  void subscribe(Observer<T> *observer);
  void unsubscribe(Observer<T> *observer);
  void notify_all(const T &source, const Platform platform);
};
