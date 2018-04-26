#include<bits/stdc++.h>
using namespace std;
int c=0;
vector<int> v;
int rr=0;
long long sum=0;
void print(vector<int> v){
	for(int i : v){
		cout<<i<<" ";
	}
	cout<<endl;
}
void cal(int k, int p){
	for(int i=1;i<=k;i++){
		int temp = i;
		int var;
		long num = i;
		long long yy=i;
		while(temp!=0){
			var=temp%10;
			temp=temp/10;
			num = ((num%p*10)%p+(var)%p)%p;
			yy=yy*10+var;
		//	cout<<num<<" ";
		}
		//cout<<yy<<" ";
		sum = (sum%p + num%p)%p;
	}
}
int main(int argc, char const *argv[])
{
	int k,p;
	cin>>k>>p;
	int i=1;

	cal(k,p);
	cout<<sum<<endl;
	return 0;
}
