/*COMP 137 Project
 *
 *Compile: gcc -o main main.c
 *Run: ./main <text to find> <file to search>
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PUT METHOD HEADERS HERE

#define MAXCHAR 100
#define MAXFILECHAR 1000000
int shiftTable[MAXCHAR];

int main(int argc, const char * argv[]) {
    if(argc != 3){
        printf("Invalid number of arguments: <executable> <text to find> <file to search>\n");
        return 0;
    }
    char textSearch[MAXCHAR];
    char fileName[MAXCHAR];
    char path[MAXCHAR] = "./testFiles/";
    char fileContents[MAXCHAR];
    int index = 0;
    //char fileText[MAXCHAR];
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
    printf("HELLO\n");
    char currChar;
    while((currChar = fgetc(fp)) != EOF){
        printf("%c", currChar);
        fileContents[i] = currChar;
        i++;
    }
    printf("BOB\n");
    for(i=0;i<MAXCHAR;i++){
        printf("%c",fileContents[i]);
    }
    //createShiftTable(textSearch);
    //horspool(
}
    /*createShiftTable(textSearch);
    
void createShiftTable(char textSearch[]){
    int textSearchLength = strlen(textSearch);
    int i=0;
    int j=0;
    for(i=0;i<MAXCHAR;i++){
        shiftTable[i] = textSearchLength;
    }
    for(j=0;j<textSearchLength-1;j++){
        shiftTable[textSearch[j]]=textSearchLength-1-j;
    }
}

int horspool(
*/
    
    
    
    
    
    
    
    
    
    
    
    
