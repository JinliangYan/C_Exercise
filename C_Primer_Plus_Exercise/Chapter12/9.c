#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WOR_LEN 56

int main(void){
    char ** pt;
    char word[WOR_LEN];
    size_t word_size;
    size_t size;
    printf("How many words do you wish to enter? ");
    scanf("%zu", &size);
    pt = (char **) malloc(size * sizeof(char *));
    printf("Enter %zu words now.\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%s", word);
        word_size = strlen(word) + 1;
        pt[i] = (char *) malloc(sizeof(char) * word_size);
        for (int j = 0; j < word_size; j++) {
            pt[i][j] = word[j];
        }
    }

    printf("Here are your words: \n");
    for (int i = 0; i < size; i++) {
        puts(pt[i]);
    }
    free(pt);
    printf("Done.\n");
    return 0;
}
