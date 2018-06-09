#include <stdio.h>

struct vel{
	int vi;
	int vf;
	int v;
};

struct experimento{
	struct vel V;
	int s;
	int a;
	int t;
};

void variacaovel(struct vel *V){
	int x;
	printf("velocidade final:\n");
	scanf("%d",&(*V).vf);
	printf("velocidade inicial:\n");
	scanf("%d",&(*V).vi);
	x=(*V).vf-(*V).vi;
	(*V).v=x;
}
void valores(struct experimento *e1){
	printf("aceleração:\n");
	scanf("%d",&(*e1).a);
	printf("distancia:\n");
	scanf("%d",&(*e1).s);
	printf("tempo:\n");
	scanf("%d",&(*e1).t);
	variacaovel(&(*e1).V);
	
}

int main(void){
	struct experimento e1;
	valores(&e1);
	printf("distancia: %d\n", e1.s);
	printf("aceleração: %d\n", e1.a);
	printf("tempo: %d\n", e1.t);
	printf("velocidade inicial: %d\n" ,e1.V.vi);
	printf("velocidade final: %d\n" ,e1.V.vf);
	printf("variação da velocidade: %d\n" ,e1.V.v);
    	
	return 0;
}
