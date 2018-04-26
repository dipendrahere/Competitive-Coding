#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = (rand() % 100 + 1);
	cout<<n<<endl;
	for(int i = 0; i < n; i++){
		long long low = 1;
		long long end = 1000000000000;
		long long num = rand()%10000;
		bitset<100> s(num);
		string str = s.to_string();
		str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
		int r = rand()%100;
		str[r] = '1';
		str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
		for(int i =0; i <str.size();i++){
			if(str[i]=='1'){
				cout<<'a';
			}
			else{
				cout<<'b';
			}
		}
		cout<<" "<<rand()%1000<<endl;
	}
}
