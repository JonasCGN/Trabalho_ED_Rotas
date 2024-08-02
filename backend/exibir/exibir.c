#include <stdio.h>
#include <stdlib.h>

#include "../estrutura/estrutura.h"
#include "exibir.h"

void exibirPedido(Pedido *pedido){
	char* status[5] = {
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

void exibirClientes(ListaCliente *cliente){
    if (cliente == NULL) {
        return;
    }

    printf("ID %d\n", cliente->cliente->id_cliente);
    printf("Nome: %s\n", cliente->cliente->nome);
    printf("CPF: %s\n", cliente->cliente->cpf);
    printf("Telefone: %s\n", cliente->cliente->telefone);
    printf("Email: %s\n", cliente->cliente->email);
    printf("Endereco: %s\n", cliente->cliente->endereco);
    printf("\n");

    exibirClientes(cliente->prox);
}

void mostrarHistorico(ListaHistorico *historico){
	if(historico == NULL)
		return;

	exibirPedido(historico->pedido);
	mostrarHistorico(historico->prox);
}

void exibirEntrega(ListaEntrega *entregas){
    if(entregas == NULL)
        return;
    exibirPedido(entregas->pedido);
    exibirEntrega(entregas->prox);
} 