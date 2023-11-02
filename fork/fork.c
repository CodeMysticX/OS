#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void SF(){
    fork();
    printf("\nSingle frok called!");
}
void MF(){
    fork();
    printf("\nMultifork is called!");
    fork();
    printf("\nWindows");
}
int main(){
    SF();
    MF();
    return 0;
}
