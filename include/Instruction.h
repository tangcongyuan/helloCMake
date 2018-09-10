#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <iostream>

using namespace std;

class Instruction {
  char* content;

public:
  Instruction(const char* content) { cout << "Constructing Instrction: " << content << endl; }

};

#endif // __INSTRUCTION_H__
