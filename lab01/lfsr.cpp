#include <iostream>
#include "lfsr.h"

// Возвращает бит номер n числа x.
// Предполагается 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {

    return (x & (1 << n)) >> n;

}
// Выставляет значение v в бите номер n
// Предполагается что 0 <= n <= 31 и v равно 0 или 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {

    *x = (*x & ~(1 << n)) | (v << n);

}
// Меняет значение бита номер n на противоположное.
// Предполагается что 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {

    *x ^= (1 << n);

}

void lfsr_calculate(uint16_t *reg) {

    uint16_t first_temp_bit;
    uint16_t second_temp_bit;

    first_temp_bit = get_bit(*reg, 0);
    second_temp_bit = get_bit(*reg, 2);

    first_temp_bit ^= second_temp_bit;
    // now in first_temp_bit 0^2

    second_temp_bit = get_bit(*reg, 3);
    first_temp_bit ^= second_temp_bit;
    // now in first_temp_bit 0^2^3
 
    second_temp_bit = get_bit(*reg, 5);
    first_temp_bit ^= second_temp_bit;
    // now in first_temp_bit 0^2^3^5
 
    *reg >>= 1;
    set_bit((unsigned*)reg, 15, first_temp_bit);

}
