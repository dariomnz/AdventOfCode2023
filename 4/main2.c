#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TxtFile.h"
#include "StrUtils.h"

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
    char buffer_win[TXTFILE_LINE_SIZE];
    char buffer_num[TXTFILE_LINE_SIZE];
    char buffer[TXTFILE_LINE_SIZE];
    int total_sum = 0;
    int *array_result = malloc(txtFile.n_lines * sizeof(int));
    
    for (int i = 0; i < txtFile.n_lines; i++)
    {
        array_result[i] = 1;
    }
    for (int i = 0; i < txtFile.n_lines; i++)
    {
        int res = 0;
        char *line = TxtFile_GetLine(&txtFile, i);
        memset(buffer_win, 0, TXTFILE_LINE_SIZE);
        splitStr(buffer_win, &line, ':');
        memset(buffer_win, 0, TXTFILE_LINE_SIZE);
        splitStr(buffer_win, &line, '|');
        memset(buffer_num, 0, TXTFILE_LINE_SIZE);
        strcpy(buffer_num, line);
        // printf("nums1: %s\n", buffer_win);
        // printf("nums2: %s\n", buffer_num);
        char *aux_buffer_win = &buffer_win[0];
        int count_win_num = 0;
        while (res == 0)
        {
            memset(buffer, 0, TXTFILE_LINE_SIZE);
            res = splitStr(buffer, &aux_buffer_win, ' ');
            if (res == 0 && atoi(buffer))
            {
                // printf("num: %d\n", atoi(buffer));
                count_win_num++;
            }
        }
        if (atoi(aux_buffer_win))
        {
            // printf("num: %d\n", atoi(aux_buffer_win));
            count_win_num++;
        }
        // printf("Count_win_num:%d\n", count_win_num);
        int *win_nums = malloc(count_win_num * sizeof(int));
        aux_buffer_win = &buffer_win[0];
        printf("%s\n", aux_buffer_win);
        int index_win_num = 0;
        res = 0;
        while (res == 0)
        {
            memset(buffer, 0, TXTFILE_LINE_SIZE);
            res = splitStr(buffer, &aux_buffer_win, ' ');
            if (res == 0 && atoi(buffer))
            {
                // printf("num: %d\n", atoi(buffer));
                win_nums[index_win_num++] = atoi(buffer);
            }
        }
        if (atoi(aux_buffer_win))
        {
            // printf("num: %d\n", atoi(aux_buffer_win));
            win_nums[index_win_num++] = atoi(aux_buffer_win);
        }
        for (int j = 0; j < count_win_num; j++)
        {
            // printf("Win_num %d: %d\n", j, win_nums[j]);
        }
        char *aux_buffer_num = &buffer_num[0];
        int count_num_num = 0;
        res = 0;
        while (res == 0)
        {
            memset(buffer, 0, TXTFILE_LINE_SIZE);
            res = splitStr(buffer, &aux_buffer_num, ' ');
            if (res == 0 && atoi(buffer))
            {
                // printf("num: %d\n", atoi(buffer));
                count_num_num++;
            }
        }
        if (atoi(aux_buffer_num))
        {
            // printf("num: %d\n", atoi(aux_buffer_num));
            count_num_num++;
        }
        // printf("Count_num_num:%d\n", count_num_num);
        int *num_nums = malloc(count_num_num * sizeof(int));
        aux_buffer_num = &buffer_num[0];
        printf("%s\n", aux_buffer_num);
        int index_num_num = 0;
        res = 0;
        while (res == 0)
        {
            memset(buffer, 0, TXTFILE_LINE_SIZE);
            res = splitStr(buffer, &aux_buffer_num, ' ');
            if (res == 0 && atoi(buffer))
            {
                // printf("num: %d\n", atoi(buffer));
                num_nums[index_num_num++] = atoi(buffer);
            }
        }
        if (atoi(aux_buffer_num))
        {
            // printf("num: %d\n", atoi(aux_buffer_num));
            num_nums[index_num_num++] = atoi(aux_buffer_num);
        }
        for (int j = 0; j < count_num_num; j++)
        {
            // printf("Num_num %d: %d\n", j, num_nums[j]);
        }

        int result = 0;
        for (int j = 0; j < count_win_num; j++)
        {
            for (int k = 0; k < count_num_num; k++)
            {
                if (win_nums[j] == num_nums[k])
                {
                    result += 1;
                }
            }
        }
        printf("Result round %d: %d\n", i, result);
        // total_sum += result;
        for (int j = 0; j < result; j++)
        {
            array_result[1+i+j] +=array_result[i];
        }
        
        free(win_nums);
        free(num_nums);
    }
    printf("Total_sum: %d\n", total_sum);
    for (int i = 0; i < txtFile.n_lines; i++)
    {
        total_sum += array_result[i];
        printf("Total_sum: %d array_result[%d]=%d\n", total_sum,i,array_result[i]);
    }

    free(array_result);
    TxtFile_Free(&txtFile);
    printf("Total_sum: %d\n", total_sum);
    return 0;
}
