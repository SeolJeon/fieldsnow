#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 100

typedef struct {
    int type;
    int pid;
    int priority;
    int compute_time;
    int remaining_time;
    int arrival_time;
    int completed;
} Process;

void SRT(Process pro_processes[], int pro_num);

int main() {
    int pro_num = 0;

    Process processes[MAX_PROCESS];

    printf("- 입력\n");

    while (1) {
        printf("-1: Complete\n1: Void\nOther: Input\n");
        printf("type: ");
        scanf_s("%d", &processes[pro_num].type);
        
        if (processes[pro_num].type == -1 || pro_num + 1 == MAX_PROCESS) {
            break;
        }
        else if(processes[pro_num].type==1) {
            pro_num++;
        }
        else {
            printf("process_id priority computing_time\n");
            scanf_s("%d %d %d", &processes[pro_num].pid, 
                &processes[pro_num].priority, &processes[pro_num].compute_time);

            processes[pro_num].remaining_time = processes[pro_num].compute_time;
            processes[pro_num].completed = 0;
            
            pro_num++;
        }
    }

    SRT(processes, pro_num);

    return 0;
}

void SRT(Process pro_processes[], int pro_num) {
    int current_time = 0;
    int completed_processes = 0;
    int arrive = 0;
    int min_remaining_time;
    int shortest_process;

    Process processes[MAX_PROCESS];

    int i = 0, j = 0;
    while (1) {
        if (pro_processes[i].type == 1) {
            arrive += 20;
            i++;
        }
        else if (pro_processes[i].type == -1) {
            pro_num = j;
            break;
        }
        else {
            processes[j] = pro_processes[i];
            processes[j].arrival_time = arrive;
            j++; i++;
        }
    }

    printf("\t\t\t출력 데이터\n");
    printf("Process_id\tpriority\tcomputing_time\tturn_around time\n");

    while (completed_processes < pro_num) {
        min_remaining_time = 9999;
        shortest_process = -1;

        for (int i = 0; i < pro_num; i++) {
            if (!processes[i].completed && processes[i].arrival_time <= current_time &&
                processes[i].remaining_time < min_remaining_time) {
                min_remaining_time = processes[i].remaining_time;
                shortest_process = i;
            }
        }

        for (int i = 0; i < pro_num - 1; i++) {
            for (int j = 0; j < pro_num - i - 1; j++) {
                if (processes[j].arrival_time == processes[j+1].arrival_time) {
                    if (processes[j].priority > processes[j + 1].priority) {
                        Process temp = processes[j];
                        processes[j] = processes[j + 1];
                        processes[j + 1] = temp;
                    }
                }
            }
        }

        if (shortest_process == -1) {
            current_time++;
            continue;
        }

        processes[shortest_process].remaining_time--;
        current_time++;

        if (processes[shortest_process].remaining_time == 0) {
            processes[shortest_process].completed = 1;
            completed_processes++;
            printf("%d\t\t%d\t\t%d\t\t%d\n", processes[shortest_process].pid, 
                processes[shortest_process].priority,
                processes[shortest_process].compute_time, 
                current_time - processes[shortest_process].arrival_time);
        }
    }
}