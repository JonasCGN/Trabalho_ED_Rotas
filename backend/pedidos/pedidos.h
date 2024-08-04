#pragma once

#include "../estrutura/estrutura.h"

void adicionaPedido(ListaPedido **listaPedido, Pedido *pedido);
Pedido* cadastrarPedido(ListaPedido **listaPedido, ListaCliente **listaCliente);
int listaPedidoVazia(ListaPedido *listaPedido);