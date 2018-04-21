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

//#define MAXCHAR 10000

int main(int argc, const char * argv[]) {
    if(argc != 3){
        printf("Invalid number of arguments: <executable> <text to find> <file to search>\n");
        return 0;
    }
    char textSearch[100];
    char fileName[100];
    char path[100] = "./testFiles/";
    char currentWord[100];
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
    
    
    
    
    
    
    
    
    
    
    // while(fscanf(fp, "%s",currentWord) != EOF){
//     //strcasecmp compares two strings to see if they are the same and disregards their case
//         if(strcasecmp(textSearch,currentWord) == 0){
//             printf("%s at index %d\n",currentWord, index);
//         }
//         index++;
//     }
//     printf("\n");
    fclose(fp);
    
    return 0;
}
