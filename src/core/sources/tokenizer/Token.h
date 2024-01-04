#pragma once
#include <string>
#include "ETokenType.h"

struct Token
{
    ETokenType type = ETokenType::UNDEFINED;
    std::string stringValue = "";
    double numberValue = 0;
    char charValue = 0;
};
