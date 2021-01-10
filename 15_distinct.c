#include <stdio.h>
#include <stdlib.h>

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

int solution(int A[], int N) {
    table_t tab = { 0, NULL };
    int i;
    int distinct = 0;

    tab.buckets = calloc(sizeof(bucket_t *), N);
    if (tab.buckets == NULL) {
        return -1;
    }

    tab.size = N;
    for (i = 0; i < N; i++) {
        if (get(&tab, A[i]) != -1) {
            continue;
        }

        if (insert(&tab, A[i], 1) == -1) {
            return -1;
        }

        distinct++;
    }

    return distinct;
}

int main() {
    int A[] = { 0, 1, 0, 1, 1 };

    printf("Result: %d\n", solution(A, 5));
    return 0;
}
