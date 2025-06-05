/* 
**    Função : Programa principal para testar o Sistema de Gerenciamento de Tarefas
**    Autor : Jucieélen Valéria Souza - Turma P2 A
**    Data  : 05/06/2025
**    Observações: Menu de interação com Lista, Pilha, Fila e Deque.
*/

#include <stdio.h>
#include <string.h>
#include "ED-lista2-questao04.h"

int main() {
    NodoLista* lista = NULL;
    NodoPilha* pilha = NULL;
    NodoFila* filaIni = NULL, *filaFim = NULL;
    NodoDeque* dequeIni = NULL, *dequeFim = NULL;

    Tarefa t;
    int op;

    do {
        printf("\n1-Adicionar Tarefa\n2-Listar Tarefas\n3-Concluir Tarefa\n4-Agendar Tarefa\n5-Inserir no Deque\n6-Listar Deque\n7-Contar Tarefas\n0-Sair\n");
        scanf("%d", &op);
        getchar();

        switch(op) {
            case 1:
                printf("Descrição: ");
                fgets(t.descricao, 100, stdin);
                t.descricao[strcspn(t.descricao, "\n")] = 0;

                printf("Prioridade (1-3): ");
                scanf("%d", &t.prioridade);
                printf("Data Vencimento (DDMMYYYY): ");
                scanf("%d", &t.dataVencimento);

                adicionarTarefa(&lista, t);
                printf("Tarefa adicionada.\n");
                break;

            case 2:
                listarTarefas(lista);
                break;

            case 3:
                if(lista) {
                    Tarefa concluida = lista->tarefa;
                    empilharTarefa(&pilha, concluida);
                    NodoLista* temp = lista;
                    lista = lista->prox;
                    free(temp);
                    printf("Tarefa concluída e movida para a pilha.\n");
                } else {
                    printf("Sem tarefas para concluir.\n");
                }
                break;

            case 4:
                printf("Descrição: ");
                fgets(t.descricao, 100, stdin);
                t.descricao[strcspn(t.descricao, "\n")] = 0;

                printf("Prioridade (1-3): ");
                scanf("%d", &t.prioridade);
                printf("Data Vencimento (DDMMYYYY): ");
                scanf("%d", &t.dataVencimento);

                enfileirarTarefa(&filaIni, &filaFim, t);
                printf("Tarefa agendada.\n");
                break;

            case 5:
                printf("Descrição: ");
                fgets(t.descricao, 100, stdin);
                t.descricao[strcspn(t.descricao, "\n")] = 0;

                printf("Prioridade (1-3): ");
                scanf("%d", &t.prioridade);
                printf("Data Vencimento (DDMMYYYY): ");
                scanf("%d", &t.dataVencimento);

                printf("1-Início ou 2-Fim: ");
                int pos; scanf("%d", &pos);

                if(pos == 1) inserirInicioDeque(&dequeIni, &dequeFim, t);
                else inserirFimDeque(&dequeIni, &dequeFim, t);

                printf("Tarefa inserida no deque.\n");
                break;

            case 6:
                listarDeque(dequeIni);
                break;

            case 7:
                printf("Total de tarefas: %d\n", contarTarefas(lista));
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while(op != 0);

    return 0;
}
