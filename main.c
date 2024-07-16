#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "backend/estrutura/estrutura.h"
#include "backend/routes/routes.h"
#include "backend/clients/cliente.h"
#include "backend/menu/menu.h"
#include "backend/cria_libera/cria_libera.h"
#include "backend/exibir/exibir.h"

int main(){
    ListaCliente *listaClientes = criaListaCliente();
	cadastroCliente(&listaClientes);
    

    // Exemplo: Percorre a lista para imprimir os dados de todos os clientes
    ListaCliente *atual = listaClientes;
    while (atual != NULL) {
        Cliente c = atual->cliente;
        printf("Nome: %s\n", c.nome);
        printf("CPF: %s\n", c.cpf);
        printf("Telefone: %s\n", c.telefone);
        printf("Email: %s\n", c.email);
        printf("Endereço: %s\n", c.endereco);
        printf("\n");

        atual = atual->prox;
    }
    
    return 0;
}