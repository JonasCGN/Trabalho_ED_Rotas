#pragma once

#include "../estrutura/estrutura.h"

void filaRota(Rota *rota,FilaListaRota **listaRota);
void removefilaRota(FilaListaRota **listaRota);
void cadastroRota(FilaListaRota **listaRota, FilaListaPedido *listaPedido);

void procurarRota(ListaRota *rota, int id);
void finalizarRota(Rota **rota,ListaHistorico *lista);

void adicionaHistorico(Pedido *pedido,ListaHistorico **listahistorico);

FilaListaEntrega * criaListaEntregraRota(ListaPedido *listaPedido);
void entregaRota(FilaListaEntrega **listaEntrega,ListaPedido *listaPedido);
void verificarPedidosCliente(FilaListaEntrega **listaEntrega, ListaPedido *listaPedido,int id);