/* 
**    Função : Implementação das funções do Sistema de Gerenciamento de Tarefas
**    Autor : Jucieélen Valéria Souza - Turma P2 A
**    Data  : 05/06/2025
**    Observações: Implementação de Lista, Pilha, Fila, Deque e Recursividade.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ED-lista2-questao04.h"

// Lista
void adicionarTarefa(NodoLista** lista, Tarefa t) {
    NodoLista* novo = malloc(sizeof(NodoLista));
    novo->tarefa = t;
    novo->prox = *lista;
    *lista = novo;
}

void listarTarefas(NodoLista* lista) {
    printf("\nTarefas pendentes:\n");
    while(lista) {
        printf("%s - Prioridade: %d - Vence: %d\n", lista->tarefa.descricao,
               lista->tarefa.prioridade, lista->tarefa.dataVencimento);
        lista = lista->prox;
    }
}

int contarTarefas(NodoLista* lista) {
    if(!lista) return 0;
    return 1 + contarTarefas(lista->prox);
}

// Pilha
void empilharTarefa(NodoPilha** pilha, Tarefa t) {
    NodoPilha* novo = malloc(sizeof(NodoPilha));
    novo->tarefa = t;
    novo->prox = *pilha;
    *pilha = novo;
}

void listarTarefasConcluidas(NodoPilha* pilha) {
    printf("\nTarefas concluídas:\n");
    while(pilha) {
        printf("%s - Prioridade: %d - Venceu: %d\n", pilha->tarefa.descricao,
               pilha->tarefa.prioridade, pilha->tarefa.dataVencimento);
        pilha = pilha->prox;
    }
}

// Fila
void enfileirarTarefa(NodoFila** inicio, NodoFila** fim, Tarefa t) {
    NodoFila* novo = malloc(sizeof(NodoFila));
    novo->tarefa = t;
    novo->prox = NULL;
    if(*fim) (*fim)->prox = novo;
    else *inicio = novo;
    *fim = novo;
}

Tarefa desenfileirarTarefa(NodoFila** inicio) {
    NodoFila* temp = *inicio;
    Tarefa t = temp->tarefa;
    *inicio = temp->prox;
    free(temp);
    return t;
}

// Deque
void inserirInicioDeque(NodoDeque** ini, NodoDeque** fim, Tarefa t) {
    NodoDeque* novo = malloc(sizeof(NodoDeque));
    novo->tarefa = t;
    novo->ant = NULL;
    novo->prox = *ini;
    if(*ini) (*ini)->ant = novo;
    else *fim = novo;
    *ini = novo;
}

void inserirFimDeque(NodoDeque** ini, NodoDeque** fim, Tarefa t) {
    NodoDeque* novo = malloc(sizeof(NodoDeque));
    novo->tarefa = t;
    novo->prox = NULL;
    novo->ant = *fim;
    if(*fim) (*fim)->prox = novo;
    else *ini = novo;
    *fim = novo;
}

void listarDeque(NodoDeque* ini) {
    printf("\nDeque de Tarefas:\n");
    while(ini) {
        printf("%s - Prioridade: %d - Vence: %d\n", ini->tarefa.descricao,
               ini->tarefa.prioridade, ini->tarefa.dataVencimento);
        ini = ini->prox;
    }
}
