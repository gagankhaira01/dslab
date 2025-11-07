#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int evaluatePostfix(const std::string& expr) {
    std::stack<int> s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (std::isdigit(ch)) {
            s.push(ch - '0');
        }
        else if (ch == ' ') {
            continue;
        }
        else {
            if (s.size() < 2) {
                std::cout << "Invalid Expression" << std::endl;
                return -1;
            }

            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();

            if (ch == '+') {
                s.push(val1 + val2);
            }
            else if (ch == '-') {
                s.push(val1 - val2);
            }
            else if (ch == '*') {
                s.push(val1 * val2);
            }
            else if (ch == '/') {
                if (val2 == 0) {
                    std::cout << "Division by zero error" << std::endl;
                    return -1;
                }
                s.push(val1 / val2);
            }
            else if (ch == '^') {
                int result = 1;
                for (int j = 0; j < val2; j++) {
                    result *= val1;
                }
                s.push(result);
            }
        }
    }

    if (s.size() != 1) {
        std::cout << "Invalid Expression" << std::endl;
        return -1;
    }

    return s.top();
}

int main() {
    std::string expr;
    std::cout << "Enter a postfix expression (use single-digit operands): ";
    std::getline(std::cin, expr);

    int result = evaluatePostfix(expr);
    if (result != -1) {
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
