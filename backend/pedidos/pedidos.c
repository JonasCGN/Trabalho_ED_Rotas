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

    adicionaPedido(listaPedido, pedido);

    return pedido;
}

