#include <cassert>
#include <cstdio>
#include <cstring>

int string_to_num(const char *src) {
    int num = 0;
    int sign = 1;
    int i = 0;

    // Check for the sign
    if (src[0] == '-') {
        sign = -1;
        i++;
    }

    // Convert each character to the corresponding integer value
    for (; src[i] != '\0'; i++) {
        num = num * 10 + (src[i] - '0');
    }

    return num * sign;
}

int main() {
    assert(string_to_num("12345") == 12345);
    assert(string_to_num("-12345") == -12345);
    assert(string_to_num("0") == 0);
    assert(string_to_num("000123") == 123);
    printf("All tests passed!\n");
    return 0;
}
