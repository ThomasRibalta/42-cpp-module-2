#include "header/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
  return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target) {
  return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
  if (this != &src) {
    this->_signed = src._signed;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  return;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getExecGrade()) {
    throw AForm::GradeTooLowException();
  }
  if (!this->getSigned()) {
    throw AForm::FormNotSignedException();
  }
  std::ofstream file((_target + std::string("_shrubbery")).c_str());
  if (!file) {
    throw ShrubberyCreationForm::WriteFileException();
  }
  file << "      /\\      " << std::endl;
  file << "     /\\*\\     " << std::endl;
  file << "    /\\O\\*\\    " << std::endl;
  file << "   /*/\\/\\/\\   " << std::endl;
  file << "  /\\O\\/\\*\\/\\  " << std::endl;
  file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
  file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "    __||__    " << std::endl;
  file << "   |      |   " << std::endl;
  file << "   |      |   " << std::endl;
  file << "   |      |   " << std::endl;
  file << "^^^^^^^^^^^^^^" << std::endl;
  file.close();
  return;
}

const char *ShrubberyCreationForm::WriteFileException::what() const throw()
{
  return "Cannot write to file";
}