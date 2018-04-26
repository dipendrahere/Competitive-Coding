#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int c[n+2];
	int t;
	int min1 = 1000000,min2 =1000000,min3 = 1000000; 
	for(int i = 0; i < n; i++){
		cin>>c[i];
	}
	for(int i = 0; i < n; i++){
		cin>>t;
		if(t == 1){
			if(min1 > c[i]){
				min1 = c[i];
			}
		}
		if(t == 2){
			if(min2 > c[i]){
				min2 = c[i];
			}
		}
		if(t == 3){
			if(min3 > c[i]){
				min3 = c[i];
			}
		}
	}
	int ans = ((min3>min1+min2)?min1+min2:min3);
	cout<<ans<<endl;
	return 0;
}
