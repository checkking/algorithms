#include <stdio.h>
#include <assert.h>

void swap(char a[], int len, int i, int j) {
    char tmp = a[i];
    assert(i <= j);
    a[i] = a[j];
    a[j] = tmp;
}

void print(char a[], int len) {
    assert(len > 0);
    int i = 0;
    printf("%c", a[0]);
    for (i = 1; i < len; ++i) {
        printf(",%c", a[i]);
    }
    printf("\n");
}

void perm(char a[], int len, int begin, int end) {
    int i = begin;
    assert(len > 0 && begin <= end && end - begin <= len);
    if (begin == end) {
        print(a, len);
        return;
    }
    for (; i <= end; ++i) {
        swap(a, len, begin, i);
        perm(a, len, begin + 1, end);
        swap(a, len, begin, i);
    }
}

int main(int argc, char** argv) {
    char a[3] = {'a', 'b', 'c'};
    perm(a, 3, 0, 2);
    return 0;
}
