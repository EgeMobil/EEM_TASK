#include <stdio.h>

int main() {

  int size;
  while(1){
  printf("Please enter a size: \n");
  if(scanf("%d", &size) !=1){
    while (getchar() != '\n');
  } else{
    char c = getchar();
    
    if(c != '\n'){
      printf("Too many values . Please choose only one. \n ");
      while (getchar() != '\n');
    }else{
      break;
      }
    }
  }

  int arr[size];

  printf("Please enter the numbers to be used :\n ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  int *all = arr + (size - 1);
  printf("inverted state : \n");
  for (int i = 0; i < size; i++) {
    printf("%d ", *all);
    all--;
  }

  printf("\n");

  return 0;
}
