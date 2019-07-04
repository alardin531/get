#include<iostream>
using namespace std;
class Date{
	public:
		int y,m,d,sum=0,fsum=0,key;
	Date(int a,int b,int c): y(a),m(b),d(c){
		if((y%4==0&&y%100!=0)||(y%400==0)){
			key=29;
		}
		else {key=28;
		}
	}
	void showtime(){
		int sa[13];
		if(y==m==d){
			key=0;
		}
		else {
			if(key==29){
			for(unsigned i=1;i<13;i++){
				if(i==1||m==3||i==5||i==7||i==8||i==10||i==12){
					sa[i]=31;
			}
			    else if(i==2){
			    	sa[i]=key;
				}
				else {
					sa[i]=30;
				}
			}
				
			}
		else if(key==28){
			for(unsigned i=1;i<13;i++){
				if(i==1||m==3||i==5||i==7||i==8||i==10||i==12){
					sa[i]=31;
			}
			    else if(i==2){
			    	sa[i]=key;
				}
				else {
					sa[i]=30;
				}
			}
		}
		for(unsigned i=1;i<=m;i++){
			sum+=sa[i];
		}
		fsum=sum+d;
		cout<<fsum<<endl;
		}

		}
		
};
int main(){
	int j,k,l;
	cin>>j>>k>>l;
	Date a(j,k,l);
	a.showtime();
	for(unsigned i=10;i<=20;i++){
			cout<<"you are fooled"<<endl;
		}
	return 0;
}
