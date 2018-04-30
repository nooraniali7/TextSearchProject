/*Brute Force Method
 *COMP 137 Project
 *
 *Compile: gcc -o bruteForce bruteForce.c
 *Run: ./bruteForce <text to find> <file to search>
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXCHAR 1000000

//METHODS
void searchingString(char textSearch[], char fileContents[]);
float getTime();

//VARIABLES
int indexArray[];
int indexValForArray = 0;


int main(int argc, const char * argv[]) {
    float start, finished, elapsed;
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
    printf("\n");
    start = getTime();
    searchingString(textSearch, fileContents);
    finished = getTime();
    elapsed = finished - start;
    printf("The text was found at indices: \n");
    for(i=0;i<indexValForArray;i++){
        printf("%d\n",indexArray[i]);
    }
    printf("Elapsed Time: %f\n",elapsed);
}

void searchingString(char textSearch[], char fileContents[]){
    long textSearchLength = strlen(textSearch);
    long fileContentsLength = strlen(fileContents);
    int j=0;
    for(int i=0;i<=fileContentsLength-textSearchLength;i++){
        for(j=0;j<textSearchLength;j++){
            if(fileContents[i+j] != textSearch[j]){
                break;
            }
        }
        if(j==textSearchLength){
            printf("String found at index %d.\n",i);
            indexArray[indexValForArray] = i;
            indexValForArray++;
        }
    }
}

float getTime(){
    clock_t t = clock();
    return ((float)t)/CLOCKS_PER_SEC;
}







