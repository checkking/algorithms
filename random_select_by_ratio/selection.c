#include <stdlib.h>
#include <time.h>
#include "selection.h"

#define mt_random(l, h) (rand() % ((h) - (l) + 1) + (l));
typedef enum { false, true } bool;
static bool sranded = false;

const void* rand_select(InputType* arr, int n) {
    uint16_t all = 0;
    int i = 0;
    uint16_t j = 1;
    uint16_t x = 0;
    if (!sranded) {
        srand((unsigned)time(0));
        sranded = true;
    }
    while (i < n) {
        all += arr[i++].ratio;
    }
    x = mt_random(1, all);
    for (i = 0; i < n; ++i) {
        if (x >= j && x < j + arr[i].ratio) {
            return arr[i].key;
        }
        j += arr[i].ratio;
    }

    return NULL;
}
