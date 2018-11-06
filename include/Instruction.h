#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <iostream>

using namespace std;

class Instruction {
  const char* content;

public:
  Instruction(const char* content) {
      this->content = content;
      cout << "Constructing Instrction: " << *this << endl;
  }

  ~Instruction() { cout << "Deleting instruction: " << this << endl; }

  friend ostream& operator<<(ostream& os, Instruction& instr) {
      return os << instr.content;
  }

  friend ostream& operator<<(ostream& os, Instruction* instr) {
      return os << instr->content;
  }

};

#endif // __INSTRUCTION_H__
