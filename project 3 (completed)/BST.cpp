#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include "BST.h"

using namespace std;


BST::BST(){
    root = NULL;
}

//add node function

BST::node* BST::CreateLeaf(char key){
    node* n = new node;
    n->key = key;
    n->count = 1;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}

void BST::AddLeaf(char key){
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(char key, node* Ptr){
    if(root == NULL){
        root = CreateLeaf(key);
    }
    else if(key < Ptr->key){
        if(Ptr->left != NULL){
            AddLeafPrivate(key, Ptr->left);
        }
        else{
            Ptr->left = CreateLeaf(key);
        }
    }
    else if(key > Ptr->key){
        if(Ptr->right != NULL){
            AddLeafPrivate(key, Ptr->right);
        }
        else{
            Ptr->right = CreateLeaf(key);
        }
    }
    else if(key == Ptr->key){
        Ptr->count ++;
    }
    else{
    }
}

//print in order
void BST::PrintInOrder(){
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr){
    if(root != NULL){
        if(Ptr->left != NULL){
            PrintInOrderPrivate(Ptr->left);
        }
        
        while(Ptr->count !=0){
            cout<<Ptr->key;
            Ptr->count--;
        }
        
        if(Ptr->right != NULL){
            PrintInOrderPrivate(Ptr->right);
        }
        
    }
    else{
        cout<<"The tree is empty."<<endl;
    }
    
}


//to return node
BST::node* BST::ReturnNode(char key){
    return ReturnNodePrivate(key, root);
}


//This function pulls out a node in accordance with key.

BST::node* BST::ReturnNodePrivate(char key, node* Ptr){
    if(Ptr != NULL){
        if(Ptr->key == key){
            return Ptr;
        }
        else{
            if(key < Ptr->key){
                return ReturnNodePrivate(key, Ptr->left);
            }
            else{
                return ReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    else{
        return NULL;
    }
}

//to find the smallest value in the tree
char BST::FindSmallest(){
    return FindSmallestPrivate(root);
}

char BST::FindSmallestPrivate(node* Ptr){
    if(root == NULL){
        return '@';
    }
    else{
        if(Ptr->left != NULL){
            return FindSmallestPrivate(Ptr->left);
        }
        else{
            return Ptr->key;
        }
    }
}


//to remove nodes
void BST::RemoveNode(char key){
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(char key, node* parent){
    if(root != NULL){
        if(root->key ==  key){
            RemoveRootMatch();
        }
        else{
            if(key < parent->key && parent->left != NULL){
                parent->left->key == key ?
                RemoveMatch(parent, parent->left, true):
                RemoveNodePrivate(key, parent->left);
            }
            else if(key > parent->key && parent->right != NULL){
                parent->right->key == key ?
                RemoveMatch(parent, parent->right, false):
                RemoveNodePrivate(key, parent->right);
            }
            else{
                cout<<"The key '"<<key<<"' is not found in the tree."<<endl;
            }
            
        }
    }
}


void BST::RemoveRootMatch(){
    if(root != NULL){
        node* delPtr = root;
        char smallestInRightSubtree;
        
        //case 0 - 0children
        if(root->left == NULL && root->right == NULL){
            if(root->count == 1){
                root = NULL;
                delete delPtr;
            }
            else if(root->count == 0){
            }
            else{
                root->count--;
            }
        }
        
        //case 1 - 1 child
        else if(root->left == NULL && root->right != NULL){
            if(root->count == 1){
                root = root->right;
                delPtr->right = NULL; //to disconect the old tree
                delete delPtr;
            }
            else if(root->count == 0){
            }
            else{
                root->count--;
            }
        }
        else if(root->left != NULL && root->right == NULL){
            if(root->count == 1){
                root = root->left;
                delPtr->left = NULL; //to disconect the old tree
                delete delPtr;
            }
            else if(root->count == 0){
            }
            else{
                root->count--;
            }
        }
        
        //case 2 - 2 children
        else{
            if(root->count == 1){
                smallestInRightSubtree = FindSmallestPrivate(root->right);
                RemoveNodePrivate(smallestInRightSubtree, root);
                root->key = smallestInRightSubtree;
            }
            else if(root->count == 0){
            }
            else{
                root->count--;
            }
        }
        
    }
    else{
        cout<<"Can not remove root. The tree is empty.\n";
    }
}

void BST::RemoveMatch(node* parent, node*match, bool left){
    if(root !=NULL){
        node* delPtr;
        char matchKey = match->key;
        char smallestInRightSubtree;
        
        //case 0 - 0 children
        if(match->left == NULL && match->right == NULL){
            if(match->count == 1){
                delPtr = match;   //to disconnect the old tree
                left ==true ? parent->left = NULL: parent->right = NULL;   //to disconnect the old tree
                delete delPtr;
            }
            else if(root->count == 0){
            }
            else{
                match->count--;
            }
        }
        
        //case 1 - 1 child
        else if(match->left == NULL && match->right != NULL){
            if(match->count == 1){
                left == true ? parent->left = match->right : parent->right = match->right;
                match->right = NULL;
                delPtr = match;
                delete delPtr;
            }
            else if(root->count == 0){
            }
            else{
                match->count--;
            }
        }
        
        else if(match->left != NULL && match->right == NULL){
            if(match->count == 1){
                left == true ? parent->left = match->left : parent->right = match->left;
                match->left = NULL;
                delPtr = match;
                delete delPtr;
            }
            else if(root->count == 0){
            }
            else{
                match->count--;
            }
        }
        
        //case 2 - 2 children
        else{
            if(match->count == 1){
                smallestInRightSubtree = FindSmallestPrivate(match->right);
                RemoveNodePrivate(smallestInRightSubtree, match);
                match->key = smallestInRightSubtree; //overloading
            }
            else if(root->count == 0){
            }
            else{
                match->count--;
            }
        }
    }
    else{
        cout<<"Can not remove match because the tree is empty.";
    }
}


//for the first input and to convert the string into a binary search tree

string BST::InputToInsert(){
    return InputToInsertPrivate();
}

string BST::InputToInsertPrivate(){
    cout<<"Enter a line of input to insert : "<<endl;
    cin>>input1;
    
    return input1;
}

void BST::convert(string s){
    
    long int n = s.length();
    
    char array[n+1];
    
    strcpy(array, s.c_str());
    
    for(int i =0; i<n; i++){
        AddLeaf(array[i]);
    }
}


//for the input to delete
string BST::InputToDelete(){
    return InputToDeletePrivate();
}

string BST::InputToDeletePrivate(){
    cout<<"Enter a line of input to remove : \n";
    cin>>input2;
    
    return input2;
}



//to delete overloaded alphabet

void BST::overloadedDelete(){
    overloadedDeletePrivate(input2 ,root);
}

void BST::overloadedDeletePrivate(string key, node* Ptr){
    
    convert(input1);
    
    for(int i = 0; i<key.length(); i++){   //remove InputToDelete from the tree
        if(ReturnNode(key.at(i)) != NULL){
            RemoveNode(key.at(i));
        }
    }
}





