#ifndef BUERAUCRAT_HPP
#define BUERAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
  private:
      std::string const _name;
      int _grade;

  public:
      Bureaucrat(std::string const name, int grade);
      Bureaucrat(Bureaucrat const &src);
      ~Bureaucrat();

      Bureaucrat &operator=(Bureaucrat const &src);

      std::string getName() const;
      int getGrade() const;

      void incrementGrade();
      void decrementGrade();

      void signForm(class AForm &form);
      void executeForm(class AForm const &form);

      class GradeTooHighException : public std::exception
      {
        public:
            virtual const char *what() const throw();
      };

      class GradeTooLowException : public std::exception
      {
        public:
            virtual const char *what() const throw();
      };

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src);

#endif