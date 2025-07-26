public class MatrixMultiplication {

    static final int SIZE = 3;
    static int[][] A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    static int[][] B = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    static int[][] C = new int[SIZE][SIZE];

    static class MultiplyThread extends Thread {
        int row;

        MultiplyThread(int row) {
            this.row = row;
        }

        public void run() {
            for (int j = 0; j < SIZE; j++) {
                C[row][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    C[row][j] += A[row][k] * B[k][j];
                }
            }
        }
    }

    public static void printMatrix(String name, int[][] matrix) {
        System.out.println("\nMatrix " + name + ":");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                System.out.printf("%4d", matrix[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws InterruptedException {
        printMatrix("A", A);
        printMatrix("B", B);

        MultiplyThread[] threads = new MultiplyThread[SIZE];

        for (int i = 0; i < SIZE; i++) {
            threads[i] = new MultiplyThread(i);
            threads[i].start();
        }

        for (int i = 0; i < SIZE; i++) {
            threads[i].join();
        }

        printMatrix("C = A x B", C);
    }
}
