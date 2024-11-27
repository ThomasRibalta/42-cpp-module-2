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

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
  *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
  if (this != &other)
  {
    this->_data = other._data;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

float BitcoinExchange::get_value_prev(std::string date)
{
  std::map<std::string, float>::iterator it;
  std::string closest_date;
  float closest_value = -1.0f;

  for (it = _data.begin(); it != _data.end(); ++it)
  {
    const std::string &current_date = it->first;
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

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10) return false;

    if (date[4] != '-' || date[7] != '-') return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < yearStr.size(); ++i) {
        if (!isdigit(yearStr[i])) return false;
    }
    for (size_t i = 0; i < monthStr.size(); ++i) {
        if (!isdigit(monthStr[i])) return false;
    }
    for (size_t i = 0; i < dayStr.size(); ++i) {
        if (!isdigit(dayStr[i])) return false;
    }

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (month < 1 || month > 12) return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year)) daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1]) return false;

    return true;
}

void BitcoinExchange::compare_data(std::string filename)
{
  std::ifstream file(filename.c_str());

  if (file.is_open())
  {
    std::string line;
    getline(file, line);
    if (line != "date | value")
    {
      std::cout << "Error: bad input => " << line << std::endl;
    }
    while (getline(file, line))
    {
      size_t separator_pos = line.find(" | ");
      if (separator_pos == std::string::npos)
        std::cout << "Error: bad input => " << line << std::endl;
      else
      {
        std::string date = line.substr(0, separator_pos);
        std::string number = line.substr(separator_pos + 3);
        if (date.empty() || number.empty() || !isValidDate(date))
          std::cout << "Error: bad input => " << line << std::endl;
        else
        {
          float max = atof(number.c_str());
          if (max >= 1000)
            std::cout << "Error: too large a number." << std::endl;
          else if (max < 0)
            std::cout << "Error: not a positive number." << std::endl;
          else if (get_value_prev(date) < 0)
            std::cout << "Error: bad date not previous date => " << line << std::endl;
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
