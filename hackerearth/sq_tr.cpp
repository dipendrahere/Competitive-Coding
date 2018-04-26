#include<stdc++.h>
#include<vector>
using namespace std;
long long int a[100006];
int main(){
	int t;
	cin>>t;
	cin>>a[0];
	for(int i = 1; i < t; i++){
		cin>>a[i];
		a[i] += a[i-1];
	}
	vector<long long> v(a, a+t);
	vector<long long>::iterator index;
	long int q;
	cin>>q;
	long long int temp;
	while(q--){
		cin>>temp;
		if(temp > a[t-1]){
			cout<< "-1\n";
		}
		else {
			index = lower_bound(v.begin(), v.end(), temp);
			cout<< (index - v.begin()) + 1 << "\n";
		}
	}
	return 0;
}
			
