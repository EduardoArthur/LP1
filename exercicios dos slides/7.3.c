#include"stdio.h"
#define L 10
#define C 10
struct Posicao{
	int x;
	int y;
};
struct personagem{
	int id;
	struct Posicao pos;
	int pts;
};
void leia_posicao(struct Posicao *pos){
	printf("x: ");
	scanf("%d", &(*pos).x);
	printf("y: ");
	scanf("%d", &(*pos).y);
}
void leia_personagem(struct personagem *p){
	printf("ID do personagem:\n");
	scanf("%d", &(*p).id);
	leia_posicao(&(*p).pos);
	(*p).pts = 0;
}

int main (void){
	struct personagem v[10];
	int i;
	int j;
	int mat[L][C]={{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

	for (i=0;i<10;i++){
		leia_personagem(&v[i]);
		}
	for (i=0;i<10;i++){
	printf("ID: %d\n", v[i].id);
        printf("Posição: x=%d y=%d\n", v[i].pos.x, v[i].pos.y);
	mat[v[i].pos.x][v[i].pos.y]=v[i].id;
	}
	//cria matriz
			
	printf("  ");
	for (j=0; j<C; j++){
		printf("%d ",j);
	}
	printf("\n");
	for (i=0; i<L; i++){
		printf("%d ",i);
		for (j=0;j<C;j++){
			int v=mat[i][j];
			if (v==0){
				printf("* ");
			}else{
				printf("%d ",v);
			}
		}
		printf("\n");
	}
	
	return 0;
}
