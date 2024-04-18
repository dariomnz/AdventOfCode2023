#include <string.h>
#include <stdlib.h>

int str_in_str(const char *haystack, const char *needle)
{
    if (haystack == NULL || needle == NULL)
    {
        return -1;
    }

    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);

    if (needle_len > haystack_len)
    {
        return -1;
    }

    for (size_t i = 0; i <= haystack_len - needle_len; ++i)
    {
        if (strncmp(&haystack[i], needle, needle_len) == 0)
        {
            return 0;
        }
    }

    return -1;
}

int checkStr(const char *str, const char *to_check)
{
    if (strlen(str) < strlen(to_check))
        return -1;
    for (int i = 0; i < strlen(to_check); i++)
    {
        if (to_check[i] != str[i])
        {
            return -1;
        }
    }
    return 0;
}

int isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    return -1;
}

int getDigits(const char *str)
{
    int num = 0;
    char buffer[20] = {0};
    if (isDigit(str[0]) != 0)
        return -1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isDigit(str[i]) == 0)
        {
            buffer[i] = str[i];
        }
        else
        {
            break;
        }
    }
    num = atoi(buffer);
    if (num == 0)
        return -1;
    return num;
}

char getNumDigits(const char *str)
{
    int num = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isDigit(str[i]) == 0)
        {
            num++;
        }
        else
        {
            return num;
        }
    }
    return num;
}

char getNumber(const char *str)
{
    // printf("%s\n", str);
    if (checkStr(str, "zero") == 0 || str[0] == '0')
        return '0';
    if (checkStr(str, "one") == 0 || str[0] == '1')
        return '1';
    if (checkStr(str, "two") == 0 || str[0] == '2')
        return '2';
    if (checkStr(str, "three") == 0 || str[0] == '3')
        return '3';
    if (checkStr(str, "four") == 0 || str[0] == '4')
        return '4';
    if (checkStr(str, "five") == 0 || str[0] == '5')
        return '5';
    if (checkStr(str, "six") == 0 || str[0] == '6')
        return '6';
    if (checkStr(str, "seven") == 0 || str[0] == '7')
        return '7';
    if (checkStr(str, "eight") == 0 || str[0] == '8')
        return '8';
    if (checkStr(str, "nine") == 0 || str[0] == '9')
        return '9';
    return -1; // Si no se encuentra ninguna palabra correspondiente
}

int findChar(const char *str, char c)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
            return i;
    }
    return -1;
}

int subStr(char *out_str, const char *str, int start, int end)
{
    memmove(out_str, &str[start], end - start);
}

// copy the first split to out_str, and move str to the new position
// return if it can split
int splitStr(char *out_str, char **str, char spliter)
{
    int pos = findChar(*str, spliter);
    if (pos == -1)
        return -1;
    subStr(out_str, *str, 0, pos);
    *str += (pos + 1) * sizeof(char);
    return 0;
}