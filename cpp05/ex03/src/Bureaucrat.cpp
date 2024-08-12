#include "header/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << name << " created" << std::endl;
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
    std::cout << "Bureaucrat " << src._name << " copied" << std::endl;
    *this = src;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    std::cout << "Bureaucrat " << src._name << " assigned" << std::endl;
    _grade = src._grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &form)
{
    if (_grade > form.getRequireGrade())
    {
        std::cout << _name << " cannot sign " << form.getName() << " because grade is too low" << std::endl;
        return;
    }
    form.beSigned(*this);
    std::cout << _name << " signs " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (_grade > form.getExecGrade())
    {
        std::cout << _name << " cannot execute " << form.getName() << " because grade is too low" << std::endl;
        return;
    }
    form.execute(*this);
    std::cout << _name << " executes " << form.getName() << std::endl;
}