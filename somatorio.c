#include <stdio.h>

int main(void){
  int n;
  printf("digite n:\n");
  scanf("%d", &n);
  int i=1;
  int s=0;
  int x;
  for (x=1;x<=n;x++){
    s=s+(i*i);
    i=i+1;
    }
  printf("somatorio:%d\n",s);
  return 0;
  }
