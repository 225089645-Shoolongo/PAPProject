#ifndef UTILS_H
#define UTILS_H

#define STR_LEN 50

void readLine(char *buf, int size);
int isBlank(const char *str);
void readRequired(const char *prompt, char *buf, int size, const char *fieldName);
int readInt(int *out);
double readNonNegativeDouble(const char *prompt, const char *errMsg);
int containsCaseInsensitive(const char *haystack, const char *needle);

#endif
