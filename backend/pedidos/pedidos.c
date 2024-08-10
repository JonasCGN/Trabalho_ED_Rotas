#include <stdio.h>
#include <stdlib.h>

#include "../clients/cliente.h"
#include "../cria_libera/cria_libera.h"
#include "../exibir/exibir.h"
#include "../blindagem/blindagem.h"
#include "pedidos.h"

void adicionaPedido(ListaPedido **listaPedido, Pedido *pedido){
    ListaPedido *novo;
	novo = (ListaPedido*)malloc(sizeof(ListaPedido));

	if(!novo){
		printf("Nao foi possivel alocar para pedido\n");
		return;
	}

	novo->pedido = pedido;
	novo->prox = (*listaPedido);

}

Pedido* cadastrarPedido(ListaPedido **listaPedido, ListaCliente *listaCliente){
    Pedido *pedido = (Pedido*)malloc(sizeof(Pedido));

    printf("Digite o id do cliente: ");
    int id = numero(1, 1100000);

    if(!verificaCliente(listaCliente,id))
        return NULL;
    printf("Cliente encontrado\n");
    pedido->id_cliente = id;
    
    if(listaPedidoVazia(*listaPedido))
        pedido->id_pedido = 1;
    else
        pedido->id_pedido = (*listaPedido)->pedido + 1;

    printf("Digite o item: ");
    verifica_letra(pedido->item, 20);

    printf("Digite a quantidade: ");

    pedido->quantidade = numero(1, 5);

    printf("Digite o valor: ");
    pedido->valor = verifica_n_float(5);
    
    pedido->status = 0;

    adicionaPedido(listaPedido, pedido);

    return pedido;
}

void pedidoId(ListaPedido *listapedido,int id){
    
    if(listapedido->pedido->id_pedido == id){
        exibirPedido(listapedido->pedido);
        getchar();
        return;
    }

    pedidoId(listapedido->prox,id);
}

ListaPedido* pedidoIdExclui(ListaPedido *listapedido,int id){
    if(listapedido == NULL)
        return NULL;

    if(listapedido->pedido->id_pedido == id){
        Pedido *remove = listapedido->pedido;
        ListaPedido *aux = listapedido;

        listapedido->prox = aux->prox;
        free(remove);

        return listapedido;
    }

    return pedidoIdExclui(listapedido->prox,id);
}