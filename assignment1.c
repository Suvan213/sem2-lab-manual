#include<stdio.h>
#include<stdlib.h>
int calculateMinOperations(int fruits[], int numBuckets) {
  int operations = 0;
  for (int i = 0; i < numBuckets; i++) {
    if (fruits[i] % 2 == 0) {
      operations++; 
    } else {
      operations++;    
      int doubledFruits = fruits[i] * 2;
      if (doubledFruits < (fruits[i] + (numBuckets - i - 1))) {
        operations++;  
      } else {
          operations += (numBuckets - i - 1);
      }
    }
  }
  return operations;
}

int main() {
  int numBuckets;
  printf("Enter the number of buckets: ");
  scanf("%d", &numBuckets);
  int fruits[numBuckets];
  printf("Enter the target number of fruits for each bucket respectively:\n");
  for (int i = 0; i < numBuckets; i++) {
    scanf("%d", &fruits[i]);
  }
  int minOperations = calculateMinOperations(fruits, numBuckets);
  printf("Minimum number of operations: %d\n", minOperations);
 return 0;
}
