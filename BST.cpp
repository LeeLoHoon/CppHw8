#include "BST.h" 
#include <iostream>
#include <string>

using namespace std;

string BST::search(tree_node *tree,string line){
  
  int a=0,b=0;
  string c,newLine,start,medium,end;
  if(tree == NULL){
    return line ;
  }
  line=search(tree->right_child,line);
  
  if(line.find(tree->str1)!=string::npos){
    
    while(line.find(tree->str1,a+b)!=string::npos){
      a=line.find(tree->str1); //index
      //cout<<"got"<<endl; //num check
      b=tree->str1.length(); //length
      if((line[a-1]=='.'||line[a-1]==','||line[a-1]==' ')&&(line[a+b]=='.'&&line[a+b]==','&&line[a+b]==' ')){
        cout<<"GGG"<<endl;
      }
      else{
        start=line.substr(0,a); 
        medium=tree->str2;
        //cout<<tree->str1<<endl;
        //cout<<medium<<endl;
        end=line.substr(a+b);
        line=start+medium+end;}
      //cout<<line<<endl;
      }
  }
  line=search(tree->left_child,line);
  
  return line;}


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
