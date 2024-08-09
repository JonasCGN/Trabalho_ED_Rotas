#include <stdio.h>
#include <stdlib.h>

#include "../clients/cliente.h"
#include "../cria_libera/cria_libera.h"
#include "../exibir/exibir.h"
#include "../blindagem/blindagem.h"
#include "pedidos.h"

static int proxid = 1;

void adicionaPedido(FilaListaPedido **listaPedido, Pedido *pedido){
    ListaPedido *novo;
	novo = (ListaPedido*)malloc(sizeof(ListaPedido));
	if(!novo){
		printf("Nao foi possivel alocar para devolucao\n");
		exit(1);
	}

	novo->pedido = pedido;
	novo->prox = NULL;

	if(listaPedidoVazia(*listaPedido)){

		FilaListaPedido *aux = (FilaListaPedido*)malloc(sizeof(FilaListaPedido));

		aux->fim = novo;
		aux->ini = novo;

		*listaPedido = aux;

		return;
	}

	(*listaPedido)->fim->prox = novo;
	(*listaPedido)->fim = novo;

}

Pedido* cadastrarPedido(FilaListaPedido **listaPedido, ListaCliente *listaCliente){
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