#include<iostream>
#include<time.h>
using namespace std;

int r(int min,int max) {
	int a = rand()%10000,b = rand()%10000,c = rand()%10;
	int d=a*100000+b*10+c;
	return d%(max-min+1)+min;
}
long long int llr(long long int min,long long int max) {
	long long int a=r(0,1e9-1),b=r(0,1e9-1);
	long long int c=a*1e9+b;
	return c%(max-min+1)+min;
}

int main() {
	freopen("make.txt","w",stdout);
	
	srand(time(0));
	
	int N=r(1,20000),M=r(1,20000);
	cout<<N<<" "<<M<<endl;
	while(M--) {
		cout<<(r(0,1)?"a":"b")<<" ";
		cout<<r(1,N)<<" ";
		cout<<r(1,N)<<" ";
		cout<<r(1,1000000)<<endl;
	}
	
	return 0;
}

#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	
	int count=1;
	while(true) {
		system("生測資.exe");
		system("要測的.exe < make.txt > A.txt");
		system("暴力.exe < make.txt > B.txt");
		
		if(system("fc A.txt B.txt")) break;
		cout<<count++<<endl;
	}
	
	return 0;
}