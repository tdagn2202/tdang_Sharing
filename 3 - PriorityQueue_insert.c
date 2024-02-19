void insert(PriorityQueue *pQ, int x) {
    pQ->size++;
    int i = (pQ->size) - 1;
    pQ->elements[i] = x;
    while (i > 0 && pQ->elements[i] > pQ->elements[parent(i)]){
        swap(&pQ->elements[i], &pQ->elements[parent(i)]);
        i = parent(i);
    }
}
