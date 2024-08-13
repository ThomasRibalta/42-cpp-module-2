#include "header/ScalarConverter.hpp"

int main(int ac, char **argv)
{
  if (ac != 2)
  {
    std::cout << "Usage: ./convert [value]" << std::endl;
    return 1;
  }
  ScalarConverter::convert(argv[1]);
  return 0;
}