#include "header/Serializer.hpp"

int main(void) {
  Data data;
  data.name = "John";
  data.age = 42;

  uintptr_t serialized = Serializer::serialize(&data);
  Data *deserialized = Serializer::deserialize(serialized);

  std::cout << "Name: " << deserialized->name << std::endl;
  std::cout << "Age: " << deserialized->age << std::endl;

  return 0;
}