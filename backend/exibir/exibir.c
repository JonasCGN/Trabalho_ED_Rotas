#include <stdio.h>
#include <stdlib.h>

#include "../estrutura/estrutura.h"
#include "exibir.h"

void exibirPedido(Pedido *pedido){
	char* status[25] = {
		"Pendente",
		"Entregue",
		"Segunda Tentativa",
		"Processo de Devolucao",
		"Devolucao Concluida"
	};

	printf("--------------------------------------\n");
	printf("Nome: %s\n",pedido->item);
	printf("Quantidade: %03d\n",pedido->quantidade);
	printf("Valor: %.2f\n",pedido->valor);
	printf("Nome: %s\n",status[pedido->status]);
	printf("--------------------------------------\n");
}

void mostrarHistorico(ListaHistorico *historico){
	if(historico == NULL)
		return;

	exibirPedido(historico->pedido);
	mostrarHistorico(historico->prox);
}