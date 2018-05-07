#include <stdio.h>

int main(void){
  int x;
  int y;
  printf("escreva um numero:\n");
  scanf("%d", &x);
  printf("escreva outro numero\n");
  scanf("%d", &y);
  if (x>y){
    printf("maior numero %d\n", x);
    }
  else{
    printf("maior numero %d\n", y);
    }
  return 0;
  }
