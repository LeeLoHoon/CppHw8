#include "BST.h" 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  BST *myBST;
  myBST= new BST();
  ifstream fp;
  string fileName,value;
  char command;
  int key;
  try{
    cin >> fileName;
    fp.open(fileName);
  }catch(const ifstream::failure& e){
   	cerr << "Exception occurred while opening the file." << endl;}
  while(!fp.eof()){
    fp>>command;
    if(command=='a'){
      fp>>key;
      fp>>value;
      myBST->Add(key,value);
    }
    else if(command=='d'){
      fp>>key;
      myBST->Delete(key);
    }
    else if(command=='p'){
      myBST->Print();
    }
    else if(command=='q') break;
  }
}
