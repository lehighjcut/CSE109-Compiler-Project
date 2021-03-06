/*
  CSE 109
  Jordan Cutler
  jdc219
  Program Description: Full microc compiler.
  Program #7
*/

#include "token.h"
#include "lexer.h"
#include "parser.h"
#include "symbolTable.h"
#include "stack.h"
#include "hashTable.h"
#include <iostream>
#include <fstream>

using namespace std;

void processFile(istream& in) {
  Lexer lexer(in);
  Token token;
  Parser parser(lexer, cout);
  Parser::TreeNode* program = parser.compilationunit();
  //  cout << Parser::TreeNode::toString(program) << endl;
  parser.genasm(program);
}

int main(int argc, char **argv) {
  ifstream in;
  
  if (argc > 1) {
      in.open(argv[1]);
      processFile(in);
      in.close();
  } else {
    processFile(cin);
  }
  return 0;
  
}
