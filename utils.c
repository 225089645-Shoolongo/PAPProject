#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include "utils.h"

static void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Reads one line of input safely. Discards any overflow beyond the buffer
// so leftover characters never leak into the next prompt.
void readLine(char *buf, int size) {
    if (fgets(buf, size, stdin) == NULL) {
        printf("\nInput closed. Exiting program.\n");
        exit(0);
    }
    if (strchr(buf, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    removeNewline(buf);
}

// Returns 1 if the string is empty or contains only whitespace
int isBlank(const char *str) {
    for (; *str; str++) {
        if (!isspace((unsigned char)*str)) return 0;
    }
    return 1;
}

// Keeps asking until the user enters a non-blank value
void readRequired(const char *prompt, char *buf, int size, const char *fieldName) {
    while (1) {
        printf("%s", prompt);
        readLine(buf, size);
        if (!isBlank(buf)) break;
        printf("Error: %s cannot be empty.\n", fieldName);
    }
}

// Reads a whole integer. Rejects letters, decimals and trailing junk (e.g. "5abc").
// Returns 1 on success, 0 on invalid input.
int readInt(int *out) {
    char buf[STR_LEN];
    char *end;
    readLine(buf, STR_LEN);

    long v = strtol(buf, &end, 10);
    while (isspace((unsigned char)*end)) end++;

    if (end == buf || *end != '\0' || v < INT_MIN || v > INT_MAX) {
        return 0;
    }
    *out = (int)v;
    return 1;
}

// Reads a non-negative number. Rejects letters, trailing junk (e.g. "5000abc"),
// negative values, and nan/inf.
double readNonNegativeDouble(const char *prompt, const char *errMsg) {
    char buf[STR_LEN];
    char *end;

    while (1) {
        printf("%s", prompt);
        readLine(buf, STR_LEN);

        double v = strtod(buf, &end);
        while (isspace((unsigned char)*end)) end++;

        if (end != buf && *end == '\0' && isfinite(v) && v >= 0) {
            return v;
        }
        printf("%s\n", errMsg);
    }
}

// Portable case-insensitive substring search (replaces non-standard strcasestr)
int containsCaseInsensitive(const char *haystack, const char *needle) {
    if (!*needle) return 1;
    for (; *haystack; haystack++) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && (tolower((unsigned char)*h) == tolower((unsigned char)*n))) {
            h++;
            n++;
        }
        if (!*n) return 1;
    }
    return 0;
}
