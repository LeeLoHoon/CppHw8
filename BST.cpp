//
#include "BST.h" 
#include <iostream>
#include <string>

using namespace std;

string BST::search(tree_node *tree,string line){
  
  
  string start,medium,end,check;
  if(tree == NULL)
    return line ;
    
  line=search(tree->right_child,line);
  
  if(line.find(tree->str1)!=string::npos){
    int a=0,b=0;
    while(line.find(tree->str1,a+b)!=string::npos){
      a=line.find(tree->str1,a+b); 
      b=tree->str1.length(); 
      if((line[a-1]>='A'&&line[a-1]<='z')||(line[a+b]>='A'&&line[a+b]<='z'))
        check="go";
      else{
        start=line.substr(0,a); 
        medium=tree->str2;
        end=line.substr(a+b);
        line=start+medium+end;}
      }
  }
  
  line=search(tree->left_child,line);
  
  return line;
}


string BST::search(string line){
  return search(root, line);
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
//
