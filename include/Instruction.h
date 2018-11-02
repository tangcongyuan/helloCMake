#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <iostream>

using namespace std;

class Instruction {
  const char* content;

public:
  Instruction(const char* content) {
      this->content = content;
      cout << "Constructing Instrction: " << this->content << endl;
  }
  ~Instruction() { cout << "Deleting instruction: " << this->content << endl; }

};

#endif // __INSTRUCTION_H__
