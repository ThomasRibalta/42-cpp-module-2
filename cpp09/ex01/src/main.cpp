#include "header/RPN.hpp"

int main(int argc, char **argv)
{
   if (argc != 2)
   {
        std::cout << "Usage: ./RPN <expression>" << std::endl;
        return (1);
   }

   RPN calcul;

   try
   {     
      int result = calcul.calculate_result(argv[1]);
      std::cout << result << std::endl;
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }

   return (0);
}