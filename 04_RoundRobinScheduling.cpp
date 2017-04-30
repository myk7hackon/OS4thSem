//RoundRobin Scheduling
#include "stdio.h"

int Process_no[20],Arrival_time[20],Burst_time[20],run_time[20],Priority[20],Job_status[20],completion_time[20],turn_around_time[20],wait_time[20],response_time[20];
int Process_Queue[100];
int num_processes,Process_Ptr=0;

int suma(){
  int retval=0;
  for(int i=0;i<num_processes;i++)
  {
    retval+=Job_status[i];
  }
  return retval;
}

int main(){
  int current_time=0;
  int quanta = 1;
  printf("\nEnter the Quanta :");
  scanf("%d",&quanta);
  printf("\nEnter The Number of Processes : ");
  scanf("%d",&num_processes);
  for(int i=0;i<num_processes;i++)
  {
    printf("\nEnter following for Process number %d",i+1);
    printf("\nArrival Time : ");
    scanf("%d",&Arrival_time[i]);
    printf("\nBurst Time : ");
    scanf("%d",&Burst_time[i]);

    Job_status[i]=1;  //Implies Job unexecuted
    run_time[i]=Burst_time[i];
  }



  while(suma()!=0){

    int flag=0;
    for(int i=0;i<num_processes;i++)
    {
      if(Job_status[i]==1){
        if((flag==0)&&(Arrival_time[i]<=current_time)){
          printf("\nProcess %d Executed from %d second to ",i+1,current_time);
          flag =1;
          if(run_time[i]==Burst_time[i]){
            response_time[i]=current_time;
          }
          if(quanta<run_time[i]){
            run_time[i]-=quanta;
            current_time+=quanta;
          }
          else{
            current_time+=run_time[i];
            completion_time[i]=current_time;
            run_time[i]=0;
            Job_status[i]=0;
          }
          printf("%d second",current_time);
        }
        else if(Arrival_time[i]<current_time){
          printf("\nProcess %d Executed from %d second to ",i+1,current_time);;
          flag =1;
          if(run_time[i]==Burst_time[i]){
            response_time[i]=current_time;
          }
          if(quanta<run_time[i]){
            run_time[i]-=quanta;
            current_time+=quanta;
          }
          else{
            current_time+=run_time[i];
            completion_time[i]=current_time;
            run_time[i]=0;
            Job_status[i]=0;
          }
          printf("%d second",current_time);
        }
      }
    }
    if(flag==0){
      current_time++;
    }
}

  for(int i=0;i<num_processes;i++){
    turn_around_time[i]=completion_time[i]-Arrival_time[i];
    wait_time[i] = turn_around_time[i]-Burst_time[i];
    response_time[i]=response_time[i]-Arrival_time[i];
  }

  for(int i=0;i<num_processes;i++){
    printf("\nProcess Number\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWait Time\tResponse Time\t");
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d",i+1,Arrival_time[i],Burst_time[i],completion_time[i],turn_around_time[i],wait_time[i],response_time[i]);
  }
  printf("\n");

  return 1;
}
