#include <stdio.h>
#include <stdlib.h>

void sorted_cards( unsigned int result, unsigned int* num[], unsigned int* num_size) {
  int j = 0;

  size_t size = 5;
  unsigned int* sorted = malloc( sizeof( unsigned int ) * size );
  for ( unsigned int* ptr = sorted; ptr < sorted + size; ptr++ ) *ptr = 0;

  for ( int i = 0; i <= 13; i++ ) {
    unsigned int extracted = result & (1<<i);
    if ( extracted != 0 ) {
      num[j++] = extracted; // [1]
    }
  }

  *num = sorted;
  *num_size = size;
}

int main(void) {

  unsigned int r1 = 2048, r2 = 8, r3 = 1024, r4 = 2, r5 = 8192;

  unsigned int* sorted = NULL;
  unsigned int sorted_size = 0;

  sorted_cards( r1 | r2 | r3 | r4 | r5, &sorted, &sorted_size );

  for(int i = 5; i > 0 ; i--) { // [2]
    printf( "[%d] = %d\n", i, sorted[i] );
  }

  free( sorted );
  sorted = NULL;

  return 0;
}
