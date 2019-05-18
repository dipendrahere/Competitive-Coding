#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int n;
	cin>>n;
	int a[n+2];
	for(int i = 0 ;i < n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n-1;i++){
        cout<<i+1<<" "<<i+2<<endl;
    }
}
