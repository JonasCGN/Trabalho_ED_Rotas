#pragma once

#include "../estrutura/estrutura.h"

void telaInicial();
void menuCliente(ListaCliente **listacliente);
void menuPedido(ListaEntrega **entrega);
void menuEntrega(ListaEntrega **primeiraEntrega,PilhaSegundaEntrega **segundaEntrega,FilaListaDevolucao **devolucao);