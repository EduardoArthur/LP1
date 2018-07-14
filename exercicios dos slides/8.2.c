#include <stdio.h>
#include <string.h>

int main (void){
	int v;
	FILE* f = fopen("/tmp/arq-02.txt", "r");
	while (v!=EOF){
		v=fgetc(f);
		if (v!=EOF){
			printf("%c ", v);
		}
	}
	printf("\n");
	fclose(f);
	return 0;
}
