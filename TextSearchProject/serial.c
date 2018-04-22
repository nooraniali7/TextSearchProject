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
void createShiftTable(char textSearch[]);
int horspool(char fileContents[], char textSearch[]);

#define MAXCHAR 100

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
    /*for(i=0;i<MAXCHAR;i++){
        printf("%c",fileContents[i]);
    }*/
    createShiftTable(textSearch);
    int position = horspool(fileContents, textSearch);
    
    int textLocation = horspool(fileContents,textSearch);
    if(position>=0){
        printf("The text begins on index %d.\n", position);
    }
    else{
        printf("Sorry, text not found\n");
    }
}
    
void createShiftTable(char textSearch[]){
    int textSearchLength = strlen(textSearch); //m
    int i=0;
    int j=0;
    for(i=0;i<MAXCHAR;i++){
        shiftTable[i] = textSearchLength;
        for(j=0;j<=textSearchLength-1;j++){
            shiftTable[textSearch[j]] = textSearchLength-1-j;
        }
    }
}

int horspool(char fileContents[], char textSearch[]){
    int fileContentsLength = strlen(fileContents); //m
    int textSearchLength = strlen(textSearch); //n
    int i = textSearchLength-1;
    int j=0; //secondary index //k
    while(i<fileContentsLength){
        j=0;
        while((j<textSearchLength) && (textSearch[textSearchLength-1-j]==fileContents[i-j])){
            j++;
        }
        if(j==textSearchLength){
            return(i-textSearchLength+1);
        }
        else{
            i = i+shiftTable[fileContents[i]];
        }
    }
    return -1;
}










