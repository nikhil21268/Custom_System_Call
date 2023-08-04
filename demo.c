
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define HELLO_SYS_CALL 451

int main(int argc, char **argv)
{
  
    int matrix1[2][2] = {{1,2},{3,4}};
    int matrix2[2][2];
 
    printf("Making system call now with the matrices 1 and 2\n");

    long res = syscall(HELLO_SYS_CALL, (float *)matrix1, (float *)matrix2, 2,2);

    printf("System call returned %ld.\n", res);
    perror("Console Output");

    printf("Now printing matrix 2 after exec the system call..\n");

    for(int i = 0 ; i<2 ; i++){
        for(int j =0 ; j<2 ; j++){
            printf("%d ",matrix2[i][j]);
        }
        printf("\n");
    }
  return res;
}
