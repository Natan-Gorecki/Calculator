#pragma once
#include <string>
#include "ETokenType.h"

struct Token
{
    ETokenType tokenType = ETokenType::UNDEFINED;
    std::string stringValue = "";
    double numberValue = 0;
    char characterValue = 0;
};
