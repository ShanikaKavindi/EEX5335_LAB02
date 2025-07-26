 #include <stdio.h>
#include <pthread.h>

#define SIZE 3

int A[SIZE][SIZE] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
int B[SIZE][SIZE] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
};
int C[SIZE][SIZE];

struct thread_data {
    int row;
};

void* multiply_row(void* arg) {
    struct thread_data* data = (struct thread_data*) arg;
    int i = data->row;
    for (int j = 0; j < SIZE; j++) {
        C[i][j] = 0;
        for (int k = 0; k < SIZE; k++) {
            C[i][j] += A[i][k] * B[k][j];
        }
    }
    pthread_exit(0);
}

void print_matrix(const char* name, int matrix[SIZE][SIZE]) {
    printf("\nMatrix %s:\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    pthread_t threads[SIZE];
    struct thread_data data[SIZE];

    // Print A and B before computation
    print_matrix("A", A);
    print_matrix("B", B);

    // Create threads
    for (int i = 0; i < SIZE; i++) {
        data[i].row = i;
        pthread_create(&threads[i], NULL, multiply_row, (void*)&data[i]);
    }

    // Join threads
    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print resulting matrix C
    print_matrix("C = A x B", C);

    return 0;
}

