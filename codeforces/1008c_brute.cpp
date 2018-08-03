#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	vector<int> b(n, 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin(), b.end());
	int mx = 0;
	int c;
	do{
		c = 0;
		for(int i=0;i<n;i++){//cout<<b[i]<<" ";
		if(b[i] > a[i]){
			c++;
			mx = max(c, mx);
		}
		}
		//cout<<endl;
	}
	while(next_permutation(b.begin(), b.end()));
	cout<<mx<<endl;
}
