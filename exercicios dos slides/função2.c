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
int todos_os_primos (int x){
  int i;
  for(i=1;i<=x;i++){
    int X=eh_primo(i);
    if (X==1){
      printf("%d\n", i);
      }
    }
  }
  
int main(void){
  int y;
  printf("digite um numero:\n");
  scanf("%d", &y);
  int X= todos_os_primos(y);
  return 0;
  }
