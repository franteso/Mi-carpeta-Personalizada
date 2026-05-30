#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
   Node<T>* p;
   Node<T>* q;
   int size;
};

template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   q.p = NULL;
   q.q = NULL;
   q.size=0;
   return q;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T e)
{
   q.size++;
   return &(enqueue<T>(q.p,q.q,e)->info);
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   q.size--;
   return dequeue(q.p,q.q);
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return isEmpty(q.p);
}

template<typename T>
int queueSize(Queue<T> q)
{
   return q.size;
}

#endif