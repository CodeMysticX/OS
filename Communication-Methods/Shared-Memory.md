# Shared Memory Communication

## Introduction
This document describes the implementation of inter-process communication (IPC) using shared memory in a single C program. Shared memory provides a fast and efficient way for processes to communicate by allowing them to share a portion of memory.

## Program Description
The provided C program consists of two parts: a sender process and a receiver process. Both processes utilize shared memory to exchange data.

## Program Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    void *shared_memory;
    char buff[100];
    int shmid;

    // Create or access a shared memory segment
    shmid = shmget((key_t)1122, 1024, 0666 | IPC_CREAT);
    printf("Key of shared memory is: %d\n", shmid);

    // Attach the shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    printf("Process attached at: %p\n", shared_memory);

    // Sender Process: Write data to shared memory
    printf("Sender Process: Enter some data to write to the shared memory:\n");
    read(0, buff, 100);
    strcpy(shared_memory, buff);
    printf("Sender Process: You wrote: %s\n", (char *)shared_memory);

    // Detach from the shared memory segment
    shmdt(shared_memory);

    // Receiver Process: Access the existing shared memory segment
    // Attach the shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    printf("Receiver Process: Process attached at: %p\n", shared_memory);

    // Receiver Process: Read data from shared memory
    printf("Receiver Process: Data read from the memory is: %s\n", (char *)shared_memory);

    // Detach from the shared memory segment
    shmdt(shared_memory);

    return 0;
}
