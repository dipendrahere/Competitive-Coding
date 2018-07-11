#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long, pair<long long, long long> > a,pair<long long, pair<long long, long long> > b){
	if(a.first>b.first){
		return true;
	}
	else if(a.second.first > b.second.first){
		return true;
	}
	else{
		if(a.second.second < b.second.second){
			return true;
		}
	}
	return false;
}
int main(){
	long long t;
	cin>>t;
	while(t--){
		//vector<long long> v;
		long long n;
		cin>>n;
		long long a[n+2];
		for(long long i=0;i<n;i++){
			cin>>a[i];
		}
		long long l;
		long long x = 0;
		long long max_so_far = long long_MIN, max_ending_here = 0;
		vector<pair<long long, pair<long long, long long> > > v;
    	for (long long i = 0; i < n; i++){
        	max_ending_here = max_ending_here + a[i];
        	x++;
        	if (max_so_far <= max_ending_here){
           		max_so_far = max_ending_here;
           		l = i;
           		//cout<<max_so_far<<" "<<x<<endl;
           		v.push_back(make_pair(max_so_far, make_pair(x, i)));
        	}
        	if (max_ending_here < 0){
        		x=0;
            	max_ending_here = 0;
        	}
    	}
    	sort(v.begin(), v.end(), comp);
    	long long st = v[0].second.second;
    	long long ll = v[0].second.first;
    	vector<long long> lo;
    	long long count = 0;
    	for(long long i = st;;i--){
    		lo.push_back(a[i]);
    		count++;
    		if(count == ll){
    			break;
    		}
    	}
    	for(auto i = lo.rbegin();i!=lo.rend();i++){
    		cout<<*i<<" ";
    	}
    	cout<<endl;
	}
}
