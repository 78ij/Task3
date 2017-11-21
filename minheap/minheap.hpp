// UniqueStudio Game Task3:Minheap
// Created By 78ij in 2017.11

#include<cstddef>
#include<iostream>
#include<stdexcept>

using std::cout;
using std::endl;
using std::size_t;

#define MAXSIZE            20
#define MINHEAPLEFT(i)     (2*i + 1)
#define MINHEAPRIGHT(i)    (2*i + 2 )
#define MINHEAPPARENT(i)   ((int)((i-1)/2))

template<class T>
class MinHeap{
private:
    T *data;
    int maxsize;
    int currentsize;
    int currentposition;
public:
    MinHeap() = default;
    MinHeap(T *value,size_t size);
    void Add(T newelement);
    void Maintaindown(T *head, int subscript);
    void Maintainup(T *head,int subscript);
    void Traverse(int subscript);
    void Delete();
    void IncreaseKey(int delta,int subscript);
    void DecreaseKey(int delta,int subscript);
};

template<class T>
MinHeap<T>::MinHeap(T *value,size_t size): currentsize(size),maxsize(MAXSIZE) {
    data = new T[MAXSIZE];
    if(size > MAXSIZE)
        throw std::runtime_error("maximum size exceeded.");
    for(int i = 0;i < size;i++){
        this->data[i] = value[i];
    }
    int leafborder = ((size - 1) / 2);
    for(;leafborder >= 0 ;leafborder--){
        Maintaindown(this->data,leafborder);
    }
}

template<class T>
void MinHeap<T>::Maintaindown(T *head,int subscript){
    int left = MINHEAPLEFT(subscript);
    int right = MINHEAPRIGHT(subscript);
    int minimum;
    if(left <= (this->currentsize - 1) &&  head[left] <  head[subscript])
        minimum = left;
    else minimum = subscript;
    if(right <= (this->currentsize - 1) && head[right] < data[minimum])
        minimum = right;
    if(minimum != subscript){
        T temp =  head[minimum];
        head[minimum] =  head[subscript];
        head[subscript] = temp;
        Maintaindown(head,minimum);
    }
}
template<class T>
void MinHeap<T>::Maintainup(T *head,int subscript){
    int parent = MINHEAPPARENT(subscript);
    if(parent >= 0 && head[parent] > head[subscript]){
        T temp =  head[parent];
        head[parent] =  head[subscript];
        head[subscript] = temp;
        Maintainup(head,parent);
    }
}

template<class T>
void MinHeap<T>::Traverse(int subscript){
     if(subscript > this->currentsize - 1) return;
     cout << this->data[subscript] << " ";
     Traverse(MINHEAPLEFT(subscript));
     Traverse(MINHEAPRIGHT(subscript));
}

template<class T>
void MinHeap<T>::Add(T newelement){
        this->currentsize++;
        if(currentsize > MAXSIZE)
            throw std::runtime_error("maximum size exceeded.");
        this->data[currentsize - 1] = newelement;
        Maintainup(this->data,currentsize - 1);
    }

template<class T>
void MinHeap<T>::Delete(){
     data[0] = data[currentsize - 1];
     this->currentsize--;
     Maintaindown(this->data,0);
}
template<class T>
void MinHeap<T>::IncreaseKey(int delta,int subscript){
    this->data[subscript] += delta;
    Maintaindown(this->data,subscript);
}

template<class T>
void MinHeap<T>::DecreaseKey(int delta,int subscript){
    this->data[subscript] -= delta;
    Maintainup(this->data,subscript);
}
