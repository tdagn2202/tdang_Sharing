void reverse(int a[], int n) {
    int i, temp;

    for (i = 0; i < n / 2; ++i) {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

void merge(int A[], int m, int B[], int n, int C[]) {
    int i = 0, j = 0, k = 0;

    reverse(A, m);
    reverse(B, n);

    while (i < m && j < n) {
        C[k++] = (A[i] < B[j]) ? A[i++] : B[j++];
    }

    while (i < m) {
        C[k++] = A[i++];
    }

    while (j < n) {
        C[k++] = B[j++];
    }

    reverse(C, k);
}
