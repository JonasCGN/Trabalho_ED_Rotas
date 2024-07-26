#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "backend/estrutura/estrutura.h"
#include "backend/routes/routes.h"
#include "backend/clients/cliente.h"
#include "backend/menu/menu.h"
#include "backend/cria_libera/cria_libera.h"
#include "backend/exibir/exibir.h"
#include "backend/pedidos/pedidos.h"

int main() {
    Pedido **pedidos = criaListaPedido();
    cadastrarPedido(pedidos);
    
    
    return 0;
}
