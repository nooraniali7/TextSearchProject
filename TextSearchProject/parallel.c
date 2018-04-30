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
#include <time.h>

#define MAXCHAR 1000000

//METHODS
void* threadWork(void* rank);
void searchingString(char textSearch[], char fileContents[]);
int cmpfunc (const void * a, const void * b);
float getTime();

//VARIABLES
pthread_t* thread_handles;
int numThreads;
int indexValForArray = 0;
char fileContents[MAXCHAR];
char textSearch[MAXCHAR];
int indexArray[];
pthread_mutex_t mutex;


int main(int argc, const char * argv[]) {
    float start, finished, elapsed;
    if(argc != 4){
        printf("Invalid number of arguments: <executable> <text to find> <file to search> <number of threads>\n");
        return 0;
    }
    
    char fileName[MAXCHAR];
    char path[MAXCHAR] = "./testFiles/";
    
    FILE *fp;
    strcpy(textSearch,argv[1]);
    strcpy(fileName,argv[2]);
    //printf("%s\n", textSearch);
    strcat(path, fileName);
    //printf("%s\n",path);
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
        //printf("%c",fileContents[i]);
    }
    printf("\n");
    
    numThreads = strtol(argv[3], NULL, 10);
    printf("Now using %d threads.\n",numThreads);
    
    long currThread;
    //creating array of thread handles
    
    
    thread_handles = malloc(numThreads*sizeof(pthread_t));
    start = getTime();
    //telling each particular thread to execute the function threadWork
    for (currThread = 0; currThread < numThreads; currThread++){
        pthread_create(&thread_handles[currThread], NULL, threadWork, (void*) currThread);
    }
    
    /* print a message from the main thread */
    //printf("Hello from the main thread\n");
    
    // waiting for threads to finish
    for (currThread = 0; currThread < numThreads; currThread++){
        pthread_join(thread_handles[currThread], NULL);
    }
    
    finished = getTime();
    elapsed = finished - start;
    
    
    //PRINTING OUT THE INDICES WHERE THE STRING IS FOUND AFTER SORTING
    qsort(indexArray, indexValForArray, sizeof(int), cmpfunc);
    printf("\n");
    printf("The text was found at indices: \n");
    for(i=0;i<indexValForArray;i++){
        printf("%d\n",indexArray[i]);
    }
    free(thread_handles);
    printf("Elapsed Time: %f\n",elapsed);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

float getTime(){
    clock_t t = clock();
    return ((float)t)/CLOCKS_PER_SEC;
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
    long my_index;
    long partitionSize = strlen(fileContents)/numThreads;
    //printf("PARTITION SIZE: %ld\n",partitionSize);
    int i=0;
    int j=0;
    
    //my_index is the beginning of the char array
    //that the thread will get
    
    if(my_rank == 0){
        my_index = partitionSize*my_rank;
    }
    else{
        my_index = partitionSize*my_rank;
    }
    
    long my_last_index = my_index+partitionSize;
    
    
    for(i=my_index;i<=my_last_index;i++){
        for(j=0;j<strlen(textSearch);j++){
            pthread_mutex_lock(&mutex);
            if(fileContents[i+j] != textSearch[j]){
                break;
            }
        }
        if(j==strlen(textSearch)){
            printf("String found at index %d.\n",i);
            indexArray[indexValForArray] = i;
            indexValForArray++;
        }
    }
    
    return NULL;
}
