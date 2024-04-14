#include "TxtFile.h"
#include "stdio.h"
#include "stdlib.h"

int TxtFile_Read(const char *file_name, struct TxtFile *out)
{
    FILE *file = fopen(file_name, "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    out->n_lines = 0;
    char line[TXTFILE_LINE_SIZE];
    while (fgets(line, TXTFILE_LINE_SIZE, file))
    {
        out->n_lines++;
    }
    out->lines = malloc(out->n_lines * sizeof(char) * TXTFILE_LINE_SIZE);

    rewind(file);
    for (int i = 0; i < out->n_lines; i++)
    {
        fgets(&out->lines[i * TXTFILE_LINE_SIZE], TXTFILE_LINE_SIZE, file);
        for (int j = 0; j < TXTFILE_LINE_SIZE; j++)
        {
            if (out->lines[i * TXTFILE_LINE_SIZE + j] == '\n')
                out->lines[i * TXTFILE_LINE_SIZE + j] = '\0';
        }
    }
    fclose(file);
}

char *TxtFile_GetLine(struct TxtFile *txtFile, int line_num)
{
    return &txtFile->lines[line_num * TXTFILE_LINE_SIZE];
}

int TxtFile_Print(struct TxtFile *to_print)
{
    for (int i = 0; i < to_print->n_lines; i++)
    {
        printf("%s", TxtFile_GetLine(to_print, i));
    }
    printf("\n");
}

int TxtFile_Free(struct TxtFile *to_free)
{
    free(to_free->lines);
}