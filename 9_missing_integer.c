#include <stdio.h>
#include <stdlib.h>

inline static void
swap(int *i, int *j) {
    int t;

    t = *i;
    *i = *j;
    *j = t;
}

inline static int
partition(int A[], int l, int r) {
    int pivot;
    int i;
    int k;

    k = l;
    pivot = A[r];
    for (i = l; i < r; i++) {
        if (A[i] < pivot) {
            if (i != k) {
                swap(&A[i], &A[k]);
            }
            k++;
        }
    }

    swap(&A[r], &A[k]);
    return k;
}

inline static void
quicksort(int A[], int l, int r) {
    int pivot;

    if (l < r) {
        pivot = partition(A, l, r);
        quicksort(A, l, pivot - 1);
        quicksort(A, pivot + 1, r);
    }
}

int solution1(int A[], int N) {
    int i;
    int min = 1;

    quicksort(A, 0, N - 1);
    for (i = 0; i < N; i++) {
        if (min == A[i]) {
            min++;
        }
    }

    return min;
}

struct bucket_s {
    unsigned int key;
    int value;
    struct bucket_s *next;
};

typedef struct bucket_s bucket_t;

typedef struct {
    int size;
    bucket_t **buckets;
} table_t;

inline static unsigned int
hash(unsigned int x, table_t *tab) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % tab->size;
}

inline static int
insert(table_t *tab, int key, int val) {
    unsigned int pos;
    bucket_t **bucket = NULL;

    pos = hash((unsigned int)key, tab);
    bucket = &(tab->buckets[pos]);
    while (*bucket != NULL) {
        if ((*bucket)->key == key) {
            return 1;
        }

        bucket = &(*bucket)->next;
    }

    *bucket = calloc(sizeof(bucket), 1);
    if (*bucket == NULL) {
        return -1;
    }

    (*bucket)->key = key;
    (*bucket)->value = val;
}

inline static int
get(table_t *tab, int key) {
    unsigned int pos;
    bucket_t *bucket = NULL;

    pos = hash((unsigned int)key, tab);
    bucket = tab->buckets[pos];
    while (bucket != NULL)
    {
        if (bucket->key == key) {
            return bucket->value;
        }

        bucket = bucket->next;
    }

    return -1;
}

int solution2(int A[], int N) {
    table_t tab = { 0, NULL };
    int i;

    tab.buckets = calloc(sizeof(bucket_t *), N);
    if (tab.buckets == NULL) {
        return -1;
    }

    tab.size = N;
    for (i = 0; i < N; i++) {
        if (insert(&tab, A[i], 1) == -1) {
            return -1;
        }
    }

    for (i = 1; i <= N; i++) {
        if (get(&tab, i) == -1) {
            return i;
        }
    }
}

// Todo free_hash_table

int main() {
    int A[] = { 1, 2, 3, 4, 3, 5 };

    printf("Result: %d\n", solution2(A, 6));
    return 0;
}
