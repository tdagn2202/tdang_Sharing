int extract_max(PriorityQueue *pQ){
    int m = pQ->elements[0];
    swap(&pQ->elements[0], &pQ->elements[pQ->size-1]);
    pQ->size--;
    max_heapify(pQ, 0);
    return m;
}
