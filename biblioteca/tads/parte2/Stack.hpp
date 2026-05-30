#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
   Node<T>* p;
   int size;
};

template<typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.p = NULL;
   st.size=0;
   return st;
}

template<typename T>
T* stackPush(Stack<T>& st,T e)
{
   st.size++;
   return &(push(st.p,e)->info);
}

template<typename T>
T stackPop(Stack<T>& st)
{
   st.size--;
   return pop(st.p);
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty(st.p);
}

template<typename T>
int stackSize(Stack<T> st)
{
   return st.size;
}

#endif