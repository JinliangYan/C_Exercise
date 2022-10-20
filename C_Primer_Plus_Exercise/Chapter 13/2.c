#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *new_file;
    FILE *source_file;
    int ch;
    if (argc  < 3){
        fprintf(stderr,"Usage:%s new_file source_pile", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((source_file = fopen(argv[2], "r")) == NULL){
        fprintf(stderr, "Can't open %s.", argv[2]);
        exit(EXIT_FAILURE);
    }
    setvbuf(source_file, NULL, _IOFBF, 4096);
    new_file = fopen(argv[1], "w");
    setvbuf(new_file, NULL, _IOFBF, 4096);
    while ((ch = getc(source_file)) != EOF) {
        putc(ch, new_file);
    }
    fclose(source_file);
    fclose(new_file);
    return 0;
}
