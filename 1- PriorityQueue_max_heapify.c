void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(PriorityQueue *pQ, int heap_size){
    int l = left(heap_size);
    int r = right(heap_size);
    int largest = heap_size;

    if (l <= pQ->size && pQ->elements[l] > pQ->elements[largest]) {
        largest = l;
    }

    if (r <= pQ->size && pQ->elements[r] > pQ->elements[largest]) {
        largest = r;
    }

    if (largest != heap_size){
        swap(&pQ->elements[heap_size], &pQ->elements[largest]);
        max_heapify(pQ, heap_size);
    }
}
