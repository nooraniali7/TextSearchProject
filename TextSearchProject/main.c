//COMP 137 Project

#include <stdio.h>
#include <stdlib.h>

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
    while(fscanf(fp, "%s",currentWord) != EOF){
        printf("%s\n",currentWord);
    }
    printf("\n");
    fclose(fp);
    
    return 0;
}
