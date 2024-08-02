#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

#include "cliente.h"
static int proxid = 1;

Cliente *cadastro(){
    Cliente *novocliente = (Cliente *)malloc(sizeof(Cliente));
    if (novocliente == NULL){
        printf("ERRO NA ALOCAÇÃO DE MEMÓRIA!!!");
        exit(1);
    }

    novocliente->id_cliente = proxid++;
    
    int valido;
    do{
        valido = 1;
        printf("Nome: ");
        fgets(novocliente->nome, 50, stdin);
        novocliente->nome[strcspn(novocliente->nome, "\n")] = '\0';// remove o /n 

        for (int i = 0; novocliente->nome[i] != '\0'; i++){
            if (!isalpha(novocliente->nome[i])  && novocliente->nome[i] != ' '){
                printf("Nome invalido, digite novamente.\n");
                valido = 0;
                break;
            }
        }
    }while(!valido);

    do{
        valido = 1;
        printf("CPF: ");
        fgets(novocliente->cpf, 11, stdin);
        novocliente->cpf[strcspn(novocliente->cpf, "\n")] = '\0'; 

        if (strlen(novocliente->cpf) != 11){
            printf("CPF invalido, digite novamente.\n");
            valido = 0;
        }else{
            for (int i = 0; novocliente->cpf[i] != '\0'; i++){
                if (!isdigit(novocliente->cpf[i])){
                    printf("CPF invalido, digite novamente.\n");
                    valido = 0;
                    break;
                }
            }
        }
        
    }while(!valido);
    
   do{
        valido = 1;
        printf("Telefone: ");
        fgets(novocliente->telefone, 15, stdin);
        novocliente->telefone[strcspn(novocliente->telefone, "\n")] = '\0';// remove o /n 

        if (strlen(novocliente->telefone) > 15){
            printf("Telefone invalido, digite novamente.\n");
            valido = 0;
        }else{
            for (int i = 0; novocliente->telefone[i] != '\0'; i++){
                if (!isdigit(novocliente->telefone[i])){
                    printf("Telefone invalido, digite novamente.\n");
                    valido = 0;
                    break;
                }
            }
        }
        
   }while(!valido);

   do{
        valido = 1;
        printf("Email: ");
        fgets(novocliente->email, 50, stdin);
        novocliente->email[strcspn(novocliente->email, "\n")] = '\0';// remove o /n 

        for (int i = 0; novocliente->email[i] != '\0'; i++){
            if (isspace(novocliente->email[i])){
                valido = 1;
                break;
            }else{
                printf("Email invalido, digite novamente.\n");
                valido = 0;
                break;
            }
        }
        
   }while(!valido);

    
    printf("Endereco: ");
    fgets(novocliente->endereco, 100, stdin);
    novocliente->endereco[strcspn(novocliente->endereco, "\n")] = '\0';// remove o /n 
    
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

    if((*listaCliente) == NULL){
            
        novo->cliente = cliente_novo;
        novo->prox = *listaCliente;

        (*listaCliente) = novo;

        return;
    }

}

void procurarcliente(ListaCliente *cliente, int id){
    ListaCliente *atual = cliente;
    int  encontrado = 0;

    while ( atual!= NULL){
        if (atual->cliente->id_cliente == id){
            printf("Cliente encontrado :\n");
            printf("ID %d\n", atual->cliente->id_cliente);
            printf("Nome: %s\n", atual->cliente->nome);
            printf("CPF: %s\n", atual->cliente->cpf);
            printf("Telefone: %s\n", atual->cliente->telefone);
            printf("Email: %s\n", atual->cliente->email);
            printf("Endereco: %s\n", atual->cliente->endereco);
            return;
        }
        atual = atual->prox;
        printf("Cliente  não encontrado :\n");
    }
    

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
                printf("Nome: ");
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
            printf("Cliente com Id %d excluido com sucesso.\n", id);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Cliente com Id %d nao encontrado.\n", id);
}
