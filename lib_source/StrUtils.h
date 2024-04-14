#ifndef _StrUtils_H_
#define _StrUtils_H_

int str_in_str(const char *haystack, const char *needle);
int checkStr(const char *str, const char *to_check);

char getNumber(const char *str);
int findChar(const char *str, char c);

int subStr(char *out_str, const char *str, int start, int end);

int splitStr(char *out_str, char **str, char spliter);
#endif