#include "header/AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _requireGrade(150), _execGrade(150) {
  return;
}

AForm::AForm(std::string const name, int requireGrade, int execGrade) : _name(name), _signed(false), _requireGrade(requireGrade), _execGrade(execGrade) {
  if (requireGrade < 1 || execGrade < 1) {
    throw AForm::GradeTooHighException();
  } else if (requireGrade > 150 || execGrade > 150) {
    throw AForm::GradeTooLowException();
  }
  return;
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _requireGrade(src._requireGrade), _execGrade(src._execGrade) {
  return;
}

AForm &AForm::operator=(AForm const &src) {
  if (this != &src) {
    this->_signed = src._signed;
  }
  return *this;
}

AForm::~AForm(void) {
  return;
}

std::string AForm::getName(void) const {
  return this->_name;
}

bool AForm::getSigned(void) const {
  return this->_signed;
}

int AForm::getRequireGrade(void) const {
  return this->_requireGrade;
}

int AForm::getExecGrade(void) const {
  return this->_execGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_requireGrade) {
    throw AForm::GradeTooLowException();
  }
  this->_signed = true;
  return;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &src) {
  out << "AForm " << src.getName() << " is ";
  if (src.getSigned()) {
    out << "signed";
  } else {
    out << "not signed";
  }
  out << " and requires grade " << src.getRequireGrade() << " to be signed and grade " << src.getExecGrade() << " to be executed" << std::endl;
  return out;
}