#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<iomanip>
#include<stdio.h>
using namespace std;
struct student{
	string collage;
	string code;
	string name;
}st[30];
struct judge{
	string name;
	double point1[30];
}ju[7];
int main(){
	static int i=0;
	//i为学生人数 
	ifstream info("C://Users//dell//Desktop//student.txt");
	if(info.fail()){
		cout<<"mission 1  failed"<<endl;
		return 0;
	}
	while(!info.eof()){
        getline(info,st[i].collage,' ');
        getline(info,st[i].code,' ');
        getline(info,st[i].name,'\n');
		i++; 
	}
	info.close();
	
	int h;
	static int j=0;
	ifstream point("C://Users//dell//Desktop//judge.txt");
	if(point.fail()){
		cout<<"mission 2 failed"<<endl;
		return 0;
	}
	string t_Score;
	while(!point.eof()){
		getline(point,ju[j].name,':');
		for(h=0;h<i-1;h++){
			getline(point,t_Score,',');
			ju[j].point1[h]=atoi(t_Score.c_str());
		}
		getline(point,t_Score,'\n');
		ju[j].point1[i-1]=atoi(t_Score.c_str());
		j++;
	}
	point.close();
	
	int s1,s2,max,min,sum=0;
	for(s1=0;s1<7;s1++){//裁判七位 
	    max=ju[s1].point1[0];
		for(s2=0;s2<i;s2++){
			if(ju[i].point1[s2]>=max){
				max=ju[i].point1[s2];
			}
		}
		min=ju[s1].point1[0];
		for(s2=0;s2<i;s2++){
			if(ju[i].point1[s2]<=min){
				min=ju[i].point1[s2];
			}
		}
		int key=1;
		s2=0;
		while(key!=0&&s2<i){
			if(ju[i].point1[s2]==max){
				ju[i].point1[s2]=0;
				key=0;
			}
			s2++;
		}
		key=1;
		while(key!=0&&s2<i){
			if(ju[i].point1[s2]==min){
				ju[i].point1[s2]=0;
				key=0;
			}
			s2++;
		}
	}
	int f_Score[i];
	for(s1=0;s1<i;s1++){
		for(s2=0;s2<7;s2++){
			sum+=ju[s2].point1[s1];
		}
		f_Score[s1]=sum/5;
	}
	
	ofstream prin("C://Users//dell//Desktop//score.txt");
	if(prin.fail()){
		cout<<"final mission failed come on!you will win!"<<endl;
	}
	for(s1=0;s1<i-1;s1++){
		prin<<st[s1].name<<":"<<f_Score[s1]<<endl;
	}
	return 0;
} 
