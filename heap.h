#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */


  size_t size() const; //just returns array size

  void heapifyUp(unsigned int i); //trickle up for push 

  void heapifyDown(unsigned int i); //trickle down for pop 

  void swap(T& a, T& b); //needed for heapify 

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> heap; //actual vector in which heap is stored 

  PComparator comp; //comparator object 

  unsigned int m_ary; //max number of children (global)
  
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) //takes in m which is max number of children and the comparator and sets them for global use 
{
  m_ary = m; 
  comp = c; 
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
  //No dynamic allocation so this shit is blank... right? 
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heap.size(); 
}

template <typename T, typename PComparator> 
void Heap<T,PComparator>::swap(T& a, T& b)
{
  T temp = b; //temp, then basic swap by reference? 
  b = a;
  a = temp; 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(unsigned int i) //fix 
{
  int current = i; 
  while((current * m_ary) + 1 < heap.size()) //while children can exist
  {
    int bestChild = (current * m_ary) + 1; //default start bestChild is leftmost child
    for (unsigned int k = 2; k <= m_ary && k <= heap.size(); ++k) //iterates through all possible children starting at 2 
    {
      if ((current * m_ary) + k >= heap.size()) //if clause to prevent seg fault from going off the range of children
      {
        break; 
      }
      else if (comp(heap[(current * m_ary) + k], heap[bestChild])) //compares children to find the one that is "best" in terms of comparison functor 
      {
        bestChild = (current * m_ary) + k; //at the end of the for loop bestChild should be "the best child"
      }
    }
    if (comp(heap[bestChild], heap[current])) //compares current to best child
    {
      swap(heap[bestChild], heap[current]);
      current = bestChild; //sets current to the best child to continue trickling down
    }
    else 
    {
      break; 
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(unsigned int i)
{
  if (i <= 0)
  {
    return; //no need to heapify and prevent seg fault 
  }
  unsigned int current = i; 
  unsigned int parent = (i - 1) / m_ary;
  if (comp(heap[current], heap[parent])) //check if swap
  {
    swap(heap[current], heap[parent]); 
    heapifyUp(parent); 
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) 
{
  if (empty())
  {
    heap.push_back(item); //if empty no need to call heapifyUp 
  }
  else 
  {
    heap.push_back(item); //pushes in the vector, then calls heapifyUp for "trickle up" effect
    heapifyUp(heap.size() - 1); 
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const 
{
  if (heap.size()) //if more than 0 elements its true 
  {
    return false; 
  }
  return true; 
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const 
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Tried to return top on an empty heap!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else
  {
    return heap[0]; //top just returns the root node, which is always at index 0 
  }
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Tried to pop an empty heap!");
    return; 
  }
  else
  {
    heap[0] = heap[size() - 1]; 
    heap.pop_back(); 
    heapifyDown(0); //calls heapifyDown on the root node (which is now the worst) and trickles down. 
  }
}


#endif

