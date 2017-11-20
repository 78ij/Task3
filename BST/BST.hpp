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
	BSTNode *parent;
	T data;
	BSTNode() = default;
	BSTNode(T value):data(value),leftchild(NULL),rightchild(NULL) {} 
};

template<class T>
void Add(T newnode,BSTNode<T> *currentnode){
	if(newnode < currentnode->data){
		if(currentnode->leftchild == NULL){
	        currentnode->leftchild = new BSTNode<T>(newnode);
	        currentnode->leftchild->parent = currentnode;
		}
		else{
		    Add(newnode,currentnode->leftchild);
		}
	}
	if(newnode > currentnode->data){
		if(currentnode->rightchild == NULL){
	        currentnode->rightchild = new BSTNode<T>(newnode);
	        currentnode->rightchild->parent = currentnode;
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

template<class T>
BSTNode<T> *Findmin(BSTNode<T> *currentnode){
    if (currentnode->leftchild == NULL)
        return currentnode;
    else{
        return Findmin(currentnode->leftchild);
    }
}

template<class T>
void TransPlant(BSTNode<T> * tree1,BSTNode<T> *tree2){
    if(tree1->parent == NULL){
        return;
    }
    else if(tree1 == tree1->parent->leftchild){
        tree1->parent->leftchild = tree2;
    }
    else
        tree1->parent->rightchild = tree2;
    if(tree2 != NULL)
        tree2->parent = tree1->parent;
}

template<class T>
void Delete(BSTNode<T> *currentnode){
    if(currentnode->leftchild == NULL){
        TransPlant<T>(currentnode,currentnode->rightchild);
        delete currentnode;
    }
    else if(currentnode->rightchild == NULL){
        TransPlant<T>(currentnode,currentnode->leftchild);
        delete currentnode;
    }
    else{
        BSTNode<T> *temp = Findmin<T>(currentnode->rightchild);
        if(temp->parent != currentnode){
            TransPlant<T>(temp,temp->rightchild);
            temp->rightchild = currentnode->rightchild;
            temp->rightchild->parent = temp;
        }
        TransPlant(currentnode,temp);
        temp->leftchild = currentnode->leftchild;
        temp->leftchild->parent = temp;
    }
}
