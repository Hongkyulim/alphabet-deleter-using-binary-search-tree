#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include "BST.h"

using namespace std;

int main(){
    
    BST myTree;
    string s;
    
    myTree.InputToInsert();
    s = myTree.returnInput1();
    myTree.convert(s);
    cout<<"Inorder traversal: ";
    myTree.PrintInOrder();
    cout<<endl;
    
    myTree.InputToDelete();
    
    
    
    
    
    cout<<"Inorder traversal: ";
    myTree.overloadedDelete();
    myTree.PrintInOrder();
    cout<<endl;
    
    
    
    
    return 0;
}
