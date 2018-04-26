#include<bits/stdc++.h>
using namespace std;
void print(vector<pair<char, int> > v){
	for(auto i : v){
		if(i.second >= 1){
			cout<<i.first;
		}
	}
	cout<<endl;
}
int main(){
	vector<pair<char, int> > v;
	char s[1000000];
	scanf("%s", s);
	int y = strlen(s);
	for(int i=0;i<y;i++){
		int r = i;
		int count = 1;
		while(r <= y-1 && s[r] == s[r+1]){
			count++;
			r++;
		}
		count %=2;
		if(v.size() == 0){
			v.push_back(make_pair(s[i], count));
			i = r;
			continue;
		}
		int size = v.size()-1;
		if(v[size].first == s[i]){
			v[size].second += count;
			v[size].second %= 2;
			if(v[size].second %2 == 0){
				//cout<<"erase :" <<v[size].first<<" jiska second : "<<v[size].second<<endl;
				v.erase(v.begin()+size);
			}
		}
		else if(count == 1){
			v.push_back(make_pair(s[i], count));
		}
		i = r;
		
		//cout<<endl<<endl<<endl;
	} 
	print(v);
}
