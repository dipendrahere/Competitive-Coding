#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b){
	return a.first > b.first;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		srand(time(0));
		map<int, vector<int> > mp;
		int n, a, b;
		scanf("%d", &n);
		scanf("%d", &a);
		scanf("%d", &b);
		//cin>>n>>a>>b;
		int actn = n;
		int fg = a;
		int grid[n+2][n+2];
		int count[n];
		memset(count, 0, sizeof(count));
		for(int i=0;i<n;i++){
			int v=0;
			for(int j=0;j<n;j++){
				scanf("%d", &(grid[i][j]));
				//cin>>grid[i][j];
				if(grid[i][j]){
					v++;
					mp[i].push_back(j);
				}
			}
			count[i] = v;
		}
		vector< pair < int, int > > v;
		for(int i=0;i<n;i++){
			v.push_back(make_pair(count[i], i));
		}
		sort(v.begin(), v.end(), comp);
		int acopy = a;
		int how[n];
		memset(how, 0, sizeof(how));
		// int id;
		// memset(how, 0, sizeof(how));
		// for(int i=0;i<v.size();i++){
		// 	int val = v[i].first;
		// 	int which = v[i].second;
		// 	if(val > acopy){
		// 		how[which] = acopy;
		// 		v[i].first -= acopy;
		// 		acopy = 0;
		// 	}
		// 	else{
		// 		how[which] = val;
		// 		acopy = acopy-val;
		// 		v[i].first = 0;
		// 	}
		// 	if(acopy == 0){
		// 		break;
		// 	}
		// }
		// int left = n - a;
		// for(int i = 0; i < n-1;i++){
		// 	int val = rand()%left;
		// 	how[i]+=val;
		// 	left = left - val;
		// }
		// how[n-1] = left;
		// int sum = 0;
		// for(int i =0 ;i < n;i++){
		// 	sum+=how[i];
		// }
		// int del = 0;
		// if(sum > n){
		// 	del = sum - n;
		// }
		// for(int i = 0 ;i < n ;i++){
		// 	if(how[i] > del){
		// 		del = 0;
		// 		break;
		// 		how[i] = how[i]-del;
		// 	}
		// 	else{
		// 		del = del-how[i];
		// 		how[i]=0;
		// 	}
		// }
		n = actn;
		int bache = n;
		for(int i = 0; i < n; i++){
			if(bache == 0){
				break;
			}
			int many = rand()%bache;
			how[v[i].second] = many;
			bache = bache - many;
		}
		int ko = rand()%n;
		how[ko]+=bache;

		






		for(int i=0;i<n;i++){
			how[i]=1;
		}









		n = actn;
		int sp = 0;
		for(int i = 0; i < n; i++){
			printf("%d ", how[i]);
			sp+=how[i];
		}
		if(sp != n){
			exit(1);
		}
		printf("\n");
		fflush(stdout);
		//cout<<"flushed";
		//cout.flush();
		int his[n];
		for(int i=0;i<n;i++){
			scanf("%d", &(his[i]));
		}

		map<int, int> my;
		map<int, int> other;

		for(int i=0;i<n;i++){
			if(how[i]>0){
				my[i] = how[i];
			}
		}
		for(int i=0;i<n;i++){
			if(his[i]>0){
				other[i] = his[i];
			}
		}
		// if(fg == 0){
		// 	fflush(stdout);
		// }
		for(int i=0;i<fg;i++){
			auto m = my.begin();
			auto u = other.begin();
			int bd1, bd2;
			// bd1 = rand()%my.size();
			// bd2 = rand()%other.size();
			bd1 = 0;
			bd2 = 0;
			// while(bd1--){
			// 	m++;
			// }
			// while(bd2--){
			// 	u++;
			// }
			printf("%d %d\n", m->first+1, u->first+1);
			fflush(stdout);
			//cout<<m->first+1<<" "<<u->first+1<<"\n"<<flush;
			//cout<<"flushed";
			//cout.flush();
			my[m->first]--;
			other[u->first]--;
			if(my[m->first] == 0){
				my.erase(my.find(m->first));
			} 
			if(other[u->first] == 0){
				other.erase(other.find(u->first));
			}
		}

		//cout<<endl<<endl;
		// for(int i = 0; i < n; i++){
		// 	int fighter = v[i].second;
		// 	for(auto j : mp[fighter]){
		// 		if(his[j] > 0){
		// 			for(int y = 1; y <= his[j] && a > 0 && how[fighter] > 0; y++){
		// 				cout<<fighter+1<<" "<<j+1<<endl;
		// 				cout.flush();
		// 				a--;
		// 				how[fighter]--;
		// 				his[j]--;
		// 			}
		// 		}
		// 	}
		// }
		// map<int, int> my;
		// map<int, int> other;
		// for(int i = 0 ;i < n; i++){
		// 	if(how[i] > 0){
		// 		my[i] = how[i];
		// 	}
		// }
		// for(int i=0;i<n;i++){
		// 	if(his[i] > 0){
		// 		other[i] = his[i];
		// 	}
		// }
		// while(a > 0){
		// 	int m = rand()%(my.size());
		// 	int u = rand()%(other.size());
		// 	auto by = my.begin();
		// 	auto whom = other.begin();
		// 	while(m--){
		// 		by++;
		// 	}
		// 	while(u--){
		// 		whom++;
		// 	}
		// 	int mn = min(by->second, whom->second);
		// 	for(int re = 0; re < mn ;re++){
		// 		a--;
		// 		cout<<by->first+1<<" "<<whom->first+1<<endl;
		// 		cout.flush();
		// 		if(a == 0){
		// 			break;
		// 		}
		// 		my[by->second]--;
		// 		other[whom->second]--;
		// 	}
		// 	if(my[by->second] == 0){
		// 		my.erase(my.find(by->first));
		// 	}
		// 	if(other[whom->second] == 0){
		// 		other.erase(other.find(whom->first));
		// 	}
		// }


		for(int i=0;i<b;i++){
			int kl,jk;
			scanf("%d", &kl);
			scanf("%d", &kl);
		}


		
		//cout.flush();
		
	}
}
