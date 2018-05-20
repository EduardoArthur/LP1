#include <stdio.h>
int main(void){
	int a;
	int b;
	printf("digite a \n");
	scanf("%d" ,&a);
	printf("digite b \n");
	scanf("%d" ,&b);
	printf("%d o valor de a era:\n", a);
	printf("%d o valor de b era:\n", b);
	int* p;
	if (a>b){
		p=&a;
		*p=*p-50;
		a=*p;
		printf("%d novo valor de a :\n", a);
		printf("%d novo valor de b :\n", b);
		}
	else{
		p=&b;
		*p=*p-50;
		b=*p;
		printf("%d novo valor de a :\n", a);
		printf("%d novo valor de b :\n", b);
		}
	return 0;
	}
