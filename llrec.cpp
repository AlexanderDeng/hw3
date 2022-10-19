#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if (head->next == nullptr) //empty list 
  {
    smaller->next = nullptr; //return nullptr for both lists 
    larger->next = nullptr; 
    return; 
  }
  else if (head->val > pivot) //if curr val is larger than pivot 
  {
    larger->val = head->val; //set the val of curr head to curr larger 
    return llpivot(head->next, smaller, larger->next, pivot); //recursive call with next elements 
  }
  else if (head->val <= pivot)
  {
    smaller->val = head->val; 
    return llpivot(head->next, smaller->next, larger, pivot); 
  }
}