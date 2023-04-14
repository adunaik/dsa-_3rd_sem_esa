#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end
    start = clock();
    printf("Enter any character\n");
    getchar();

    double time_taken= ((double)end - start)/CLOCKS_PER_SEC;

    printf("Time taken to execute in seconds : %f", time_taken);
    return 0;
}
