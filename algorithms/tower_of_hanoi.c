#include <stdio.h>
#include <time.h>

clock_t start, end;

void tower(int n, char s, char t, char d) {
    if (n==1) {
        printf("Moved %d from %c to %c\n",n,s,d);
        return;
    }
    tower(n-1, s, d ,t);
    printf("Moved %d from %c to %c\n",n,s,d);
    tower(n-1, t, s, d);
}

void main() {
    int n;
    printf("Enter no of disks: ");
    scanf("%d",&n);
    start = clock();
    tower(n, 'A', 'B', 'C');
    end = clock();
    double duration = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken: %f\n",duration);
}