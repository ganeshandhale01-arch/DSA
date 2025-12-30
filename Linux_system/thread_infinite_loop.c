/**
 * @file thread_infinite_loop_demo.c
 * @brief Demonstration of infinite loops in threads with various control mechanisms.
 * @details Shows how to handle threads with infinite loops using:
 *          1. Detached threads
 *          2. Control flags
 *          3. pthread_cancel()
 * @author Your Name
 * @date December 12, 2025
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

/* ============================================================================
 * Global Control Variables
 * ============================================================================ */

/** @brief Flag to control worker thread execution */
volatile bool keep_running = true;

/** @brief Counter for infinite loop iterations */
volatile int iteration_count = 0;

/* ============================================================================
 * Thread Function Implementations
 * ============================================================================ */

/**
 * @brief Thread with infinite loop - controlled by flag.
 * @param arg Thread argument (description string).
 * @return NULL when loop exits.
 */
void* thread_infinite_controlled(void* arg)
{
    char* name = (char*)arg;
    int local_count = 0;
    
    printf("[%s] Started with controlled infinite loop\n", name);
    
    while(keep_running) {
        printf("[%s] Iteration %d - Still running...\n", name, ++local_count);
        sleep(1);  // Simulate work
    }
    
    printf("[%s] Exiting gracefully after %d iterations\n", name, local_count);
    return (void*)(long)local_count;  // Return iteration count
}

/**
 * @brief Thread with true infinite loop - never returns naturally.
 * @param arg Thread argument (description string).
 * @return Never returns (infinite loop).
 */
void* thread_infinite_uncontrolled(void* arg)
{
    char* name = (char*)arg;
    int count = 0;
    
    printf("[%s] Started with UNCONTROLLED infinite loop\n", name);
    
    // This thread must be cancelled or detached
    while(1) {
        printf("[%s] Forever iteration %d\n", name, ++count);
        iteration_count = count;
        sleep(1);
        
        // Enable cancellation points
        pthread_testcancel();  // Check if thread was cancelled
    }
    
    return NULL;  // Never reached
}

/**
 * @brief Normal thread that completes quickly.
 * @param arg Thread argument.
 * @return NULL after completion.
 */
void* thread_normal(void* arg)
{
    char* name = (char*)arg;
    printf("[%s] Running for 2 seconds...\n", name);
    sleep(2);
    printf("[%s] Completed successfully\n", name);
    return NULL;
}

/**
 * @brief Detached thread with infinite loop - runs independently.
 * @param arg Thread argument.
 * @return NULL (but never actually returns).
 */
void* thread_detached_worker(void* arg)
{
    char* name = (char*)arg;
    int count = 0;
    
    printf("[%s] Detached thread started (runs in background)\n", name);
    
    while(1) {
        printf("[%s] Background work iteration %d\n", name, ++count);
        sleep(2);
        
        if(count >= 3) {
            printf("[%s] Self-terminating after 3 iterations\n", name);
            pthread_exit(NULL);
        }
    }
    
    return NULL;
}

/* ============================================================================
 * Demonstration Functions
 * ============================================================================ */

/**
 * @brief Demo 1: Controlled infinite loop with flag.
 */
void demo_controlled_loop(void)
{
    printf("\n=== DEMO 1: Controlled Infinite Loop ===\n");
    
    pthread_t thread;
    void* retval;
    
    keep_running = true;
    
    pthread_create(&thread, NULL, thread_infinite_controlled, "ControlledThread");
    
    // Let it run for 3 seconds
    printf("[Main] Letting thread run for 3 seconds...\n");
    sleep(3);
    
    // Signal thread to stop
    printf("[Main] Signaling thread to stop...\n");
    keep_running = false;
    
    // Wait for thread to finish
    pthread_join(thread, &retval);
    printf("[Main] Thread finished with %ld iterations\n", (long)retval);
}

/**
 * @brief Demo 2: Uncontrolled infinite loop with pthread_cancel.
 */
void demo_cancel_thread(void)
{
    printf("\n=== DEMO 2: Cancelling Uncontrolled Thread ===\n");
    
    pthread_t thread;
    
    pthread_create(&thread, NULL, thread_infinite_uncontrolled, "CancelTarget");
    
    // Let it run for 3 seconds
    printf("[Main] Letting thread run for 3 seconds...\n");
    sleep(3);
    
    // Cancel the thread
    printf("[Main] Cancelling thread after %d iterations...\n", iteration_count);
    pthread_cancel(thread);
    
    // Wait for cancellation to complete
    pthread_join(thread, NULL);
    printf("[Main] Thread cancelled successfully\n");
}

/**
 * @brief Demo 3: Detached thread runs independently.
 */
void demo_detached_thread(void)
{
    printf("\n=== DEMO 3: Detached Thread (Background Worker) ===\n");
    
    pthread_t thread;
    pthread_attr_t attr;
    
    // Initialize thread attributes
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    pthread_create(&thread, &attr, thread_detached_worker, "DetachedWorker");
    pthread_attr_destroy(&attr);
    
    printf("[Main] Detached thread launched, continuing with main work...\n");
    
    // Main thread continues independently
    for(int i = 1; i <= 5; i++) {
        printf("[Main] Main thread working... step %d\n", i);
        sleep(1);
    }
    
    printf("[Main] Main work done (detached thread may still be running)\n");
    sleep(2);  // Give detached thread time to finish
}

/**
 * @brief Demo 4: Multiple threads with normal completion.
 */
void demo_normal_threads(void)
{
    printf("\n=== DEMO 4: Normal Threads (For Comparison) ===\n");
    
    pthread_t threads[3];
    char* names[] = {"Thread-A", "Thread-B", "Thread-C"};
    
    // Create threads
    for(int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_normal, names[i]);
    }
    
    // Wait for all to complete
    printf("[Main] Waiting for all threads to complete...\n");
    for(int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("[Main] All threads completed\n");
}

/* ============================================================================
 * Main Function
 * ============================================================================ */

/**
 * @brief Main function demonstrating various thread control mechanisms.
 * @return EXIT_SUCCESS on successful execution.
 */
int main(void)
{
    printf("??????????????????????????????????????????????????????????\n");
    printf("?  Thread Infinite Loop Control Demonstration           ?\n");
    printf("??????????????????????????????????????????????????????????\n");
    
    // Run demonstrations
    demo_controlled_loop();
    
    sleep(1);
    demo_cancel_thread();
    
    sleep(1);
    demo_detached_thread();
    
    sleep(1);
    demo_normal_threads();
    
    printf("\n? All demonstrations completed successfully!\n");
    return EXIT_SUCCESS;
}