#include<bits/stdc++.h>
using namespace std;
double pos(double t, double e, double v, int d, double pos, double c){
	double newpos = 0.0;
	//printf("shuru time = %0.9f\n", t);
	if(d == 1){
		newpos = pos+v*(t+e);
	//	printf("newpos = %0.9f\n", newpos);
		if(newpos < -1e-6){
			return t+e;
		}
		else{
			double tt = (c*1.0+(1e-6)-pos*1.0)/(v*1.0);
	//		printf("time = %0.9f\n", tt);
			if(tt > t){
				tt = tt-t;
			}
			else{
				return t+e;
			}
			return (t+e+tt);
		}
	}
	else{
		newpos = pos-v*(t+e);
	//	printf("newpos = %0.9f\n", newpos);
		if(newpos > 1e-6){
			return t+e;
		}
		else{
			double tt = (1.0*c*1.0+(1e-6)+pos*1.0)/(v*1.0);
	//		printf("time = %0.9f\n", tt);
			if(tt > t){
				tt = tt-t;
			}
			else{
				return t+e;
			}
			return (t+e+tt);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,s,y;
		cin>>n>>s>>y;
		int v[n+2], d[n+2], p[n+2], c[n+2];
		for(int i = 0; i < n; i++){
			cin>>v[i];
		}
		for(int i = 0; i < n; i++){
			cin>>d[i];
		}
		for(int i = 0; i < n; i++){
			cin>>p[i];
		}
		for(int i = 0; i < n; i++){
			cin>>c[i];
		}
		double t = 0.0;
		for(int i = 0; i < n; i++){
			double wait = pos(t*1.0, (y+0.0)/(s*1.0), v[i]+0.0, d[i], p[i]*1.0, c[i]*1.0);
			t = wait;
			//printf("%0.9f\n", wait);
		}
		printf("%0.9f\n", t);
	}
}
