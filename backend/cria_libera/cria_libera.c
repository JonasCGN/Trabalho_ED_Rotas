#include <stdio.h>
#include <stdlib.h>

#include "../estrutura/estrutura.h"
#include "cria_libera.h"

ListaEntrega* criaListaEntrega(){
	Pedido *pedido = (Pedido*)malloc(sizeof(Pedido));
	ListaEntrega *entrega = (ListaEntrega*)malloc(sizeof(ListaEntrega));
	entrega->pedido = pedido;
	entrega->prox = NULL;
	return entrega;
}

ListaSegundaEntrega* criaListaSegundaEntrega(){
	return NULL;
}

FilaListaHistorico* criaListaHistorico(){
	return NULL;
}

FilaListaDevolucao* criaListaDevolucao(){
	return NULL;
}

int historicoVazio(FilaListaHistorico *fila){
	if(fila == NULL)
		return 1;

	return 0;
}

int devolucaoVazio(FilaListaDevolucao *fila){
	if(fila == NULL)
		return 1;

	return 0;
}

void liberaListaEntrega(ListaEntrega* l){
	if(l == NULL)
		return;
	liberaListaEntrega(l->prox);
	free(l);
}

void liberaListaSegundaEntrega(ListaSegundaEntrega* l){
	if(l == NULL)
		return;

	liberaListaSegundaEntrega(l->prox);
	free(l);
}

void liberaFilaListaHistorico(FilaListaHistorico *fila){
	if(historicoVazio(fila))
		return;

	liberaListaHistorico(fila->ini);
}

void liberaListaHistorico(ListaHistorico* l){
	if(l == NULL)
		return;

	liberaListaHistorico(l->prox);
	free(l);
}

void liberaFilaListaDevolucao(FilaListaDevolucao* fila){
	if(devolucaoVazio(fila))
		return;

	liberaListaDevolucao(fila->ini);
}

void liberaListaDevolucao(ListaDevolucao* l){
	if(l == NULL)
		return;

	liberaListaDevolucao(l->prox);
	free(l);
}
