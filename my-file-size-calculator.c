#include<stdio.h>

int main(int argc, char **argv){
    // printf("%d",sizeof(char));
    unsigned long   cal_size(FILE *p){
        unsigned long i=0;
        int c = 0;
        while( (c= getc(p)) != EOF){
        if(c != '\n' && c != ' ' && c != '\t' ) i++;
        }
        return i;
    }
    if(argc < 2){
        printf("Usage: please provide a file name\n");
        return -1;
    }
    FILE *fp;
    if( (fp = fopen(argv[1], "r")) != NULL){
        printf("File opened successfully\n");
        unsigned long long size = cal_size(fp);
        printf("%lu bytes",size);
        fclose(fp);
    }
}