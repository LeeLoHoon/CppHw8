//
#include <iostream>
#include <string>

using namespace std;

typedef struct node {
string str1;
string str2;
struct node *left_child, *right_child;
} tree_node;

class BST{
  private:
    tree_node* root;
  public: 
    BST(){
      root=NULL;
    };
    string search(tree_node *tree,string key);
    string search(string key);
    tree_node* Add(tree_node *tree,string key, string value);
    void Add(string key, string value){
      root=Add(root,key,value);
    }
};
