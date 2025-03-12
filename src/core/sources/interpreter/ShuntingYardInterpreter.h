#pragma once
#include <vector>
#include "../tokenizer/Tokenizer.h"
#include "Interpreter.h"

namespace CalculatorCore
{
    class ShuntingYardInterpreter : public Interpreter
    {
    public:
        ~ShuntingYardInterpreter() override = default;
        double interpret(Tokenizer* tokenizer) override;

    private:
        double calculate();
        void handleOperator(const Token& op1);
        void handleRightParenthesis();

        std::vector<double> mNumberStack;
        std::vector<Token> mOutputStack;
        std::vector<Token> mOperatorStack;
    };
}
