#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void generate_assembly(const char *source) {
    char *token = strtok((char *)source, " ");
    int register_count = 0;

    while (token != NULL) {
        if (isdigit(token[0])) {
            // For numeric tokens, generate an instruction to load the immediate value into a register
            printf("li x%d, %s\n", register_count, token);
            register_count++;
        } else if (token[0] == '+') {
            // add
            printf("add x%d, x%d, x%d\n", register_count - 2, register_count - 2, register_count - 1);
        } else if (token[0] == '-') {
            // sub
            printf("sub x%d, x%d, x%d\n", register_count - 2, register_count - 2, register_count - 1);
        } else if (token[0] == '*') {
            // mul
            printf("mul x%d, x%d, x%d\n", register_count - 2, register_count - 2, register_count - 1);
        } else if (token[0] == '/') {
            // div
            printf("div x%d, x%d, x%d\n", register_count - 2, register_count - 2, register_count - 1);
        }
        // next token
        token = strtok(NULL, " ");
    }
}

int main() {
    char source[] = "3 + 4 - 2 * 5 / 1";

    generate_assembly(source);

    return 0;
}

