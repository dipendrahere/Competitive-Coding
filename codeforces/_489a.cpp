 

 /** NOT MINIMUM SWAPS TO BE A SORTED ARRAY**/


/** for minimum swaps 

for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int t = i; t < n; t++)
            if (a[j] > a[t])
                j = t;
        if (i != j)
            answer.push_back(make_pair(i, j));
        swap(a[i], a[j]);
    }

**/

#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ans;

void print(){
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].second<< " "<<ans[i].first<<endl;
	}
	//cout<<endl;
}

void minswap(int a[], int n){
	vector<pair<int, int> > v;
	for(int i=0;i<n;i++){
		v.push_back(make_pair(a[i], i));
	}

	sort(v.begin(), v.end());
	int vis[n+2];
	memset(vis, 0, sizeof(vis));
	for(int i=0;i<v.size();i++){
		if(i == v[i].second){
			continue;
		}
		int j = i;
		while(vis[j] != 1){
			vis[j] = 1;
			if(vis[v[j].second] != 1){
				ans.push_back(make_pair(j, v[j].second));
			}
			j = v[j].second;
		}
	}
}
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	minswap(a, n);
	print();
}
