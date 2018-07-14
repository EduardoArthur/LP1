#include <stdio.h>
#include <string.h>

int main(void){
	char v[10][25];
	int i;
	int j;
	for(i=0;i<10;i++){
		printf("digite a string %d:", i+1);
		scanf("%s", v[i]);
	}
	for(i=0;i<10;i++){
		printf("%s", v[i]);
		printf("\n");
	}
	FILE* f=fopen("/tmp/arq-02.txt", "w");
	for(i=0;i<10;i++){
		for(j=0;j<strlen(v[i]);j++){
			fputc(v[i][j], f);
		}
	}
}
