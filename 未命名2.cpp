#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
int main(){
	string s1,s2,s3;
	ifstream in("C://Users//dell//Desktop//student.txt");
	ofstream out("C://Users//dell//Desktop//judge.txt");
	if(in.is_open()){
		getline(in,s1,',');
		
	} 
	if(out.is_open()){
		out<<"all is well!"<<endl<<s1;
		cout<<"all is well!"<<endl;
	}
}
