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
size(stack_t *stack) {
    return stack->top;
}

inline static int
is_empty(stack_t *stack) {
    if (stack->top == 0) {
        return 1;
    } else {
        return 0;
    }
}

int solution(int H[], int N) {
    stack_t *stack = NULL;
    int i;
    int prev;
    int count = 0;

    stack = create_stack(N);
    for (i = 0; i < N; i++) {
        if (is_empty(stack)) {
            push(stack, H[i]);
            continue;
        }

        while (!is_empty(stack)) {
            prev = top(stack);
            if (prev < H[i]) {
                push(stack, prev);
                push(stack, H[i]);
                break;
            }

            if (prev == H[i]) {
                push(stack, prev);
                break;
            }

            count++;
        }

        if (is_empty(stack)) {
            push(stack, H[i]);
        }
    }
    

    return count + size(stack);
}

int main() {
    int H[] = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };

    printf("Result: %d\n", solution(H, 9));
    return 0;
}
