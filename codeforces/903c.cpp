#include<bits/stdc++.h>
using namespace std;
void show(set<pair<int, int> > c){
	for(auto i :c){
		cout<<i.first<<" "<<i.second<<endl;
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a, a+n);
	
	set<pair<int, int> > c;

	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<n-1;){
		int count = 1;
		while(a[i]==a[i+1] &&i< n){
			count++;
			i++;
		}
		i++;
		c.insert(make_pair(count, a[i]));
	}
	//show(c);
	set<pair<int, int> >::iterator it = c.end();
	it--;
	int s = it->first;
	cout<<s<<endl;
}
