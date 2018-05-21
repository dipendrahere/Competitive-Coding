#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	vector<int> v;
	cin>>n;
	while(n--){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cout<<v[ceil((1.0*v.size())/2.0 )- 1]<<endl;;
}
