#include <math.h>
#include <sched.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sched.h>
#include <sys/resource.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BILLION  1000000000.0
double arr1[3];
double brr1[3];
double crr1[3];
int ai=0;
int bj=0;
int ck=0;

// Driver code
int main()
{
    struct timespec start1, end1;
    struct timespec start2, end2;
	struct timespec start3, end3;
 
 
    clock_gettime(CLOCK_REALTIME, &start1);
    int id1 = fork();
    clock_gettime(CLOCK_REALTIME, &start2);
    clock_gettime(CLOCK_REALTIME, &start3);
    int id2 = fork();
    pid_t pid1;
    pid_t pid2;
    pid_t pid3;

    //int id3=fork();
    if (id1 == 0) {
        if (id2 == 0) {
            //printf("We are process y\n");
            int a=setpriority(SCHED_OTHER, id2, 0);
            //printf("%d\n",a);
            execl
            (
                /*"./cat_trial_yt",
                "cat_trial_yt",
                "hi.txt",
                NULL*/
                "./scrip3.sh",
                "scrip3.sh",
                //"hi.txt",
                //args[1],
                NULL,
                NULL

            );
            
            pid1=getpid();
            // if(waitpid(pid1,NULL,0)==pid1)
            // {
            //     clock_gettime(CLOCK_REALTIME, &end1);
 
            //     // time_spent = end - start
            //     double time_spent = (end1.tv_sec - start1.tv_sec) +
            //                         (end1.tv_nsec - start1.tv_nsec) / BILLION;
            //                         //int ai=0;
            //                         arr1[ai]=time_spent;
            //     ai++;
            //                         printf("The elapsed time is %f seconds\n", time_spent);
            // }

        } else {
            //printf("We are process x\n");
            int a=setpriority(SCHED_RR, id1, 1);
                    //printf("%d\n",a);
                   execl
                    (
                        /*"./cat_trial_yt",
                        "cat_trial_yt",
                        "hi.txt",
                        NULL*/
                        "./scrip2.sh",
                        "scrip2.sh",
                        //"hi.txt",
                        //args[1],
                        NULL,
                        NULL

                    );
            pid2=getpid();
        }
    } else {
        if (id2 == 0) {
            //printf("We are process z\n");
            //int a=setpriority(SCHED_FIFO, pid2, 1);
            int a=setpriority(SCHED_FIFO, id2, 1);
                        //printf("%d\n",a);
                       execl
                        (
                            /*"./cat_trial_yt",
                            "cat_trial_yt",
                            "hi.txt",
                            NULL*/
                            "./scrip1.sh",
                            "scrip1.sh",
                            //"hi.txt",
                            //args[1],
                            NULL,
                            NULL

                        );
            pid3=getpid();
        } else {
            int flag1=0;
            int flag2=0;
            int flag3=0;
            while(1)
            {
                if(flag1==1 && flag2==1 && flag3==1)
                {
                    break;
                }
                if(flag1==0)
                {
                    if(waitpid(pid1,NULL,0)==0)
                    {
                        ;
                    }
                    else
                    {
                        //printf("hey\n");
                        //if(waitpid(pid3,NULL,0)==pid1)
                        //{
                        clock_gettime(CLOCK_REALTIME, &end1);

                        // time_spent = end - start
                        double time_spent = (end1.tv_sec - start1.tv_sec) +
                                            (end1.tv_nsec - start1.tv_nsec) / BILLION;
                                            arr1[ai]=time_spent;
                        ai++;
                                            printf("The elapsed time is %f seconds\n", time_spent);
                        //break;
                        flag1=1;
                    }

                }
                if(flag2==0)
                {
                    if(waitpid(pid2,NULL,0)==0)
                    {
                        ;
                    }
                    else
                    {
                        //printf("hey\n");
                        //if(waitpid(pid3,NULL,0)==pid1)
                        //{
                        clock_gettime(CLOCK_REALTIME, &end2);

                        // time_spent = end - start
                        double time_spent = (end2.tv_sec - start2.tv_sec) +
                                            (end2.tv_nsec - start2.tv_nsec) / BILLION;
                                            brr1[bj]=time_spent;
                        bj++;

                        printf("The elapsed time is %f seconds\n", time_spent);
                        //break;
                        flag2=1;
                    }

                }
                if(flag3==0)
                {
                    if(waitpid(pid3,NULL,0)==0)
                    {
                        ;
                    }
                    else
                    {
                        //printf("hey\n");
                        //if(waitpid(pid3,NULL,0)==pid1)
                        //{
                        clock_gettime(CLOCK_REALTIME, &end3);

                        // time_spent = end - start
                        double time_spent = (end3.tv_sec - start3.tv_sec) +
                                            (end3.tv_nsec - start3.tv_nsec) / BILLION;
                                            crr1[ck]=time_spent;
                        ck++;
        
                        printf("The elapsed time is %f seconds\n", time_spent);
                        //break;
                        flag3=1;
                    }

                }
                
                
                
            }
            //sleep(2);
            //printf("%d\n",pid1);
            //if(waitpid(pid1,NULL,0)==pid1)
            
            /*while(1)
            {
                if(waitpid(pid1,NULL,0)==0)
                {
                    ;
                }
                else
                {
                    //printf("hey\n");
                    clock_gettime(CLOCK_REALTIME, &end1);
 
                    // time_spent = end - start
                    double time_spent = (end1.tv_sec - start1.tv_sec) +
                                        (end1.tv_nsec - start1.tv_nsec) / BILLION;
                                        arr1[ai]=time_spent;
                    ai++;
                                        printf("The elapsed time is %f seconds\n", time_spent);
                    break;
                }
            }
            while(1)
            {
                if(waitpid(pid2,NULL,0)==0)
                {
                    ;
                }
                else
                {
                    //printf("hey\n");
                    clock_gettime(CLOCK_REALTIME, &end2);
 
                    // time_spent = end - start
                    double time_spent = (end2.tv_sec - start2.tv_sec) +
                                        (end2.tv_nsec - start2.tv_nsec) / BILLION;
                                        brr1[bj]=time_spent;
                    bj++;
    
                    printf("The elapsed time is %f seconds\n", time_spent);
                    break;
                }
            }
            while(1)
            {
                if(waitpid(pid3,NULL,0)==0)
                {
                    ;
                }
                else
                {
                    //printf("hey\n");
                    //if(waitpid(pid3,NULL,0)==pid1)
                    //{
                    clock_gettime(CLOCK_REALTIME, &end3);
    
                    // time_spent = end - start
                    double time_spent = (end3.tv_sec - start3.tv_sec) +
                                        (end3.tv_nsec - start3.tv_nsec) / BILLION;
                                        crr1[ck]=time_spent;
                    ck++;
    
                    printf("The elapsed time is %f seconds\n", time_spent);
                    //}
                    break;
                }
            }*/
            /*if(waitpid(pid1,NULL,0)==0)
            {
                clock_gettime(CLOCK_REALTIME, &end1);
 
                // time_spent = end - start
                double time_spent = (end1.tv_sec - start1.tv_sec) +
                                    (end1.tv_nsec - start1.tv_nsec) / BILLION;
                                    arr1[ai]=time_spent;
                ai++;
                                    printf("The elapsed time is %f seconds\n", time_spent);
            }*/
            /*if(waitpid(pid2,NULL,0)==pid1)
            {
                clock_gettime(CLOCK_REALTIME, &end2);
 
                // time_spent = end - start
                double time_spent = (end2.tv_sec - start2.tv_sec) +
                                    (end2.tv_nsec - start2.tv_nsec) / BILLION;
                                    brr1[bj]=time_spent;
                bj++;
 
                printf("The elapsed time is %f seconds\n", time_spent);

            }*/
            /*if(waitpid(pid3,NULL,0)==pid1)
            {
                clock_gettime(CLOCK_REALTIME, &end3);
 
                // time_spent = end - start
                double time_spent = (end3.tv_sec - start3.tv_sec) +
                                    (end3.tv_nsec - start3.tv_nsec) / BILLION;
                                    crr1[ck]=time_spent;
                ck++;
 
                printf("The elapsed time is %f seconds\n", time_spent);
            }*/
            //printf("We are the parent process\n");
            struct timespec start12, end12;
            struct timespec start22, end22;
            struct timespec start32, end32;\

            clock_gettime(CLOCK_REALTIME, &start12);
 
            int id1 = fork();
            clock_gettime(CLOCK_REALTIME, &start22);
            clock_gettime(CLOCK_REALTIME, &start32);
            int id2 = fork();
            pid_t pid1;
            pid_t pid2;
            pid_t pid3;
            if (id1 == 0) {
                if (id2 == 0) {
                    //printf("We are process y\n");
                    int a=setpriority(SCHED_OTHER, id2, 2);
                    //printf("%d\n",a);
                    execl
                    (
                        /*"./cat_trial_yt",
                        "cat_trial_yt",
                        "hi.txt",
                        NULL*/
                        "./scrip3.sh",
                        "scrip3.sh",
                        //"hi.txt",
                        //args[1],
                        NULL,
                        NULL

                    );
                    pid1=getpid();

                } else {
                    //printf("We are process x\n");
                    int a=setpriority(SCHED_RR, id1, 3);
                    //printf("%d\n",a);
                   execl
                    (
                        /*"./cat_trial_yt",
                        "cat_trial_yt",
                        "hi.txt",
                        NULL*/
                        "./scrip2.sh",
                        "scrip2.sh",
                        //"hi.txt",
                        //args[1],
                        NULL,
                        NULL

                    );
                    pid2=getpid();
                }
            } else {
                if (id2 == 0) {
                    //printf("We are process z\n");
                    //int a=setpriority(SCHED_FIFO, pid2, 3);
                    int a=setpriority(SCHED_FIFO, id2, 3);
                        //printf("%d\n",a);
                       execl
                        (
                            /*"./cat_trial_yt",
                            "cat_trial_yt",
                            "hi.txt",
                            NULL*/
                            "./scrip1.sh",
                            "scrip1.sh",
                            //"hi.txt",
                            //args[1],
                            NULL,
                            NULL

                        );
                    pid3=getpid();
                } else {
                    int flag1=0;
                    int flag2=0;
                    int flag3=0;
                    while(1)
                            {
                                if(flag1==1 && flag2==1 && flag3==1)
                                {
                                    break;
                                }
                                if(flag1==0)
                                {
                                    if(waitpid(pid1,NULL,0)==0)
                                    {
                                        ;
                                    }
                                    else
                                    {
                                        //printf("hey\n");
                                        //if(waitpid(pid3,NULL,0)==pid1)
                                        //{
                                        clock_gettime(CLOCK_REALTIME, &end12);
    
                                        // time_spent = end - start
                                        double time_spent = (end12.tv_sec - start12.tv_sec) +
                                                            (end12.tv_nsec - start12.tv_nsec) / BILLION;
                                                            arr1[ai]=time_spent;
                                        ai++;
                                                            printf("The elapsed time is %f seconds\n", time_spent);
                                        //break;
                                        flag1=1;
                                    }

                                }
                                if(flag2==0)
                                {
                                    if(waitpid(pid2,NULL,0)==0)
                                    {
                                        ;
                                    }
                                    else
                                    {
                                        //printf("hey\n");
                                        //if(waitpid(pid3,NULL,0)==pid1)
                                        //{
                                        clock_gettime(CLOCK_REALTIME, &end22);
            
                                        // time_spent = end - start
                                        double time_spent = (end22.tv_sec - start22.tv_sec) +
                                                            (end22.tv_nsec - start22.tv_nsec) / BILLION;
                                                            brr1[bj]=time_spent;
                                        bj++;
                
                                        printf("The elapsed time is %f seconds\n", time_spent);
                                        //break;
                                        flag2=1;
                                    }

                                }
                                if(flag3==0)
                                {
                                    if(waitpid(pid3,NULL,0)==0)
                                    {
                                        ;
                                    }
                                    else
                                    {
                                        //printf("hey\n");
                                        //if(waitpid(pid3,NULL,0)==pid1)
                                        //{
                                        clock_gettime(CLOCK_REALTIME, &end32);
    
                                        // time_spent = end - start
                                        double time_spent = (end32.tv_sec - start32.tv_sec) +
                                                            (end32.tv_nsec - start32.tv_nsec) / BILLION;
                                                            crr1[ck]=time_spent;
                                        ck++;
                        
                                        printf("The elapsed time is %f seconds\n", time_spent);
                                        //break;
                                        flag3=1;
                                    }

                                }
                                
                                
                                
                            }
                    /*while(1)
                    {
                        if(waitpid(pid1,NULL,0)==0)
                        {
                            ;
                        }
                        else
                        {
                            //printf("hey\n");
                            //if(waitpid(pid3,NULL,0)==pid1)
                            //{
                            clock_gettime(CLOCK_REALTIME, &end12);
 
                            // time_spent = end - start
                            double time_spent = (end12.tv_sec - start12.tv_sec) +
                                                (end12.tv_nsec - start12.tv_nsec) / BILLION;
                                                arr1[ai]=time_spent;
                            ai++;
                                                printf("The elapsed time is %f seconds\n", time_spent);
                                //}
                            break;
                        }
                    }
                    while(1)
                    {
                        if(waitpid(pid2,NULL,0)==0)
                        {
                            ;
                        }
                        else
                        {
                            //printf("hey\n");
                            //if(waitpid(pid3,NULL,0)==pid1)
                            //{
                            clock_gettime(CLOCK_REALTIME, &end22);
 
                            // time_spent = end - start
                            double time_spent = (end22.tv_sec - start22.tv_sec) +
                                                (end22.tv_nsec - start22.tv_nsec) / BILLION;
                                                brr1[bj]=time_spent;
                            bj++;
            
                            printf("The elapsed time is %f seconds\n", time_spent);
                                //}
                            break;
                        }
                    }
                    while(1)
                    {
                        if(waitpid(pid3,NULL,0)==0)
                        {
                            ;
                        }
                        else
                        {
                            //printf("hey\n");
                            //if(waitpid(pid3,NULL,0)==pid1)
                            //{
                            clock_gettime(CLOCK_REALTIME, &end32);

                            // time_spent = end - start
                            double time_spent = (end32.tv_sec - start32.tv_sec) +
                                                (end32.tv_nsec - start32.tv_nsec) / BILLION;
                                                crr1[ck]=time_spent;
                            ck++;
            
                            printf("The elapsed time is %f seconds\n", time_spent);
                            break;
                        }
                    }*/
                    /*if(waitpid(pid1,NULL,0)==pid1)
                    {
                        clock_gettime(CLOCK_REALTIME, &end12);
 
                        // time_spent = end - start
                        double time_spent = (end12.tv_sec - start12.tv_sec) +
                                            (end12.tv_nsec - start12.tv_nsec) / BILLION;
                                            arr1[ai]=time_spent;
                        ai++;
                                            printf("The elapsed time is %f seconds\n", time_spent);
                    }
                    if(waitpid(pid2,NULL,0)==pid1)
                    {
                        clock_gettime(CLOCK_REALTIME, &end22);
 
                        // time_spent = end - start
                        double time_spent = (end22.tv_sec - start22.tv_sec) +
                                            (end22.tv_nsec - start22.tv_nsec) / BILLION;
                                            brr1[bj]=time_spent;
                        bj++;
        
                        printf("The elapsed time is %f seconds\n", time_spent);
                    }
                    if(waitpid(pid3,NULL,0)==pid1)
                    {
                        clock_gettime(CLOCK_REALTIME, &end32);
 
                        // time_spent = end - start
                        double time_spent = (end32.tv_sec - start32.tv_sec) +
                                            (end32.tv_nsec - start32.tv_nsec) / BILLION;
                                            crr1[ck]=time_spent;
                        ck++;
        
                        printf("The elapsed time is %f seconds\n", time_spent);
                    }*/
                    //printf("We are the parent process\n");
                    struct timespec start13, end13;
                    struct timespec start23, end23;
                    struct timespec start33, end33;
                    clock_gettime(CLOCK_REALTIME, &start13);
                    int id1 = fork();
                    clock_gettime(CLOCK_REALTIME, &start23);
                    clock_gettime(CLOCK_REALTIME, &start33);
                    int id2 = fork();
                    pid_t pid1;
                    pid_t pid2;
                    pid_t pid3;

                    if (id1 == 0) {
                        if (id2 == 0) {
                            //printf("We are process y\n");
                            int a=setpriority(SCHED_OTHER, id2, 2);
                            //printf("%d\n",a);
                            execl
                            (
                                /*"./cat_trial_yt",
                                "cat_trial_yt",
                                "hi.txt",
                                NULL*/
                                "./scrip3.sh",
                                "scrip3.sh",
                                //"hi.txt",
                                //args[1],
                                NULL,
                                NULL

                            );
                            pid1=getpid();

                        } else {
                            //printf("We are process x\n");
                            int a=setpriority(SCHED_RR, id1, 4);
                                //printf("%d\n",a);
                            execl
                                (
                                    /*"./cat_trial_yt",
                                    "cat_trial_yt",
                                    "hi.txt",
                                    NULL*/
                                    "./scrip2.sh",
                                    "scrip2.sh",
                                    //"hi.txt",
                                    //args[1],
                                    NULL,
                                    NULL

                                );
                            pid2=getpid();
                        }
                    } else {
                        if (id2 == 0) {
                            //printf("We are process z\n");
                            //int a=setpriority(SCHED_FIFO, pid2, 3);
                            int a=setpriority(SCHED_FIFO, id2, 3);
                                //printf("%d\n",a);
                            execl
                                (
                                    /*"./cat_trial_yt",
                                    "cat_trial_yt",
                                    "hi.txt",
                                    NULL*/
                                    "./scrip1.sh",
                                    "scrip1.sh",
                                    //"hi.txt",
                                    //args[1],
                                    NULL,
                                    NULL

                                );
                            pid3=getpid();
                        } else {
                            int flag1=0;
                            int flag2=0;
                            int flag3=0;
                            while(1)
                            {
                                if(flag1==1 && flag2==1 && flag3==1)
                                {
                                    break;
                                }
                                if(flag1==0)
                                {
                                    if(waitpid(pid1,NULL,0)==0)
                                    {
                                        ;
                                    }
                                    else
                                    {
                                        //printf("hey\n");
                                        //if(waitpid(pid3,NULL,0)==pid1)
                                        //{
                                        clock_gettime(CLOCK_REALTIME, &end13);
    
                                        // time_spent = end - start
                                        double time_spent = (end13.tv_sec - start13.tv_sec) +
                                                            (end13.tv_nsec - start13.tv_nsec) / BILLION;
                                                            arr1[ai]=time_spent;
                                        ai++;
                                                            printf("The elapsed time is %f seconds\n", time_spent);
                                        //break;
                                        flag1=1;
                                    }

                                }
                                if(flag2==0)
                                {
                                    if(waitpid(pid2,NULL,0)==0)
                                    {
                                        ;
                                    }
                                    else
                                    {
                                        //printf("hey\n");
                                        //if(waitpid(pid3,NULL,0)==pid1)
                                        //{
                                        clock_gettime(CLOCK_REALTIME, &end23);
            
                                        // time_spent = end - start
                                        double time_spent = (end23.tv_sec - start23.tv_sec) +
                                                            (end23.tv_nsec - start23.tv_nsec) / BILLION;
                                                            brr1[bj]=time_spent;
                                        bj++;
                
                                        printf("The elapsed time is %f seconds\n", time_spent);
                                        //break;
                                        flag2=1;
                                    }

                                }
                                if(flag3==0)
                                {
                                    if(waitpid(pid3,NULL,0)==0)
                                    {
                                        ;
                                    }
                                    else
                                    {
                                        //printf("hey\n");
                                        //if(waitpid(pid3,NULL,0)==pid1)
                                        //{
                                        clock_gettime(CLOCK_REALTIME, &end33);
    
                                        // time_spent = end - start
                                        double time_spent = (end33.tv_sec - start33.tv_sec) +
                                                            (end33.tv_nsec - start33.tv_nsec) / BILLION;
                                                            crr1[ck]=time_spent;
                                        ck++;
                        
                                        printf("The elapsed time is %f seconds\n", time_spent);
                                        //break;
                                        flag3=1;
                                    }

                                }
                                
                                
                                
                            }
                            /*while(1)
                            {
                                if(waitpid(pid2,NULL,0)==0)
                                {
                                    ;
                                }
                                else
                                {
                                    //printf("hey\n");
                                    //if(waitpid(pid3,NULL,0)==pid1)
                                    //{
                                    clock_gettime(CLOCK_REALTIME, &end23);
        
                                    // time_spent = end - start
                                    double time_spent = (end23.tv_sec - start23.tv_sec) +
                                                        (end23.tv_nsec - start23.tv_nsec) / BILLION;
                                                        brr1[bj]=time_spent;
                                    bj++;
            
                                    printf("The elapsed time is %f seconds\n", time_spent);
                                    break;
                                }
                            }
                            while(1)
                            {
                                if(waitpid(pid3,NULL,0)==0)
                                {
                                    ;
                                }
                                else
                                {
                                    //printf("hey\n");
                                    //if(waitpid(pid3,NULL,0)==pid1)
                                    //{
                                    clock_gettime(CLOCK_REALTIME, &end32);
 
                                    // time_spent = end - start
                                    double time_spent = (end32.tv_sec - start32.tv_sec) +
                                                        (end32.tv_nsec - start32.tv_nsec) / BILLION;
                                                        crr1[ck]=time_spent;
                                    ck++;
                    
                                    printf("The elapsed time is %f seconds\n", time_spent);
                                    break;
                                }
                            }*/
                            
                            /*if(waitpid(pid1,NULL,0)==pid1)
                            {
                                 clock_gettime(CLOCK_REALTIME, &end13);
 
                                // time_spent = end - start
                                double time_spent = (end13.tv_sec - start13.tv_sec) +
                                                    (end13.tv_nsec - start13.tv_nsec) / BILLION;
                                                    arr1[ai]=time_spent;
                                ai++;
                                                    printf("The elapsed time is %f seconds\n", time_spent);
                            }
                            if(waitpid(pid2,NULL,0)==pid1)
                            {
                                clock_gettime(CLOCK_REALTIME, &end23);
        
                                // time_spent = end - start
                                double time_spent = (end23.tv_sec - start23.tv_sec) +
                                                    (end23.tv_nsec - start23.tv_nsec) / BILLION;
                                                    brr1[bj]=time_spent;
                                bj++;
        
                                printf("The elapsed time is %f seconds\n", time_spent);
                            }
                            if(waitpid(pid3,NULL,0)==pid1)
                            {
                                clock_gettime(CLOCK_REALTIME, &end32);
 
                                // time_spent = end - start
                                double time_spent = (end32.tv_sec - start32.tv_sec) +
                                                    (end32.tv_nsec - start32.tv_nsec) / BILLION;
                                                    crr1[ck]=time_spent;
                                ck++;
                
                                printf("The elapsed time is %f seconds\n", time_spent);
                                    }*/
                            //printf("We are the parent process\n");
                            // int id1 = fork();
                            // int id2 = fork();
                            // pid_t pid1;
                            // pid_t pid2;
                            // pid_t pid3;
                        }
                    }
                }
            }
        }
    }
    /*while (wait(NULL) != -1 || errno != ECHILD) {
        printf("Waited for a child to finish\n");
    }*/
    //waitpid(pid1,NULL,0);
    
    FILE *fp=fopen("out12.txt", "w");
    for(int p=0;p<3;p++)
    {
      //fp.write()
      //fputs((char)a[p],fp);
      fprintf(fp, "%f\n", arr1[p]);
    }  
    fclose(fp);

    FILE *fp2=fopen("out22.txt", "w");
    for(int p=0;p<3;p++)
    {
      //fp.write()
      //fputs((char)a[p],fp);2
      fprintf(fp2, "%f\n", brr1[p]);
    }  
    fclose(fp2);

    FILE *fp3=fopen("out32.txt", "w");
    for(int p=0;p<3;p++)
    {
      //fp.write()
      //fputs((char)a[p],fp);
      fprintf(fp3, "%f\n", crr1[p]);
    }  
    fclose(fp3);
    return 0;

}