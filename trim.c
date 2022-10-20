#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#include <trim.h>
 
size_t maxlen(char **strings, size_t len)
{
    unsigned int i;
    size_t max = 0;
    for (i = 0; i < len; i++) {
        if (strlen(strings[i]) > max) {
            max = strlen(strings[i]);
        }
    }
    return max;
}
 
int main(void)
{
    char *strings[] = {"", " ", "  " "test", " test", "test ", " test ",
        "  test", "test  ", "  test  "};
    const size_t n = sizeof(strings) / sizeof(char *);
    unsigned int i;
    char *str = malloc(maxlen(strings, n) + 1);
    for (i = 0; i < n; i++) {
        strcpy(str, strings[i]);
        trim(str, NULL);
        printf("%s\n", str);
    }
    free(str);
    return 0;
}
