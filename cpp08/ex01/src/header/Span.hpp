#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
  private :
    unsigned int _n;
    std::vector<int> _v;

  public :
    Span(void);
    Span(unsigned int n);
    Span(Span const &src);
    Span &operator=(Span const &src);
    ~Span(void);

    void addNumber(int n);
    void randomFill(unsigned int n);
    void print(void);
    int shortestSpan(void);
    int longestSpan(void);

    class NoSpanException : public std::exception {
      public :
        virtual const char *what() const throw();
    };
    class NotEnoughNumbersException : public std::exception {
      public :
        virtual const char *what() const throw();
    };
};

#endif