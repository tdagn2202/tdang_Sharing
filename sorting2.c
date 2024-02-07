// Given an array A of n elements and q queries. For each query, you are given a value x; your task is to answer whether x is in the array A or not.

// Input

// The first line contains 2 integer a, q separated by a blank; number of elements in the array and number of queries, respectively.
// The second line consists n integers, separated by blanks: elements of the array A.
// Next q lines, each line is an integer - the query value.
// Output

// Each query, print YES if x∈A, otherwise print NO; followed by a blank.

#include <stdio.h>
#include <stdlib.h> 

#define ll long long
#define MAX_SIZE 100001

void swap(ll *a, ll *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partiontionHodre(ll A[], ll start, ll end){
	int pivot =A[start];
	int i = start-1, j = end+1;

	while(true){
		do {
			i++;
		} while(A[i]>=pivot);

		do {
			j--;
		} while(A[i]<=pivot);
		
		if(i<j){
			swap(&A[i], &A[j]);
		} else return j;
	}
}

int partition(ll A[], ll start, ll end) {
    int i = start + 1;
    int piv = A[start];
    int j;

    for (j = start + 1; j <= end; ++j) {
        if (A[j] < piv) {
            swap(&A[i], &A[j]);
            i++;
        }
    }

    swap(&A[start], &A[i - 1]);
    return i - 1;
}

void quickSort(ll A[], ll start, ll end){
	if(start<end) {
		ll pos = partition(A, start, end);
		quickSort(A, start, pos-1);
		quickSort(A, pos+1, end);
	}
}
  

ll binarySearch(ll array[], ll x, ll n) {
    int low = 0;
    int high = n-1;
    
    while (low <= high) {
        int mid = (high + low) / 2;

        if (array[mid] < x)
            low = mid + 1;

        else if (array[mid] > x)
            high = mid - 1;
        else
            return mid;
    }

    return -1;
}

int main() {
    ll n, q, x;
    scanf("%lld%lld", &n, &q);
    ll a[MAX_SIZE];

    for (ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    quickSort(a, 0, n);

    for (ll j = 0; j < q; ++j) {
        scanf("%lld", &x);
        int result = binarySearch(a, x, n);
        printf(result != -1 ? "YES " : "NO ");
    }

    //system("pause");
    return 0;
}
