#include <stdio.h>

int eh_primo (int x){
  int i;
  if (x<=1){
    return 0;
    }
  else{
    for (i=2;i<=x/2;i++){
      if (x%i==0){
        return 0;
        }
      }
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
