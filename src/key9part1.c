/*------------------------------------
    Здравствуй, человек!
    Чтобы получить ключ 
    поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *incorrect_input);
int sum_numbers(int *a, int n);
int find_numbers(int *a, int n, int number, int* numbers);

void output(int sum_value, int *a, int n);


int input(int *a, int *n, int *incorrect_input) {
    if (scanf("%d", n) == 0) {
        printf("n/a");
        *incorrect_input = 1;
        return 0;
    }

    if (*n > NMAX || *n == 0) {printf("n/a");
        *incorrect_input = 1;
        return 0;
    }

    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) == 0) {
            printf("n/a");
            *incorrect_input = 1;
            return 0;
        }
    }

    return 0;
}

int sum_numbers(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            sum += a[i];
        }
    }

    return sum;
}

int find_numbers(int *a, int n, int number, int* numbers) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && (number % a[i]) == 0) {
            numbers[k] = a[i];
            k++;
        }
    }
    return k;
}

void output(int sum_value, int *a, int n) {
    printf("%d \n", sum_value);
    for (int i = 0; i < n; i++) {
         printf("%d ", a[i]);
    }
}

int main() {
    int n, data[NMAX], output_data[NMAX];
    int incorrect_input = 0;
    input(data, &n, &incorrect_input);
    if (incorrect_input == 1) return 0;
    find_numbers(data, n, sum_numbers(data, n), output_data);
    output(sum_numbers(data, n), output_data, find_numbers(data, n, sum_numbers(data, n), output_data));
}
