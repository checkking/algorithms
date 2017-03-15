#ifndef CHECKKING_ALGORITHMS_SELECTION_H
#define CHECKKING_ALGORITHMS_SELECTION_H
#include <stdint.h>

typedef struct InputType {
    const void* key;
    uint16_t ratio;
    void* data;
} InputType;


/**
 * @param InputType array
 * @return select key or null
 */
const void* rand_select(InputType* arr, int n);
#endif
