#pragma once
#include "stack.cpp"
#include <map>

class BalancedBrackets
{
public:
    static bool Find(char bracket, char* brackets)
    {
        for(int i = 0; i < 3; i++)
        {
            if(bracket == brackets[i])
            {
                return true;
            }
        }

        return false;
    }
    static bool IsBalanced(std::string str)
    {
        char openBrackets[] = {'(', '{', '['};

        std::map<char, char> bracketPairs;
        bracketPairs[')'] = '(';
        bracketPairs['}'] = '{';
        bracketPairs[']'] = '[';

        Stack *stack = new Stack();

        for(int i = 0; i < str.length(); i++)
        {
            if(Find(str[i], openBrackets))
            {
                stack->Push(str[i]);
            }
            else
            {
                char top = stack->Pop();
                if(top == bracketPairs[str[i]])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        if(stack->Size() != 0) return false;
        return true;
    }
};
