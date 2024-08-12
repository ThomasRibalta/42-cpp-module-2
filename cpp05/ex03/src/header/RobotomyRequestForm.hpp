#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  private :
    std::string const _target;

  public :
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string const target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
    ~RobotomyRequestForm(void);

    void execute(Bureaucrat const &executor) const;

    class RobotomizeException : public std::exception {
      public :
        virtual const char *what() const throw();
    };

};

#endif