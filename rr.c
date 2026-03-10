#include <stdio.h>
#include <string.h>

struct process {
    char pid[10];
    int at, bt, rt;
    int ct, wt, tat;
};

int main() {

    int n = 4;
    int tq = 2;

    struct process p[20] = {
        {"P1", 0, 5},
        {"P2", 1, 3},
        {"P3", 2, 6},
        {"P4", 3, 4}
    };

    float avg_wt = 0, avg_tat = 0;
    int time = 0, done = 0;

    for(int i = 0; i < n; i++)
        p[i].rt = p[i].bt;

    while(done < n) {

        for(int i = 0; i < n; i++) {

            if(p[i].rt > 0 && p[i].at <= time) {

                if(p[i].rt <= tq) {
                    time += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = time;
                    done++;
                }
                else {
                    time += tq;
                    p[i].rt -= tq;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    printf("Waiting Time:\n");
    for(int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].wt);

    printf("Turnaround Time:\n");
    for(int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].tat);

    printf("Average Waiting Time: %.2f\n", avg_wt/n);
    printf("Average Turnaround Time: %.2f\n", avg_tat/n);

    return 0;
}
