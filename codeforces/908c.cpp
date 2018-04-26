#include<bits/stdc++.h>
using namespace std;
double sqrte(double n)
{
  /*We are using n itself as initial approximation
   This can definitely be improved */
  double x = n;
  double y = 1;
  double e = 0.000000001; /* e decides the accuracy level*/
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}
 
int main(){
	double n,r;
	cin>>n>>r;
	//cout<<r<<" ";
	double a[1003+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<pair<double, double> > v;
	v.push_back(make_pair(a[0], r));
	for(int i =1 ;i < n;i++){
		//cout<<i<<":"<<endl;
		double x=-1;
		double y=0;
		for(int j = 0;j<v.size();j++){
			//cout<<"with : "<<j<<endl;
			//cout<<"asking is "<<a[i]<<" between "<<v[j].first-r<<" and "<<v[j].first+r<<endl;
			if(a[i]>=v[j].first-r-r && a[i]<=v[j].first+r+r){
				double nowy = v[j].second+sqrte(2.0*2.0*r*r - (a[i] - v[j].first)*(a[i] - v[j].first));
				y = y>nowy?y:nowy;
			//	cout<<"nowy: "<<nowy<<endl;
			}
		}
		v.push_back(make_pair(a[i], y));
	}
	for(auto r:v){
		cout<<r.second<<" ";
	}
	cout<<endl;
}
