#include<bits/stdc++.h>
using namespace std;
set<node, comparator> shops;
set<node, comparator> houses;
vector<node> mix;
struct node{
	int houseno;
	int shopno;
	int rate;
	vector<int> hate;
	int add;
};
struct comparator{
	bool operator()(const node &a, const node &b){
		return a.add < b.add;
	}
};
#define node struct node
node makeshop(int add, int rate, int id){
	node temp;
	temp.houseno = -1;
	temp.shopno = id;
	temp.rate = rate;
	temp.add = add;
	return temp;
}
node makehouse(int houseno, vector<int> hate, int add){
	node temp;
	temp.houseno = houseno;
	temp.shopno = -1;
	temp.hate = hate;
	temp.add = add;
	return temp;
}
int main(){
	int n.m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int s, p;
		cin>>s>>p;
		shops.insert(makeshop(s, p, i));
	}
	for(int i= 0;i <m;i++){
		int c, k;
		cin>>c>>k;
		vector<int> temp;
		for(int i= 0;i<k;i++){
			int x;
			cin>>x;
			temp.insert(x);
		}
		houses.insert(makehouse(i, temp, c));
	}
	
	auto sp = shops.begin();
	auto hp = houses.begin();
	while(sp!=shops.end() && hp!=houses.end()){
		if(sp->add >= hp->addr){
			mix.push_back(*sp);
			sp++;
		}
		else{
			mix.push_back(*hp);
			hp++;
		}
	}
	node ns;
	for(int i = 0; i < mix.size(); i++){
		
	}
}