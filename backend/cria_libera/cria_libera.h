#pragma once

#include "../estrutura/estrutura.h"

//Cria
ListaHistorico *criaListaHistorico();
FilaListaRota *criaRota();
ListaCliente *criaListaCliente();
FilaListaPedido *criaListaPedido();
FilaListaEntrega* criaListaEntrega();
PilhaSegundaEntrega* criaListaSegundaEntrega();
FilaListaDevolucao* criaListaDevolucao();

int entregaVazio(FilaListaEntrega *fila);
int segundaEntregaVazia(PilhaSegundaEntrega *fila);
int devolucaoVazio(FilaListaDevolucao *fila);
int rotaVazia(FilaListaRota *listaRota);
int listaClienteVazia(ListaCliente *listacliente);
int listaPedidoVazia(FilaListaPedido *listaPedido);

//Libera
void liberaFilaListaPedido(FilaListaPedido* fila);
void liberaListaPedido(ListaPedido *l);

void liberaFilaListaEntrega(FilaListaEntrega* fila);
void liberaListaEntrega(ListaEntrega* l);

void liberaListaSegundaEntrega(PilhaSegundaEntrega* l);

void liberaFilaListaDevolucao(FilaListaDevolucao* fila);
void liberaListaDevolucao(ListaDevolucao* l);
void liberarListaCliente(ListaCliente *Cliente);

void liberaFilaListaRota(FilaListaRota *listaRota);
void liberarListaRota(ListaRota *listaRota);