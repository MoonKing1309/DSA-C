#include <stdio.h>

void shellSort(int array[], int n) {

  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int length,i;
    printf("Enter length:\t");
    scanf("%d",&length);
    int data[length];
   for(i=0;i<length;i++)
    {
        printf("Enter a[%d]:\t",i);
        scanf("%d",&data[i]);
        printf("");
    }
  int size = sizeof(data) / sizeof(data[0]);
  shellSort(data, size);
  printf("Sorted array: \n");
  printArray(data, size);
}