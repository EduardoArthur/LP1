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
int todos_os_primos (int x){
  int i;
  for(i=1;i<=x;i++){
    if (eh_primo(i)!=0){
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
