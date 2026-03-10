#include <stdio.h>

int main() {
    int n = 4;                     // number of processes
    int bt[] = {10, 5, 8, 6};      // burst times
    int rt[4];                     // remaining times
    int wt[4], tat[4];
    int tq = 2;                    // time quantum
    int time = 0, remain;
    int i;

    remain = n;

    for(i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] <= tq) {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                    remain--;
                } else {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
