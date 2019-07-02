#include<iostream>
using namespace std;
int main()
{
	int n,k,sum=0,a,i=0,j;
	cin>>n;
	j=n;
	while(j>0){
		j/=10;
		i++;
	}
	for(k=0;k<i;k++){
		a=n%10;
		n/=10;
		sum+=a;
	}
	cout<<i<<" "<<sum;
	if(k>10){
		cout<<"too long"<<endl;
		
	} 
	else {
		cout<<"it is suitable"<<endl;
	}
	return 0;
 } 
