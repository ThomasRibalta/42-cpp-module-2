#include "header/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        b.incrementGrade();
        Bureaucrat b2("Bureaucrat2", 151);       
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
        
