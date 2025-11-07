#include <iostream>

bool isBalanced(const std::string &expr)
{
    std::stack<char> s;

    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return s.empty();
}

int main()
{
    std::string expr;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expr);

    if (isBalanced(expr))
        std::cout << "Expression is balanced" << std::endl;
    else
        std::cout << "Expression is not balanced" << std::endl;

    return 0;
}
