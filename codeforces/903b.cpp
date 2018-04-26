#include<bits/stdc++.h>
using namespace std;
int h1, a1, c1;
vector<string> ans;
int h2, a2;
struct s{
	int h1, h2, a1, a2, c1, d;
	string s;
};

struct classcomp {
  bool operator() (const struct s& lhs, const struct s& rhs) const
  {

  	// return lhs.d<rhs.d;

  	if(lhs.d<rhs.d) return lhs.d<rhs.d;
  	else if(lhs.d == rhs.d) return lhs.h2 < rhs.h2;
  	else return lhs.d<rhs.d;
  }
};
multiset<struct s, classcomp> as;

void print(string s){
	for(int j=0;j<s.size();j++){char i=s[j];
		if(i=='0'){
			cout<<"HEAL\n";
		}
		else
			cout<<"STRIKE\n";
	}
}
struct s rec(int h1, int h2, int a1, int a2, int d){
	while(as.size() > 0){
		struct s temp = *as.begin();
		as.erase(as.begin());
		//cout<<temp.h1<<" "<<temp.h2<<" "<<temp.a1<<" "<<temp.a2<<" "<<temp.d<<" string: "<<temp.s<<endl;
		
		if(temp.h1 <= 0){
			continue;
		}
		if(temp.h2 <= 0){
			
			return temp;

		}
		
		if(temp.d % 2 == 0){
			struct s a = {temp.h1+temp.c1, temp.h2, temp.a1, temp.a2, temp.c1, temp.d+1, temp.s+"0"};
			struct s b = {temp.h1, temp.h2-temp.a1, temp.a1, temp.a2, temp.c1, temp.d+1, temp.s+"1"};
			as.insert(a);
			as.insert(b);
		}
		else{
			struct s a = {temp.h1-temp.a2, temp.h2, temp.a1, temp.a2, temp.c1, temp.d+1, temp.s};
			as.insert(a);
		}
		
	}
	struct s rr;
	return rr;
}
int main(){
	cin>>h1>>a1>>c1;
	cin>>h2>>a2;
	struct s temp;
	temp.h1=h1;
	temp.h2=h2;
	temp.c1=c1;
	temp.h2=h2;
	temp.a1 =a1;
	temp.a2 = a2;
	temp.d = 0;
	temp.s="";
	as.insert(temp);
	int count=0;
	struct s ans = rec(h1, h2, a1, a2, 0);
	
	cout<<ans.s.size()<<endl;
	print(ans.s);
}
