#include<bits/stdc++.h>
using namespace std;
vector<int> fib;
int main(){
	int n;
	cin>>n;
	fib.push_back(1);
	int last = 1;
	for(int i = 0; last+fib[fib.size()-1] <= n;i++){
		fib.push_back(last+fib[fib.size()-1]);
		last = fib[fib.size()-2];
	}
	int ptr = 0;
	for(int i =1 ;i <= n;i++){
		if(i == fib[ptr]){
			cout<<"O";
			ptr++;
		}
		else{
			cout<<"o";
		}
	}
	cout<<endl;
}
