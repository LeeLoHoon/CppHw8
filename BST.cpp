#include "BST.h" 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  BST *myBST;
  myBST= new BST();
  ifstream fp,ep;
  int size,size2,index;
  string fileName1,fileName2,value,line;
  string source, target,temp,fixed;
  

  try{
    cin>>fileName1;
    ep.open(fileName1);
    cin >> fileName2;
    fp.open(fileName2);
  }catch(const ifstream::failure& e){
   	cerr << "Exception occurred while opening the file." << endl;}
  while(!fp.eof()){
    getline(fp,line);
    size=line.size();
    index=line.find(":");
    
    source=line.substr(0,index);
    target=line.substr(index+1,size);
    if(target[0]==' '){
      target=target.substr(1);
    }
    size2=target.size();
    if(target[size2-1]==' '){ 
      target=target.substr(0,size2-1);
    }
    //cout<<target<<endl;
    myBST->Add(source,target);
    }
  fp.close();
  while(!ep.eof()){
    getline(ep,line);
    fixed=myBST->search(line);
    cout<<fixed<<endl;
  //BST는 끝, 구현 할 것:  line을 파라미터로 search 실행하면 search 메소드 안에서 map tree의 key들을 빠짐없이 compare하여 같은 것이 있으면 value값으로 replace  그리고 string return
  }
  ep.close();
}
  
