#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
  private :
    std::string const _target;

  public :
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string const target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
    ~ShrubberyCreationForm(void);

    void execute(Bureaucrat const &executor) const;

    class WriteFileException : public std::exception {
      public :
        virtual const char *what() const throw();
    };

};

#endif