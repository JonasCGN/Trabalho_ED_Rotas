#pragma once

#include "../estrutura/estrutura.h"

void adicionaPedido(FilaListaPedido **listaPedido, Pedido *pedido);
Pedido* cadastrarPedido(FilaListaPedido **listaPedido, ListaCliente *listaCliente);
void pedidoId(ListaPedido *listapedido,int id);
