#pragma once
#include <stdexcept>

class InterpreterException : public std::exception
{
    using std::exception::exception;
};
