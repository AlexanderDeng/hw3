#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
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
private: 
    std::vector<T> stack; 
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
    return stack.empty();  
}

template <typename T>
size_t Stack::size() const; 
{
    return stack.size();  
}

void Stack::push(const T& item)
{
    stack.push_back(item); 
}
void Stack::pop()
{
    if (stack.empty()) 
    {
        throw std::underflow_error("Tried to pop on an empty stack!")
    }
    else 
    {
        stack.pop_back();
    }
}

const T& Stack::top() const
{
    if (stack.empty())
    {
        throw std::underflow_error("Tried to return top on an empty stack!"); 
    }
    else
    {
        return stack.back(); 
    }
}

#endif