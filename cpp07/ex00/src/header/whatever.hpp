#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T min(T const &a, T const &b) {
  return (a < b) ? a : b;
}

template <typename T>
T max(T const &a, T const &b) {
  return (a > b) ? a : b;
}

#endif