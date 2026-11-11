#include <stdio.h>
#include <stdlib.h>

// CÓDIGO PRODUZIDO PELO GEMINI...
// 1. Definir os tipos de nós que a árvore pode ter
typedef enum {
    NODE_NUMERO,
    NODE_OPERADOR
} TipoNo;

// 2. Definir a estrutura do nó da AST
typedef struct Node {
    TipoNo tipo;
    int valor;               // Usado se o tipo for NODE_NUMERO
    char operador;           // Usado se o tipo for NODE_OPERADOR ('+')
    struct Node* esquerda;   // Filho da esquerda
    struct Node* direita;    // Filho da direita
} Node;

// Função para criar um nó de número (Folha)
Node* criarNoNumero(int valor) {
    Node* no = (Node*)malloc(sizeof(Node));
    no->tipo = NODE_NUMERO;
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

// Função para criar um nó de operador
Node* criarNoOperador(char operador, Node* esquerda, Node* direita) {
    Node* no = (Node*)malloc(sizeof(Node));
    no->tipo = NODE_OPERADOR;
    no->operador = operador;
    no->esquerda = esquerda;
    no->direita = direita;
    return no;
}

// 3. Função para avaliar (mudar/calcular) o valor da AST
int avaliarAST(Node* raiz) {
    if (raiz == NULL) return 0;

    // Se for um número, apenas retorna o valor
    if (raiz->tipo == NODE_NUMERO) {
        return raiz->valor;
    }

    // Se for um operador, avalia a esquerda e a direita e aplica a operação
    if (raiz->tipo == NODE_OPERADOR) {
        int esq = avaliarAST(raiz->esquerda);
        int dir = avaliarAST(raiz->direita);

        if (raiz->operador == '+') {
            return esq + dir;
        }
    }
    return 0;
}

// Função simples para liberar a memória da árvore
void liberarAST(Node* raiz) {
    if (raiz == NULL) return;
    liberarAST(raiz->esquerda);
    liberarAST(raiz->direita);
    free(raiz);
}

int main() {
    // Vamos construir manualmente a AST para a expressão: "3 + 5"
    //     [ + ]
    //    /     \
    //  [3]     [5]

    Node* no3 = criarNoNumero(3);
    Node* no5 = criarNoNumero(5);
    Node* raiz = criarNoOperador('+', no3, no5);

    // AQUI A FUNÇÃO DE RECURSÃO QUE PERCORRE NÓS DA ÁRVORE
    // Avaliar e printar o resultado
    int resultado = avaliarAST(raiz);
    printf("O resultado da avaliacao da AST (3 + 5) eh: %d\n", resultado);

    // Liberar a memória alocada
    liberarAST(raiz);

    return 0;
}
