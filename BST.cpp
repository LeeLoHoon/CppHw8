#include "BST.h" 
#include <iostream>
#include <string>

using namespace std;

string BST::search(tree_node *tree,string line){
  
  if(tree == NULL)
    return;
  search(tree->left_child,line);
  line.find(tree->str1);
  if()
  //cout<<"("<<tree->str1<<","<<tree->str2<<")"<<endl;
  search(tree->right_child,line);
  


/*  if(tree==NULL){
    return NULL;  
  }
  while(tree!=NULL){
    if(key.compare(tree->str1)==0) return tree->str2;
    else if (key.compare(tree->str1)<0)
      if(tree->left_child == NULL) return NULL;
      else tree=tree->left_child;
    else                       
      if (tree->right_child == NULL) return NULL; 
      else tree = tree->right_child;
  }
  return NULL;
}*/
string BST::search(string line){
  return search(root, key);
}


tree_node* BST::Add(tree_node* tree, string key, string value){
  if(tree==NULL){
    tree = new tree_node;
    tree->str1 = key;
    tree->str2 = value;
    tree->left_child=NULL;
    tree->right_child=NULL;
  }  
  else if(key.compare(tree->str1)==0){
    cout<<key<<" is already in the tree."<<endl;
  } 
  else{
    if(key.compare(tree->str1)>0){
      tree->right_child = Add(tree->right_child,key,value);}
    else if(key.compare(tree->str1)<0){
      tree->left_child=Add(tree->left_child,key,value);
    }
}
  return tree;
}
tree_node* BST::Delete(tree_node* tree,string key){
  tree_node* temp;
  if(key.compare(tree->str1)==0){
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
      string a;
      string b;
      temp=findMin(tree->right_child);
      a=temp->str1;
      b=temp->str2;
      Delete(a);
      tree->str1=a;
      tree->str2=b;
    }
  }
  else if(key.compare(tree->str1)>0){
    if(tree->right_child==NULL){
      cout<<key<<" is not in the tree."<<endl;
      return tree;}
    tree->right_child=Delete(tree->right_child,key);
    }
  else if(key.compare(tree->str1)<0){
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
  cout<<"("<<tree->str1<<","<<tree->str2<<")"<<endl;
  Print(tree->right_child);
}
