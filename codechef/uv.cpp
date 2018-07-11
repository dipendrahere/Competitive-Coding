#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	//cin.clear();
	cin>>t;
	while(t--){
		srand(time(0));
		int n, a, b;
		string param;
	//	cin.clear();
		getline(cin, param);
		stringstream ll(param);
		int uu;
		int h = 0;
		while(ll >> uu){
			if(h == 0){
				n = uu;
			}
			else if(h == 1){
				a = uu;
			}
			else{
				b = uu;
			}
			h++;
		}
		string grid[n+2];
		for(int i=0;i<n;i++){
		//	cin.clear();
			getline(cin, grid[i]);
		}
		int how[n+10];
		for(int i=0;i<n;i++){
			how[i]=1;
		}
		string ppp = "";
		for(int i = 0; i < n; i++){
			ppp += (to_string(1)+" ");
		}
		printf("%s\n", ppp.c_str());
		fflush(stdout);
		string his_str;
	//	cin.clear();
		getline(cin, his_str);
		vector<int> his;
        stringstream lineStream(his_str);
		int vgg;
		while(lineStream >> vgg){
			his.push_back(vgg);
		}
		map<int, int> other;
		for(int i=0;i<n;i++){
			if(his[i]>0){
				other[i] = his[i];
			}
		}
		int ptr = 0;
		for(int i=0;i<a;i++){
			//my[ptr]--;
			auto p = other.begin();
			printf("%d %d\n", ptr+1, (p->first)+1);
			fflush(stdout);
			ptr++;
			other[(p->first)] -= 1;
			if(other[(p->first)] == 0){
				other.erase(other.find(p->first));
			}
		}
		
		for(int i=0;i<b;i++){
			int kl,jk;
			string lk;
		//	cin.clear();
			getline(cin , lk);
			//scanf("%d", &kl);
		}

	}
}
