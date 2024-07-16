#include <stdio.h>
#include <stdlib.h>

#include "../estrutura/estrutura.h"
#include "routes.h"

void removeFila(ListaEntrega **entregas){

}


void removeSegundaEntrega(ListaSegundaEntrega **entregaNE){
	ListaSegundaEntrega *aux = *entregaNE;

	if(*entregaNE != NULL){
		*entregaNE = aux->prox;
	}else{
		printf("Entrega vazia\n");
	}

}

void adicionaSegundaEntrega(Pedido *pedido,ListaSegundaEntrega **entregaNE){
	ListaSegundaEntrega *aux;
	aux = (ListaSegundaEntrega*)malloc(sizeof(ListaSegundaEntrega));
	if(!aux){
		printf("Nao foi possivel alocar para entrega\n");
		exit(1);
	}

	if((*entregaNE) == NULL){
		
		aux->pedido = pedido;
		aux->prox = NULL;

		(*entregaNE) = aux;

		return;
	}

	aux->pedido = pedido;
	aux->prox = (*entregaNE);

	(*entregaNE) = aux;
}

void adicionaDevolucao(Pedido *pedido,FilaListaDevolucao **devolucao){
	ListaDevolucao *novo;
	novo = (ListaDevolucao*)malloc(sizeof(ListaDevolucao));
	if(!novo){
		printf("Nao foi possivel alocar para devolucao\n");
		exit(1);
	}

	novo->pedido = pedido;
	novo->prox = NULL;

	if(devolucaoVazio(*devolucao)){

		FilaListaDevolucao *aux = (FilaListaDevolucao*)malloc(sizeof(FilaListaDevolucao));

		aux->fim = novo;
		aux->ini = novo;

		*devolucao = aux;

		return;
	}

	(*devolucao)->fim->prox = novo;
	(*devolucao)->fim = novo;
}

/*Remove uma entrega da devolução*/
void removeDevolucao(FilaListaDevolucao** devolucao){
	if(*devolucao != NULL){
		ListaDevolucao *aux = (*devolucao)->ini;

		if(aux->prox == NULL){
			(*devolucao) = NULL;
		}else{
			(*devolucao)->ini = aux->prox;
		}
	}
}

void segundaRota(ListaEntrega **entrega,ListaSegundaEntrega **entregaNE){
	if(*entrega != NULL){
		(*entrega)->pedido->status = 2;

		adicionaSegundaEntrega((*entrega)->pedido,entregaNE);
		removeFila(entrega);
	
	}else{
		printf("Não há pedidos para serem entregadoss\n");
	}
}

void entregaNEPilha(ListaSegundaEntrega **entregaNE){
	if(*entregaNE != NULL){
		(*entregaNE)->pedido->status = 2;
		removeSegundaEntrega(entregaNE);
	}else{
		printf("Não há pedidos para serem entregadoss\n");
	}
}

void segundaEntregaDevolucao(ListaSegundaEntrega **entregaNE,FilaListaDevolucao **devolucao){
	if(*entregaNE != NULL){
		(*entregaNE)->pedido->status = 3;
		adicionaDevolucao((*entregaNE)->pedido,devolucao);
		removeSegundaEntrega(entregaNE);
	}else{
		printf("Não há pedidos para serem entregadoss\n");
	}
}

void processoDevolucao(FilaListaDevolucao **devolucao){
	if(*devolucao != NULL){
		(*devolucao)->ini->pedido->status = 4;
		removeDevolucao(devolucao);
	}else{
		printf("Não há pedidos para serem devolvidos\n");
	}
	
}

void addHistorico(Pedido* pedido,FilaListaHistorico **historico){
	ListaHistorico *novo;
	novo = (ListaHistorico*)malloc(sizeof(ListaHistorico));
	if(!novo){
		printf("Nao foi possivel alocar para historico\n");
		exit(1);
	}

	novo->pedido = pedido;
	novo->prox = NULL;

	if((*historico) == NULL){

		FilaListaHistorico *aux = (FilaListaHistorico*)malloc(sizeof(FilaListaHistorico));

		aux->fim = novo;
		aux->ini = novo;

		*historico = aux;

		return;
	}

	(*historico)->fim->prox = novo;
	(*historico)->fim = novo;
}

void liberaPedido(Pedido *pedido){
	free(pedido);
}


