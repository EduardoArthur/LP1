#include <stdio.h>
#include <string.h>

int main (void){
	int i, b;
	char a[25];
	FILE* f = fopen("/tmp/arq-02.txt", "w");
	printf("Digite a string:");
	scanf("%s", a);
	b=strlen(a);
	for(i=0; i<b; i++){
		fputc(a[i], f);
	}
	return 0;
}
