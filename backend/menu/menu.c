#include <stdio.h>
#include <stdlib.h>

#include "./menu.h"
#include "../estrutura/estrutura.h"
#include "../routes/routes.h"
#include "../clients/cliente.h"
#include "../cria_libera/cria_libera.h"
#include "../exibir/exibir.h"
#include "../pedidos/pedidos.h"

void telaInicial(){
    int opc;

    ListaCliente *listaCliente = criaListaCliente();
    ListaEntrega *primeiraEntrega = criaListaEntrega();
    PilhaSegundaEntrega *segundaEntrega = criaListaSegundaEntrega();
    FilaListaDevolucao *devolucao = criaListaDevolucao();
    ListaHistorico *historico = criaListaHistorico();
    
    do{

        printf("1 - Menu Cliente\n");
        printf("2 - Menu Pedido\n");
        printf("3 - Menu Entrega\n");
        printf("0 - Sair\n");
        scanf("%d", &opc);
        
        getchar();
        system("cls||clear");

        switch (opc){
        
            case 1:
                menuCliente(&listaCliente);
            break;

            case 2:
                menuPedido(&primeiraEntrega);
            break;

            case 3:
                menuEntrega(&primeiraEntrega,&segundaEntrega,&devolucao);
            break;

            case 0:
                printf("Saindo...");
            break;
            
            default:
                printf("Opcao Invalida");
            break;
        }

        system("cls||clear");

    }while(opc != 0);
}

int exibeOpcaoCliente(){
    int op;
    printf("\n----- MENU -----\n");
    printf("1. Cadastrar cliente\n");
    printf("2. Exibir todos os clientes \n");
    printf("3. Procurar cliente por ID\n");
    printf("4. Editar cliente por ID\n");
    printf("5. Excluir cliente por ID\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

    getchar();
    return op;
}

int exibeOpcaoPedido(){
    int op;
    printf("\n----- MENU -----\n");
    printf("1. Cadastrar Pedido\n");
    printf("2. Exibir todos os Pedidos \n");
    printf("3. Procurar Pedido por ID\n");
    printf("4. Procurar Pedido por ID Cliente\n");
    printf("5. Excluir Pedido por ID\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

    getchar();
    return op;
}

int exibeOpcaoEntrega(){
    int op;
    printf("\n----- MENU -----\n");
    printf("1. Primeira Entrega\n");
    printf("2. Segunda Entrega\n");
    printf("3. Devolucao\n");
    printf("4. Exibir Entregas\n");
    printf("5. Exibir Historico\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

    getchar();
    return op;
}

void menuCliente(ListaCliente **listacliente){
    int op,id;

    do{
        op = exibeOpcaoEntrega();
        
        system("cls||clear");

        switch (op){
            case 1:
                cadastroCliente(listacliente);
            break;

            case 2:
                exibirClientes(*listacliente);
            break;
        
            case 3:
                
                printf("Digite o ID do cliente que deseja procurar:");
                scanf("%d",&id);

                procurarcliente(*listacliente,id);

            break;

            case 4:
                printf("Digite o ID do cliente que deseja procurar:");
                scanf("%d",&id);

                editarcliente(*listacliente,id);
            break;

            case 5:
                printf("Digite o ID do cliente que deseja procurar:");
                scanf("%d",&id);

                excluircliente(listacliente,id);
            break;

            case 0:
                printf("Voltando...");
            break;

            default:
            break;
        }

        getchar();
        system("cls||clear");
    }while(op != 6);

}

void menuPedido(ListaEntrega **entrega){
    int op;
    Pedido *pedido = NULL;

    do{
        int op = exibeOpcaoPedido();

        switch (op){
            case 1:
                pedido = cadastrarPedido();
                pedidoFila(pedido,entrega);
            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:

            break;
            case 0:
                printf("Saindo...\n");
            break;
        default:
            break;
        }
    }while(op != 0);

}

int menuPergunta(){
    int op;
    printf("Pedido foi entregue:\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

    getchar();
    return op;
}

void menuEntrega(ListaEntrega **primeiraEntrega,PilhaSegundaEntrega **segundaEntrega,FilaListaDevolucao **devolucao){
    int op,id,retorno;

    do{
        op = exibeOpcaoEntrega();
        
        system("cls||clear");

        switch (op){
            case 1:
                retorno = menuPergunta();
                if(retorno == 1){
                    removeFila(primeiraEntrega);
                }else{
                    segundaRota(primeiraEntrega,segundaEntrega);
                }

            break;

            case 2:
                retorno = menuPergunta();
                if(retorno == 1){
                    entregaNEPilha(segundaEntrega);
                }else{
                    segundaEntregaDevolucao(segundaEntrega,devolucao);
                }
            break;
        
            case 3:
                processoDevolucao(devolucao);
            break;

            case 4:
                exibirEntrega(primeiraEntrega);
            break;

            case 0:
                printf("Voltando...");
            break;

            default:
            break;
        }

        getchar();
        system("cls||clear");
    }while(op != 0);
}