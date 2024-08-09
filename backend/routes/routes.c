#include <stdio.h>
#include <stdlib.h>

#include "../cria_libera/cria_libera.h"
#include "../entrega/entrega.h"
#include "../exibir/exibir.h"
#include "routes.h"

void filaRota(Rota *rota,FilaListaRota **listaRota){
	ListaRota *novo;
	novo = (ListaRota*)malloc(sizeof(ListaRota));
	if(!novo){
		printf("Nao foi possivel alocar para devolucao\n");
		exit(1);
	}

	novo->rota = rota;
	novo->prox = NULL;

	if(rotaVazia((*listaRota))){

		FilaListaRota *aux = (FilaListaRota*)malloc(sizeof(FilaListaRota));

		rota->id_rota = 1;
		aux->fim = novo;
		aux->ini = novo;

		*listaRota = aux;

		return;
	}

	rota->id_rota = (*listaRota)->fim->rota->id_rota + 1;

	(*listaRota)->fim->prox = novo;
	(*listaRota)->fim = novo;
}

void removefilaRota(FilaListaRota **listaRota){
	if(*listaRota != NULL){
		ListaRota *aux = (*listaRota)->ini;

		if(aux->prox == NULL){
			(*listaRota) = NULL;
		}else{
			(*listaRota)->ini = aux->prox;
		}
	}
}

void cadastroRota(FilaListaRota **listaRota, FilaListaPedido *listaPedido){
	
	if(listaPedidoVazia(listaPedido)){
		printf("Nao ha pedidos para criar rota\n");
		return;
	}

	if((*listaRota) == NULL || (*listaRota)->fim->rota->score != 0){
		Rota *rota = (Rota*)malloc(sizeof(Rota));	
		
		rota->score = 0;
		rota->entrega = criaListaEntregraRota(listaPedido->ini);
		
		if(rota->entrega == NULL){
			printf("Nao foi possivel criar a rota, verifique se a pedidos cadastrados\n");
			return;
		}else{
			printf("Rota criada\n");
		}
		rota->segundaEntrega = criaListaSegundaEntrega();
		rota->devolucao = criaListaDevolucao();
		rota->historico = criaListaHistorico();

		filaRota(rota,listaRota);
		return;
	}else{
		printf("Rota nao cadastrado, ate que a anterior seja concluida\n");
	}
}

void procurarRota(ListaRota *rota, int id){
	if(rota == NULL){
		printf("Rota nao encontrada\n");
		return;
	}

	if(rota->rota->id_rota == id){
		exibirInfoRota(rota->rota);
		return;
	}

	procurarRota(rota->prox,id);
}

void finalizarRota(Rota **rota,ListaHistorico *lista){
	if(*rota == NULL){
		return;
	}
	if(lista == NULL){
		return;
	}

	if(lista->pedido->status == 2){
		(*rota)->score += 5;
	}else if(lista->pedido->status == 3){
		(*rota)->score += 3;
	}else if(lista->pedido->status == 5){
		(*rota)->score -= 1;
	}

	finalizarRota(rota,lista->prox);
}

void adicionaHistorico(Pedido *pedido,ListaHistorico **listahistorico){
	ListaHistorico *novo;
	novo = (ListaHistorico*)malloc(sizeof(ListaHistorico));

	if(novo == NULL){
		printf("Nao foi possivel alocar para historico\n");
		exit(1);
	}

	novo->pedido = pedido;
	novo->prox = *listahistorico;

	*listahistorico = novo;
}

FilaListaEntrega * criaListaEntregraRota(ListaPedido *listaPedido){
	FilaListaEntrega *entregas = criaListaEntrega();

	entregaRota(&entregas,listaPedido);

	return entregas;
}

void entregaRota(FilaListaEntrega **listaEntrega,ListaPedido *listaPedido){

	if(listaPedido == NULL){
		return;
	}
	
	verificarPedidosCliente(listaEntrega,listaPedido, listaPedido->pedido->id_cliente);
	
	entregaRota(listaEntrega,listaPedido->prox);
}

void verificarPedidosCliente(FilaListaEntrega **listaEntrega, ListaPedido *listaPedido,int id){
	if(listaPedido == NULL){
		return;
	}
	
	if(listaPedido->pedido->id_cliente == id && listaPedido->pedido->status == 0){

		pedidoFilaEntrega(listaPedido->pedido,listaEntrega);
		
		listaPedido->pedido->status = 1;
	}
	
	verificarPedidosCliente(listaEntrega,listaPedido->prox,id);
}