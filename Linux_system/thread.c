#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

/**
 * @file thread.c
 * @brief Implementation of thread management functions.
 * @details This file contains functions to create, join, and manage threads
 *          using the pthread library in C.
 * @author Your Name
 * @date December 8, 2025
 * @version 1.0
 */

 void* thread_func1(void* arg)
{
    char* str = (char*)arg;
    printf("Thread is running with argument: %s\n", str);
    return NULL;
}

void thread_func2(void* arg)
{
    char* str = (char*)arg;
    printf("Thread says: %s\n", str);
}

int main()
{
    pthread_t thread1, thread2;
    char* arg2 = "Hello from thread!";

    // Create first thread
    if(pthread_create(&thread1, NULL, (void* (*)(void*))thread_func1, arg2) != 0)
    {
        perror("Failed to create thread 1");
        return EXIT_FAILURE;
    }

    // Create second thread
    if(pthread_create(&thread2, NULL, (void* (*)(void*))thread_func2, arg2) != 0)
    {
        perror("Failed to create thread 2");
        return EXIT_FAILURE;
    }

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have finished execution.\n");
    return EXIT_SUCCESS;
}