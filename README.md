**Threads**  

A thread is a lightweight unit of execution within a process. Threads share the same memory but run independently, each with its own stack and execution context.
-Threads can directly read/write to shared variables or data structures.
-to ensure safe interaction without race conditions, there are tools like
    Mutexes: To lock shared resources.

**Deadlocks**  

A deadlock occurs when two or more threads (or processes) are waiting for each other to release resources, but none can proceed because they are all stuck in a cycle of dependencies. This results in the program freezing indefinitely.

**Functions**  

**pthread_mutex_init:** initializes mutex before using it for locking and unlocking.  
parameters:  
mutex: A pointer to the mutex object you want to initialize.
attr: A pointer to a pthread_mutexattr_t structure that defines the attributes for the mutex. to use default attributes, pass NULL(opposed to PTHREAD_MUTEX_RECURSIVE, when we want it to be recursive).
