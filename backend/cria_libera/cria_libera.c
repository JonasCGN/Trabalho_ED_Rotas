#include <stdio.h>
#include <stdlib.h>

#include "../estrutura/estrutura.h"
#include "cria_libera.h"

FilaListaRota *criaRota(){
	return NULL;
}

ListaHistorico *criaListaHistorico(){
	return NULL;
}

ListaCliente *criaListaCliente(){
    return NULL;
}

FilaListaPedido *criaListaPedido(){
	return NULL;
}

FilaListaEntrega* criaListaEntrega(){
	return NULL;	
}

PilhaSegundaEntrega* criaListaSegundaEntrega(){
	return NULL;
}

FilaListaDevolucao* criaListaDevolucao(){
	return NULL;
}



int entregaVazio(FilaListaEntrega *fila){
	if(fila == NULL)
		return 1;

	return 0;
}

int segundaEntregaVazia(PilhaSegundaEntrega *fila){
	if(fila == NULL)
		return 1;

	return 0;
}

int devolucaoVazio(FilaListaDevolucao *fila){
	if(fila == NULL)
		return 1;

	return 0;
}

int rotaVazia(FilaListaRota *listaRota){
	if(listaRota == NULL)
		return 1;

	return 0;
}

int listaPedidoVazia(FilaListaPedido *listaPedido){
    if(listaPedido == NULL)
        return 1;

    return 0;
}

int listaClienteVazia(ListaCliente *listacliente){
	if(listacliente == NULL){
		return 1;
	}
	return 0;
}



void liberaFilaListaPedido(FilaListaPedido* fila){
	if(listaPedidoVazia(fila))
		return;

	liberaListaPedido(fila->ini);
}

void liberaListaPedido(ListaPedido *l){
	if(l == NULL)
		return;

	liberaListaPedido(l->prox);
	free(l);
}

void liberaFilaListaEntrega(FilaListaEntrega* fila){
	if(entregaVazio(fila))
		return;

	liberaListaEntrega(fila->ini);
}

void liberaListaEntrega(ListaEntrega* l){
	if(l == NULL)
		return;

	liberaListaEntrega(l->prox);

	free(l);
}

void liberaListaSegundaEntrega(PilhaSegundaEntrega* l){
	if(l == NULL)
		return;

	liberaListaSegundaEntrega(l->prox);

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

void liberarListaCliente(ListaCliente *l){
	if(l == NULL)
		return;

	liberarListaCliente(l->prox);

	free(l);
    
}

void liberaFilaListaRota(FilaListaRota *listaRota){
	if(listaRota == NULL)
		return;

	liberarListaRota(listaRota->ini);
}

void liberarListaRota(ListaRota *listaRota){
	if(listaRota == NULL)
		return;

	liberarListaRota(listaRota->prox);

	liberaFilaListaDevolucao(listaRota->rota->devolucao);
	liberaListaSegundaEntrega(listaRota->rota->segundaEntrega);
	liberaFilaListaEntrega(listaRota->rota->entrega);
	free(listaRota->rota);
}