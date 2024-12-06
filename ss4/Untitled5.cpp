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


void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    int index = 0;
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        free(newNode); 
        return;
    }


    newNode->next = temp->next;
    temp->next = newNode;
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Danh sách trong\n");
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
    int n, value, position;


    printf("so luong phan tu: ");
    scanf("%d", &n);
	
    for (int i = 0; i < n; i++) {
        printf("phan tu %d: ", i + 1);
        scanf("%d", &value);
        appendNode(&head, value);
    }

    printf("gia tri can chen: ");
    scanf("%d", &value);
    printf("trij tri can chen: ");
    scanf("%d", &position);


    insertAtPosition(&head, value, position);


    printf("sau khi them: ");
    displayList(head);

    return 0;
}

