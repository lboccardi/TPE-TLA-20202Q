#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){ int first[4]={1,2,3,4}; int second[4]={5,6,7,8}; int i=0; printf("Before swap: ");
while(i < 4){printf("%d ",first[i]);
i=i+1; }
i=0; while(i < 4){printf("%d ",second[i]);
i=i+1; }
i=0; printf("\n After swap: ");
while(i < 4){int aux=first[i]; first[i]=second[i]; second[i]=aux; i=i+1; }
i=0; while(i < 4){printf("%d ",first[i]);
i=i+1; }
i=0; while(i < 4){printf("%d ",second[i]);
i=i+1; }
printf("\n");
      }
