// UniqueStudio Game Task3:QuickSort
// Created By 78ij in 2017.11

#include<ctime>
#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::rand;
using std::srand;
using std::time;

template<class T>
void swap(T *a,T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
template<class T>
void QuickSort(T *head,int size){
if(size <= 0) return;
//perform the partition
    srand((unsigned)time(0));
    int randnum = rand() % size;
    swap<T>(head + randnum,head + size - 1);
    int first = -1;
    int last = size - 1;
    T pivot = head[last];
    for(int j = 0;j < last;j++){
        if(*(head + j) <= pivot){
            first++;
            swap<T>(head + first,head + j);
        }
    }
    swap<T>(head + first + 1,head + size - 1);
//recursive
    QuickSort(head,first + 1);
    QuickSort(head + first + 2, size - first - 2);
;}

int main(){
    int a[1000000] = {0};
    for(int i = 0; i < 1000000;i++){
        cin >> a[i];
    }
    QuickSort<int>(a,1000000);
    for(int i = 0; i < 1000000;i++){
        cout << a[i] << endl;
    }
    return 0;
}
