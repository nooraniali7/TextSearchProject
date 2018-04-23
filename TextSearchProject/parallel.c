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
#include <pthread.h>

#define MAXCHAR 100

int thread_count;

void* threadWork(void* rank);
void searchingString(char textSearch[], char fileContents[]);


int main(int argc, const char * argv[]) {
    
    if(argc != 4){
        printf("Invalid number of arguments: <executable> <text to find> <file to search> <# of threads>\n");
        return 0;
    }
    thread_count = strtol(argv[3], NULL, 10);

    
    // thread initialization
    long thread;
    pthread_t* thread_handles;
    
    // creating array of thread handles
    thread_handles = malloc(thread_count*sizeof(pthread_t));
    
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
    
    // starting threads, each w/ a unique rank
    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_create(&thread_handles[thread], NULL, threadWork, (void*) thread);
    }
    
    printf("\nHELLO FROM THE MAIN THREAD\n");
    
    // waiting for threads to finish
    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_join(thread_handles[thread], NULL);
    }
    
    
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
    printf("\nHello from thread %ld of %d", my_rank, thread_count);
    return NULL;
}

