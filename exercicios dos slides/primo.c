#include <stdio.h>

int eh_primo (int x){
  int d=0;
  int i;
  for (i=1;i<=x;i++){
    if (x%i==0){
      d=d+1;
    }
  }
  if (d>2){
    return 0;
  }
  else{
    return 1;
    }
  }

int main(void){
  int y;
  printf("digite um numero:\n");
  scanf("%d", &y);
  int X= eh_primo(y);
  if (X==0){
    printf("não é primo\n");
    }
  else{
  printf("é primo\n");
    }
    return 0;
  }


