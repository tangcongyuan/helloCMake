#include "Instruction.h"
#include "util.h"
#include <thread>
#include <atomic>
#include <iostream>
#include <vector>
#include <list>

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

int main(int argc, char** argv) {
  using namespace std;

  Instruction *instr = new Instruction("instruction1");
  cout << "Hello from Eric!" << endl;
  cout << "instr = " << instr << endl;
  delete instr;

  list<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(3);
  util::print(v, "list");

  // Mutex with Counter
  const int THREAD_NUM = 10;
  thread threads[THREAD_NUM];
  Counter counter;
  for(int i = 0; i < THREAD_NUM; i++) {
    threads[i] = thread([&counter]() {
      for(int i = 0; i < 1000; i++)  counter.increment();
    });
  }
  for(int i = 0; i < THREAD_NUM; i++) {
    threads[i].join();
  }
  cout << "Counter value = " << counter.value << endl;

  // Atomic Types with AtomicCounter
  AtomicCounter aCounter;
  for(int i = 0; i < THREAD_NUM; i++) {
    threads[i] = thread([&aCounter]() {
      for(int i = 0; i < 1000; i++)  aCounter.increment();
    });
  }
  for(int i = 0; i < THREAD_NUM; i++) {
    threads[i].join();
  }
  cout << "Atomic Counter value = " << aCounter.get() << endl;

  return 0;
}
