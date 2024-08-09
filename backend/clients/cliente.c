#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

#include "../exibir/exibir.h"
#include "../blindagem/blindagem.h"
#include "cliente.h"
static int proxid = 1;

Cliente *cadastro(){
    Cliente *novocliente = (Cliente *)malloc(sizeof(Cliente));
    if (novocliente == NULL){
        printf("ERRO NA ALOCAÇÃO DE MEMÓRIA!!!");
        exit(1);
    }

    novocliente->id_cliente = proxid++;
    
    printf("Nome: ");
    verifica_letra(novocliente->nome, 50);

    printf("\n");

    printf("CPF: ");
    // verifica_n_int(novocliente->cpf, 11,11);
    verifica_n_int(novocliente->cpf, 1,1);
    
    printf("\n");

    printf("Telefone: ");
    // verifica_n_int(novocliente->telefone,11,11);
    verifica_n_int(novocliente->telefone,1,1);

    printf("\n");

    printf("Email: ");
    do{
        fgets(novocliente->email, 50, stdin);
        novocliente->email[strcspn(novocliente->email, "\n")] = '\0';// remove o /n 
        if(!verifica_email(novocliente->email)){
            printf("Email invalido, digite novamente.\n");
        }
    }while (!verifica_email(novocliente->email));
    
    printf("\n");

    printf("Endereco: ");
    fgets(novocliente->endereco, 100, stdin);
    novocliente->endereco[strcspn(novocliente->endereco, "\n")] = '\0';// remove o /n 
    
    printf("\n");

    return novocliente;
}

void cadastroCliente(ListaCliente **listaCliente){
    Cliente *cliente_novo = cadastro();

    ListaCliente *novo;
	novo = (ListaCliente*)malloc(sizeof(ListaCliente));
    if(!novo){
        printf("Nao foi possivel alocar para entrega\n");
        exit(1);
    }

    novo->cliente = cliente_novo;
    novo->prox = *listaCliente;

    (*listaCliente) = novo;

}

Cliente* verificaCliente(ListaCliente *listacliente,int id){
    if(listacliente == NULL){
        printf("Cliente nao cadastrado\n");
        return NULL;
    }

    if(id == listacliente->cliente->id_cliente)
        return listacliente->cliente;

    return verificaCliente(listacliente->prox,id);
}

void procurarcliente(ListaCliente *listacliente, int id){
    
    printf("\nProcurando cliente com ID %d\n", id);
    
    Cliente *cliente = verificaCliente(listacliente, id);

    if(cliente != NULL){
        exibirInfoCliente(cliente);
    }else{
        printf("Cliente com ID %d nao encontrado\n", id);
    }
    
    limparTela();
}

void editarcliente(ListaCliente *cliente, int id){
    // aprimorar depois essa desgraça 
    ListaCliente *atual = cliente;
    int encontrado = 0;
    while (atual != NULL){
        if (atual->cliente->id_cliente == id){
            printf (" Editar cliente com ID %d: \n", id);
    
            int valido;
            do{
                valido = 1;
                printf("Novo Nome: ");
                fgets(atual->cliente->nome, 50, stdin);
                atual->cliente->nome[strcspn(atual->cliente->nome, "\n")] = '\0';// remove o /n 

                for (int i = 0; atual->cliente->nome[i] != '\0'; i++){
                    if (!isalpha(atual->cliente->nome[i])  && atual->cliente->nome[i] != ' '){
                        printf("Nome invalido, digite novamente.\n");
                        valido = 0;
                        break;
                    }
                }
            }while(!valido);

            printf("Novo CPF: ");
            fgets(atual->cliente->cpf, 15, stdin);
            atual->cliente->cpf[strcspn(atual->cliente->cpf, "\n")] = '\0';// remove o /n 

            printf("Novo Telefone: ");
            fgets(atual->cliente->telefone, 15, stdin);
            atual->cliente->telefone[strcspn(atual->cliente->telefone, "\n")] = '\0';// remove o /n 

            printf("Novo Email: ");
            fgets(atual->cliente->email, 50, stdin);
            atual->cliente->email[strcspn(atual->cliente->email, "\n")] = '\0';// remove o /n 

            printf("Novo Endereco: ");
            fgets(atual->cliente->endereco, 100, stdin);
            atual->cliente->endereco[strcspn(atual->cliente->endereco, "\n")] = '\0';// remove o /n 
            
            printf(" Cliente editado com sucesso\n");
            encontrado = 1; 
        }
        atual = atual->prox;
        if (!encontrado){
            printf(" Cliente com Id %d nao encontrado. \n ", id);
        }
        
    }
   

}

void excluircliente(ListaCliente **cliente, int id ){
   // printf("Excluir cliente com ID %d\n", id);
    ListaCliente *atual = *cliente;
    ListaCliente *anterior = NULL;

    while (atual != NULL){
        if (atual->cliente->id_cliente == id){
            if (anterior == NULL){
               *cliente = atual->prox; 
                free(atual);
                return;
            }else{
                anterior->prox = atual->prox;
                
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Cliente com Id %d nao encontrado.\n", id);
}
