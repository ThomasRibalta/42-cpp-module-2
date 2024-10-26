#include "header/Intern.hpp"

AForm *makeRobot(std::string const &target)
{
  return new RobotomyRequestForm(target);
}

AForm *makeShrubbery(std::string const &target)
{
  return new ShrubberyCreationForm(target);
}

AForm *makePresidential(std::string const &target)
{
  return new PresidentialPardonForm(target);
}

Intern::Intern(void)
{
  _forms["robotomy request"] = &makeRobot;
  _forms["shrubbery creation"] = &makeShrubbery;
  _forms["presidential pardon"] = &makePresidential;
}

Intern::Intern(Intern const &src)
{
  *this = src;
}

Intern::~Intern(void) {}

Intern &Intern::operator=(Intern const &src)
{
  if (this != &src)
  {
    this->_forms = src._forms;
  }
  return *this;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
  if (_forms.find(formName) != _forms.end())
  {
    return _forms[formName](target);
  }
  else
  {
    throw Intern::UnknownFormException();
  }
}

const char *Intern::UnknownFormException::what() const throw()
{
  return "Unknown form";
}
