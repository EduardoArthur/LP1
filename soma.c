#include <stdio.h>

int main(void){
  int x;
  printf("digite um numero ou 0 para encerrar:\n");
  scanf("%d", &x);
  int y=0;
  y=y+x;
  while (x!=0){
    printf("digite um numero:\n");
    scanf("%d", &x);
    y=y+x;
    }
  printf("soma:%d\n",y);
  return 0;
  }
