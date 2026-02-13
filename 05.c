#include <stdio.h>

struct node
{
    int value;
    struct node* ptr;
};

typedef struct node Node;

int main()
{
    Node a, b, c;
    
    a.value = 10;
    b.value = 20;
    c.value = 30;
    
    a.ptr = &b;
    b.ptr = &c;
    c.ptr = &a;
    
    Node* current = &a;
    while (1) {
        printf("%d\n", current->value);
        current = current->ptr;
    }
    
    return 0;
}