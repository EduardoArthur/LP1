#include <stdio.h>
#include <string.h>
struct experimento{
	float v;
	float vi;
	float a;
	float s;
	float t;
};


/*
adaptar as funçoes para todos os possiveis casos
void torriceli(struct experimento e1){
	v*v=vi*vi+2*a*s
}
void muv2(struct experimento e1){
	s=vi*t+(a*t*t)/2(float)
}
void muv1(struct experimento e1){
	v=vi+a*t
}
void desviopadrão(){}
*/
void tempomedio(struct experimento *e1){
	int n;
	int i;
	float t;
	float somatemp=0;
	printf("Calculo do tempo medio\n");
	printf("quantidade de medidas recolhidas\n");
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		printf("tempo%d \n", i);
		scanf("%f", &t);
		somatemp=somatemp+t;
	}
	(*e1).t=somatemp/n;	
}
void valoresF(struct experimento *e1){
	int x;
	printf("informações fornecidas\n");
	printf("digite 1 para sim e 0 para não\n");
	printf("velocidade final\n");
	scanf("%d", &x);
	if (x==1){
		printf("valor\n");
		scanf("%f",&(*e1).v);
	}
	printf("velocidade inicial\n");
	scanf("%d", &x);
	if (x==1){
		printf("valor\n");
		scanf("%f",&(*e1).vi);
	}
	printf("aceleração\n");
	scanf("%d", &x);
	if (x==1){
		printf("valor\n");
		scanf("%f",&(*e1).a);
	}
	printf("distancia\n");
	scanf("%d", &x);
	if (x==1){
		printf("valor\n");
		scanf("%f",&(*e1).s);
	}
	printf("tempo \n");
	scanf("%d", &x);
	if (x==1){
		printf("valor\n");
		scanf("%f",&(*e1).t);
	}
}
int main(void){
	struct experimento e1;
	int menu;
	printf("selecione o tipo de exercicio\n");
	printf("1 - Exercicios classicos\n");	
	printf("2 - Laboratorio\n");	
	scanf("%d",&menu);
	switch(menu){
		case 1:	
			valoresF(&e1);
		case 2:
			tempomedio(&e1);
			printf("tempo medio %f\n", e1.t);
	}
	

	return 0;
}

/*
	int unidadeS;
	printf("escolha a unidade espacial utilizada\n");
	printf("1 - metro\n");	
	printf("2 - kilometro\n");
	printf("3 - centimetro\n");
	printf("4 - não sei\n");
	switch(unidadeS){
		case 1:
	int unidadeT;
	printf("escolha a unidade temporal utilizada\n");
	printf("1 - segundo\n");	
	printf("2 - hora\n");
	printf("3 - minuto\n");
	printf("4 - não sei\n");
	switch(unidadeS){
		case 1:	
	adicionar unidade desejada ou utilizar a unidade padrão	
*/
