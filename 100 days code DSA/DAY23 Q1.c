//Merge Two Sorted Linked Lists
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

struct Node* merge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

void print(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    struct Node* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);

    struct Node* result = merge(l1, l2);

    print(result);
    return 0;
}