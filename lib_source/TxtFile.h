#ifndef _TxtFile_H_
#define _TxtFile_H_

#define TXTFILE_LINE_SIZE 1024

struct TxtFile
{
    char *lines; // each line a max of TXTFILE_LINE_SIZE
    int n_lines;
};

int TxtFile_Read(const char *file_name, struct TxtFile *out);
char *TxtFile_GetLine(struct TxtFile *txtFile, int line_num);
int TxtFile_Print(struct TxtFile *to_print);
int TxtFile_Free(struct TxtFile *to_free);

#endif