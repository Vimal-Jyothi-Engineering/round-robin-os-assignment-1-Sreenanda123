#include <stdio.h>
#include <string.h>

struct process {
    char pid[10];
    int at, bt, rt;
    int ct, wt, tat;
};

int main() {
    int n, tq;
    scanf("%d", &n);

    struct process p[20];

    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    scanf("%d", &tq);   // time quantum

    int time = 0, done = 0;
    float avg_wt = 0, avg_tat = 0;

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
