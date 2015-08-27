#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

void find_and_replace(string& source, string const& find, string const& replace){
  //cout<<source<<endl;
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;){
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}

int main( int argc, char *argv[] ){
	string file = argv[1];
	string line;
  vector<string> key;// = {"pushl", "ebp", "subl", "esp", "ebp", "8", "5", "4"};
  key.push_back("pushl");key.push_back("subl");key.push_back("esp");key.push_back("ebp");
  key.push_back("8");key.push_back("5");key.push_back("4");
  map<string,string> mapping;
  ofstream myfile;
  myfile.open ("add64.s");
  mapping["pushl"] = "pushq";
  mapping["subl"] = "subq";
  mapping["esp"] = "rsp";
  mapping["ebp"] = "rbp";
  mapping["8"] = "16";
  mapping["5"] = "6";
  mapping["4"] = "7";
  vector<string> buffer;
  ifstream in( argv[1] );
  while (getline(in, line)) {
  	for(int i=0;i<key.size();i++){
      find_and_replace(line, key[i], mapping[key[i]]);
   }
    myfile << line<<"\n";
  }
  in.close();
  myfile.close();
}