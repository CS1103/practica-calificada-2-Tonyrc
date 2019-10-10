//
// Created by rudri on 10/10/2019.
//

#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H

#include<iostream>

template<class T>
struct Nodo{
    T valor;
    Nodo<T>* next;
    Nodo(T valor):valor{valor},next{nullptr}{};
};

template<class T>
class LinkedList {
private:
    Nodo<T>* head;
    Nodo<T>* tail;
    T tam;
public:
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void push_front(T item);
    void push_back(T item);
    T pop_front();
    T pop_back();
    T front();
    T back();
    T size();
    void print();
    T insert(T item);
    T get_max();
    void clear();
    ostream& operator<<(ostream& out, const LinkedList<T> array);
    istream& operator>>(istream& in, const LinkedList<T> array);
};

template<class T>
void LinkedList<T>::insert(T item){
    this->push_back(item);
}

template<class T>
LinkedList<T>::LinkedList():head{nullptr},tail{nullptr},tam{0}{}

template<class T>
void LinkedList<T>::push_front(T item){
    Nodo<T>* temp = new Nodo<T>(item);
    if(head == nullptr){
        head = tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
    tam++;
}

template<class T>
void LinkedList<T>::push_back(T item){
    Nodo<T>* temp = new Nodo<T>(item);
    if(head == nullptr){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
    tam++;
}

template<class T>
bool LinkedList<T>::isEmpty(){
    return (head==nullptr && tail==nullptr);
}

template<class T>
T LinkedList<T>::pop_front(){
    T element = head->valor;
    head = head->next;
    tam--;
    return element;
}

template<class T>
T LinkedList<T>::pop_back(){
    T element = tail->valor;
    Nodo<T>* actual = head;
    while(actual->next != tail){
        actual = actual->next;
    }
    tail = actual;
    tail->next = nullptr;
    tam--;
    return element;
}

template<class T>
T LinkedList<T>::front(){
    return head->valor;
}

template<class T>
T LinkedList<T>::back(){
    return tail->valor;
}

template<class T>
T LinkedList<T>::size(){
    return tam;
}

template<class T>
void LinkedList<T>::print(){
    Nodo<T>* actual = head;
    do{
        std::cout<<actual->valor<<"->";
        actual = actual->next;
    }while(actual != nullptr);
    std::cout<<"Null\n";
}

template<class T>
void LinkedList<T>::clear(){
    if(head != nullptr){
        Nodo<T>* actual = head;
        while(actual != nullptr){
            Nodo<T>* temp = actual;
            actual = actual->next;
            delete temp;
        }
    }
}

template<class T>
T LinkedList<T>::get_max() {
    T max = head->valor;
    auto it = head;
    while(it != nullptr){
        if(it->valor > max){
            max = it->valor;
        }
        it = it->next;
    }
    return max;
}

template<typename T>
ostream& operator<<(ostream& out, const LinkedList<T> array ){
    this->print();
}

template<typename T>
istream& LinkedList<T>::operator>>(istream& in, const LinkedList<T> array){
    this->insert(in);
}

template<class T>
LinkedList<T>::~LinkedList(){
    this->clear();
}



#endif //CS1103_PC2_201902_HEAP_H

