#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  private :
    std::string const _name;
    bool _signed;
    int const _requireGrade;
    int const _execGrade;
  public :
    Form(void);
    Form(std::string const name, int requireGrade, int execGrade);
    Form(Form const &src);
    Form &operator=(Form const &src);
    ~Form(void);
    std::string getName(void) const;
    bool getSigned(void) const;
    int getRequireGrade(void) const;
    int getExecGrade(void) const;
    void beSigned(Bureaucrat &bureaucrat);
    class GradeTooHighException : public std::exception {
      public :
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public :
        virtual const char *what() const throw();
    };

};

std::ostream &operator<<(std::ostream &out, Form const &src);

#endif 