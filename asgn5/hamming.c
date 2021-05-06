#include <stdio.h>

uint8_t ham_encode(BitMatrix *G, uint8_t msg);

HAM_STATUS ham_decode(BitMatrix *Ht, uint8_t code, uint8_t *msg);

