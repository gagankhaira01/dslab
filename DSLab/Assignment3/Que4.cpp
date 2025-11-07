#include <iostream>

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

std::string infixToPostfix(const std::string &infix)
{
    std::stack<char> st;
    std::string postfix;

    for (char c : infix)
    {
        if (std::isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    std::string infix;
    std::cout << "Enter an infix expression: ";
    std::cin >> infix;

    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;

    return 0;
}