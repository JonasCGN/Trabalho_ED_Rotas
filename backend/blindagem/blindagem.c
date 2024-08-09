#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

#include "blindagem.h"

void verifica_n_int(char *v, int min, int max) {
    int i = 0;
    char c;

    do {
        c = getch();

        if (c >= '0' && c <= '9' && i < max) { 
            printf("%c", c);

            v[i] = c;
            i++;
        } else if (c == 8 && i >= 1) {
            i--; 
            v[i] = '\0';
            printf("\b \b");
        }

        if (c == 13 && i < min) { 
            c = 14;
        }
    } while (c != 13);

    v[i] = '\0';
}

int numero(int min,int max){
    char v[10];
    int num;

    do{
        gets(v);
        if(atoi(v) != 0){
            num = atoi(v);
        }else{
            printf("\nDigite um numero inteiro:");
        }
    }while(atoi(v) != 0);

    return num;
}

float verifica_n_float(int max){
    char v[10];
    int num;

    do{
        gets(v);
        if(atof(v) != 0){
            num = atof(v);
        }else{
            printf("\nDigite um numero real:");
        }
    }while(atof(v) != 0);

    return num;
}

void verifica_letra(char *v,int tam){
    char c;
    int i=0;

	for(int j=0;j < 50 ;j++){
		*(v+j) = '\0';
	}

    do{
        c = getch();

        if(((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')) && i < tam){
            printf("%c", c);
            *(v+i) = c;
            i++;
        }else if(c == 8 && i >= 1){
            *(v+i) = '\0';
            printf("\b \b");
            i--;
        }else if(i == 0){
            c = 14;
        }else if(*(v + i - 1) == ' '){
            c = 14;
        }
    }while(c != 13);
    *(v+i) = '\0';
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

char recebeUmNumero(char v){
    char temp;
    do{
        temp = getch();

        if(temp >= '0' && temp <= '9'){
            v = temp;
            printf("%c",v);
        }

    }while(!(temp >= '0' && temp <= '9'));

    

    return v;
}