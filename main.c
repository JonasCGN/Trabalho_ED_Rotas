#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backend/estrutura/estrutura.h"
#include "backend/routes/routes.h"
#include "backend/clients/cliente.h"
#include "backend/menu/menu.h"
#include "backend/cria_libera/cria_libera.h"
#include "backend/exibir/exibir.h"

int main(){
	ListaEntrega *entregas = criaListaEntrega();
	ListaSegundaEntrega *segundaEntrega = criaListaSegundaEntrega();
	FilaListaDevolucao *devolucao = criaListaDevolucao();
	FilaListaHistorico *historico = criaListaHistorico();

	Pedido *pedido1 = (Pedido*)malloc(sizeof(Pedido));
	pedido1->id_cliente = 1;
	strcpy(pedido1->item, "Panela");
	pedido1->quantidade = 20;
	pedido1->status = 0;
	pedido1->valor = 10.0;

	// Pedido *pedido2 = (Pedido*)malloc(sizeof(Pedido));
	// pedido2->id_cliente = 2;
	// strcpy(pedido2->item, "Carro");
	// pedido2->quantidade = 1;
	// pedido2->status = 0;
	// pedido2->valor = 1000000;

	// addHistorico(pedido2,&historico);

	adicionaSegundaEntrega(pedido1,&segundaEntrega);
	
	addHistorico(pedido1,&historico);
	
	segundaEntregaDevolucao(&segundaEntrega,&devolucao);
	
	mostrarHistorico(historico->ini);

	getchar();

	liberaPedido(pedido1);
	liberaListaEntrega(entregas);
	liberaListaSegundaEntrega(segundaEntrega);
	liberaFilaListaDevolucao(devolucao);
	liberaFilaListaHistorico(historico);
	
	printf("Executado com sucesso!\n");

	return 0;
}