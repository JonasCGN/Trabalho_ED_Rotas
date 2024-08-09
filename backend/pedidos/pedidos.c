#include <stdio.h>
#include <stdlib.h>

#include "../clients/cliente.h"
#include "../cria_libera/cria_libera.h"
#include "../exibir/exibir.h"
#include "../blindagem/blindagem.h"
#include "pedidos.h"

static int proxid = 1;

void adicionaPedido(ListaPedido **listaPedido, Pedido *pedido){
    ListaPedido *novo = (ListaPedido*) malloc(sizeof(ListaPedido));
    
    if(!novo){
        printf("Erro ao alocar memoria para lista pedidos");
        return;
    }
    
    novo->pedido = pedido;
    novo->prox = *listaPedido;

    *listaPedido = novo;

}

Pedido* cadastrarPedido(ListaPedido **listaPedido, ListaCliente *listaCliente){
    Pedido *pedido = (Pedido*)malloc(sizeof(Pedido));

    printf("Digite o id do cliente: ");
    int id = numero(1, 1100000);

    if(!verificaCliente(listaCliente,id))
        return NULL;
    printf("\nCliente encontrado\n");
    pedido->id_cliente = id;

    pedido->id_pedido = proxid;
    proxid++;

    printf("Digite o item: ");
    verifica_letra(pedido->item, 20);

    printf("\nDigite a quantidade: ");
    pedido->quantidade = numero(1, 5);

    printf("\nDigite o valor: ");
    pedido->valor = verifica_n_float(5);
    
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

void pedidoId(ListaPedido *listapedido,int id){
    if(listaPedidoVazia(listapedido)){
        return;
    }
    
    if(listapedido->pedido->id_pedido == id){
        exibirPedido(listapedido->pedido);
        return;
    }

    pedidoId(listapedido->prox,id);
}