#include "header/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("default") {
  return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src._target) {
  return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
  if (this != &src) {
    this->_signed = src._signed;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
  return;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getExecGrade()) {
    throw AForm::GradeTooLowException();
  }
  if (!this->getSigned()) {
    throw AForm::FormNotSignedException();
  }
  std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

const char *PresidentialPardonForm::WriteFileException::what() const throw() {
  return "Write file failed";
}