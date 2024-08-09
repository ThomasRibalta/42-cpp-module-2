#include "header/Bureaucrat.hpp"
#include "header/Form.hpp"

int main()
{
    std::cout << "Test 1: Create a Bureaucrat with a grade of 150" << std::endl;
    try
    {
        Bureaucrat b2("Bureaucrat2", 151);       
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Test 2: Create a Bureaucrat with a grade of 0" << std::endl;
    try
    {
        Bureaucrat b1("Bureaucrat1", 0);       
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Test 3: Create a Bureaucrat with a grade of 1" << std::endl;
    try
    {
        Bureaucrat b3("Bureaucrat3", 1);       
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Test 4: Create a Bureaucrat with a grade of 150" << std::endl;
    try
    {
        Bureaucrat b4("Bureaucrat4", 150);       
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Test 5: Create a Bureaucrat and form" << std::endl;
    try
    {
        Bureaucrat b5("Bureaucrat5", 150);       
        Form f1("Form1", 150, 150);
        b5.signForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Test 6: Create a Bureaucrat grade 10 and form grade 9" << std::endl;
    try
    {
        Bureaucrat b6("Bureaucrat6", 10);       
        Form f2("Form2", 9, 9);
        b6.signForm(f2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
        
