#include<bits/stdc++.h>
using namespace std;
int main(){
	char grid[27][4];
	for(int i=0;i<27;i++){
		cin>>grid[i];
	}
	int a, b;
	cin>>a>>b;
	int temp = 0;
	while(a - temp >0){
		temp += 3;
	}
	temp -=3;
	int x = a - temp;
	temp = 0;
	while(b - temp > 0){
		temp += 3;
	}
	temp-=3;
	int y = b-temp;
	int s = 0;
	if(x == 1){
		s = y-1;
	}
	if(x == 2){
		s = 8+y;
	}
	if(x  == 3){
		s = 17+y;
	}
	int flag = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(grid[s+i*3][j] == '.'){
				flag = 1;
			}
		}
	}
	//cout<<"x: "<<x<<" y: "<<y<<endl;
	//co/ut<<"flag: "<<flag<<"start: "<<s<<endl;


	if(flag == 1){
		for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(grid[s+i*3][j] == '.'){
				grid[s+i*3][j] = '!';
			}
		}
	}
	}
	else{
		for(int i=0;i<27;i++){
			for(int j= 0; j<3;j++){
				if(grid[i][j]=='.'){
					grid[i][j]='!';
				}
			}
		}
	}

	int xx=0;
	int yy=0;
	for(int i =0 ; i< 27; i++){
		cout<<grid[i]<<" ";
		xx++;
		if(xx == 3){
			cout<<endl;
			yy++;
			xx = 0;
		}
		if( yy == 3){
			cout<<endl;
			yy= 0;
		}
	}
}
