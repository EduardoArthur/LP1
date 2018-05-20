#include <stdio.h>
void compra(int* conta, int valor){
	*conta=*conta-valor;
	}
int main(void){
	int x;
	int y;
	int valor=500;
	printf("saldo atual a:\n");
	scanf("%d", &x);
	printf("saldo atual b:\n");
	scanf("%d", &y);
	if (x<y){
		compra(&y, valor);
	}
	else{
		compra(&x, valor);
	}
	printf("novo saldo de a:%d\n", x);
	printf("novo saldo de b:%d\n", y);
	return 0;
	}
