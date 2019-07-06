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
	int i=0;
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
	int j=0;
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
	//point.close();
	
	int s1,s2,max,min,sum=0;
	for(s1=0;s1<i;s1++){//学生i位 
	    if(ju[0].point1[s1]!=0){
			max=ju[0].point1[s1];
		}
		else{
			max=ju[1].point1[s1];
		}
		for(s2=0;s2<7;s2++){
			if(ju[s2].point1[s1]>=max){
				max=ju[s2].point1[s1];
			}
		}
		if(ju[0].point1[s1]!=0){
			min=ju[0].point1[s1];
		}
		else{
			min=ju[1].point1[s1];
		}
		for(s2=0;s2<7;s2++){
			if(ju[s2].point1[s1]<=min){
				min=ju[s2].point1[s1];
			}
		}
		int key=1;
		s1=0;
		s2=0;
		while(key!=0&&s2<7){
			if(ju[s2].point1[s1]==max){
				ju[s2].point1[s1]=0;
				key=0;
			}
			s2++;
		}
		key=1;
		while(key!=0&&s2<7){
			if(ju[s2].point1[s1]==min){
				ju[s2].point1[s1]=0;
				key=0;
			}
			s2++;
		}
	}
	point.close();
	double f_Score[i];
	for(s1=0;s1<i;s1++){
		for(s2=0;s2<7;s2++){
			sum+=ju[s2].point1[s1];
		}
		f_Score[s1]=sum/5*1.0;
	}
	
	ofstream prin("C://Users//dell//Desktop//score.txt");
	if(prin.fail()){
		cout<<"final mission failed come on!you will win!"<<endl;
	}
	for(s1=0;s1<i;s1++){
		prin<<st[s1].name<<":"<<f_Score[s1]<<endl;
	}
	return 0;
} 
