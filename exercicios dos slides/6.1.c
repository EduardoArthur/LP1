#include <stdio.h>

void preenche(int v[4],int L){
    int i;
    for(i=0;i<L;i++){
        printf("digite v %d \n", i+1);
	    scanf("%d", &v[i]);
    }
}
int media(int v[4],int L){
    float x=0;
    int i;
    for(i=0;i<L;i++){
       x=x+v[i];
    }
    x=x/L;
    return x;      
}
int main(void){
    int v[4];
    preenche(v,4);
    printf("%d",media(v,4));
    	
    return 0;
}
