#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		vector<long> a;
		vector<long> b;
		map<long, int> mp;
		long temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			a.pb(temp);
			b.pb(temp);
			mp.insert(make_pair(temp, i));
		}
		sort(a.begin(), a.end());
		long x;
		for(int i=0;i<q;i++){
			cin>>x;
			int less = lower_bound(a.begin(), a.end(), x) - a.begin();
			int more = n-less-1;
			//cout<<less<<" "<<more<<endl;
			int ind = mp[x];
			int low = 0;
			int high = n-1;
			int count = 0;
			int mid;
			int flag = 0;
			vector<int> lo;
			vector<int> hi;
			while(low <= high){
				mid = (low+high)/2;
				if(less < 0 || more < 0){
				//	flag = 0; 
				//	break;
				}
				if(mid == ind){
					flag = 1;
					break;
				}
				else if(mid < ind){
					low = mid+1;
					if(b[mid] < x){
						less--;
						continue;
					}
					else{
						hi.pb(mid);
						more--;
						count++;
						if(more < 0){
						//	flag = 0;break;
						}
					}
				}
				else{
					high = mid - 1;
					if(b[mid] > x){
						more--;
						continue;
					}
					else{
						lo.pb(mid);
						less--;
						count++;
						if(less < 0){
						//	flag = 0;break;
						}
					}
				}
			}


			
			// for(auto i : lo){
			// 	cout<<i<<" ";
			// }
			// cout<<endl;
			// for(auto i : hi){
			// 	cout<<i<<" ";
			// }
			// cout<<endl;



			if(flag == 0){
				cout<<"-1\n";
			}
			else{
				cout<<max(lo.size(), hi.size())<<endl;
			}
		}
	}
}
