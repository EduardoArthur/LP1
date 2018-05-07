#include <stdio.h>

int main(void){
  int x;
  printf("celular em dolar:\n");
  scanf("%d", &x);
  int y=x*3.17;
  if (y<=1000){
    printf("bom negocio:\n");
    }
  else{
    printf("mau negocio:\n");
    }
  return 0;
  }
