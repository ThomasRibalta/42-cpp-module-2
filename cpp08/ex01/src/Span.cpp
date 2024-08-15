#include "header/Span.hpp"

Span::Span(void) : _n(0) {
  return;
}

Span::Span(unsigned int n) : _n(n) {
  return;
}

Span::Span(Span const &src) {
  *this = src;
}

Span &Span::operator=(Span const &src) {
  if (this != &src) {
    this->_n = src._n;
    this->_v = src._v;
  }
  return *this;
}

Span::~Span(void) {
  return;
}

void Span::addNumber(int n) {
  if (this->_v.size() >= this->_n) {
    throw Span::NoSpanException();
  }
  this->_v.push_back(n);
}

void Span::randomFill(unsigned int n) {
  if (this->_v.size() + n > this->_n) {
    throw Span::NoSpanException();
  }
  srand(time(0));
  for (unsigned int i = 0; i < n; i++) {
    this->_v.push_back(rand());
  }
}

void Span::print(void) {
  for (std::vector<int>::iterator it = this->_v.begin(); it != this->_v.end(); it++) {
    std::cout << *it << std::endl;
  }
}

int Span::shortestSpan(void) {
  if (this->_v.size() < 2) {
    throw Span::NotEnoughNumbersException();
  }
  std::vector<int> v = this->_v;
  std::sort(v.begin(), v.end());
  int min = v[1] - v[0];
  for (std::vector<int>::iterator it = v.begin(); it != v.end() - 1; it++) {
    if (*(it + 1) - *it < min) {
      min = *(it + 1) - *it;
    }
  }
  return min;
}

int Span::longestSpan(void) {
  if (this->_v.size() < 2) {
    throw Span::NotEnoughNumbersException();
  }
  std::vector<int> v = this->_v;
  std::sort(v.begin(), v.end());
  return v[v.size() - 1] - v[0];
}

const char *Span::NoSpanException::what() const throw() {
  return "No span";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
  return "Not enough numbers";
}