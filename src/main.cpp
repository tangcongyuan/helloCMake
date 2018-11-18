#include "Instruction.h"
#include "util.h"
#include <thread>
#include <iostream>
#include <vector>
#include <list>

void threadFunction() {
  using namespace std;
  cout << "Your're inside a new thread." << endl;
}

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

  thread th(threadFunction);
  cout << "Your're inside the main thread." << endl;
  th.join();

  return 0;
}
