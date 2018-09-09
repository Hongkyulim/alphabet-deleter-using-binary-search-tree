
#ifndef Header_h
#define Header_h
using namespace std;



class BST{
private:
    struct node{
        char key;
        int count;
        node* left;
        node* right;
        
    };
    
    node* root;
    
    //add node function
    void AddLeafPrivate(char key, node* Ptr);
    node* CreateLeaf(char key);
    
    
    //print in order
    void PrintInOrderPrivate(node* Ptr);
    
    
    //to return node
    node* ReturnNodePrivate(char key, node* Ptr);
    
    //to find the smallest value in the tree
    char FindSmallestPrivate(node* Ptr);
    
    //to remove nodes
    void RemoveNodePrivate(char key, node* parent);
    void RemoveRootMatch();
    void RemoveMatch(node* parent, node*match, bool left); //parent- the node we want to remove. Match will mark the node that will be deleted. bool left is just to check up the node is left or right.
    
    //for the input to insert
    string input1;
    string InputToInsertPrivate();
    
    //for the input to delete
    string input2;
    string InputToDeletePrivate();
    
    //creating a list for line2
    std::list<int> line2;
    
    void overloadedDeletePrivate(string key, node* Ptr);
public:
    
    BST(); //constructor
    
    //add node function
    void AddLeaf(char key);
    
    
    //print in order
    void PrintInOrder();
    
    //to return node
    node* ReturnNode(char key);
    
    //to print children
    char ReturnRootKey();
    void PrintChildren(char key);
    
    //to find the smallest value in the tree
    char FindSmallest();
    
    //to remove nodes
    void RemoveNode(char key);
    
    //for the first input
    string InputToInsert();
    
    //for the input to delete
    std::string InputToDelete();
    
    //to delete overloaded alphabet
    void overloadedDelete();
    
    //creating a list for line2
    void createList(string line);
    
    //converting
    void convert(string s);
    
    string returnInput1(){
        return input1;
    }
};



#endif /* Header_h */




















