// program for calulating the sum of an array using multithreading

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

const int size = 100;
int array[100];
int arraySum = 0;

pthread_mutex_t mutexLock = PTHREAD_MUTEX_INITIALIZER;

void sumCalculator(void *args);

// structure to pass arguments to the target function of threads
typedef struct
{
    int startIndex;
    int size;
    int *arr;
} ThreadArgs;

void sumCalculator(void *args)
{
    // casting the type to ThreadArgs
    ThreadArgs *arg = (ThreadArgs *)args;
    int startIndex = arg->startIndex;
    int size = arg->size;
    int *arr = arg->arr;

    int temp = 0;
    for (int i = startIndex; i < startIndex + size; i++)
    {
        temp = temp + arr[i];
    }
    pthread_mutex_lock(&mutexLock);
    arraySum = arraySum + temp;
    printf("updated the sum to %d\n ", arraySum);
    pthread_mutex_unlock(&mutexLock);

}
    int main()
    {

for (int i=0;i<100;i++){
    array[i] = i;
}

        pthread_t thread_id[4];
        
        // creating the required arguments to pass into the thread functions

        ThreadArgs argsArr[4];
        int threadZone = size/4;
        for (int i=0;i<4;i++)
        {
            argsArr[i].startIndex = threadZone * i;
            argsArr[i].size = threadZone;
            argsArr[i].arr = &array;
            pthread_create(&thread_id[i], NULL, sumCalculator, (void *)&argsArr[i] );

            
        }  
    pthread_join(thread_id[0],NULL);

    pthread_join(thread_id[1],NULL);
    pthread_join(thread_id[2],NULL);
    pthread_join(thread_id[3],NULL);

    printf("final Value of Sum is : %d\n",arraySum);

    exit(EXIT_SUCCESS);
        
        



    

    return 0;
}