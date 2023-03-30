#include<stdio.h>

void waitingTime (int processes[], int n, int bt[], int wt[]) {
	wt[0] = 0;
	
	for (int i = 0; i < n; i++) {
		wt[i] = bt[i-1] + wt[i-1];
	}
}#include <stdio.h>
#include <stdlib.h>
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
void fcfs(struct process *procs, int n) {
    int current_time = 0;
    printf("\nFCFS Gantt Chart:\n");
    printf("%d", current_time);
    for (int i = 0; i < n; i++) {
        current_time += procs[i].burst_time;
        printf(" | P%d | %d", procs[i].pid, current_time);
        procs[i].waiting_time = current_time - procs[i].arrival_time - procs[i].burst_time;
        if (procs[i].waiting_time < 0) {
            procs[i].waiting_time = 0;
        }
        procs[i].turnaround_time = procs[i].burst_time + procs[i].waiting_time;
    }
    printf("\n");
}
void sjf(struct process *procs, int n) {
    int current_time = 0;
    int completed = 0;
    printf("SJF Gantt Chart:\n");
    printf("%d", current_time);
    while (completed < n) {
        int next_proc = -1;
        int shortest_bt = 999999;
        for (int i = 0; i < n; i++) {
            if (procs[i].arrival_time <= current_time && procs[i].burst_time < shortest_bt && procs[i].turnaround_time == 0) {
                shortest_bt = procs[i].burst_time;
                next_proc = i;
            }
        }
        if (next_proc == -1) {
            current_time++;
        } else {
            current_time += procs[next_proc].burst_time;
            printf(" | P%d | %d", procs[next_proc].pid, current_time);
            procs[next_proc].waiting_time = current_time - procs[next_proc].arrival_time - procs[next_proc].burst_time;
            if (procs[next_proc].waiting_time < 0) {
                procs[next_proc].waiting_time = 0;
            }
            procs[next_proc].turnaround_time = procs[next_proc].burst_time + procs[next_proc].waiting_time;
            completed++;
        }
    }
    printf("\n");
    int total_waiting_time_sjf = 0;
int total_turnaround_time_sjf = 0;
for (int i = 0; i < n; i++) {
    total_waiting_time_sjf += procs[i].waiting_time;
    total_turnaround_time_sjf += procs[i].turnaround_time;
}
float avg_waiting_time_sjf = (float)total_waiting_time_sjf / (float)n;
float avg_turnaround_time_sjf = (float)total_turnaround_time_sjf / (float)n;
printf("\nAverage Waiting time (SJF): %f", avg_waiting_time_sjf);
printf("\nAverage Turnaround time (SJF): %f", avg_turnaround_time_sjf);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process *procs = malloc(n * sizeof(struct process));
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &procs[i].arrival_time, &procs[i].burst_time);
        procs[i].pid = i+1;
        procs[i].waiting_time = 0;
        procs[i].turnaround_time = 0;
    }
    sjf(procs,n);
    fcfs(procs, n);
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += procs[i].waiting_time;
        total_turnaround_time += procs[i].turnaround_time;
    }
    float avg_waiting_time = (float)total_waiting_time / (float)n;
    float avg_turnaround_time=(float)total_turnaround_time/(float)n;
    printf("\nAverage Waiting time(FCFS) : %f",avg_waiting_time);
    printf("\nAverage Turnaround time(FCFS) : %f\n",avg_turnaround_time);
return 0;
}пожалуйста

void turnAroundTime (int processes[], int n, int bt[], int wt[], int tat[]) {
	for (int i = 1; i <n; i++) {
		tat[i] = bt[i] + wt[i];
	}
}

void avgTime (int processes[], int n, int bt[]) {
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	
	waitingTime(processes, n, bt, wt);
	
	turnAroundTime(processes, n, bt, wt, tat);
	
	printf("Processes\tBT\tWT\tTAT\n");
	
	for (int i = 0; i <n; i++) {
		total_wt += wt[i];
		total_tat += tat[i];
		printf("%d", (i+1));
		printf("\t\t%d", bt[i]);
		printf("\t%d", wt[i]);
		printf("\t%d\n", tat[i]);
	}
	
	int s = (float)total_wt / (float)n;
	int t = (float)total_tat / (float)n;
	printf("Average waiting time = %d\n", s);
	printf("Average turn around time = %d\n", t);
}

void main () {
	int processes[] = {1,2,3};
	int n = sizeof processes / sizeof processes[0];
	int burst_time[] = {10,5,8};
	avgTime(processes, n, burst_time);
}
