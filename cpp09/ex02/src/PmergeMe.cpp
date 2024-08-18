#include "header/PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

int is_sorted(const std::vector<int>& v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            return 0;
    }
    return 1;
}

int only_digit(const char* str)
{
    while (*str)
    {
        if (!std::isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

int PmergeMe::parse_args(char** av)
{
    int i = 0;
    while (av[i])
    {
        if (!only_digit(av[i]))
        {
            std::cout << "Error: " << av[i] << " isn't a number." << std::endl;
            return 1;
        }
        long num = std::atol(av[i]);
        if (num < 0 || num > INT_MAX)
        {
            std::cout << "Error: " << av[i] << " number is too long." << std::endl;
            return 1;
        }
        
        this->args.push_back(static_cast<int>(num));
        i++;
    }
    return 0;
}

int PmergeMe::merge_vector()
{
    std::clock_t start = std::clock();
    double duration;

    if (is_sorted(this->args))
    {
        std::cout << "Already sorted" << std::endl;
        this->vector_sorted = this->args;
        return 1;
    }
    if (this->args.size() == 1)
    {
        this->vector_sorted.push_back(this->args[0]);
        std::cout << "Only one number" << std::endl;
        return 1;
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < this->args.size(); i += 2)
    {
        if (i + 1 < this->args.size())
        {
            if (this->args[i] > this->args[i + 1])
                pairs.push_back(std::make_pair(this->args[i + 1], this->args[i]));
            else
                pairs.push_back(std::make_pair(this->args[i], this->args[i + 1]));
        } else
            pairs.push_back(std::make_pair(-1, this->args[i]));
    }

    std::vector<int> mins;
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
        mins.push_back(it->first);
    std::sort(mins.begin(), mins.end());

    std::vector<int> sorted = mins;
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), it->second);
        sorted.insert(pos, it->second);
    }

    this->vector_sorted = sorted;

    duration = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * 1000;
    this->vector_duration = duration;
    return 0;
}


int PmergeMe::merge_list()
{
    std::clock_t start = std::clock();
    double duration;

    if (is_sorted(this->args))
    {
        std::cout << "Already sorted" << std::endl;
        this->list_sorted.assign(this->args.begin(), this->args.end());
        return 1;
    }
    if (this->args.size() == 1)
    {
        this->list_sorted.push_back(this->args[0]);
        std::cout << "Only one number" << std::endl;
        this->list_duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
        return 1;
    }

    std::list<std::pair<int, int> > pairs;
    for (size_t i = 0; i < this->args.size(); i += 2)
    {
        if (i + 1 < this->args.size())
        {
            if (this->args[i] > this->args[i + 1])
                pairs.push_back(std::make_pair(this->args[i + 1], this->args[i]));
            else
                pairs.push_back(std::make_pair(this->args[i], this->args[i + 1]));
        } else
            pairs.push_back(std::make_pair(-1, this->args[i]));
    }

    std::list<int> mins;
    for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
        mins.push_back(it->first);

    mins.sort();

    std::list<int> sorted_list = mins;
    for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        std::list<int>::iterator pos = sorted_list.begin();
        for (; pos != sorted_list.end(); ++pos)
        {
            if (*pos >= it->second)
                break;
        }
        sorted_list.insert(pos, it->second);
    }

    this->list_sorted = sorted_list;

    duration = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * 1000;
    this->list_duration = duration;
    return 0;
}


void PmergeMe::display()
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = this->args.begin(); it != this->args.end(); ++it)
    {
        if (*it != -1)
            std::cout << *it << " ";
    }

    std::cout << "\nAfter (vector): ";
    for (std::vector<int>::const_iterator it = this->vector_sorted.begin(); it != this->vector_sorted.end(); ++it)
    {
        if (*it != -1)
            std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << this->args.size() << " elements with std::list: " << this->list_duration << "us" << std::endl;
    std::cout << "Time to process a range of " << this->args.size() << " elements with std::vector: " << this->vector_duration << "us" << std::endl;
}