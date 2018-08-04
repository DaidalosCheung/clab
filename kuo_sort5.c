#include <stdio.h>
#include <stdlib.h>

/* Syntaxlly, int* res[] is equivalent to int** res. */
/* int* res[] means pointer to pointer, in this case, each number will
   be assigned to res[i], total for `res_size` numbers. */
void sorted_cards( unsigned int mask, unsigned int* res[], int* res_size ) {
  int si = 0;
  
  size_t size = 5;
  /* int* sorted indicate a 1-D address, no matter with `*size` in malloc */
  unsigned int* sorted = malloc( sizeof( unsigned int ) * size );
  for ( unsigned int* ptr = sorted; ptr < sorted + size; ptr++ ) *ptr = 0;

  for ( int i = 0; i <= 13; i++ ) {
    unsigned int extracted = mask & ( 1 << i );
    if ( extracted ) {
      sorted[ si++ ] = extracted;
    }
  }

  *res = sorted; // 2-D unit * element still uses 1-D pointer?
  *res_size = size;
}

int main( void ) {

  unsigned int r1 = 2048, r2 = 1024, r3 = 8192, r4 = 4, r5 = 4096;

  unsigned int* sorted = NULL;
  int sorted_size = 0;

  // Since `sorted` was decleared as a pointer (int* sorted), the
  // function `sorted_cards` should be passed along with a pointer to
  // pointer:

  sorted_cards( r1 | r2 | r3 | r4 | r5, &sorted, &sorted_size );

  for ( int i = 0; i < sorted_size; i++ ) {
    printf( "[%d] %d\n", i, sorted[ i ] );
  }

  free( sorted );
  sorted = NULL;

  return 0;
}

/* Notes:
unsigned int: normal int take 32 bits, but the first bit
indicate its sign "+ or -", which makes it can store only 31 bits int;
but unsigned int takes whole 32 bits with no sign.
*/
