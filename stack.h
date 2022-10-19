#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T> 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack::Stack()
{

}

template <typename T> 
Stack::~Stack()
{
    //delete vector or something idk 
}

template <typename T>
bool Stack::empty() const
{
    return std::vector<T>::empty(); 
}

template <typename T>
size_t Stack::size() const; 
{
    return std::vector<T>::size(); 
}

void Stack::push(const T& item)
{
    std::vector<T>::push_back(item); 
}
void Stack::pop()
{
    if (std::vector<T>::empty()) 
    {
        throw std::underflow_error("Tried to pop on an empty stack!")
    }
    else 
    {
        std::vector<T>::pop_back();
    }
}

const T& Stack::top() const
{
    if (std::vector<T>::empty())
    {
        throw std::underflow_error("Tried to return top on an empty stack!"); 
        return nullptr: 
    }
    else
    {
        return std::vector<T>[std::vector<T>::size() - 1]
    }
}

#endif