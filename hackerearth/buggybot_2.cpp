#include<bits/stdc++.h>
using namespace std;
void print(vector<int> ans){
 
	for(auto i: ans){
		cout<<i<<" ";
	}
	cout<<endl;
}
vector<int> graph[1000007];
 
void print(set<int> a){
	for(auto r: a){
		cout<<r<<" ";
	}
	cout<<endl;
}
 
bool check(set<int> r, int v){
 
	if(r.size() == 0){
		return false;
	}
	set<int>::iterator it = r.lower_bound(v);
 
	if(it == r.end() || *it!=v){
		return false;
	}
	//cout<<"searched for: "<<v<<" got "<<*it<<endl;
	return true;
}
 
 vector<pair<int, int > > s;
 set<int> inst[1000600];
int main(){
	int n, m, k;
	cin>>n>>m>>k;
	
	for(int i = 0 ;i < m ; i++ ){
		int a, b;
		cin>>a>>b;
		graph[a].push_back(b); 
	}
	// for(int i= 0;i<=n;i++){
	// 	cout<<"for "<<i<<" : "<<endl;
	// 	print(graph[i]);
		
	// }
 
	int arr[1006000]={0};
//	arr[1] = 1;
	int curr = 1;
	
		for(auto i : graph[curr]){
		//	cout<<"i say "<<curr<<" "<<i<<" exists"<<endl;
			arr[i]=1;
		}
	
	// 	for(int i=0;i<k;i++){
	// 	int a,b;
		
	// 	cin>>a>>b;
	// 	 set<int>::iterator it = inst[a].lower_bound(b);
	// 	 if(it == inst[a].end() || *it !=b){
	// 		s.push_back(make_pair(a,b));
	// 		inst[a].insert(b);
	// 	}
		
	// }

		int path[1000500]={0};
		path[1]=1;

	for(int p=0;p<k;p++){
		int a,b;
		cin>>a>>b;
	///	set<int>::iterator it = inst[a].lower_bound(b);
	///////	if(it!=inst[a].end()&&*it==b){continue;}
	///////////	if(arr[a]!=1 && curr !=a){
	///////		inst[a].insert(b);
	////////	}
		if(arr[a] == 1){
			arr[a]=0;
			arr[b]=1;
		}	
		//if(!check(graph[a],b)){continue;}
		if(curr == a){
			path[a]=0;
			path[b]=1;
			curr = b;

			for(auto i : graph[a]){
				if(i==b){
				///	continue;
				}
		//	cout<<"i say "<<curr<<" "<<i<<" exists"<<endl;
			arr[i]=1;
		}
		for(auto i : graph[b]){
				if(i==b){
				//	continue;
				}
		//	cout<<"i say "<<curr<<" "<<i<<" exists"<<endl;
			arr[i]=1;
		}
		}
		
	}
	arr[curr] = 1;
	for(auto i : graph[curr]){
		//	cout<<"i say "<<curr<<" "<<i<<" exists"<<endl;
			arr[i]=1;
		}
	int count = 0;
	vector<int> ans;
	for(int i=0;i<=n+1;i++){
		if(arr[i]==1 || path[i]==1){
			count++;
			ans.push_back(i);
		}
	}
	cout<<count<<endl;;
	print(ans);
}