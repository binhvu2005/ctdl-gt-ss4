#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


void displayList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;


    printf("so luong phan tu: ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        printf("phan tu  %d: ", i + 1);
        scanf("%d", &value);
        insertAtHead(&head, value);
    }

    printf("gia tri muon chen: ");
    scanf("%d", &value);

    insertAtHead(&head, value);

    printf("danh sách sau khi chèn: ");
    displayList(head);

    return 0;
}

