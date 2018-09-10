#include "Instruction.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  Instruction *instr = new Instruction("instruction1");
  cout << "Hello from Eric!" << endl;
  delete instr;
  return 0;
}
