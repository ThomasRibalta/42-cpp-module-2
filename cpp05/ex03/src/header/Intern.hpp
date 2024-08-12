#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
  public:
    Intern();
    Intern(Intern const &src);
    ~Intern();

    Intern &operator=(Intern const &src);

    AForm *makeForm(std::string const &formName, std::string const &target);

    class UnknownFormException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif