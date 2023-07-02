#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no início da lista
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Função para inserir um nó no fim da lista
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Função para exibir a lista do início ao fim
void displayForward(Node* head) {
    printf("Lista: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Função para exibir a lista do fim ao início
void displayBackward(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    printf("Lista (Reversa): ");
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

// Função principal
int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);

    displayForward(head);
    displayBackward(head);

    return 0;
}
