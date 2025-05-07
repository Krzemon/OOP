#include <cstdio>

char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
char **cp[] = { c + 3, c + 2, c + 1, c };
char ***cpp = cp;

int main() {
    printf("%s", **++cpp);
    printf("%s", *--*++cpp + 3);
    printf("%s", *cpp[-2] + 3);
    printf("%s", cpp[-1][-1] + 1);

    int i;
    for (i = sizeof(c) / sizeof(*c); i > 0; i--) {
        printf(" %d%s", sizeof(c) / sizeof(*c) - i, *cp[i - 1]);
    }

    return 0;
}
