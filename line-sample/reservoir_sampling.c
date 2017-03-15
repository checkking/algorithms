/**
 * @file reservoir_sampling.c
 * @desc An implementation of Reservoir sampling, you can use it to sample file lines
 * @author checkking <checkking at foxmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define LINESIZE 1024

void usage(int argc, char*argv[]);
bool malloc2(char ***a, int m, int n);
void free2(char **a, int n);
int sample(int k, int i);

void usage(int argc, char*argv[]) {
    (void)argc;
    printf("Usage: %s file_path n\n", argv[0]);
}

bool malloc2(char ***a, int m, int n) {
    int i = 0;
    if (a == NULL || m <= 0 || n <= 0) {
        return false;
    }
    *a = (char **)malloc(sizeof(char *) * m);
    if (*a == NULL) {
        return false;
    }
    while (i < m) {
        (*a)[i++] = (char *)malloc(sizeof(char) * n);
        if ((*a)[i - 1] == NULL) {
            free2(*a, i);
            return false;
        }
    }

    return true;
}

void free2(char **a, int n) {
    if (a == NULL) {
        return;
    }
    while (n > 0) {
        if (a[--n]) {
            free(a[n]);
            a[n] = NULL;
        }
    }
}

int sample(int k, int i) {
    int a = -1;
    if (k >= i) {
        return -1;
    }
    a = rand() % i;
    return  a < k ? a : -1;
}

void output(char** result, int m) {
    int i = 0;
    if (result == NULL) {
        return;
    }
    for (; i < m; ++i) {
        if (result[i] == NULL) {
            continue;
        }
        printf("%s", result[i]);
    }
 }

int main(int argc, char *argv[]) {
    FILE *fh = NULL;
    char buf[LINESIZE];
    int k = 0;
    int i = 0;
    char **result = NULL;
    time_t t;
    int a = -1;
    srand((unsigned) time(&t));
    if (argc != 3) {
        usage(argc, argv);
        return 1;
    }
    k = atoi(argv[2]);
    if (k < 0) {
        usage(argc, argv);
        return 1;
    }
    fh = fopen(argv[1], "r");
    if (fh == NULL) {
        perror("Failed to open file");
        return 1;
    }

    if (!malloc2(&result, k, LINESIZE)) {
        perror("Failed to malloc.");
        return 1;
    }
    while (fgets(buf, sizeof(buf), fh) != NULL) {
        if (i < k) {
            memcpy(result[i], buf, LINESIZE);
        } else {
            if ((a = sample(k, i + 1)) != -1) {
                memcpy(result[a], buf, LINESIZE);
            }
        }
        ++i;
        memset(buf, 0, sizeof(buf));
    }
    fclose(fh);
    output(result, k);
    return 0;
}

