#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de nó da lista circular
typedef struct Node {
    char name[31];
    int token;
    struct Node* next;
    struct Node* prev;
} Node;

// Função para criar um novo nó
Node* createNode(char name[], int token) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->token = token;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Função para remover um nó da lista
Node* removeChild(Node* current, char direction[], int count) {
    for (int i = 0; i < count - 1; i++) {
        if (strcmp(direction, "clockwise") == 0) {
            current = current->next;
        } else {
            current = current->prev;
        }
    }

    Node* nextChild = current->next;
    Node* prevChild = current->prev;
    nextChild->prev = prevChild;
    prevChild->next = nextChild;

    return nextChild;
}

// Função principal para resolver o problema
void solve() {
    while (1) {
        int N;
        scanf("%d", &N);

        if (N == 0) {
            break;
        }

        // Criação da lista circular
        Node* children[N];
        Node* startChild = NULL;

        for (int i = 0; i < N; i++) {
            char name[31];
            int token;
            scanf("%s %d", name, &token);

            Node* child = createNode(name, token);
            children[i] = child;

            if (startChild == NULL) {
                startChild = child;
            }

            if (i > 0) {
                Node* prevChild = children[i - 1];
                child->prev = prevChild;
                prevChild->next = child;
            }
        }

        // Obtenção do nó inicial e do valor do token
        int startIdx;
        scanf("%d", &startIdx);
        int tokenValue = children[startIdx - 1]->token;

        // Definição da direção da contagem
        char direction[12];
        strcpy(direction, (tokenValue % 2 == 0) ? "clockwise" : "counterclockwise");

        // Jogo
        Node* current = children[startIdx - 1];
        while (N > 1) {
            current = removeChild(current, direction, tokenValue);
            strcpy(direction, (current->token % 2 == 0) ? "clockwise" : "counterclockwise");
            N--;
        }

        // Impressão do vencedor
        printf("Vencedor(a): %s\n", children[0]->name);
    }
}

int main() {
    solve();
    return 0;
}
