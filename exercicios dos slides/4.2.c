#include <stdio.h>
#define L 4
#define C 4
void preenche(int v[L][C]){
    int i;
    int j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
	    printf("digite v %d %d\n", i, j);
	    scanf("%d", &v[i][j]);
        }
    }
}
int media(int v[L][C]){
    float x=0;
    int i;
    int j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            x=x+v[i][j];
        }
    }
    x=x/(L*C);
    return x;      
}
int main(void){
    int v[L][C];
    preenche(v);
    media(v);
    	
    return 0;
}
