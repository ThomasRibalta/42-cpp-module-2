#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <iterator>
# include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw std::exception();
  return it;
}

#endif