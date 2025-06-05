#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void push(int *stk, int *top, int item) {
    *top = *top + 1;
    stk[*top] = item;
}

int pop(int *stk, int *top) {
    if (*top == -1) {
        return 0;
    }
    int item = stk[*top];
    *top = *top - 1;
    return item;
}

int main() {
    int *stk, len, top = -1, item = 0, i = 0;
    stk = (int *)malloc(sizeof(int) * MAX);
    char *str = (char *)malloc(sizeof(char) * 100);

    printf("Enter the postfix expression:\n");
    fgets(str, 100, stdin);

    len = strlen(str);
    while (i < len) {
        if (str[i] >= '0' && str[i] <= '9') {
            item = 0;
            while (i < len && str[i] >= '0' && str[i] <= '9') {
                item = item * 10 + (str[i] - '0');
                i++;
            }
            push(stk, &top, item);
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int top1 = pop(stk, &top);
            int top2 = pop(stk, &top);
            switch (str[i]) {
                case '+':
                    push(stk, &top, top2 + top1);
                    break;
                case '-':
                    push(stk, &top, top2 - top1);
                    break;
                case '*':
                    push(stk, &top, top2 * top1);
                    break;
                case '/':
                    if (top1 != 0)
                        push(stk, &top, top2 / top1);
                    else
                        printf("Division by zero!\n");
                    break;
            }
            i++;
        } else {
            i++;
        }
    }

    int res = pop(stk, &top);
    printf("Result is: %d\n", res);

    free(stk);
    free(str);
    return 0;
}
