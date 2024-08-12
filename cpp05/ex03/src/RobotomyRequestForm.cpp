#include "header/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default") {
  return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target) {
  return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
  if (this != &src) {
    this->_signed = src._signed;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
  return;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getExecGrade()) {
    throw AForm::GradeTooLowException();
  }
  if (!this->getSigned()) {
    throw AForm::FormNotSignedException();
  }
  std::srand(std::time(0));
  if (std::rand() % 2) {
    std::cout << this->_target << " has been robotomized successfully" << std::endl;
  } else {
    throw RobotomyRequestForm::RobotomizeException();
  }
}

const char *RobotomyRequestForm::RobotomizeException::what() const throw() {
  return "Robotomize failed";
}