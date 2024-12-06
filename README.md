**Threads**  

A thread is a lightweight unit of execution within a process. Threads share the same memory but run independently, each with its own stack and execution context.
-Threads can directly read/write to shared variables or data structures.
-to ensure safe interaction without race conditions, there are tools like
    Mutexes: To lock shared resources.

**Deadlocks**  

A deadlock occurs when two or more threads (or processes) are waiting for each other to release resources, but none can proceed because they are all stuck in a cycle of dependencies. This results in the program freezing indefinitely.
