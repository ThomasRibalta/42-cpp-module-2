#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP


#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
  private:
    std::map<std::string, float> _data;
    bool is_valid_format(const std::string& line);
    float get_value_prev(std::string data);
    
  public:
    BitcoinExchange(void);
    ~BitcoinExchange();

    void compare_data(std::string);
    
};

#endif