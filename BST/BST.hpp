// UniqueStudio Game Task3:Binary Search Tree
// Created By 78ij in 2017.11

#include<cstddef>
#include<iostream>

using std::cout;
using std::endl;
using std::size_t;

template<class T>
class BSTNode{
public:
	BSTNode *leftchild;
	BSTNode *rightchild;
	T data;
	BSTNode() = default;
	BSTNode(T value):data(value) {} 
};


	/*void Add(T newnode);
	void Deletemin();
	void Deletemax();
	void DeleteKey(T key);
	void Traverse;*/

template<class T>
void Add(T newnode,BSTNode<T> *currentnode){
	if(newnode < currentnode->data){
		if(currentnode->leftchild == NULL){
	        currentnode->leftchild = new BSTNode<T>(newnode);
		}
		else{
		    Add(newnode,currentnode->leftchild);
		}
	}
	if(newnode > currentnode->data){
		if(currentnode->rightchild == NULL){
	        currentnode->rightchild = new BSTNode<T>(newnode);
		}
		else{
		    Add(newnode,currentnode->rightchild);
		}
	}	
}

template<class T>
void Traverse(BSTNode<T> *currentnode){
    if(currentnode == NULL) return;
    Traverse(currentnode->leftchild);
    cout << currentnode->data;
    Traverse(currentnode->rightchild);
}
