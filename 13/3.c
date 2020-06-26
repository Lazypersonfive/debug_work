#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} Node;

Node* circle_create(int n);
void count_off(Node* head, int n, int k, int m);

int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    Node* head = circle_create(n);
    count_off(head, n, k, m);
    return 0;
}

Node* circle_create(int n)
{
    Node *temp, *new_node, *head;
    int i;

    // create the first node and assign it
    temp = (Node*)malloc(sizeof(Node));
    head = temp;
    head->data = 1;

    // create the rest nedes and assign them
    for (i = 2; i <= n; i++) {
        new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i;
        temp->next = new_node;
        temp = new_node;
    }

    // set "next" of the last node towards the first one
    temp->next = head;

    return head;
}

void count_off(Node* head, int n, int k, int m)
{
    int x, y;
    Node* find;
    Node* temp; // temp: the previous node of find
    temp = head;
    if (k == 1) {
        for (x = 1; x < n; x++) {
            temp = temp->next;
        }
    } else {
        for (x = 1; x < k - 1; x++) {
            temp = temp->next;
        }
    } // get to the node ahead of the start one

    for (y = 0; y < n; y++) {
        for (x = 1; x < m; x++) {
            temp = temp->next;
        }
        find = temp->next;

        printf("%d", find->data);
        if (y != n - 1) {
            printf(" ");
        }
        temp->next = find->next;
        free(find);
    }

    return;
}
