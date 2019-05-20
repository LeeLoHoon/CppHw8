#include "BST.h" 
#include <iostream>
#include <string>

using namespace std;

tree_node* BST::search(tree_node *tree,int key){
  if(tree==NULL){
    return NULL;  
  }
  while(tree!=NULL){
    if(tree->num ==key) return NULL;
    else if (key<tree->num)
      if(tree->left_child == NULL) return tree;
      else tree=tree->left_child;
    else                       
      if (tree->right_child == NULL) return tree; 
      else tree = tree->right_child;
  }
  return NULL;
}
tree_node *BST::search(int key){
  return search(root, key);
}


tree_node* BST::Add(tree_node* tree, int key, string value){
  if(tree==NULL){
    tree = new tree_node;
    tree->num = key;
    tree->str = value;
    tree->left_child=NULL;
    tree->right_child=NULL;
  }  
  else if(key==tree->num){
    cout<<key<<" is already in the tree."<<endl;
  } 
  else{
    if(key>tree->num){
      tree->right_child = Add(tree->right_child,key,value);}
    else if(key<tree->num){
      tree->left_child=Add(tree->left_child,key,value);
    }
}
  return tree;
}
tree_node* BST::Delete(tree_node* tree,int key){
  tree_node* temp;
  if(tree->num==key){
    if((tree->left_child==NULL)&&(tree->right_child==NULL)){
      tree=NULL;
      return tree;}
    else if(tree->left_child==NULL){
      temp=tree;
      tree=tree->right_child;
      delete temp;
    }
    else if(tree->right_child==NULL){
      temp=tree;
      tree=tree->left_child;
      delete temp;
    }
    else{
      int a;
      string b;
      temp=findMin(tree->right_child);
      a=temp->num;
      b=temp->str;
      Delete(a);
      tree->num=a;
      tree->str=b;
    }
  }
  else if(key>tree->num){
    if(tree->right_child==NULL){
      cout<<key<<" is not in the tree."<<endl;
      return tree;}
    tree->right_child=Delete(tree->right_child,key);
    }
  else if(key<tree->num){
    if(tree->left_child==NULL){
      cout<<key<<" is not in the tree."<<endl;
      return tree;}
    tree->left_child=Delete(tree->left_child,key);
    }
  return tree;
}
tree_node* BST::findMin(tree_node* tree){
  tree_node* temp=NULL;
  if(tree->left_child==NULL){
    temp=tree;
    return temp;}
  else {
    tree=tree->left_child;
    findMin(tree);
    return tree;
  }
}
void BST::Print(tree_node* tree){
  if(tree == NULL)
    return;
  Print(tree->left_child);
  cout<<"("<<tree->num<<","<<tree->str<<")"<<endl;
  Print(tree->right_child);
}
