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

void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Danh sách tr?ng\n");
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
        appendNode(&head, value);
    }

    printf("danh sach truoc khi xoa: ");
    displayList(head);


    deleteFirstNode(&head);

    printf("sau khi xoa: ");
    displayList(head);

    return 0;
}

