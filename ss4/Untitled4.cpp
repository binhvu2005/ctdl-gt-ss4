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


int searchList(struct Node* head, int value) {
    struct Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; 
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
    int n, value, searchValue, index;

    printf("so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d: ", i + 1);
        scanf("%d", &value);
        appendNode(&head, value);
    }


    printf(" search: ");
    scanf("%d", &searchValue);

 
    index = searchList(head, searchValue);

    if (index != -1) {
        printf("vi tri: %d\n", index);
    } else {
        printf("khong co phan tu can tim\n");
    }

    return 0;
}

