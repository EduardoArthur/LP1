#include <stdio.h>
void compra(int* conta, int valor){
	*conta=*conta-valor;
	}
int main(void){
	int x;
	int y;
	int i;
	int compras[]={100, 50, 80, 30, 20 };
	printf("saldo atual a:\n");
	scanf("%d", &x);
	printf("saldo atual b:\n");
	scanf("%d", &y);
	for (i=0; i<5; i++){
		if (x<y){
			compra(&y, compras[i]);
			printf("novo saldo de a:%d\n", x);
			printf("novo saldo de b:%d\n", y);
		}
		else{
			compra(&x, compras[i]);
			printf("novo saldo de a:%d\n", x);
			printf("novo saldo de b:%d\n", y);
		}
	}
	return 0;
	}
