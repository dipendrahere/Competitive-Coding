#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	if(n == 2){
		cout<<"1\n1 1"<<endl;
	}
	else if((n/2)%2 == 0 && n%2 == 0){
		cout<<"0\n";
		cout<<n/2<<" ";
		for(int i =0 ; i <n/4;i++){
			cout<<1+2*i<<" "<<n-2*i<<" ";
		}
		cout<<endl;
		return 0;
	}
	else if(n%2 == 0){
		cout<<1<<endl;
		cout<<n/2<<" ";
		for(int i =0 ; i < n/2;i++){
			if(i%2 == 0){
				cout<<1+i<<" ";
			}
			else{
				cout<<n-(i-1)<<" ";
			}
		}
		cout<<endl;
	}
	else if(n == 3){
		cout<<0<<endl;
		cout<<2<<" ";
		cout<<"1 2"<<endl;
	}
	else {
		int p = n - n/2;
		p = p/2;
		vector<int> a;
		//vector<int> b;
		long long sum = 0;
		//cout<<p<<endl;
		int c=0;
		for(int i = n;i>=0;i--){
			a.push_back(i);
			sum+=i;

			c++;
			if(c == p){
				break;
			}
		}
		if((n/2)%2 == 0){
			int s = p+1;
			for(int i=1;i<=s;i++){
				a.push_back(i);
				sum+=i;
			}
		}
		else{
			int s = p -1;
			for(int i=1;i<=s;i++){
				a.push_back(i);
				sum+=i;
			}
		}
		cout<<abs((n*(n+1)/2)-2*sum)<<endl;
		cout<<a.size()<<" ";
		for(auto i:a ){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
