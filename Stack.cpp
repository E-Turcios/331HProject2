#include "Stack.h"

/***************************************************************/
/* Programmer: Anna Salvati                                    */        
/*                               */        
/* Purpose: Array  Stack class  -   implementation file        */ 
/* Input: none                                                 */
/* Output: none                                                */
/***************************************************************/

template <class T>
Stack<T> :: Stack ()
{
   top = NULL;
}

template <class T>
Stack<T> :: ~Stack()
{
   destroy();
}

template <class T>
Stack<T> :: Stack ( const Stack<T> & other )
{
   copy(other);
}

template <class T>
const Stack<T> & Stack<T> :: operator= ( const Stack<T> & other )
{
   if ( this != &other )
   {
      destroy();
      copy (other);
   }
   return *this;
}

template <class T>
bool Stack<T> :: isEmpty ()
{
   return top == NULL; 
}

template <class T>
void Stack<T> :: push ( T item )
{
   node<T> *temp;
   
   temp = new node<T>;		
   temp->info = item;		
   temp->next = top;		
   top = temp;		
}

template <class T>
void Stack<T> :: pop ()
{
   if ( !isEmpty())
      {
        node<T> *temp;
        temp = top;	
        top = top->next;	
        delete temp;	
      }
}

template <class T>
int Stack<T> :: getLength()
{
   node<T> *p = top;
   int count = 0;

   while (p != NULL)
   {
      count++;
      p = p->next;
   }
   
   return count;
}

template <class T>
void Stack<T> :: Top (T &item)
{
   if (!isEmpty ())
      item = top->info;
}

template <class T>
void Stack<T> :: copy (const Stack<T> & other)
{
    if ( other.top == NULL )
       top = NULL;
    else
    {
       top = new node<T>;
       top->info = other.top->info;

       node<T> *p = other.top->next;
       node<T> *r = top;

       while ( p != NULL )
       {
         r->next = new node<T>;
         r->next->info = p->info;
         p = p->next;
         r = r->next;
       }

       r->next = NULL;
      
    }
}

template <class T>
void Stack<T> :: destroy()
{
   node<T> *p;

    while ( top != NULL )
    {
       p = top;
       top = top->next;
       delete p;
    }
}