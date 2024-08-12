#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  protected :
    std::string const _name;
    bool _signed;
    int const _requireGrade;
    int const _execGrade;
    
    AForm(void);
    AForm(std::string const name, int requireGrade, int execGrade);
    AForm(AForm const &src);
    AForm &operator=(AForm const &src);
    ~AForm(void);

  public :
    std::string getName(void) const;
    bool getSigned(void) const;
    int getRequireGrade(void) const;
    int getExecGrade(void) const;
    void beSigned(Bureaucrat &bureaucrat);

    virtual void execute(Bureaucrat const &executor) const = 0;
    
    class GradeTooHighException : public std::exception {
      public :
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public :
        virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
      public :
        virtual const char *what() const throw();
    };

};

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif 