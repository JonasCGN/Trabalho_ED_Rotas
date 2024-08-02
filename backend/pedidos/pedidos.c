#include <stdio.h>

#include "pedidos.h"

Pedido* cadastrarPedido(){
    Pedido *pedido = (Pedido*) malloc(sizeof(Pedido));

    printf("Digite o id do cliente: ");
    scanf("%d", &pedido->id_cliente);
    printf("Digite o item: ");
    scanf("%s", pedido->item);
    printf("Digite a quantidade: ");
    scanf("%d", &pedido->quantidade);
    printf("Digite o valor: ");
    scanf("%f", &pedido->valor);
    
    pedido->status = 0;
    
    return pedido;
}
