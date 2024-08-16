#include "header/RPN.hpp"

RPN::RPN(void){}

RPN::~RPN(void){}

int RPN::calculate_result(std::string expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]))
        {
            this->_stack.push(std::stoi(token));
        }
        else
        {
            if (this->_stack.size() < 2)
            {
                throw std::runtime_error("Error: insufficient operands.");
            }
            int b = this->_stack.top();
            this->_stack.pop();
            int a = this->_stack.top();
            this->_stack.pop();

            if (token == "+")
            {
                this->_stack.push(a + b);
            }
            else if (token == "-") 
            {
                this->_stack.push(a - b);
            }
            else if (token == "*")
            {
                this->_stack.push(a * b);
            }
            else if (token == "/")
            {
                if (b == 0)
                {
                    throw std::runtime_error("Error: division by zero.");
                }
                this->_stack.push(a / b);
            }
            else
            {
                throw std::runtime_error("Error: unknown operator.");
            }
        }
    }

    if (this->_stack.size() != 1) {
        throw std::runtime_error("Error: malformed expression.");
    }

    return this->_stack.top();
}
