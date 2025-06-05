/* 
**    Função : Definição de structs e protótipos do Sistema de Gerenciamento de Tarefas
**    Autor : Jucieélen Valéria Souza - Turma P2 A
**    Data  : 05/06/2025
**    Observações: Estruturas para Lista, Pilha, Fila e Deque de Tarefas.
*/

#ifndef TODO_H
#define TODO_H

typedef struct {
    char descricao[100];
    int prioridade; // 1-baixa, 2-média, 3-alta
    int dataVencimento; // formato DDMMYYYY
} Tarefa;

// Lista de Tarefas (To-Do)
typedef struct NodoLista {
    Tarefa tarefa;
    struct NodoLista* prox;
} NodoLista;

// Pilha de Tarefas Concluídas
typedef struct NodoPilha {
    Tarefa tarefa;
    struct NodoPilha* prox;
} NodoPilha;

// Fila de Agendamentos
typedef struct NodoFila {
    Tarefa tarefa;
    struct NodoFila* prox;
} NodoFila;

// Deque
typedef struct NodoDeque {
    Tarefa tarefa;
    struct NodoDeque* ant;
    struct NodoDeque* prox;
} NodoDeque;

// Lista
void adicionarTarefa(NodoLista** lista, Tarefa t);
void listarTarefas(NodoLista* lista);
int contarTarefas(NodoLista* lista);

// Pilha
void empilharTarefa(NodoPilha** pilha, Tarefa t);
void listarTarefasConcluidas(NodoPilha* pilha);

// Fila
void enfileirarTarefa(NodoFila** inicio, NodoFila** fim, Tarefa t);
Tarefa desenfileirarTarefa(NodoFila** inicio);

// Deque
void inserirInicioDeque(NodoDeque** ini, NodoDeque** fim, Tarefa t);
void inserirFimDeque(NodoDeque** ini, NodoDeque** fim, Tarefa t);
void listarDeque(NodoDeque* ini);

#endif
