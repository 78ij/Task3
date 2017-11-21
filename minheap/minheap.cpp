// UniqueStudio Game Task3:Minheap
// Created By 78ij in 2017.11

#include"minheap.hpp"

int main(){
    int a[20] = {9,3,7,6,5,1,10,2,11,12,13,14,15,16,17,18,19,20,21};
    try{
        MinHeap<int> heap(a,20);
        heap.Traverse(0);
        cout << "\n";
        //heap.Delete();
        //heap.Traverse(0);
        //cout << "\n";
        heap.Add(100);
        heap.Traverse(0);
        cout << "\n";
        heap.DecreaseKey(10,0);
        heap.Traverse(0);
        cout << "\n";
    }
    catch(std::runtime_error &e){
        std::cout<<"Runtime Exception:" << e.what() << "\n";
    }
    return 0;
}
