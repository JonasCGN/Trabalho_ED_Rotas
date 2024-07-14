#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "cliente.h"

ListaCliente *criaListaCliente(){
    return NULL;
}
Cliente *cadastro(){
    Cliente *novocliente = (Cliente *)malloc(sizeof(Cliente));
    if (novocliente == NULL){
        printf("ERRO NA ALOCAÇÃO DE MEMÓRIA!!!");
        exit(1);
    }

    printf("Nome: ");
    fgets(novocliente->nome, 50, stdin);
    novocliente->nome[strcspn(novocliente->nome, "\n")] = '\0';// remove o /n 
    
    printf("CPF: ");
    fgets(novocliente->cpf, 15, stdin);

    printf("Telefone: ");
    fgets(novocliente->telefone, 15, stdin);

    printf("Email: ");
    fgets(novocliente->email, 50, stdin);

    printf("Endereço: ");
    fgets(novocliente->endereco, 100, stdin);
    
    return novocliente;

    
}
void cadastroCliente(ListaCliente **lista){
    Cliente *novo = cadastro();
    ListaCliente *novoNO = (ListaCliente *) malloc(sizeof(ListaCliente));
    if (novoNO){
         printf("ERRO NA ALOCAÇÃO DE MEMÓRIA!!!");
         exit(1);
    }
    
    novoNO->cliente = *novo;// copia as informações do cliente para o novo nó
    novoNO->prox = NULL;// Define proximo nó como NUll
    
    // se a lista estiver vazia add no inicio 
    if (*lista == NULL){
        *lista = novoNO;

    }else{// percorre e add no fim 
        ListaCliente *atual = *lista;
            while (atual->prox !=NULL){
                atual = atual->prox;
            }
            atual->prox = novoNO;
    }
    

}
// void exibirClientes(ListaCLiente **cliente){

// }
// void Procurarcliente(ListaCLiente **cliente){

// }
// void editarcliente(ListaCLiente **cliente){

// }
// void excluircliente(ListaCLiente **cliente){

// }