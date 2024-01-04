#pragma once
#include <string>
#include "EOperatorType.h"
#include "ETokenType.h"

struct Token
{
    ETokenType tokenType = ETokenType::UNDEFINED;
    double numberValue = 0;
    char separatorValue = 0;
    EOperatorType operatorType = EOperatorType::UNDEFINED;
    int operatorPriority = 0;
};
