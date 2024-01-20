#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void generate_assembly(const char *source) {
    const char *token = strtok((char *)source, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            printf("addi x0, x0, %s\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char source[] = "3 + 4";

    generate_assembly(source);

    return 0;
}

