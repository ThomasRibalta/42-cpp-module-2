#include "header/BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange(void)
{
  std::ifstream file; 

  file.open("src/data.csv");
  if (file)
  {
    std::string line;
    while (getline(file, line))
    {
      int start = 0;
      int end = line.find(",");
      this->_data[line.substr(start, end)] = atof(line.substr(end + 1, line.length()).c_str());
    }
  }
  else
    std::cout << "Erreur ouverture du fichier: " << "src/data.csv" << std::endl;
}

BitcoinExchange::~BitcoinExchange(){}

float BitcoinExchange::get_value_prev(std::string date)
{
    std::map<std::string, float>::iterator it;
    std::string closest_date;
    float closest_value = -1.0f;

    for (it = _data.begin(); it != _data.end(); ++it)
    {
        const std::string& current_date = it->first;
        float current_value = it->second;

        if (current_date <= date)
        {
            if (closest_date.empty() || current_date >= closest_date)
            {
                closest_date = current_date;
                closest_value = current_value;
            }
        }
    }
    return closest_value;
}

void BitcoinExchange::compare_data(std::string filename) {
    std::ifstream file(filename);

    if (file.is_open())
    {
        std::string line;
        getline(file, line);
        while (getline(file, line))
        {
            size_t separator_pos = line.find(" | ");
            if (separator_pos == std::string::npos)
              std::cout << "Error: bad input => " << line << std::endl;
            else
            {
              std::string date = line.substr(0, separator_pos);
              std::string number = line.substr(separator_pos + 3);
              if (date.empty() || number.empty())
                std::cout << "Error: bad input => " << line << std::endl;
              else
              {
                float max = atof(number.c_str());
                if (max >= INT_MAX && line[line.length() - 1] == '8')
                  std::cout << "Error: too large a number." << std::endl;
                else if (max < 0)
                  std::cout << "Error: not a positive number." << std::endl;
                else if (get_value_prev(date) < 0)
                  std::cout << "Error: not previous date => " << line << std::endl;
                else
                {
                  std::cout << date << " => " << number << " = " << (get_value_prev(date) * max) << std::endl;
                }
              }
            }
                }
        file.close();
    }
    else
    {
        std::cout << "Erreur ouverture du fichier: " << filename << std::endl;
    }
}