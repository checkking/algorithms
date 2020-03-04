#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int myAtoi(char * str) {
    char *p = str;
    int ans = 0;
    if (str == NULL) {
        return 0;
    }
    int neg = 1;
    while (*p != '\0' && *p == ' ') ++p;
    if (*p == '-') {
        neg = -1;
        ++p;
    }
    if (*p < '0' || *p > '9') {
        return 0;
    }
    while (*p != '\0' && *p >= '0' && *p <= '9') {
        if (neg != -1) {
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (*p - '0') > 7)) {
                return INT_MAX;
            }
        }
        else {
            if (-1 * ans < INT_MIN / 10 || (-1 *ans == INT_MIN / 10 && (*p - '0') > 8)) {
                return INT_MIN;
            }
        }
        ans = ans * 10 + (*p - '0');
        ++p;
    }
    return neg * ans;
}

int main(int argc, char *argv[])
{
   char *s = "  -42";
   printf("%d", myAtoi(s));
   return 0;
}
