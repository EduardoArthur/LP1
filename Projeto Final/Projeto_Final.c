#include <stdio.h>
#include <string.h>
#include <math.h>
#define L 11
#define C 11
struct experimento{
	float v;
	float vi;
	float a;
	float s;
	float t;
};


void torriceli(struct experimento *e1){
	//v²=vi²+2*a*s
	if (e1->v  == -1000){
		e1->v=sqrt(pow(e1->vi,2)+(2*(e1->a)*(e1->s)));
	}
	if (e1->vi == -1000){
		e1->vi=sqrt(pow(e1->v,2)-(2*(e1->a)*(e1->s)));
	}
	if (e1->a  == -1000){
		e1->a=(pow(e1->v,2)-pow(e1->vi,2))/(2*e1->s);
	}
	if (e1->s  == -1000){
		e1->s=(pow(e1->v,2)-pow(e1->vi,2))/(2*e1->a);
	}
}
void muv1(struct experimento *e1){
	//v=vi+a*t
	if(e1->v  == -1000){
		e1->v=(e1->vi)+(e1->a)*(e1->t);
	}
	if(e1->vi == -1000){
		e1->vi=(e1->v)-(e1->a)*(e1->t);
	}
	if(e1->a  == -1000){
		e1->a=((e1->v)-(e1->vi))/(e1->t);
	}
	if(e1->t  == -1000){
		e1->t=((e1->v)-(e1->vi))/(e1->a);
	}
}
void muv2(struct experimento *e1){
	//s=vi*t+(a*t²)/2
	if (e1->s  == -1000){
		e1->s=e1->vi*e1->t+(((e1->a)*pow(e1->t,2))/2);
	}
	if (e1->vi == -1000){
		e1->vi=(e1->s/e1->t)-(((e1->a)*pow(e1->t,2))/2);
	}
	if (e1->a  == -1000){
		e1->a=((2*e1->s)/pow(e1->t,2))-((2*e1->vi)/(e1->t));
	}
	if (e1->t  == -1000){
		//devido a dificuldade em isolar o t o programa realiza torriceli(v²=vi²+2*a*s)
		// para encontrar o v e depois, com o v obtido
		// ele usa muv1(t=v-vi/a) para achar o tempo.
		e1->v=sqrt(pow(e1->vi,2)+(2*(e1->a)*(e1->s)));
		e1->t=((e1->v)-(e1->vi))/(e1->a);
	}
}

/*
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
		printf("valor da velocidade final:\n");
		scanf("%f",&(*e1).v);
	}
	printf("velocidade inicial\n");
	scanf("%d", &x);
	if (x==1){
		printf("valor da velocidade inicial:\n");
		scanf("%f",&(*e1).vi);
	}
	printf("aceleração\n");
	scanf("%d", &x);
	if (x==1){
		printf("valor da aceleração:\n");
		scanf("%f",&(*e1).a);
	}
	printf("deslocamento\n");
	scanf("%d", &x);
	if (x==1){
		printf("valor do deslocamento:\n");
		scanf("%f",&(*e1).s);
	}
	printf("tempo \n");
	scanf("%d", &x);
	if (x==1){
		printf("valor do tempo:\n");
		scanf("%f",&(*e1).t);
	}
}

void gera_grafico(struct experimento *e1){	
	int mat[L][C]={{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
	int i,j;
	int grafico;
	printf("selecione o tipo de grafico:\n");
	printf("1 - movimento uniforme / variado ∆S X ∆T\n");	
	printf("2 - movimento uniformemente variado ∆V X ∆T\n");
	printf("3 - ∆V X ∆T\n");
	//pensar em casos negativos *comum em ∆a X ∆T	
	scanf("%d",&grafico);
	printf("\n");
	switch(grafico){
		case 1:
			if(e1->a==0){
				if(e1->t == -1000){
					for(i=0;i<L;i++){
						//colocar possibilidade de erro do usuario caso troque v com vi
						j=i*e1->v;
						if(j<L){
							mat[i][j]=1;
						}
					}
					}else{
						for(i=0;i<L;i++){
							j=i*e1->v;
							if(j<=e1->t){
								if(j<L){
									mat[i][j]=1;
								}
						}
					}
				}
			}else{
				if(e1->t == -1000){
					for(i=0;i<L;i++){
						j=(i*e1->vi)+(e1->a*pow(i,2))/2;
						if(j<L){
							mat[i][j]=1;
						}
					}
					}else{
						for(i=0;i<L;i++){
							j=(i*e1->vi)+(e1->a*pow(i,2))/2;
							if(j<=e1->t){
								if(j<L){
									mat[i][j]=1;
								}
						}
					}
				}
			
	}

	//imprime o grafico
	printf("∆S");
	printf("\n");
	for (i=L-1; i>0; i--){
		printf("%d ",i);
		for (j=1;j<C;j++){
			int v=mat[j][i];
			if (v==0){
				printf(". ");
			}else{
				printf("● ");
			}
		}
		printf("\n");
	}
	printf("  ");
	
	for (j=1; j<C; j++){
		printf("%d ",j);
	}
	printf("∆T");
	printf("\n");
	
}

int main(void){
	struct experimento e1;
	e1.v  = -1000;
	e1.vi = -1000;
	e1.a  = -1000;
	e1.s  = -1000;
	e1.t  = -1000;
	int menu;
	printf("selecione o tipo de exercicio\n");
	printf("1 - Exercicios classicos\n");	
	printf("2 - Laboratorio\n");	
	scanf("%d",&menu);
	printf("\n");
	switch(menu){
		case 1:	
		//v²=vi²+2*a*s
		//s=vi*t+(a*t²)/2
			valoresF(&e1);
			if( e1->v != -1000 && e1->vi != -1000 && e1->a != -1000 || e1->v != -1000 && e1->vi != -1000 && e1->t != -1000 || e1->vi != -1000 && e1->a != -1000 && e1->t != -1000 || e1->v != -1000 && e1->a != -1000 && e1->t != -1000 ){
				muv1(&e1);
			}
			if( e1->s != -1000 && e1->vi != -1000 && e1->a != -1000 || e1->s != -1000 && e1->vi != -1000 && e1->t != -1000 || e1->s != -1000 && e1->a != -1000 && e1->t != -1000 || e1->vi != -1000 && e1->a != -1000 && e1->t != -1000 ){
				muv2(&e1);
			}
			if( e1->v != -1000 && e1->vi != -1000 && e1->a != -1000 || e1->v != -1000 && e1->vi != -1000 && e1->s != -1000 || e1->vi != -1000 && e1->a != -1000 && e1->s != -1000 || e1->v != -1000 && e1->a != -1000 && e1->s != -1000 ){
				torriceli(&e1);
			}
			
			gera_grafico(&e1);
			break;
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
