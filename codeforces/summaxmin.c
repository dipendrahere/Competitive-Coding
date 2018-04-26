#include<stdio.h>
int main(){
	int m;
	int s;
	scanf("%d%d",&m,&s);
	if(s == 0 && m == 1){
		printf("0 0\n");
		return 0;
	}

	if(m*9 < s || s == 0){
		printf("-1 -1\n");
		return 0;
	}
	char nummax[m+1];
	char nummin[m+1];
	int flag = 0;
	int temp = s;
	int index = 0;
	while(temp > 0){
		nummax[index] = '0'+ ((temp = (temp - 9)) >= 0 ? 9 : (temp+9));
		//printf("%c\n", nummax[index]);
		index++;
	}
	for(;index < m; index++){
		nummax[index] = '0';	
	}
	nummax[m] = '\0';
	int i;
	nummin[0] = '1';
	for(i = 1; i < m; i++){
		nummin[i] = '0';
	}
	nummin[m] = '\0';
	temp = s - 1;
	i--;
	while(temp > 0){
		nummin[i] += (temp = (temp - 9)) >= 0 ? 9 : (temp + 9);
		i--;	
	}
	for(i = 0; i < m; i++){
		printf("%c", nummin[i]);
	}
	printf(" ");
	for(i = 0; i < m;i++){
		printf("%c",nummax[i]);
	}
	printf("\n");
	return 0;
}
	
