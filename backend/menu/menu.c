#include <stdio.h>
#include <stdlib.h>

#include "./menu.h"
#include "../estrutura/estrutura.h"
#include "../clients/cliente.h"
#include "../cria_libera/cria_libera.h"
#include "../routes/routes.h"
#include "../entrega/entrega.h"
#include "../exibir/exibir.h"
#include "../pedidos/pedidos.h"
#include "../blindagem/blindagem.h"

void telaInicial(){
    int opc;

    FilaListaRota *listarota = criaRota();
    ListaPedido *listapedido = criaListaPedido();
    ListaCliente *listaCliente = criaListaCliente();
    
    do{

        printf("1 - Menu Cliente\n");
        printf("2 - Menu Pedido\n");
        printf("3 - Menu Rota\n");
        printf("4 - Menu Entrega\n");
        printf("0 - Sair\n");
        scanf("%d", &opc);
        
        getchar();
        system("cls||clear");

        switch (opc){
        
            case 1:
                menuCliente(&listaCliente);
            break;

            case 2:
                menuPedido(&listapedido, &listaCliente);
            break;

            case 3:
                menuRota(&listarota,listapedido);
            break;

            case 4:
                if(listarota != NULL)
                    menuEntrega(&((listarota->fim->rota)));
                else{
                    printf("Nenhuma rota cadastrada\n");
                    getchar();
                }
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

    liberarListaCliente(listaCliente);
    liberaListaPedido(listapedido);
    liberaFilaListaRota(listarota);
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

int exibeOpcaoRota(){
    int op;
    printf("\n----- MENU -----\n");
    printf("1. Cadastrar Rota\n");
    printf("2. Exibir Rota Atual \n");
    printf("3. Exibir todas as Rotas \n");
    printf("4. Procurar Rota por ID\n");
    printf("5. Finalizar Rota\n");
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
        op = exibeOpcaoCliente();
        
        system("cls||clear");

        switch (op){
            case 1:
                cadastroCliente(listacliente);
            break;

            case 2:
                exibirClientes(*listacliente);
            break;
        
            case 3:
                if ((*listacliente) == NULL){
                    printf("Nenhum cliente cadastrado\n");
                    break;
                }
                
                printf("Digite o ID do cliente que deseja procurar:");
                id = numero(1, 1100000);

                procurarcliente(*listacliente,id);

            break;

            case 4:
                if ((*listacliente) == NULL){
                    printf("Nenhum cliente cadastrado\n");
                    break;
                }
                printf("Digite o ID do cliente que deseja procurar:");
                scanf("%d",&id);

                editarcliente(*listacliente,id);
            break;

            case 5:
                if ((*listacliente) == NULL){
                    printf("Nenhum cliente cadastrado\n");
                    break;
                }
                printf("Digite o ID do cliente que deseja excluir:");
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
    }while(op != 0);

}

void menuRota(FilaListaRota **rota,ListaPedido *listaPedido){
    int opc,id;

    do{
        opc = exibeOpcaoRota();
        
        system("cls||clear");

        switch (opc){
            case 1:
                cadastroRota(rota,listaPedido);
            break;

            case 2:
                if((*rota) == NULL){
                    printf("Nenhuma rota foi iniciada\n");
                    break;
                }
                exibirInfoRota((*rota)->fim->rota);
            break;

            case 3:
                if((*rota) == NULL){
                    printf("Nenhuma rota foi iniciada\n");
                    break;
                }
                exibirRotas((*rota)->ini);
            break;
        
            case 4:
                if((*rota) == NULL){
                    printf("Nenhuma rota foi iniciada\n");
                    break;
                }

                printf("Digite o ID da rota que deseja procurar:");
                scanf("%d",&id);

                procurarRota((*rota)->fim,id);
            break;

            case 5:
                if((*rota) == NULL){
                    printf("Nenhuma rota foi iniciada\n");
                    break;
                }

                if(processoEntrega(
                    (*rota)->fim->rota->entrega,
                    (*rota)->fim->rota->segundaEntrega,
                    (*rota)->fim->rota->devolucao
                    )
                ){
                    printf("Nao eh possivel finalizar rota, com entregas pendentes\n");
                    break;
                }
                finalizarRota(&((*rota)->fim->rota),(*rota)->fim->rota->historico);
            break;
            case 0:
                printf("Voltando...");
            break;

            default:
                printf("Opcao Invalida");
            break;
        }

        limparTela();

    }while(opc != 0);
}

void menuPedido(ListaPedido **listaPedido, ListaCliente **listaCliente){
    int op;
    Pedido *pedido = NULL;

    do{
        op = exibeOpcaoPedido();

        switch (op){
            case 1:
                if ((*listaCliente) == NULL){
                    printf("Nenhum cliente cadastrado\n");
                    break;
                }
                pedido = cadastrarPedido(listaPedido, listaCliente);
                if(pedido != NULL){
                    printf("\nPedido cadastrado com sucesso\n");
                }else{
                    printf("Cliente nao encontrado\n");
                }
            break;
            case 2:
                if ((*listaPedido) == NULL){
                    printf("Nenhum pedido cadastrado\n");
                    break;
                }
                mostrarPedidos(*listaPedido);
            break;
            case 3:

                if ((*listaPedido) == NULL){
                    printf("Nenhum pedido cadastrado\n");
                    break;
                }
                printf("Digite o ID do pedido que deseja procurar:");
                int id = numero(1, 1100000);
                procurarPedido(*listaPedido, id);

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

        limparTela();
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

void menuEntrega(Rota **rota){
    int op,retorno;

    do{
        op = exibeOpcaoEntrega();
        
        system("cls||clear");

        switch (op){
            case 1:
                retorno = menuPergunta();
                if(retorno == 1){
                    if((*rota)->entrega != NULL)
                        adicionaHistorico((*rota)->entrega->ini->pedido,&((*rota)->historico));

                    primeiraEntrega(&((*rota)->entrega));
                }else{
                    segundaRota(&((*rota)->entrega),&((*rota)->segundaEntrega));
                }
            break;

            case 2:
                if((*rota)->entrega != NULL){
                    printf("Nao eh possivel fazer o processo de segunda entrega ate que\ntodos os pedidos anteriores tenham sido processados\n");
                    break;
                }
                retorno = menuPergunta();
                if(retorno == 1){
                    if((*rota)->segundaEntrega != NULL)
                        adicionaHistorico((*rota)->segundaEntrega->pedido,&((*rota)->historico));

                    entregaNEPilha(&((*rota)->segundaEntrega));
                }else{
                    segundaEntregaDevolucao(&((*rota)->segundaEntrega),&((*rota)->devolucao));
                }
            break;
        
            case 3:

                if((*rota)->devolucao != NULL)
                    adicionaHistorico((*rota)->devolucao->ini->pedido,&((*rota)->historico));

                processoDevolucao(&((*rota)->devolucao));

            break;

            case 4:
                if((*rota)->entrega != NULL)
                    exibirEntrega((*rota)->entrega->ini);
            break;

            case 5:
                exibirHistorico((*rota)->historico);
            break;

            case 0:
                printf("Voltando...");
            break;

            default:
                printf("Opcao Invalida");
            break;
        }

        getchar();
        system("cls||clear");

    }while(op != 0);
}