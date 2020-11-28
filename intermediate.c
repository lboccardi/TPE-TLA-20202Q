#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int welcome(){
printf("Puede reordenar hasta 50 caracteres \n Escriba algo para ordenar:\n");
return 0;}

int main(){ welcome(); char w[50];
fgets(w,50,stdin);
 int l=strlen(w); int i=1; int j; int k; int m; char temp; char tempj; char tempk; while(i < l){j=0; m=l-i; while(j < m){k=j+1; tempj=w[j]; tempj=w[k]; if(tempj > tempk){temp=w[j]; char aux=w[k]; w[j]=aux; w[k]=temp; }
j=j+1;  }
i=i+1;  }
return 0;  }
