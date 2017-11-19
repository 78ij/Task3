// UniqueStudio Game Task3:Minheap
// Created By 78ij in 2017.11

#include"minheap.hpp"

int main(){
    int a[8] = {9,3,7,6,5,1,10,2};
    MinHeap<int> heap(a,8);
    heap.Traverse(0);
    cout << "\n";
    heap.Delete();
    heap.Traverse(0);
    cout << "\n";
    heap.Add(100);
    heap.Traverse(0);
    cout << "\n";
    heap.IncreaseKey(10,0);
    heap.Traverse(0);
    cout << "\n";
}
