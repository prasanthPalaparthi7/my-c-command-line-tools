#include<stdio.h>
#include<stdlib.h>
//----------------------------------------------------------------
// show contents of a file
//----------------------------------------------------------------
int main(int argc, char *argv[]){

    FILE *fp;
    void print_data_to_screen(FILE *,FILE *);
    // printf("%d",argc);
    if(argc == 1){
        printf("Usage: mycat filename\n");
        printf("no filename specified");
        return 1;
    }
    else if( argc < 3 ){
        if( (fp = fopen(*++argv, "r")) != NULL ){
            print_data_to_screen(fp,stdout);
            fclose(fp);
        }
        else{
            printf("Can't open file %s\n", argv[1]);
            return 1;
        }
    }
}

void print_data_to_screen(FILE *file,FILE *screen){
    int i ;
    while( (i = getc(file))  != EOF) putc(i,screen);
}