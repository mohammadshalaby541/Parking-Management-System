#ifndef Queue_H
#define Queue_H

#include <stdexcept> 
#include <iostream>

using namespace std;

template <class T>

class QueueArr {
    private:
    T* arr; 
    
    int front; 
    int back; 
    int elements; 
    int capacity;
    
    public:
    QueueArr(int); 
    int showSize(); 
    void enqueue(T); 
    void dequeue(); 

    T Front(); 

    bool empty(); 
    bool full(); 

    ~QueueArr(void); 

};

template <class T>
QueueArr<T>::QueueArr(int cap){

    capacity = cap; 
    front = 0;
    back = -1; 
    elements = 0;
    arr = new T[capacity];
}

template <class T>
int QueueArr<T>::showSize(){

    return elements;
    
}

template <class T>
void QueueArr<T>::enqueue(T value){

    if(full()) throw out_of_range("Queue is full");

    if (elements == 0){
        front = 0;
        back = 0; 
    } else {
        back = (back + 1) % capacity; 
    }
    arr[back] = value; 
    elements++; 

}

template <class T>
void QueueArr<T>::dequeue(){

    if(empty()) throw out_of_range("Queue is empty");

    if(elements == 1){
        front = 0;
        back = -1;
        elements = 0;
    }
    else {
        front = (front + 1) % capacity;
        elements--;
    }
}

template <class T>
T QueueArr<T>::Front(){

    if(empty()) throw out_of_range("Queue is empty"); 

    return arr[front]; 

}

template <class T>
bool QueueArr<T>::full(){

    return(elements==capacity); 

}

template <class T>
bool QueueArr<T>::empty(){

    return(elements==0); 

}

template <class T>
QueueArr<T>::~QueueArr(void){

    delete[] arr; 

}

#endif
