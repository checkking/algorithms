#ifndef CHECKKING_ALGORITHMS_SELECTION_H
#define CHECKKING_ALGORITHMS_SELECTION_H
#include <stdint.h>

typedef struct Item {
    const void* item;
    uint16_t ratio;
} Item;


/**
 * @param Item array
 * @return select key or null
 */
const void* rand_select(Item* arr, int n);
#endif
