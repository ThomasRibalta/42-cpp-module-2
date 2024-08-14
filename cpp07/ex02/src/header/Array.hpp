#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array{
  private :
    T *_array;
    unsigned int _size;

  public :
    Array(void) : _array(new T[0]), _size(0) {}
    Array(unsigned int n) : _array(new T[n]), _size(n) {}
    Array(Array const &src) : _array(new T[src._size]), _size(src._size) {
      for (unsigned int i = 0; i < _size; i++)
        _array[i] = src._array[i];
    }
    Array &operator=(Array const &src) {
      if (this == &src)
        return *this;
      delete[] _array;
      _array = new T[src._size];
      _size = src._size;
      for (unsigned int i = 0; i < _size; i++)
        _array[i] = src._array[i];
      return *this;
    }
    ~Array(void) {
      delete[] _array;
    }

    T &operator[](unsigned int i) {
      if (i >= _size)
        throw std::out_of_range("Index out of range");
      return _array[i];
    }

    unsigned int size(void) const {
      return _size;
    }
};

#endif
