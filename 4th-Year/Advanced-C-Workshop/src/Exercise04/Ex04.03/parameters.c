#include "parameters.h"
#include <stdbool.h>

Case CaseOf(const char *str)
{
    Case case_of_str = NO_CASE;
    Case case_of_char;
    for (; *str; ++str)
    {
        case_of_char = CaseOfChar(*str);
        if (case_of_char == NO_CASE)
        {
            continue;
        }
        else if (case_of_str == NO_CASE)
        {
            case_of_str = case_of_char;
        }
        else if (case_of_str != case_of_char)
        {
            case_of_str = NO_CASE;
            break;
        }
    }
    return case_of_str;
}

Case CaseOfChar(char character)
{
    return (character >= 'a' && character <= 'z') ? LOWER_CASE : (character >= 'A' && character <= 'Z') ? UPPER_CASE : NO_CASE;
}

bool IsParamChar(char c)
{
    switch (c)
    {
    case '\0':
    case ' ':
    case '\t':
    case '\n':
    case '\r':
    case '=':
        return false;

    default:
        return true;
    }
}

size_t FlagCount(const char *param)
{
    size_t result = 0;
    if (*param == '-')
    {
        ++param;
        if (*param == '-')
        {
            result = IsParamChar(param[1]);
        }
        else
        {
            const char *end = param;
            for (; IsParamChar(*end); ++end);
            result = end - param;
        }
    }
    return result;
}