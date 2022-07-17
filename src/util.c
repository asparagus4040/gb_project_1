#include "util.h"

int round(float num) {
    int num2 = 0;
    while(num > 1) {
        num -= 1;
        num2 += 1;
    }
    if (num < 0.5) {
        return num2;
    } else {
        return num2 + 1;
    }
}
