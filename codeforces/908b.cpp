#include<bits/stdc++.h>
using namespace std;
string pos[]={"URLD","URDL","ULRD","ULDR","UDLR","UDRL","RULD","RUDL","RLUD","RLDU","RDLU","RDUL","LRUD","LRDU","LURD","LUDR","LDUR","LDRU","DRLU","DRUL","DLRU","DLUR","DULR","DURL"};
int main(){
	int r, c;
	cin>>r;
	cin>>c;
	int rr =r;
	int cc = c;
	int x,y,ex,ey;
	int xx;int yy;
	char grid[r+2][c+2];
	for(int i =0 ; i <r;i++){
		for(int j=0;j<c;j++){
			cin>>grid[i][j];
			if(grid[i][j] == 'S'){
				x = i;
				y = j;
			}
			if(grid[i][j] == 'E'){
				ex = i;
				ey = j;
			}
		}
	}
	xx=x;
	yy=y;
	//cout<<x<<y<<ex<<ey;
	int ans= 0;
	string f;
	cin>>f;
	//cout<<f<<endl;
	//cout<<f.size();
	for(int i=0;i<24;i++){
		x=xx;
		y=yy;
		string str = pos[i];
		//cout<<str<<":"<<endl;
		for(int r = 0; r<f.size();r++){
			//cout<<str[f[r]-'0']<<endl;
			char st = f[r];
			if(str[st-'0'] == 'U'){
				x = x-1;
			}
			else if(str[st-'0'] == 'D'){
				x = x+1;
			}
			else if(str[st-'0'] == 'L'){
				y = y-1;
			}
			else{
				y =y+1;
			}
			if(x == ex && y == ey){
			//	cout<<"reach"<<endl;
				ans++;
				break;
			}
			if(x >= rr || y >=cc || x <0 || y<0){
			//	cout<<"bahar"<<endl;
				break;
			}
			if(grid[x][y] == '#'){
			//	cout<<"obs"<<endl;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
