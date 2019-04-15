
#include<stdio.h>

/*

void Enter_process(struct process process_queue[],int total_process);

void Arrival_Time_Sorting(struct process process_queue[],int total_process);

void process_cal(struct process process_queue[],int total_process);

*/
struct process
{

      char process_no;
      int arrival_time, burst_time, completion_time, waiting_time, turnaround_time, priority;
      int status;

};


int total_process;

int time = 0,burst_time = 0,  Max;

float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;




void Enter_process(struct process process_queue[],int total_process)
{

         // printf("\nP[%d]\n",i+1);

      for(int i = 0; i < total_process; i++)

      {
            process_queue[i].process_no = i+1;

            printf("\nEnter Details For ProcessP[%d]:\n", process_queue[i].process_no);

            printf("Enter Arrival Time:\t");

            scanf("%d", &process_queue[i].arrival_time );

            printf("Enter Burst Time:\t");

            scanf("%d", &process_queue[i].burst_time);

            printf("Enter Priority:\t\t");

            scanf("%d", &process_queue[i].priority);

            process_queue[i].status = 0;

            burst_time = burst_time + process_queue[i].burst_time;

            //printf("%d", burst_time);
      }
}





void Arrival_Time_Sorting(struct process process_queue[],int total_process)
{

      struct process temp;

      for(int i = 0; i < total_process - 1; i++)
      {
            for(int j = i + 1; j < total_process; j++)
            {
                  if(process_queue[i].arrival_time > process_queue[j].arrival_time)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
          //  printf("%d\n",process_queue[i].arrival_time);
      }
         //  printf("Anand");
}




void process_cal(struct process process_queue[],int total_process)

{

         //tat=ct-at

        //wt=tat-bursttime

      process_queue[9].priority = -9999;

      printf("\n||Process Number||  ||Arrival Time||  ||Burst Time||  ||Priority||   ||Waiting Time||  ||Turnaround_time||\n");



       for(time = process_queue[0].arrival_time; time < burst_time; )
        {

            Max = 9;

            for(int i = 0; i < total_process; i++)
            {

            if(process_queue[i].arrival_time <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[Max].priority)

                {
                        Max = i;

                }

            }


            time = time + process_queue[Max].burst_time;

            process_queue[Max].completion_time = time;
            printf("%d",process_queue[Max].completion_time);

            process_queue[Max].waiting_time = process_queue[Max].completion_time - process_queue[Max].arrival_time - process_queue[Max].burst_time;

            process_queue[Max].turnaround_time = process_queue[Max].completion_time - process_queue[Max].arrival_time;
           
            process_queue[Max].status = 1;

            wait_time = wait_time + process_queue[Max].waiting_time;

            turnaround_time = turnaround_time + process_queue[Max].turnaround_time;

            printf("\nP[%d]\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", process_queue[Max].process_no, process_queue[Max].arrival_time, process_queue[Max].burst_time, process_queue[Max].priority, process_queue[Max].waiting_time,process_queue[Max].turnaround_time);

            //  printf("Anand");

        }

          average_waiting_time = wait_time / total_process;

          average_turnaround_time = turnaround_time / total_process;

          printf("\n\n         ||Average waiting time||  =\t%f\n", average_waiting_time);

          printf("  \n      ||Average Turnaround Time|| =\t%f\n\n", average_turnaround_time);

     // printf("Anand");

}


void main()
{



       printf("\nEnter Total Number of Processes:\t");

       scanf("%d", &total_process);

       struct process process_queue[10];


       Enter_process(process_queue,total_process);

       Arrival_Time_Sorting(process_queue,total_process);

       process_cal(process_queue,total_process);



}
