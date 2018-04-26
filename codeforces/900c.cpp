#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int count = 0;
	vector<pair<int, int> > v;
	int h[1000006]={0};
	a[0] = -1;
	for(int i=1;i<=n;i++){
		if(a[i] > a[i-1]){
			count++;
			continue;
		}
		h[i] = count;
		
		v.push_back(make_pair(i, count));
		count = 0;
	}
	v.push_back(make_pair(n, count));
	int max =0 ;
	int index=0;
	for(int i =0; i <v.size()-1;i++){
		pair<int, int> rr= v[i];
		int ind = rr.first;
		int tat= rr.second;
		if(a[ind - 1] < a[ind+1]){
			if(max < tat+v[i+1].second){
				max = tat+v[i+1].second;
				index = ind;
			}
		}
	}
	cout<<a[index]<<endl;
}
