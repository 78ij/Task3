// UniqueStudio Game Task3:Binary Search Tree
// Created By 78ij in 2017.11

#include"BST.hpp"

int main(){
    BSTNode<int> *head = new BSTNode<int>(1);
    Add<int>(3,head);
    Add<int>(4,head);
    Add<int>(5,head);
    Add<int>(9,head);
    Add<int>(2,head);
    Add<int>(7,head);
    Add<int>(8,head);
    Traverse<int>(head);
    return 0;
}
