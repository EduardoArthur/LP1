#include <stdio.h>

int main(void){
  int x;
  printf("velocidade atual:\n");
  scanf("%d", &x);
  int y=x*1.6;
  if (y>80){
    printf("acelere:\n");
    }
  else if (y>100){
    printf("desacelere\n");
    }
  else{
    printf("mantenha\n");
    }
  return 0;
  }
