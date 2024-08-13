#include "header/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
  return;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
  *this = src;
  return;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
  static_cast<void>(src);
  return *this;
}

ScalarConverter::~ScalarConverter(void) {
  return;
}

void print_char(std::string input)
{
  char c = std::atoi(input.c_str());
  if (input.length() == 1 && !isdigit(input[0]))
    std::cout << "char: '" << input << "'" << std::endl;
  else if (isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else if (input.length() == 1 && isdigit(input[0]))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: impossible" << std::endl;
}

void print_int(std::string input)
{
  if (input.length() == 1)
  {
    if (!std::isprint(input[0]))
      std::cout << "int: impossible" << std::endl;
    else
      std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
    return;
  }

  long long int i = std::atoll(input.c_str());
  if (i > INT_MAX || i < INT_MIN)
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << i << std::endl;
}

void print_float(std::string input)
{
  float f = std::atof(input.c_str());
  if (f - static_cast<int>(f) == 0)
    std::cout << "float: " << f << ".0f" << std::endl;
  else
    std::cout << "float: " << f << "f" << std::endl;
}

void print_double(std::string input)
{
  double d = std::atof(input.c_str());
  if (d - static_cast<int>(d) == 0)
    std::cout << "double: " << d << ".0" << std::endl;
  else
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string input)
{
  print_char(input);
  print_int(input);
  print_float(input);
  print_double(input);

}
