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
#define BILLION  1000000000.0

double a[3];
double b[3];
double c[3];
int ai=0;
int bj=0;
int ck=0;
void countA()
{
  
 
    long long int i, start;

    long long int end;

   start = 1;
   end = pow(2,32);

   for(i = start; i <= end; i++) 
   {
    ;
   }

 
    
 


}
void countB()
{
 
   
    long long int i, start;
    long long int end;

   start = 1;
   end = pow(2,32);

   for(i = start; i <= end; i++) 
   {
    ;
   }
 
 

    
}
void countC()
{
   
   
 
   
    long long int i, start;
    long long int end;

   start = 1;
   end = pow(2,32);

   for(i = start; i <= end; i++) 
   {
    ;
   }
  
 
    
    
}
void * Thr_A(void *arg)
{

  struct timespec start1, end1;
 
    clock_gettime(CLOCK_REALTIME, &start1);
 
  countA();
	
  clock_gettime(CLOCK_REALTIME, &end1);
 
    double time_spent = (end1.tv_sec - start1.tv_sec) +
                        (end1.tv_nsec - start1.tv_nsec) / BILLION;
    a[ai]=time_spent;
    ai++;
    printf("The elapsed time is %f seconds\n", time_spent);


	pthread_exit(0);

}
void * Thr_B(void *arg)
{
  

  struct timespec start2, end2;
 
    clock_gettime(CLOCK_REALTIME, &start2);
 
  countB();
	
  clock_gettime(CLOCK_REALTIME, &end2);
 
    double time_spent = (end2.tv_sec - start2.tv_sec) +
                        (end2.tv_nsec - start2.tv_nsec) / BILLION;
    b[bj]=time_spent;
    bj++;
    printf("The elapsed time is %f seconds\n", time_spent);


	pthread_exit(0);

}
void * Thr_C(void *arg)
{


  struct timespec start3, end3;
 
  clock_gettime(CLOCK_REALTIME, &start3);
 
  countC();
	
  clock_gettime(CLOCK_REALTIME, &end3);
 
    double time_spent = (end3.tv_sec - start3.tv_sec) +
                        (end3.tv_nsec - start3.tv_nsec) / BILLION;
    c[ck]=time_spent;
    ck++;
    printf("The elapsed time is %f seconds\n", time_spent);


	pthread_exit(0);
}

int main(int argc, char **argv)
{
    

    pthread_t task_idA;

    int tA;
    int statusA;
    int t1A;

    pthread_attr_t attrA;
    struct sched_param sch_paramsA;
    pthread_attr_init(&attrA);
    sch_paramsA.sched_priority = 0;
    statusA = pthread_attr_setschedpolicy(&attrA, SCHED_OTHER);
    statusA = pthread_attr_setschedparam(&attrA, &sch_paramsA);
    statusA = pthread_create(&task_idA, &attrA, Thr_A, NULL);
    pthread_getschedparam(pthread_self(), &tA, &sch_paramsA);

    pthread_t task_idB;

    int tB;
    int statusB;
    int t1B;

    pthread_attr_t attrB;
    struct sched_param sch_paramsB;
    pthread_attr_init(&attrB);
    statusB = pthread_attr_getschedparam(&attrB,&sch_paramsB); 
    sch_paramsB.sched_priority = 1;
    statusB = pthread_attr_setschedpolicy(&attrB, SCHED_FIFO);
    statusB = pthread_attr_setschedparam(&attrB, &sch_paramsB);
    statusB = pthread_create(&task_idB, &attrB, Thr_B, NULL);
    pthread_getschedparam(pthread_self(), &tB, &sch_paramsB);

    pthread_t task_idC;

    int tC;
    int statusC;
    int t1C;

    pthread_attr_t attrC;
    struct sched_param sch_paramsC;
    pthread_attr_init(&attrC);
    sch_paramsC.sched_priority = 1;
    statusC = pthread_attr_setschedpolicy(&attrC, SCHED_RR);
    statusC = pthread_attr_setschedparam(&attrC, &sch_paramsC);
    statusC = pthread_create(&task_idC, &attrC, Thr_C, NULL);
    pthread_getschedparam(pthread_self(), &tC, &sch_paramsC);


    /*pthread_join(task_idA, NULL);
    pthread_join(task_idB, NULL);
    pthread_join(task_idC, NULL);*/



    pthread_t task_idA2;

    int tA2;
    int statusA2;
    int t1A2;

    pthread_attr_t attrA2;
    struct sched_param sch_paramsA2;
    pthread_attr_init(&attrA2);
    sch_paramsA2.sched_priority = 2;
    statusA2 = pthread_attr_setschedpolicy(&attrA2, SCHED_OTHER);
    statusA2 = pthread_attr_setschedparam(&attrA2, &sch_paramsA2);
    statusA2 = pthread_create(&task_idA2, &attrA2, Thr_A, NULL);
    pthread_getschedparam(pthread_self(), &tA2, &sch_paramsA2);

    pthread_t task_idB2;

    int tB2;
    int statusB2;
    int t1B2;


    pthread_attr_t attrB2;
    struct sched_param sch_paramsB2;
    pthread_attr_init(&attrB2);
    sch_paramsB2.sched_priority = 3;
    statusB2 = pthread_attr_setschedpolicy(&attrB2, SCHED_FIFO);
    statusB2 = pthread_attr_setschedparam(&attrB2, &sch_paramsB2);
    statusB2 = pthread_create(&task_idB2, &attrB2, Thr_B, NULL);
    pthread_getschedparam(pthread_self(), &tB2, &sch_paramsB2);

    pthread_t task_idC2;

    int tC2;
    int statusC2;
    int t1C2;

    pthread_attr_t attrC2;
    struct sched_param sch_paramsC2;
    pthread_attr_init(&attrC2);
    sch_paramsC2.sched_priority = 3;
    statusC2 = pthread_attr_setschedpolicy(&attrC2, SCHED_RR);
    statusC2 = pthread_attr_setschedparam(&attrC2, &sch_paramsC2);
    statusC2 = pthread_create(&task_idC2, &attrC2, Thr_C, NULL);
    pthread_getschedparam(pthread_self(), &tC2, &sch_paramsC2);


    /*pthread_join(task_idA2, NULL);
    pthread_join(task_idB2, NULL);
    pthread_join(task_idC2, NULL);*/


    pthread_t task_idA3;

    int tA3;
    int statusA3;
    int t1A3;

    pthread_attr_t attrA3;
    struct sched_param sch_paramsA3;
    pthread_attr_init(&attrA3);
    sch_paramsA3.sched_priority = 2;
    statusA3 = pthread_attr_setschedpolicy(&attrA3, SCHED_OTHER);
    statusA3 = pthread_attr_setschedparam(&attrA3, &sch_paramsA3);
    statusA3 = pthread_create(&task_idA3, &attrA3, Thr_A, NULL);
    pthread_getschedparam(pthread_self(), &tA3, &sch_paramsA3);

    pthread_t task_idB3;

    int tB3;
    int statusB3;
    int t1B3;

    pthread_attr_t attrB3;
    struct sched_param sch_paramsB3;
    pthread_attr_init(&attrB3);
    sch_paramsB3.sched_priority = 3;
    statusB3 = pthread_attr_setschedpolicy(&attrB3, SCHED_FIFO);
    statusB3 = pthread_attr_setschedparam(&attrB3, &sch_paramsB3);
    statusB3 = pthread_create(&task_idB3, &attrB3, Thr_B, NULL);
    pthread_getschedparam(pthread_self(), &tB3, &sch_paramsB3);

    pthread_t task_idC3;

    int tC3;
    int statusC3;
    int t1C3;

    pthread_attr_t attrC3;
    struct sched_param sch_paramsC3;
    pthread_attr_init(&attrC3);
    sch_paramsC3.sched_priority = 4;
    statusC3 = pthread_attr_setschedpolicy(&attrC3, SCHED_RR);
    statusC3 = pthread_attr_setschedparam(&attrC3, &sch_paramsC3);
    statusC3 = pthread_create(&task_idC3, &attrC3, Thr_C, NULL);
    pthread_getschedparam(pthread_self(), &tC3, &sch_paramsC3);

    pthread_join(task_idA, NULL);
    pthread_join(task_idB, NULL);
    pthread_join(task_idC, NULL);

    pthread_join(task_idA2, NULL);
    pthread_join(task_idB2, NULL);
    pthread_join(task_idC2, NULL);

    pthread_join(task_idA3, NULL);
    pthread_join(task_idB3, NULL);
    pthread_join(task_idC3, NULL);


    FILE *fp=fopen("out1.txt", "w");
    for(int p=0;p<3;p++)
    {
      
      fprintf(fp, "%f\n", a[p]);
    }  
    fclose(fp);

    FILE *fp2=fopen("out2.txt", "w");
    for(int p=0;p<3;p++)
    {
      
      fprintf(fp2, "%f\n", b[p]);
    }  
    fclose(fp2);

    FILE *fp3=fopen("out3.txt", "w");
    for(int p=0;p<3;p++)
    {
      
      fprintf(fp3, "%f\n", c[p]);
    }  
    fclose(fp3);

    return 1;
    



}