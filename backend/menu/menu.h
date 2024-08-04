#pragma once

#include "../estrutura/estrutura.h"

void telaInicial();
void menuCliente(ListaCliente **listacliente);
void menuPedido(ListaPedido **listaPedido, ListaCliente **listaCliente);
void menuRota(FilaListaRota **rota,ListaPedido *listaPedido);
void menuEntrega(Rota **rota);