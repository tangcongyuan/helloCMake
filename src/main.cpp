#include "Instruction.h"
#include "util.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char** argv) {
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

  return 0;
}
