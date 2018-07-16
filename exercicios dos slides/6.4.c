#include <stdio.h>
#include <string.h>

int strlen2(char v[]){
	int i=0;
	while(v[i]!='\0'){
		i=i+1;
	}
	return i;
}
void strjoin(char v[],char v2[],int x,int y /*, char d[]*/){
	int i;
	char r[x+y];
	for (i=0;i<x;i++){
		r[i]=v[i];
	}
	for (i=0;i<y;i++){
		r[i+x]=v2[i];
	}
	printf("%s \n",r);
}
int main(void){
	char v[25];
	char v2[25];
	printf("escreva uma string:\n");
	scanf("%s",v);
	int x=strlen2(v);
	printf("escreva outra string:\n");
	scanf("%s",v2);
	int y=strlen2(v2);
	//printf("escreva o destino:\n");
	printf("%d \n" ,strlen2(v));
	printf("%d \n" ,strlen2(v2));
	strjoin(v,v2,x,y);
	return 0;
}
