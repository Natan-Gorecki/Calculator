#pragma once
#include <memory>
#include "../tokenizer/Tokenizer.h"
#include "../Interpreter.h"

class RecursiveInterpreter : public Interpreter
{
public:
    virtual ~RecursiveInterpreter() {};
    double interpret(Tokenizer* tokenizer) override;

private:
    double interpretImpl(int start, int end);
    bool findLeastPrecedenceOperator(int start, int end, int& position);
    bool isWrapperWithBrackets(int start, int end);

    Tokenizer* mTokenizer = nullptr;
};
