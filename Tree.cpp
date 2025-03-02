#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    
   public:
     int data;
     node* left;
     node* right;
    
      node(int val){
        data=val;
        left=right=nullptr;
      }

//Traversals

  void printTreeInPreorder(node* root){
    //node left right
   
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
   
    printTreeInPreorder(root->left);
    printTreeInPreorder(root->right);
  }
 void PostOrder(node* root){
   //left right node
   
    if(root==nullptr){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
  }

 void Inorder(node* root){
    //left node right
   
    if(root==nullptr){
        return;
    }
   
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
  }
};

//Sum of left andd right nodes

int sumOfLeft(node *root){
    if(root== nullptr) return 0;
    
    int sumLeft=0;
    if(root->left!=nullptr){
        sumLeft+=root->left->data;
    }
    //ecountering left node is null or not in left subtree using recursion
    sumLeft+=sumOfLeft(root->left);
     //ecountering left node is null or not in right subtree using recursion
    sumLeft+=sumOfLeft(root->right);
    
    return sumLeft;
}

int sumOfRight(node* root){
    if(root == nullptr){
        return 0;
    }
    int sumRight=0;
    if(root->right != nullptr){
        sumRight+=root->right->data;
    }

    sumRight+=sumOfRight(root->left);
    sumRight+=sumOfRight(root->right);

    return sumRight;
}

int main() {
    // Creation of tree

    node* root=new node(1); //Root is a pointer to a node 
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);

    cout<<"-----Preorder Traversal-----"<<endl;
    root->printTreeInPreorder(root);
    cout<<endl;
    
    cout<<"Sum of LeftNodes:"<<endl;
    int sumL=sumOfLeft(root);
    cout<<sumL<<endl;

    cout<<"Sum Of RightNodes:"<<endl;
    int sumR=sumOfRight(root);
    cout<<sumR<<endl;

    return 0;
}
