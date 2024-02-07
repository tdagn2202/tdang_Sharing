#include <stdio.h>
#include <stdlib.h>

#define ll long long

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// left, right và parent là những operators cơ bản của Heap
int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

int parent(int i){
    return (i - 1) / 2;
}

//hàm đệ quy heapify theo node được chỉ định
void max_heapify(int a[], int i, int heap_size){
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= heap_size && a[l] > a[largest]) {
        largest = l;
    }

    if (r <= heap_size && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i){
        swap(&a[i], &a[largest]);
        max_heapify(a, largest, heap_size);
    }
}

//hàm thêm phần tử vào một mảng đã được heapify
void add(int arr[], int *heap_size, int x) {
    (*heap_size) += 1;
    int i = (*heap_size) - 1;
    arr[i] = x;
    while (i > 0 && arr[i] > arr[parent(i)]){
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

//hàm trả về giá trị lớn nhất trong một mảng đã được heapify
int get_max(int arr[]) {
    return arr[0];
}

//hàm heapify cả mảng, sử dụng lại hàm heapify theo từng node kết hợp với vòng lặp
void heapify(int a[], int heap_size){
    for (int i = heap_size/2 - 1; i >= 0; --i){
        max_heapify(a, i, heap_size - 1);
    }
}

int main(){
    int n, q, type, x;
    // int c[1000001], sizec=0;
    int arr[1000001];
    int heap_size = 0;

    scanf("%d", &n);

  //LƯU Ý: NHẬP PHẦN TỬ VÀO MẢNG TRƯỚC, RỒI MỚI HEAPIFY
    for (int i = 0; i < n; ++i) {
       scanf("%d", &arr[i]);
      //cập nhật heapsize, heapsize có thể hiểu là số lượng phần tử có trong mảng đó, cần phải cập nhật vì một lát khi sử dụng hàm add sẽ cần tới dữ liệu này.
       heap_size++;
    }

  // heapify mảng vừa nhập
    heapify(arr, n);

    scanf("%d", &q);
  
    for (int i = 0; i < q; ++i) {
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &x);
            add(arr, &heap_size, x);
        } else if (type == 2) {
            int result = get_max(arr);
            // c[sizec++] = result; --> cách này cũng được
            printf("%d\n", result);
        }
    }

    // for(int i = 0; i < sizec; ++i){
    //     printf("%d\n", c[i]);
    // }
    return 0;
}
