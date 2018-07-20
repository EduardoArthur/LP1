#include <stdio.h>

struct Ponto{
	int x;
	int y;
};

void preenchePt(struct Ponto* pt){
	printf("Digite o ponto x: ");
	scanf("%d", &(*pt).x);
	printf("Digite o ponto y: ");
	scanf("%d", &(*pt).y);
}

void preencheVet(struct Ponto vetPt[10]){
    int i;
    for(i=0;i<10;i++){
        struct Ponto pt;
        preenchePt(&pt);
        vetPt[i] = pt;
    }
}

int pontodistante(struct Ponto vetPt[10], int x){
	int i;
	int j;
	int cont=0;
	int maior[2]={0,0};
	for(i=0;i<10;i++){
		if (vetPt[i].x + vetPt[i].y > cont){
			cont=vetPt[i].x + vetPt[i].y;
			maior[0]=vetPt[i].x;
			maior[1]=vetPt[i].y;
		}
	}
	if (x==0){
		return maior[0];
	}else{
		return maior[1];
	}
}
int main(void){
	struct Ponto vetPt[10];
	preencheVet(vetPt);
	int i;
	for(i=0;i<10;i++){
        	printf("Ponto %d (x,y): (%d,%d)\n", i+1, vetPt[i].x, vetPt[i].y);
	}
	int maior[2];
	maior[0]=pontodistante(vetPt , 0);
	maior[1]=pontodistante(vetPt , 1);
	printf("x:%d y:%d \n",maior[0],maior[1]);
	return 0;
}
