#include <stdio.h>
#include <stdlib.h>

int double(int n){
  return n*2;
}

int main(){
  int i;
  
  printF("Hello World");
  scanf("%d",&i);
  printf("i: %d",i);

  printf("double: %d",double(i));
  return 0;
}
