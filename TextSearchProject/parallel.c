/*Parallel Brute Force Method
 *COMP 137 Project
 *
 *Compile: gcc -o parallel parallel.c
 *Run: ./parallel <text to find> <file to search> <number of threads>
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAXCHAR 100

//METHODS
void* threadWork(void* rank);
void searchingString(char textSearch[], char fileContents[]);

//VARIABLES
pthread_t* thread_handles;
int numThreads;


int main(int argc, const char * argv[]) {
    
    if(argc != 4){
        printf("Invalid number of arguments: <executable> <text to find> <file to search> <number of threads>\n");
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
    int i = 0;
    char currChar;
    while((currChar = fgetc(fp)) != EOF){
        fileContents[i] = currChar;
        i++;
    }
    for(i = 0;i < MAXCHAR; i++){
        printf("%c",fileContents[i]);
    }
    printf("\n");
    
    numThreads = strtol(argv[3], NULL, 10);
    printf("Now using %d threads.\n",numThreads);
    
    long currThread;
    //creating array of thread handles
    thread_handles = malloc(numThreads*sizeof(pthread_t));
    
    //telling each particular thread to execute the function threadWork
    for (currThread = 0; currThread < numThreads; currThread++){
        pthread_create(&thread_handles[numThreads], NULL, threadWork, (void*) currThread);
    }
    
    /* print a message from the main thread */
    printf("Hello from the main thread\n");
    
    // waiting for threads to finish
    for (currThread = 0; currThread < numThreads; currThread++){
        pthread_join(thread_handles[currThread], NULL);
    }
    free(thread_handles);
    return 0;
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
        }
    }
}

void* threadWork(void* rank) {
    long my_rank = (long) rank;
    printf("Hello from thread %ld of %d\n", my_rank, numThreads);
    return NULL;
}

