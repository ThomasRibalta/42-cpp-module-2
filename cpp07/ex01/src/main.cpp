#include "header/iter.hpp"
#include <iostream>
#include <string>

void print(int &i) {
  std::cout << i << " ";
}

void addOne(int &i) {
  i++;
}

int main(void) {
  int tab[] = {0, 1, 2, 3, 4};
  for (int i = 0; i < 10; i++)
  {
    ::iter(tab, 5, print);
    std::cout << std::endl;
    ::iter(tab, 5, addOne);
  }
  return 0;
}