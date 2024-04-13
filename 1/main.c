#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256

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

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char line[LINE_SIZE];
    memset(line, 0, LINE_SIZE);
    char num1;
    char num2;
    int sum = 0;
    while (fgets(line, LINE_SIZE, file))
    {
        char num1 = 'a';
        char num2 = 'a';
        char num[3] = "aa";
        char aux = -1;
        // printf("%s", line);
        for (int i = 0; i < LINE_SIZE; i++)
        {
            aux = getNumber(&line[i]);
            if (aux != -1)
            {
                num1 = aux;
                break;
            }
        }
        // printf("%s", line);
        for (int i = LINE_SIZE - 1; i >= 0; i--)
        {
            aux = getNumber(&line[i]);
            if (aux != -1)
            {
                num2 = aux;
                break;
            }
        }
        num[0] = num1;
        num[1] = num2;
        printf("%d\n", atoi(num));
        sum += atoi(num);
        memset(line, 0, LINE_SIZE);
    }
    printf("Sum: %d\n", sum);
    fclose(file);
    return 0;
}
