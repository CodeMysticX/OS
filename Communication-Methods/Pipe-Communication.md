# Pipe Communication

## Introduction
This document describes the implementation of inter-process communication (IPC) using pipes in a C program. Pipes allow communication between processes by creating a unidirectional channel.

## Program Description
The provided C program demonstrates the creation of a pipe and communication between two processes using that pipe. The program consists of the following steps:

1. **Pipe Creation**: The program creates a pipe using the `pipe()` system call. This pipe provides a unidirectional communication channel between a parent and a child process.

2. **Data Writing**: Two messages are prepared to be written into the pipe. Each message contains a name/surname and a corresponding message.

3. **Writing to Pipe**: The program writes the messages into the pipe using the `write()` system call. It writes each message one by one into the write end of the pipe.

4. **Data Reading**: The program reads from the pipe using the `read()` system call. It reads the messages from the read end of the pipe.

5. **Output Display**: After reading from the pipe, the program displays the received messages on the standard output.

## Program Code

```c
#include<stdio.h>
#include<unistd.h>

int main(){
    int p[2];
    int status;
    char writmsg[2][25] = {"name/mesaage ", "surname/message"};
    char readmsg[25];
    
    status = pipe(p);
    
    if(status == -1){
        printf("Pipe not created");
    }else{
        printf("Writing into pipe msg = %s\n ", writmsg[1]);
        write(p[1],writmsg[1], sizeof(writmsg[1]));
        printf("Writing into pipe msg = %s\n ", writmsg[0]);
        write(p[1],writmsg[0], sizeof(writmsg[0]));
        
        for(int i =0 ;i<2;i++){
            read(p[0], readmsg , sizeof(readmsg));
            printf("Reading from pipe - msg = %s\n", readmsg);
        }
        return 0;
    }
}
