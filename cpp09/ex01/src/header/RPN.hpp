#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN
{
  private:
    std::stack<int> _stack;

  public:
    RPN(void);
    ~RPN(void);
    int calculate_result(std::string);
};

#endif