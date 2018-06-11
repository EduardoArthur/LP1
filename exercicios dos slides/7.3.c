#include <stdio.h>
#define L 3
#define C 2
int mat[L][C] = {{0,1}, {3,0}, {0,0}};
int main(void){
	int i,j;
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
