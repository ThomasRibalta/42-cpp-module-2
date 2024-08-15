#include "header/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
   if (argc != 2)
   {
        std::cout << "Usage: ./btc <filename>" << std::endl;
        return (1);
   }

   BitcoinExchange btc;
   btc.compare_data(argv[1]);
   return (0);
}