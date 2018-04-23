/*Parallel Brute Force Method
 *COMP 137 Project
 *
 *Compile: gcc -o main main.c
 *Run: ./main <text to find> <file to search>
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Brute Force Method
 *COMP 137 Project
 *
 *Compile: gcc -o main main.c
 *Run: ./main <text to find> <file to search>
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 100

void searchingString(char textSearch[], char fileContents[]);

int main(int argc, const char * argv[]) {
    if(argc != 3){
        printf("Invalid number of arguments: <executable> <text to find> <file to search>\n");
        return 0;
    }
    char textSearch[MAXCHAR];
    char fileName[MAXCHAR];
    char path[MAXCHAR] = "./testFiles/";
    char fileContents[MAXCHAR];
    FILE *fp;
    
    strcpy(textSearch,argv[1]);
    strcpy(fileName,argv[2]);
    printf("%s\n", textSearch);
    strcat(path, fileName);
    printf("%s\n",path);
    if((fp = fopen(path, "r")) == NULL){
        printf("Sorry, there was an error opening the file!\n");
        return 0;
    }
    int i=0;
    char currChar;
    while((currChar = fgetc(fp)) != EOF){
        fileContents[i] = currChar;
        i++;
    }
    printf("LOOK HERE\n");
    for(i=0;i<MAXCHAR;i++){
        printf("%c",fileContents[i]);
    }
    printf("\n");
}

