#include <stdio.h>
#include <string.h>
#include <math.h>
#define L 11
#define C 11

struct deslocamento{
	float si;
	float sf;
};

struct experimento{
	unsigned char flags[5];
	float v;
	float vi;
	float a;
	float s;
	float t;
	struct deslocamento d1;
};


void torriceli(struct experimento *e1){
	//v²=vi²+2*a*s
	if (e1->flags[0]  == 0){
		e1->v=sqrt(pow(e1->vi,2)+(2*(e1->a)*(e1->s)));
		e1->flags[0]  = 1;
	}
	if (e1->flags[1]  == 0){
		e1->vi=sqrt(pow(e1->v,2)-(2*(e1->a)*(e1->s)));
		e1->flags[1]  = 1;
	}
	if (e1->flags[2]  == 0){
		e1->a=(pow(e1->v,2)-pow(e1->vi,2))/(2*e1->s);
		e1->flags[2]  = 1;
	}
	if (e1->flags[3]  == 0){
		e1->s=(pow(e1->v,2)-pow(e1->vi,2))/(2*e1->a);
		e1->flags[3]  = 1;
	}
}
void muv1(struct experimento *e1){
	//v=vi+a*t
	if(e1->flags[0]  == 0){
		e1->v=(e1->vi)+(e1->a)*(e1->t);
		e1->flags[0]  = 1;
	}
	if(e1->flags[1]  == 0){
		e1->vi=(e1->v)-(e1->a)*(e1->t);
		e1->flags[1]  = 1;
	}
	if(e1->flags[2]  == 0){
		e1->a=((e1->v)-(e1->vi))/(e1->t);
		e1->flags[2]  = 1;
	}
	if(e1->flags[4]  == 0 ){
		if(e1->a != 0){
			e1->t=((e1->v)-(e1->vi))/(e1->a);
			e1->flags[4]  = 1;
		}
	}
}
void muv2(struct experimento *e1){
	//s=vi*t+(a*t²)/2
	if (e1->flags[3]  == 0){
		e1->s=e1->vi*e1->t+(((e1->a)*pow(e1->t,2))/2);
		e1->flags[3]  = 1;
	}
	if (e1->flags[1]  == 0){
		e1->vi=(e1->s/e1->t)-(((e1->a)*pow(e1->t,2))/2);
		e1->flags[1]  = 1;
	}
	if (e1->flags[2]  == 0){
		e1->a=((2*e1->s)/pow(e1->t,2))-((2*e1->vi)/(e1->t));
		e1->flags[2]  = 1;
	}
	if (e1->flags[4]  == 0){
		if(e1->a == 0){
			e1->t =(e1->s)/(e1->v);
			e1->flags[4]  = 1;
		}else{
			//devido a dificuldade em isolar o t o programa realiza torriceli(v²=vi²+2*a*s)
			// para encontrar o v e depois, com o v obtido
			// ele usa muv1(t=v-vi/a) para achar o tempo.
			e1->v=sqrt(pow(e1->vi,2)+(2*(e1->a)*(e1->s)));
			e1->t=((e1->v)-(e1->vi))/(e1->a);
			e1->flags[4]  = 1;
		}
	}

}

/*
float desviopadrão(int x[],int n,float m ){ /*vetor com todas as medidas, tamanho do vetor e media dos valores * /
int i;
float s=0;
for(i=0;i<=n;i++){
	s=pow((x[i]-m),2)+s;
}
dp=sqrt(s/n)
return dp;
}
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
		printf("tempo: %d \n", i);
		scanf("%f", &t);
		somatemp=somatemp+t;
	}
	(*e1).t=somatemp/n;	
}

void valoresF(struct experimento *e1 , struct deslocamento *d1){
	char x;
	char r = 'y';
	printf("informações fornecidas\n");
	printf("digite y para sim e n para não\n");
	printf("possui a velocidade final?\n");
	scanf("%c", &x);
	scanf("%c", &x);
	x = tolower(x);
	
	if (x == r){
		e1->flags[0] = 1;
		printf("valor da velocidade final:\n");
		scanf("%f",&(*e1).v);
	}
	printf("possui a velocidade inicial?\n");
	scanf("%c", &x);
	scanf("%c", &x);
	x = tolower(x);
	if (x == r){
		e1->flags[1] = 1;
		printf("valor da velocidade inicial:\n");
		scanf("%f",&(*e1).vi);
	}
	printf("possui a aceleração?\n");
	scanf("%c", &x);
	scanf("%c", &x);
	x = tolower(x);
	if(x == r){
		e1->flags[2] = 1;
		printf("valor da aceleração:\n");
		scanf("%f",&(*e1).a);
	}
	printf("possui o deslocamento?\n");
	scanf("%c", &x);
	scanf("%c", &x);
	x = tolower(x);
	if (x == r){
		e1->flags[3] = 1;
		printf("Possui referencia de ponto inicial?(caso seja diferente de zero):\n");
		scanf("%c", &x);
		scanf("%c", &x);
		x = tolower(x);
		if(x == r){
			printf("valor da posição inicial:\n");
			scanf("%f" ,&(*d1).si);
			printf("valor da posição final:\n");
			scanf("%f" ,&(*d1).sf);
			e1->s = d1->sf - d1->si;
		}else{
		printf("valor do deslocamento:\n");
		scanf("%f",&(*e1).s);
		d1->sf=e1->s;
		}
	}
	printf("possui o tempo? \n");
	scanf("%c", &x);
	scanf("%c", &x);
	x = tolower(x);
	if (x == r){
		e1->flags[4] = 1;
		printf("valor do tempo:\n");
		scanf("%f",&(*e1).t);
	}
	scanf("%c", &x);
}


void gera_grafico(struct experimento *e1, struct deslocamento *d1){	
	int mat[L][C]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}};
	int matN[L][C]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}};
	int i,j;
	int aux=0;
	int grafico;
	printf("selecione o tipo de grafico:\n");
	printf("1 - movimento uniforme / variado ∆S X ∆T\n");	
	printf("2 - movimento uniformemente variado ∆V X ∆T\n");
	printf("3 - ∆A X ∆T\n");
	scanf("%d",&grafico);
	printf("\n");
	switch(grafico){
		case 1:
			for(i=0;i<L;i++){
				j=(d1->si)+(i*e1->vi)+(e1->a*pow(i,2))/2;
				if(j>=0){
					if((j<L)&&(i<=e1->t)){
						mat[i][j]=1;
					}
					
				}else{
					j=j*(-1);
					if((j<L)&&(i<=e1->t)){
						matN[i][j]=1;
						aux=1;
					}
					
				}
			}
			
			//imprime o grafico
			printf("∆S");
			printf("\n");
			for (i=L-1; i>0; i--){
				if(i>9){
					printf("%d ",i);
				}else{
					printf(" %d ",i);
				}
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
			printf(" 0 ");
	
			for (j=1; j<C; j++){
				printf("%d ",j);
			}
			printf("∆T");
			printf("\n");
			if(aux==1){
				for (i=1; i<L; i++){
					if(i>9){
						printf("%d ",i);
					}else{
						printf("-%d ",i);
					}
					for (j=1;j<C;j++){
						int v=matN[j][i];
						if (v==0){
							printf(". ");
						}else{
							printf("● ");
						}
					}
					printf("\n");
				
				}
			}
			
			break;
		case 2:
			for(i=0;i<L;i++){
				j=(e1->vi)+(e1->a)*i;
				if(j>=0){
					if((j<L)&&(i<=e1->t)){
						mat[i][j]=1;
					}
				}else{
					j=j*(-1);
					if((j<L)&&(i<=e1->t)){
						matN[i][j]=1;
						aux=1;
					}
				}
			}
	
			//imprime o grafico
			printf("∆V");
			printf("\n");
			for (i=L-1; i>0; i--){
				if(i>9){
					printf("%d ",i);
				}else{
					printf(" %d ",i);
				}
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
			printf(" 0 ");
			for (j=1; j<C; j++){
				printf("%d ",j);
			}
			printf("∆T");
			printf("\n");
			if(aux == 1){
				for (i=1; i<L; i++){
					if(i>9){
						printf("%d ",i);
					}else{
						printf("-%d ",i);
					}
					for (j=1;j<C;j++){
						int v=matN[j][i];
						if (v==0){
							printf(". ");
						}else{
							printf("● ");
						}
					}
					printf("\n");
				
				}
			}
			break;
		case 3:
			if( (e1->a) > 0){
				for(i=0;i<L;i++){
					j=e1->a;
					if((j<L)&&(i<=e1->t)){
						mat[i][j]=1;
					}
				}
			}else{
				for(i=0;i<L;i++){
					j=(e1->a)*(-1);
					if((j<L)&&(i<=e1->t)){
						matN[i][j]=1;
					}
				}
			}
			//imprime o grafico
			printf("∆A");
			printf("\n");
			for (i=L-1; i>0; i--){
				if(i>9){
					printf("%d ",i);
				}else{
					printf(" %d ",i);
				}
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
			printf(" 0 ");
			for (j=1; j<C; j++){
				printf("%d ",j);
			}
			printf("∆T");
			printf("\n");
			for (i=1; i<L; i++){
				if(i>9){
					printf("%d ",i);
				}else{
					printf("-%d ",i);
				}
				for (j=1;j<C;j++){
					int v=matN[j][i];
					if (v==0){
						printf(". ");
					}else{
						printf("● ");
					}
				}
				printf("\n");
			}

	}
}

int main(void){
	struct deslocamento d1;
	d1.si = 0;
	struct experimento e1;
	e1.flags[0]  = 0;
	e1.flags[1]  = 0;
	e1.flags[2]  = 0;
	e1.flags[3]  = 0;
	e1.flags[4]  = 0;
	int menu;
	int novo;
	int salvar;
	printf("selecione o tipo de exercicio\n");
	printf("1 - Exercicios classicos\n");	
	printf("2 - Laboratorio\n");	
	scanf("%d",&menu);
	printf("\n");
	switch(menu){
		case 1:
			printf("1 - Novo experimento\n");
			printf("2 - Carregar experimento\n");	
			scanf("%d",&novo);
			switch(novo){
				case 1:
					valoresF(&e1,&d1);
					if( (e1.flags[0] == 1 && e1.flags[1]  == 1 && e1.flags[2]  == 1) || (e1.flags[0] == 1 && e1.flags[1]  == 1 && e1.flags[4]  == 1) || (e1.flags[1]  == 1 && e1.flags[2]  == 1 && e1.flags[4]  == 1) || (e1.flags[0] == 1 && e1.flags[2]  == 1 && e1.flags[4]  == 1) ){
						muv1(&e1);
					}
					if( (e1.flags[3]  == 1 && e1.flags[1]  == 1 && e1.flags[2]  == 1) || (e1.flags[3]  == 1 && e1.flags[1]  == 1 && e1.flags[4]  == 1) || (e1.flags[3]  == 1 && e1.flags[2]  == 1 && e1.flags[4]  == 1) || (e1.flags[1]  == 1 && e1.flags[2]  == 1 && e1.flags[4]  == 1) ){
						muv2(&e1);
					}
					if( (e1.flags[0]  == 1 && e1.flags[1]  == 1 && e1.flags[2]  == 1) || (e1.flags[0] == 1 && e1.flags[1]  == 1 && e1.flags[3]  == 1) || (e1.flags[1]  == 1 && e1.flags[2]  == 1 && e1.flags[3]  == 1) || (e1.flags[0] == 1 && e1.flags[2]  == 1 && e1.flags[3]  == 1) ){
						torriceli(&e1);
					}
					if( (e1.flags[3]  == 1 && e1.flags[1]  == 1 && e1.flags[2]  == 1) || (e1.flags[3]  == 1 && e1.flags[1]  == 1 && e1.flags[4]  == 1) || (e1.flags[3]  == 1 && e1.flags[2]  == 1 && e1.flags[4]  == 1) || (e1.flags[1]  == 1 && e1.flags[2]  == 1 && e1.flags[4]  == 1) ){
						muv2(&e1);
					}
					if( (e1.flags[0] == 1 && e1.flags[1]  == 1 && e1.flags[2]  == 1) || (e1.flags[0] == 1 && e1.flags[1]  == 1 && e1.flags[4]  == 1) || (e1.flags[1]  == 1 && e1.flags[2]  == 1 && e1.flags[4]  == 1) || (e1.flags[0] == 1 && e1.flags[2]  == 1 && e1.flags[4]  == 1) ){
						muv1(&e1);
					}
					printf("1 - Salvar experimento\n");
					printf("2 - Não salvar\n");	
					scanf("%d",&salvar);
					switch(salvar){
						case 1:
							{
							FILE* f = fopen ("salva_info.bin" , "wb");
							fwrite(&e1, sizeof(struct experimento), 1, f);
							fwrite(&d1, sizeof(struct deslocamento), 1, f);
							fclose(f);
							}
							break;
						case 2:
							break;
					}
					break;
				case 2:
					{
					FILE* f = fopen("salva_info.bin", "rb");
					fread(&e1, sizeof(struct experimento), 1, f);
					fread(&d1, sizeof(struct deslocamento), 1, f);
					fclose(f);
					}
					break;
				}
						
			printf("velocidade final: %f\n", e1.v);
			printf("velocidade inicial: %f\n", e1.vi);
			printf("aceleração: %f\n", e1.a);
			printf("deslocamento: %f\n", e1.s);
			printf("tempo: %f\n", e1.t);
			
			gera_grafico(&e1,&d1);
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
