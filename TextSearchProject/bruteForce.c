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
    int index = 0;
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
    searchingString(textSearch, fileContents);
}

void searchingString(char textSearch[], char fileContents[]){
    int textSearchLength = strlen(textSearch);
    int fileContentsLength = strlen(fileContents);
    int j=0;
    for(int i=0;i<=fileContentsLength-textSearchLength;i++){
        for(j=0;j<textSearchLength;j++){
            if(fileContents[i+j] != textSearch[j]){
                break;
            }
        }
        if(j==textSearchLength){
            printf("String found at index %d.\n",i);
        }
    }
}




/*
 int counter = 0;
 int i=0;
 int j=0;
 for(i=0;i<strlen(fileContents);i++){
 for(j=0;j<strlen(textSearch);j++){
 if(fileContents[i] == textSearch[j]){
 counter++;
 printf("%c, %c\n",fileContents[i],textSearch[j]);
 if(counter == strlen(textSearch)){
 printf("Found String at index %d.\n",i);
 counter = 0;
 }
 }
 }
 }*/





