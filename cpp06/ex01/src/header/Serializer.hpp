#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <fstream>

typedef struct Data
{
  std::string name;
  int age;
} Data;

class Serializer
{
  private :
    Serializer(void);
    Serializer(Serializer const &src);
    Serializer &operator=(Serializer const &src);
    ~Serializer(void);

  public :
    uintptr_t static serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif