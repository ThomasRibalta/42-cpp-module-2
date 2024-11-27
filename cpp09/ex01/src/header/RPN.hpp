#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN
{
private:
  std::stack<int> _stack;

public:
  RPN(void);
  ~RPN(void);
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  int calculate_result(std::string);
};

#endif
