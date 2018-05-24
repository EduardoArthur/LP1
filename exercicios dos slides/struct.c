#include <stdio.h>
struct experimento{
	int v;
	int vi;
	int a;
	int s;
	int t;
};
void valores(struct experimento *e1){
	printf("velocidade final:\n");
	scanf("%d",&(*e1).v);
	printf("velocidade inicial:\n");
	scanf("%d",&(*e1).vi);
	printf("aceleração:\n");
	scanf("%d",&(*e1).a);
	printf("distancia:\n");
	scanf("%d",&(*e1).s);
	printf("tempo:\n");
	scanf("%d",&(*e1).t);
}
int main(void){
	struct experimento e1;
	e1.v  = 10;
	e1.vi =  0;
	e1.a  = 10;
	e1.s  = 15;
	e1.t  = 20;
	
	printf("velocidade %d, velocidade inicial %d, aceleração %d, distancia %d, tempo %d,\n", e1.v, e1.vi, e1.a, e1.s, e1.t);
	valores(&e1);
	printf("velocidade %d, velocidade inicial %d, aceleração %d, distancia %d, tempo %d,\n", e1.v, e1.vi, e1.a, e1.s, e1.t);
	return 0;
}
