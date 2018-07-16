#include <stdio.h>
#include <string.h>

void escrevastring(FILE* f, char* str){
	int j;
	for(j=0;j<strlen(str);j++){
		fputc(str[j], f);
	}
}

int main(void){
	char v[10][25];
	int i;
	FILE* f;
	f=fopen("/tmp/arq-02.txt", "w");
	for(i=0;i<10;i++){
		printf("digite a string %d:", i+1);
		scanf("%s", v[i]);
		escrevastring(f,v[i]);
	}
	fclose(f);
	return 0;	
}
