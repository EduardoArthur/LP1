#include <stdio.h>
#include <string.h>

int main(void){
  int w=0;
  int l=100;
  int v;
  int e;
  int d;
  int r;
  char t[20], wn[20], ln[20];
  while (t!="end"){
    printf("nome do time:\n");
    scanf("%s", t);
    if (t!="end"){
      printf("numero de vitorias:\n");
      scanf("%d", &v);
      printf("numero de empates:\n");
      scanf("%d", &e);
      printf("numero de derrotas:\n");
      scanf("%d", &d);
      r=(v*3)+(e*1)+(d*0);
      if (r>w){
        w=r;
        strcpy(wn, t);
        }
      if (r<l){
        l=r;
        strcpy(ln, t);
        }
      }
    }
  printf("primeiro lugar:%s\n",wn);
  printf("ultimo lugar:%s\n",ln);
  return 0;
  }
