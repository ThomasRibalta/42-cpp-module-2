#include "header/PmergeMe.hpp"

int main(int argc, char **argv)
{
   if (argc < 2)
   {
        std::cout << "Usage: ./PmergeMe <number1> <number2> ..." << std::endl;
        return (1);
   }
   PmergeMe merge;

   if (merge.parse_args(argv + 1))
      return (1);

   if (merge.merge_vector() || merge.merge_list())
      return (1);

   merge.display();

   return (0);
}