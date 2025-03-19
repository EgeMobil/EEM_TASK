#include <stdio.h>
#include <stdlib.h>

void joinArray(int *Aaddress , int Asize, int *Baddress , int Bsize , int **newaddress , int *newsize){
*newsize = Asize + Bsize ;
*newaddress = (int *)malloc((*newsize) * sizeof(int));

if (*newaddress == NULL){
  printf("HATA!");
  exit(1);
}

  // for first array
  for(int i = 0 ; i < Asize ; i++){
    (*newaddress)[i] = Aaddress[i];
  }

  // for second array
  for(int i = 0 ; i < Bsize ; i++){
    (*newaddress)[Asize + i] = Baddress[i];
  }
}

int main(){
  int Aaddress[] = {1 ,3 ,5 ,7 ,9 };
  int Baddress[] = {2 ,4 ,6 ,8 ,10 };

  int *totalArray = NULL ;
  int totalsize = 0;

  joinArray(Aaddress, 5 , Baddress , 5 , &totalArray , &totalsize);


  printf("Total Array : ");
  for(int i = 0 ; i < totalsize ; i++){
    printf("%d ", totalArray[i]);
  }
  printf("\n");

free(totalArray);

  return 0;
}
