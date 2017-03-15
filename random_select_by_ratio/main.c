#include <stdio.h>
#include "selection.h"

#define MAXITERATIVE 10000

int main(int argc, char** argv) {
    char* key = NULL;
    char key1[] = "key1";
    uint16_t ratio1 = 1;

    char key2[] = "key2";
    uint16_t ratio2 = 2;

    char key3[] = "key3";
    uint16_t ratio3 = 3;

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    int i = 0;

    Item it[3] = {
        {
            (void *)key1,
            ratio1
        },
        {
            (void *)key2,
            ratio2
        },
        {
            (void *)key3,
            ratio3
        }
    };

    for (; i < MAXITERATIVE; ++i) {
        key = (char *)rand_select(it, 3);
        if (strcmp(key, key1) == 0) {
            cnt1++;
        } else if (strcmp(key, key2) == 0) {
            cnt2++;
        } else if (strcmp(key, key3) == 0) {
            cnt3++;
        }
    }
    
    printf("%s\t%f\n", key1, (float)cnt1 / MAXITERATIVE);
    printf("%s\t%f\n", key2, (float)cnt2 / MAXITERATIVE);
    printf("%s\t%f\n", key3, (float)cnt3 / MAXITERATIVE);

    return 0;
}
