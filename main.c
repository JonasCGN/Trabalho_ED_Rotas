#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "backend/estrutura/estrutura.h"
#include "backend/routes/routes.h"
#include "backend/clients/cliente.h"
#include "backend/menu/menu.h"
#include "backend/cria_libera/cria_libera.h"
#include "backend/exibir/exibir.h"
// Exemplo de uso da função exibirClientes no main
int main() {
    FilaListaCLiente listaClientes;
    listaClientes.ini = criaListaCliente();
    listaClientes.fim = listaClientes.ini;

    int op;
    int id;
    ListaCliente *clienteEncontrado;

    do{
        op = menu();

        switch (op){
        case 1:
            cadastroCliente(&listaClientes);
            break;
        case 2:
            if(listaClientes.ini == NULL){

                printf("Nenhum cliente cadastrado.\n");
            }else{

                printf("----- CLIENTES CADASTRADOS -----\n");
                exibirClientes(listaClientes.ini);

            }
            break;
        case 3:// ajustar uns bagulho
            printf(" Digite o Id do cliente a ser procurado: ");
            scanf("%d", &id);
            getchar();
            Procurarcliente(listaClientes.ini, id);
            break;
        case 4:
            printf(" Digite o Id do cliente a ser editado: ");
            scanf("%d", &id);
            getchar();
            editarcliente(listaClientes.ini, id);
            break;
        case 5:
            printf(" Digite o Id do cliente a ser excluido: ");
            scanf("%d", &id);
            getchar();
            excluircliente(listaClientes.ini, id);
            break;
        case 6:
            printf("----- FIM ------\n");
            break;
        default:
            printf("Opcao invalida.Tente novamente.\n");
            break;
        }
    } while (op != 6);
    liberar_clientes(&listaClientes.ini);
    getchar();
    return 0;
}
