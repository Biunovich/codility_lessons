#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *arr;
    int capacity;
    int top;
} stack_t;

inline static stack_t *
create_stack(int capacity) {
    stack_t *stack = NULL;

    stack = calloc(sizeof(stack_t), 1);
    if (stack == NULL) {
        return stack;
    }

    stack->arr = malloc(sizeof(int) * capacity);
    if (stack->arr == NULL) {
        free(stack);
        stack = NULL;
        return stack;
    }

    stack->capacity = capacity;
    stack->top = 0;

    return stack;
}

inline static void
push(stack_t *stack, int w) {
    if (stack->top < stack->capacity) {
        stack->arr[stack->top] = w;
        stack->top++;
    }
}

inline static int
top(stack_t *stack) {
    if (stack->top > 0) {
        stack->top--;
        return stack->arr[stack->top];
    }

    return -1;
}

inline static int
is_empty(stack_t *stack) {
    if (stack->top == 0) {
        return 1;
    } else {
        return 0;
    }
}

inline static int
size(stack_t *stack) {
    return stack->top;
}

int solution(int A[], int B[], int N) {
    stack_t *stack = NULL;
    int i;
    int alive = 0;

    stack = create_stack(N);
    for (i = 0; i < N; i++) {
        if (B[i] == 0) {
            if (is_empty(stack)) {
                alive++;
                continue;
            }

            while (!is_empty(stack)) {
                int fish_w = top(stack);
                if (A[i] < fish_w) {
                    push(stack, fish_w);
                    break;
                }
            }

            if (is_empty(stack)) {
                alive++;
            }
        }

        if (B[i] == 1) {
            push(stack, A[i]);
        }
    }

    return alive + size(stack);
}

int main() {
    int A[] = { 4, 3, 2, 1, 5 };
    int B[] = { 0, 1, 0, 0, 0 };

    printf("Result: %d\n", solution(A, B, 5));
    return 0;
}
