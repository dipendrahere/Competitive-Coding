#include <iostream>
#include<algorithm>
using namespace std;
unsigned long long int minn(long long a, long long b){
	return a>b?b:a;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		unsigned long long a[1000] = {0};
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		unsigned long long int min = 999999999999999999;
		long long int gcd;
		for(int i = 0 ;i < n;i++){
			for(int j=i+1;j<n;j++){
				gcd = __gcd(a[i],a[j]);
				min = minn(min, (a[i]*a[j])/gcd);
			}
		}
		cout<<min<<endl;
		//min = minn(min, a[i]*a[j]/gcd);
	}
	return 0;
}