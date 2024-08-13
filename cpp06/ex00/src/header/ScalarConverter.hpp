#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cmath>

class ScalarConverter {
  private :
    ScalarConverter(void);
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &src);
    ~ScalarConverter(void);

  public :
    void static convert(std::string input);

};


#endif