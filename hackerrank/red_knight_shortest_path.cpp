#include<bits/stdc++.h>
using namespace std;
int n;
bool reachable(int sx, int dx, int sy, int dy){
	
	if((abs(sx - dx) == 1 || abs(sx-dx)==0) && (abs(sy-dy) == 0 || abs(sy-dy) == 1)){
		return false;
	}
    if(sx == dx && abs(sy-dy)%2==1){
        return false;
    }
	if(abs(sx - dx) %2 == 1){
		return false;
	}
	return true;
}
bool valid(int x, int y){
	if(x < 0 || y< 0 || x>=n||y>=n){
		return false;
	}
	return true;
}
int ul, ur, l, r, lr, ll;
int cnt= 0;
string ans="";
void takenext(int &sx, int &sy, int dx, int dy){
	if(dx < sx && dy < sy){
		sx = sx - 2;
		sy = sy - 1;
		ans += "UL ";
		ul++;
		cnt++;
	}
	if(dx < sx && dy == sy){
		if(valid(sx-2, sy-1)){
			sx = sx - 2;
			sy = sy - 1;
			ans += "UL ";
			ul++;
			cnt++;
		}
		else{
			sx = sx - 2;
			sy = sy + 1;
			ans += "UR ";
			ur++;
			cnt++;
		}
	}
	if(dx < sx && dy > sy){
		sx = sx - 2;
		sy = sy+1;
		ans += "UR ";
		ur++;
		cnt++;
	}
	if(dx == sx && dy > sy){
		sy = sy + 2;
		ans +="R ";
		r++;
		cnt++;
	}
	if(dx > sx && dy > sy){
		sx = sx+2;
		sy = sy+1;
		ans += "LR ";
		lr++;
		cnt++;
	}
	if(dx > sx && dy == sy){
		if(valid(sx+2, sy+1)){
			sx = sx+2;
			sy = sy+1;
			ans += "LR ";
			lr++;
			cnt++;
		}
		else{
			sx = sx+2;
			sy = sy-1;
			ans += "LL ";
			ll++;
			cnt++;
		}
	}
	if(dx > sx && dy < sy){
		sx = sx+2;
		sy=sy-1;
		ans+="LL ";
		ll++;
		cnt++;
	}
	if(dx == sx && dy < sy){
		sy = sy -2;
		ans+="L ";
		l++;
		cnt++;
	}
	return;
}
bool reached(int sx, int sy, int dx, int dy){
	if(sx == dx && sy == dy){
		return true;
	}
	return false;
}
bool check(int x, int y, int dx, int dy){
    for(int i=0;i<ul;i++){
        x = x - 2;
        y = y-1;
    }
    for(int i=0;i<ur;i++){
        x = x - 2;
        y = y+1;
    }
    for(int i=0;i<r;i++){
        //x = x - 2;
        y = y+2;
    }
    for(int i=0;i<lr;i++){
        x = x + 2;
        y = y+1;
    }
    for(int i=0;i<ll;i++){
        x = x + 2;
        y = y-1;
    }
    for(int i=0;i<l;i++){
        //x = x - 2;
        y = y-2;
    }
    if(x == dx && y==dy){
        return true;
    }
    return false;
}
int main(){
	cin>>n;
	int sx, sy;
	int dx, dy;
	cin>>sx>>sy>>dx>>dy;
    int x,y;
    x=sx;
    y=sy;
	if(!valid(sx,sy)){
		cout<<"Impossible"<<endl;
		return 0;
	}
	if(!valid(dx,dy)){
		cout<<"Impossible"<<endl;
		return 0;
	}
	// if(sx == dx && dy == sy){
	// 	cout<<"2\nUL LR\n";
	// 	return 0;
	// }
	while(reachable(sx, dx, sy, dy) && !reached(sx,sy,dx,dy)){
		takenext(sx, sy, dx, dy);
		//cout<<ans<<endl;
		if(!valid(sx,sy)){

			cout<<"Impossible"<<endl;
			return 0;
			break;
		}
	}
	if(cnt == 0){
		cout<<"Impossible\n";
		return 0;
	}
    if(!check(x,y,dx,dy)){
        cout<<"Impossible\n";
		return 0;
    }
	cout<<cnt<<endl;
	for(int i=0;i<ul;i++)cout<<"UL ";
	for(int i=0;i<ur;i++)cout<<"UR ";
	for(int i=0;i<r;i++)cout<<"R ";
	for(int i=0;i<lr;i++)cout<<"LR ";
	for(int i=0;i<ll;i++)cout<<"LL ";
	for(int i=0;i<l;i++)cout<<"L ";

}
