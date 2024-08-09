#include <stdio.h>
#include <stdlib.h>

#include "../clients/cliente.h"
#include "../blindagem/blindagem.h"
#include "pedidos.h"

void adicionaPedido(ListaPedido **listaPedido, Pedido *pedido){
    ListaPedido *novo = (ListaPedido*) malloc(sizeof(ListaPedido));

    novo->pedido = pedido;
    novo->prox = *listaPedido;

    *listaPedido = novo;

}

Pedido* cadastrarPedido(ListaPedido **listaPedido, ListaCliente **listaCliente){
    Pedido *pedido = (Pedido*)malloc(sizeof(Pedido));

    printf("Digite o id do cliente: ");
    int id = numero(1, 1100000);

    if(!verificaCliente(*listaCliente,id))
        return NULL;
    printf("\nCliente encontrado\n");
    pedido->id_cliente = id;

    printf("Digite o item: ");
    verifica_letra(pedido->item, 20);

    printf("\nDigite a quantidade: ");
    pedido->quantidade = numero(1, 5);

    printf("\nDigite o valor: ");
    pedido->valor = verifica_n_float(1);
    
    pedido->status = 0;

    // Verifica o id de todos os pedidos e atribui automaticamente o próximo valor como id
    ListaPedido *auxId = *listaPedido;
    int novoId = 1;

    while (auxId != NULL) {
        if (auxId->pedido->id_pedido >= novoId) {
            novoId = auxId->pedido->id_pedido + 1;
        }
        auxId = auxId->prox;
    }

    pedido->id_pedido = novoId;
   

    adicionaPedido(listaPedido, pedido);

    return pedido;
}

void procurarPedido(ListaPedido *listaPedido, int id){
    ListaPedido *aux = listaPedido;

    while(aux != NULL){
        if(aux->pedido->id_pedido == id){
            printf("Pedido encontrado\n");
            printf("ID: %d\n", aux->pedido->id_pedido);
            printf("ID Cliente: %d\n", aux->pedido->id_cliente);
            printf("Item: %s\n", aux->pedido->item);
            printf("Quantidade: %d\n", aux->pedido->quantidade);
            printf("Valor: %.2f\n", aux->pedido->valor);
            printf("Status: %d\n", aux->pedido->status);
            return;
        }
        aux = aux->prox;
    }
    printf("Pedido não encontrado\n");
}


