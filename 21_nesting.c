#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *arr;
    int capasity;
    int top;
} stack_t;

inline static stack_t *
create_stack(int capasity) {
    stack_t *stack = NULL;

    stack = calloc(sizeof(stack_t), 1);
    if (stack == NULL) {
        return stack;
    }

    stack->arr = malloc(sizeof(char) * capasity);
    if (stack->arr == NULL) {
        free(stack);
        stack = NULL;
        return stack;
    }

    stack->capasity = capasity;
    stack->top = 0;

    return stack;
}

inline static void
push(stack_t *stack, char ch) {
    if (stack->top < stack->capasity) {
        stack->arr[stack->top] = ch;
        stack->top++;
    }
}

inline static char
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

int solution(char *S) {
    stack_t *stack = NULL;
    int len;
    int i;

    len = strlen(S);
    stack = create_stack(len);
    for (i = 0; i < len; i++) {
        switch (S[i])
        {
        case '{':
            push(stack, S[i]);
            break;
        case '(':
            push(stack, S[i]);
            break;
        case '[':
            push(stack, S[i]);
            break;
        case '}':
            if (top(stack) != '{') {
                return 0;
            }
            break;
        case ')':
            if (top(stack) != '(') {
                return 0;
            }
            break;
        case ']':
            if (top(stack) != '[') {
                return 0;
            }
            break;
        }
    }

    if (is_empty(stack)) {
        return 1;
    }

    return 0;
}

int main() {
    char *S = "{([])}";

    printf("Result: %d\n", solution(S));
    return 0;
}
