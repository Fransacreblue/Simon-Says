#include <stdint.h>

uint8_t _rand_state = 0;

#define srand(seed) (_rand_state = seed)
/* A linear congruential pseudo-random number generator is of the form:
 * Xn+1 = (aXn + c) mod m
 * A LCG will have a full period for all seed values if:
 * 1. m and c are relatively prime
 * 2. a-1 is divisible by all prime factors of m
 * 3. a-1 is divisible by 4 if m is divisible by 4
 * For this generator, m = 2^8 = 256. Thus a and c must be odd numbers and a
 * must additionally be a multiple of four plus one.
 * Use the most significant bits of the output when restricting it.
 */
#define rand() (_rand_state = ((_rand_state * 137) + 59))
