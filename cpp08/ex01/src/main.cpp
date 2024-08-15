#include "header/Span.hpp"

int main(void) {
  Span s(5);
  s.addNumber(5);
  s.addNumber(3);
  s.addNumber(17);
  s.addNumber(9);
  s.addNumber(11);
  std::cout << s.shortestSpan() << std::endl;
  std::cout << s.longestSpan() << std::endl;

  Span s2(5);
  s2.randomFill(5);
  std::cout << "print s2" << std::endl;
  s2.print();
  std::cout << "shortestSpan and longestSpan" << std::endl;
  std::cout << s2.shortestSpan() << std::endl;
  std::cout << s2.longestSpan() << std::endl;

  return 0;
}