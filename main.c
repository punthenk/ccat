#include <stdio.h>
#include <string.h>
#include <stdbool.h>

FILE* get_file(char* path) {
    if (path == NULL) {
        printf("You need specify a valid file path.\n");
        return NULL;
    }

    // Open the file in 'read' mode.
    FILE* fptr = fopen(path, "r");

    if (fptr == NULL) {
        printf("The file could not be opened.\n");
        return NULL;
    }

    return fptr;
}

void print_file_with_line_numbers(FILE* file) {
    int c;
    int line = 1;
    bool on_new_line = true;

    while ((c = fgetc(file)) != EOF) {
        if (on_new_line) {
            printf("%6d  ", line);
            line++;
            on_new_line = false;
        }

        putchar(c);
        if (c == '\n')
            on_new_line = true;
    }
}

void print_file_with_line_numbers_non_blank(FILE* file) {
    int c;
    bool on_new_line = true;
    int line = 1;

    while ((c = fgetc(file)) != EOF) {
        if (on_new_line && c != '\n') {
            printf("%6d  ", line);
            line++;
            on_new_line = false;
        }

        putchar(c);
        if (c == '\n')
            on_new_line = true;
    }
}

void print_file(FILE* file) {
    char c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
}

int main(int argc, char *argv[]) {
    char* fpath = argv[1]; 
    char* param = argv[2];

    FILE* fptr = get_file(fpath);

    if (fptr == NULL)
        return 1;

    if (param != NULL) {
        if (strcmp(param, "-n") == 0) {
            print_file_with_line_numbers(fptr);
            return 0;
        }
        else if (strcmp(param, "-b") == 0) {
            print_file_with_line_numbers_non_blank(fptr);
            return 0;
        }
        else {
            printf("Please specify a valid paramater\n");
            return 1;
        }
    }

    print_file(fptr);

    fclose(fptr);
    return 0;
}
