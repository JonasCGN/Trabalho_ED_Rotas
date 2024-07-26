#include <stdio.h>
#include "pedidos.h"
#include "../backend/estrutura/estrutura.h"

Pedido cadastrarPedido(Pedido *pedido){
    printf("Digite o id do cliente: ");
    scanf("%d", &pedido->id_cliente);
    printf("Digite o item: ");
    scanf("%s", pedido->item);
    printf("Digite a quantidade: ");
    scanf("%d", &pedido->quantidade);
    printf("Digite o valor: ");
    scanf("%f", &pedido->valor);
    pedido->status = 0;
    return *pedido;
}

void PedidoFila(Pedido *pedido, ListaEntrega *entregas){
    ListaEntrega *novo = (ListaEntrega*)malloc(sizeof(ListaEntrega));
    novo->pedido = pedido;
    novo->prox = NULL;
    if(entregas == NULL){
        entregas = novo;
    }else{
        ListaEntrega *aux = entregas;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }

}

void exibirEntrega(ListaEntrega *entregas){
    if(entregas == NULL)
        return;
    exibirPedido(entregas->pedido);
    exibirEntrega(entregas->prox);
}