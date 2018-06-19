#include <stdio.h>
#define L 4
#define C 4
void preenche(int v[L][C]){
    int x;
    int i;
    int j;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            scanf("elementos da matriz:%d\n",&x);
                    v[i][j]=x;
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
    return printf("Media:%f\n", x);      
}
int main(void){
    int v[L][C];
    preenche(v);
    media(v);

    return 0;
}
