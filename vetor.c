#include <stdio.h>

int main(void){
	int t;
	char temps[50];
	int x;
	int cont=5;
	int i;
	int s=0;
	for (i=1;i<=cont;i++){
		printf("escreva a temperatura:\n");
                scanf("%d", &t);
		temps[i]=t;
		s=s+temps[i];
		}
	x=s/cont;
	printf("media:%d\n", x);
	s=0;
	for (i=1;i<=cont;i++){
		if (x>temps[i]){
			s=s+1;
			}
		}
	printf("temperaturas acima da media:%d\n",s);
	return 0;
	}
