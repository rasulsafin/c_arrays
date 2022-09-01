#include <stdio.h>
#define NMAX 10

int input(int *a, int n, int *incorrect_input);
int sort(int *a, int n);
void output(int *a, int n);

int input(int *a, int n, int *incorrect_input) {
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            *incorrect_input = 1;
            return 0;
        }
    }
    return 0;
}

int sort(int *a, int n) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
           if (a[i] > a[j]) {
               temp = a[i];
               a[i] = a[j];
               a[j] = temp;
           }
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int data[NMAX];
    int n = NMAX;
    int incorrect_input;
    input(data, n, &incorrect_input);
    if (incorrect_input == 1) {
        printf("n/a");
        return 0;
    }
    sort(data, n);
    output(data, n);
    return 0;
}
