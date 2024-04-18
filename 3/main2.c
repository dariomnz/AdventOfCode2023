#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TxtFile.h"
#include "StrUtils.h"

struct gear
{
    int x;
    int y;
    int num;
};

struct gear *gears;
int current_gear_index = 0;

int isPartNumber(struct TxtFile *txtFile, int line_num, int char_num)
{
    char *line = TxtFile_GetLine(txtFile, line_num);
    int numDigits = getNumDigits(&line[char_num]);
    int num = getDigits(&line[char_num]);
    printf("isPartNumber: %s %d %d\n", line, line_num, num);
    int x = char_num, y = line_num, dx, dy;
    // Top line
    for (int i = -1; i < numDigits + 1; i++)
    {
        dx = x + i;
        dy = y - 1;
        if (dy >= 0 && dy < txtFile->n_lines &&
            dx >= 0 && dx < strlen(TxtFile_GetLine(txtFile, dy)))
        {
            char *dline = TxtFile_GetLine(txtFile, dy);
            printf("x:%d y:%d %c\n", dx, dy, dline[dx]);
            if (dline[dx] == '*')
            {
                gears[current_gear_index].x = dx;
                gears[current_gear_index].y = dy;
                gears[current_gear_index].num = num;
                current_gear_index++;
            }
        }
    }
    // Botton line
    for (int i = -1; i < numDigits + 1; i++)
    {
        dx = x + i;
        dy = y + 1;
        if (dy >= 0 && dy < txtFile->n_lines &&
            dx >= 0 && dx < strlen(TxtFile_GetLine(txtFile, dy)))
        {
            char *dline = TxtFile_GetLine(txtFile, dy);
            printf("x:%d y:%d %c\n", dx, dy, dline[dx]);
            if (dline[dx] == '*')
            {
                gears[current_gear_index].x = dx;
                gears[current_gear_index].y = dy;
                gears[current_gear_index].num = num;
                current_gear_index++;
            }
        }
    }
    // center left
    dx = x + -1;
    dy = y;
    if (dy >= 0 && dy < txtFile->n_lines &&
        dx >= 0 && dx < strlen(TxtFile_GetLine(txtFile, dy)))
    {
        char *dline = TxtFile_GetLine(txtFile, dy);
        printf("x:%d y:%d %c\n", dx, dy, dline[dx]);
        if (dline[dx] == '*')
        {
            gears[current_gear_index].x = dx;
            gears[current_gear_index].y = dy;
            gears[current_gear_index].num = num;
            current_gear_index++;
        }
    }
    // center rigt
    dx = x + numDigits;
    dy = y;
    if (dy >= 0 && dy < txtFile->n_lines &&
        dx >= 0 && dx < strlen(TxtFile_GetLine(txtFile, dy)))
    {
        char *dline = TxtFile_GetLine(txtFile, dy);
        printf("x:%d y:%d %c\n", dx, dy, dline[dx]);
        if (dline[dx] == '*')
        {
            gears[current_gear_index].x = dx;
            gears[current_gear_index].y = dy;
            gears[current_gear_index].num = num;
            current_gear_index++;
        }
    }

    return -1;
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
    TxtFile_Print(&txtFile);
    int total_sum = 0;
    char buffer[TXTFILE_LINE_SIZE] = {0};
    int count_gear = 0;
    for (int i = 0; i < txtFile.n_lines; i++)
    {
        char *line = TxtFile_GetLine(&txtFile, i);
        for (int j = 0; j < strlen(line); j++)
        {
            if (line[j] == '*')
            {
                count_gear += 2;
            }
        }
    }
    printf("count_gear: %d\n", count_gear);
    gears = malloc(sizeof(struct gear) * count_gear);
    memset(gears, 0, sizeof(struct gear) * count_gear);
    for (int i = 0; i < txtFile.n_lines; i++)
    {
        int res = 0;
        int numDigits = 0;
        char *line = TxtFile_GetLine(&txtFile, i);
        for (int j = 0; j < strlen(line); j++)
        {
            if (isDigit(line[j]) == 0)
            {
                numDigits = getNumDigits(&line[j]);
                printf("line: %s\n", line);
                printf("numDigits: %i\n", numDigits);
                printf("getDigits: %d\n", getDigits(&line[j]));
                int part_number = isPartNumber(&txtFile, i, j);
                if (part_number != -1)
                {
                    printf("isPartNumber True %d\n", part_number);
                    total_sum += part_number;
                }
                j += numDigits;
            }
        }
    }
    for (int i = 0; i < current_gear_index; i++)
    {
        for (int j = 0; j < current_gear_index; j++)
        {
            if (i == j)
                continue;
            if (gears[i].x == gears[j].x && gears[i].y == gears[j].y)
            {
                printf("gear1: x:%d y:%d num:%d\n", gears[i].x, gears[i].y, gears[i].num);
                printf("gear2: x:%d y:%d num:%d\n", gears[j].x, gears[j].y, gears[j].num);
                printf("mult: %d\n", gears[i].num * gears[j].num);
                total_sum += gears[i].num * gears[j].num;
            }
        }
    }

    TxtFile_Free(&txtFile);
    free(gears);
    printf("Total_sum: %d\n", total_sum/2);
    return 0;
}
