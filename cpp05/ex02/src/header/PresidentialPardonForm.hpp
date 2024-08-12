#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private :
    std::string const _target;

  public :
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string const target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
    ~PresidentialPardonForm(void);

    void execute(Bureaucrat const &executor) const;

    class WriteFileException : public std::exception {
      public :
        virtual const char *what() const throw();
    };

};

#endif