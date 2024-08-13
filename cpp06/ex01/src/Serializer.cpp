#include "header/Serializer.hpp"

Serializer::Serializer(void) {
  return;
}

Serializer::Serializer(Serializer const &src) {
  *this = src;
  return;
}

Serializer &Serializer::operator=(Serializer const &src) {
  static_cast<void>(src);
  return *this;
}

Serializer::~Serializer(void) {
  return;
}

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}