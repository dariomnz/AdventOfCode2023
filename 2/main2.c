#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TxtFile.h"
#include "StrUtils.h"

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

int sum_index = 0;
int max_red = 1;
int max_green = 1;
int max_blue = 1;
int mult_color = 0;

int getColor(char *line)
{
    int res_red = str_in_str(line, "red");
    int res_green = str_in_str(line, "green");
    int res_blue = str_in_str(line, "blue");
    int res = 0;
    char buffer[TXTFILE_LINE_SIZE] = {0};
    if (res_red == 0)
    {
        res = splitStr(buffer, &line, 'r');
        if (res == 0)
        {
            res_red = atoi(buffer);
            printf("Red: %d\n", res_red);
            if (max_red < res_red)
                max_red = res_red;
        }
    }
    if (res_green == 0)
    {
        res = splitStr(buffer, &line, 'g');
        if (res == 0)
        {
            res_green = atoi(buffer);
            printf("Green: %d\n", res_green);
            if (max_green < res_green)
                max_green = res_green;
        }
    }
    if (res_blue == 0)
    {
        res = splitStr(buffer, &line, 'b');
        if (res == 0)
        {
            res_blue = atoi(buffer);
            printf("Blue: %d\n", res_blue);
            if (max_blue < res_blue)
                max_blue = res_blue;
        }
    }
    if (res_red <= MAX_RED && res_green <= MAX_GREEN && res_blue <= MAX_BLUE)
        return 0;

    return -1;
}

int splitColor(char *line)
{
    char buffer[TXTFILE_LINE_SIZE] = {0};
    int res = 0;
    int res_color = 0;
    while (res == 0)
    {
        memset(buffer, 0, TXTFILE_LINE_SIZE);
        res = splitStr(buffer, &line, ',');
        if (res == 0)
        {
            printf("%s\n", buffer);
            res_color = getColor(buffer);
            // if (res_color == -1)
            //     return -1;
        }
    }
    printf("%s\n", line);
    res_color = getColor(line);
    return res_color;
}

int splitLine(char *line)
{
    printf("Line: %s\n", line);
    char buffer[TXTFILE_LINE_SIZE] = {0};
    int res = 0;
    int res_color = 0;
    max_red = 1;
    max_green = 1;
    max_blue = 1;
    splitStr(buffer, &line, ':');
    while (res == 0)
    {
        memset(buffer, 0, TXTFILE_LINE_SIZE);
        res = splitStr(buffer, &line, ';');
        if (res == 0)
        {
            printf("%s\n", buffer);
            res_color = splitColor(buffer);
            // if (res_color == -1)
            //     return -1;
        }
    }
    printf("%s\n", line);
    res_color = splitColor(line);
    printf("Max_red: %d Max_green: %d Max_blue: %d\n", max_red, max_green, max_blue);
    mult_color += max_red * max_green * max_blue;
    return res_color;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    struct TxtFile txtFile = {0};
    TxtFile_Read(argv[1], &txtFile);
    // TxtFile_Print(&txtFile);
    char buffer[TXTFILE_LINE_SIZE] = {0};
    char buffer2[TXTFILE_LINE_SIZE] = {0};
    for (int i = 0; i < txtFile.n_lines; i++)
    {
        int res = 0;
        char *line = TxtFile_GetLine(&txtFile, i);
        if (splitLine(line) == 0)
        {
            sum_index += i + 1;
        }
    }
    printf("Sum_index: %d\n", sum_index);
    printf("Mult_color: %d\n", mult_color);
    TxtFile_Free(&txtFile);

    return 0;
}
