#include <stdio.h>
#include <stdlib.h>
void printenc(char *);
int fLen(FILE *);
int isFile(char *);
int main(int argc, char **argv)
{
    char *inText = 0;
    if(argc < 4)
    {
        printf("Format: ccipher <file> <[e]ncrypt or [d]ecrypt> <shift>\n");
        return 0;
    }
    if(isFile(argv[1]) == 0)
    {
        printf("Format: ccipher <file> <[e]ncrypt or [d]ecrypt> <shift>\n");
        return 0;
    }
    char e_or_d = argv[2][0];
    FILE *fp = fopen(argv[1], "r");
    int len = fLen(fp);
    inText = malloc(len + 1);
    signed int shift = atoi(argv[3]);
    if(e_or_d == 'd' || e_or_d == 'D')
    {
        shift *= -1;
    }
    int c = 0;
    int i = 0;
    while((c = getc(fp)) != -1)
    {
        inText[i++] = ((c + shift)%256);
    }
    fclose(fp);
    inText[i] = -1;
    printenc(inText);
    return 0;
}

int fLen(FILE *fp)
{
    int len;
    fseek(fp, 0L, SEEK_END);
    len = ftell(fp);
    rewind(fp);
    return len;
}

int isFile(char *fname)
{
    int retval = 1;
    FILE *fp;
    fp = fopen(fname, "r");
    if(fp == 0) {
            retval = 0;
    }
    if(retval == 1) {
            fclose(fp);
    }
    return retval;
}
void printenc(char *str)
{
    int i = 0;
    while(str[i] != -1)
    {
        putc(str[i++], stdout);
    }
    return;
}
