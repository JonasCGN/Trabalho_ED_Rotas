#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>

#include "blindagem.h"

int numeroInteiro(const char str[]) {
    int i=0;

    while (str[i]) {
        if (isdigit(str[i]) == 0) return 0;

        i++;
    }
    return 1;
}

int numeroReal(const char str[]) {
    int i=0,cont = 0;

    while (str[i]) {
        if (isdigit(str[i]) == 0 && str[i] != 46) return 0;
        
        if(str[i] == 46) cont++;
        if(cont > 1) return 0;

        i++;
    }
    return 1;
}

void verifica_n_int(char *v, int min, int max) {
    char palavra[11];

    do{
        scanf("%s",palavra);
        if(!numeroInteiro(palavra)){
            printf("Digite um numero inteiro:");
        }
    }while(!numeroInteiro(palavra));
    setbuf(stdin,NULL);

    strcpy(v,palavra);

}

int numero(int min, int max) {
    char v[10];
    int num;
    char *ver;

    do{
        scanf("%s",v);
        if(!numeroInteiro(v)){
            printf("Digite um numero inteiro:");
        }
    }while(!numeroInteiro(v));

    num = strtol(v,&ver,10);
    setbuf(stdin,NULL);

    return num;
}

float verifica_n_float(float max) {
    char v[10];
    float num;
    char *ver;

    do{
        scanf("%s",v);
        if(!numeroReal(v)){
            printf("Digite um numero inteiro:");
        }
    }while(!numeroReal(v));

    num = strtof(v,&ver);
    setbuf(stdin,NULL);

    return num;
}

void verifica_letra(char *v, int tam) {
    
    scanf("%s", v);
    setbuf(stdin,NULL);
}

int verifica_email(char *v){
    int n=strlen(v);
    for(int i=0;i<n;i++){
        if(*(v+i) == ' '){
            return 0;
        }
    }
    return 1;
}

void limparTela(){
    printf("\n");
    printf("Pressione qualquer tecla para continuar");
    getchar();
    system("cls||clear");
}