#include "header/Intern.hpp"

Intern::Intern(void) {
  return;
}

Intern::Intern(Intern const &src) {
  *this = src;
  return;
}

Intern::~Intern(void) {
  return;
}

Intern &Intern::operator=(Intern const &src) {
  if (this != &src) {
    // this->_signed = src._signed;
  }
  return *this;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
  if (formName == "robotomy request") {
    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
    return new RobotomyRequestForm(target);
  } else if (formName == "shrubbery creation") {
    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
    return new ShrubberyCreationForm(target);
  } else if (formName == "presidential pardon") {
    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
    return new PresidentialPardonForm(target);
  } else {
    throw Intern::UnknownFormException();
  }
}

const char *Intern::UnknownFormException::what() const throw() {
  return "Unknown form";
}