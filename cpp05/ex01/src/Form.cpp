#include "header/Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _requireGrade(150), _execGrade(150) {
  return;
}

Form::Form(std::string const name, int requireGrade, int execGrade) : _name(name), _signed(false), _requireGrade(requireGrade), _execGrade(execGrade) {
  if (requireGrade < 1 || execGrade < 1) {
    throw Form::GradeTooHighException();
  } else if (requireGrade > 150 || execGrade > 150) {
    throw Form::GradeTooLowException();
  }
  return;
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _requireGrade(src._requireGrade), _execGrade(src._execGrade) {
  return;
}

Form &Form::operator=(Form const &src) {
  if (this != &src) {
    this->_signed = src._signed;
  }
  return *this;
}

Form::~Form(void) {
  return;
}

std::string Form::getName(void) const {
  return this->_name;
}

bool Form::getSigned(void) const {
  return this->_signed;
}

int Form::getRequireGrade(void) const {
  return this->_requireGrade;
}

int Form::getExecGrade(void) const {
  return this->_execGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_requireGrade) {
    throw Form::GradeTooLowException();
  }
  this->_signed = true;
  return;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &src) {
  out << "Form " << src.getName() << " is ";
  if (src.getSigned()) {
    out << "signed";
  } else {
    out << "not signed";
  }
  out << " and requires grade " << src.getRequireGrade() << " to be signed and grade " << src.getExecGrade() << " to be executed" << std::endl;
  return out;
}