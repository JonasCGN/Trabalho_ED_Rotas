#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../estrutura/estrutura.h"
#include "../cria_libera/cria_libera.h"
#include "exibir.h"

void exibirPedido(Pedido *pedido){
	char* status[6] = {
		"Pendente",
		"Em Transito",
		"Entregue",
		"Segunda Tentativa",
		"Processo de Devolucao",
		"Devolucao Concluida"
	};

	printf("\n--------------------------------------\n");
	printf("ID Pedido: %d\n",pedido->id_pedido);
	printf("ID Cliente: %d\n",pedido->id_cliente);
	printf("Nome: %s\n",pedido->item);
	printf("Quantidade: %03d\n",pedido->quantidade);
	printf("Valor: %.2f\n",pedido->valor);
	printf("Status: %s\n",status[pedido->status]);
	printf("--------------------------------------\n");
}

void exibirInfoCliente(Cliente *cliente){
	printf("\n--------------------------------------\n");
	printf("ID %d\n", cliente->id_cliente);
	printf("Nome: %s\n", cliente->nome);
	printf("CPF: %s\n", cliente->cpf);
	printf("Telefone: %s\n", cliente->telefone);
	printf("Email: %s\n", cliente->email);
	printf("Endereco: %s\n", cliente->endereco);
	printf("\n--------------------------------------\n");
}

void mostrarClientes(ListaCliente *listacliente){
	if(listaClienteVazia(listacliente)){
		printf("Nenhum cliente cadastrado!\n");
		return;
	}

	exibirClientes(listacliente);
}

void exibirClientes(ListaCliente *listacliente){
    if (listacliente == NULL) {
        return;
    }

    exibirClientes(listacliente->prox);
    exibirInfoCliente(listacliente->cliente);

}

void exibirInfoRota(Rota *rota){
	if(rota == NULL)
		return;

	printf("ID Rota: %d\n", rota->id_rota);
	printf("Score: %d\n", rota->score);
	exibirPedido(rota->entrega->ini->pedido);
	printf("\n");
}

void exibirRotas(ListaRota *listaRota){
	if(listaRota == NULL)
		return;

	exibirInfoRota(listaRota->rota);
	exibirRotas(listaRota->prox);
}

void exibirEntrega(ListaEntrega *entregas){
    if(entregas == NULL)
        return;

    exibirPedido(entregas->pedido);
    exibirEntrega(entregas->prox);
} 

void exibirSegundaEntrega(PilhaSegundaEntrega *listasegunda){
	if(listasegunda == NULL)
        return;

    exibirPedido(listasegunda->pedido);
    exibirSegundaEntrega(listasegunda->prox);
}

void exibirDevolucao(ListaDevolucao *listaDevolucao){
	if(listaDevolucao == NULL)
        return;

    exibirPedido(listaDevolucao->pedido);
    exibirDevolucao(listaDevolucao->prox);
}

void mostrarPedidos(ListaPedido *lista){
	if(lista == NULL)
		return;
		
	mostrarPedidos(lista->prox);
	exibirPedido(lista->pedido);
}

void exibirHistorico(ListaHistorico *listahistorico){
	if(listahistorico == NULL)
		return;
		
	exibirPedido(listahistorico->pedido);
	exibirHistorico(listahistorico->prox);
}

void exibirPedidosDeRotas(ListaRota *listaRota){
	if(listaRota == NULL)
		return;

	exibirEntrega(listaRota->rota->entrega->ini);
	exibirPedidosDeRotas(listaRota->prox);
}

void exibirPedidosPorIdCliente(ListaPedido *listaPedido, int idCliente){
	if(listaPedido == NULL)
		return;

	if(listaPedido->pedido->id_cliente == idCliente)
		exibirPedido(listaPedido->pedido);

	exibirPedidosPorIdCliente(listaPedido->prox,idCliente);
}