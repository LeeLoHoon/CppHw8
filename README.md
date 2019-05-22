# CppHw8

    void Delete(string key){
      root = Delete(root,key);
    }
    tree_node* Delete(tree_node* tree,string key);
    void Print(){
      Print(root);
    }
    void Print(tree_node* tree);
    tree_node* findMin(tree_node* tree);



===============
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
