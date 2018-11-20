#ifndef __CONCURRENT_COUNTER__
#define __CONCURRENT_COUNTER__

#include <thread>
#include <atomic>
#include <iostream>

struct Counter {
  std::mutex mutex;
  int value;

  Counter(): value(0) {}

  void increment() {
    mutex.lock();
    value++;
    mutex.unlock();
  }
};

struct AtomicCounter {
  std::atomic<int> value;

  AtomicCounter(): value(0) {}

  void increment() {
    value++;
  }

  int get() {
    return value.load();
  }
};

class ConcurrentCounter {
public:
  ConcurrentCounter() {
    std::cout << std::endl;
    std::cout << "Concurrent Counter starts:" << std::endl;
  }

  ~ConcurrentCounter() {
    std::cout << "Concurrent Counter ends." << std::endl;
    std::cout << std::endl;
  }

  void operator()(const int NUM_OF_THREADS = 10) const {
    Counter counter;
    AtomicCounter aCounter;
    std::thread threads[NUM_OF_THREADS];

    // Mutex with Counter
    for(int i = 0; i < NUM_OF_THREADS; i++) {
      threads[i] = std::thread([&counter]() {
        for(int i = 0; i < 1000; i++)  counter.increment();
      });
    }
    for(int i = 0; i < NUM_OF_THREADS; i++) {
      threads[i].join();
    }
    std::cout << "Counter value = " << counter.value << std::endl;

    // Atomic Types with AtomicCounter
    for(int i = 0; i < NUM_OF_THREADS; i++) {
      threads[i] = std::thread([&aCounter]() {
        for(int i = 0; i < 1000; i++)  aCounter.increment();
      });
    }
    for(int i = 0; i < NUM_OF_THREADS; i++) {
      threads[i].join();
    }
    std::cout << "Atomic Counter value = " << aCounter.get() << std::endl;
  }

}; // end of class ConcurrentCounter

#endif // __CONCURRENT_COUNTER__
