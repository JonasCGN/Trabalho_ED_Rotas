#pragma once

#include "../estrutura/estrutura.h"

void adicionaPedido(ListaPedido **listaPedido, Pedido *pedido);
Pedido* cadastrarPedido(ListaPedido **listaPedido, ListaCliente **listaCliente);

void excluiPedido(ListaPedido **listaPedido, int id);






