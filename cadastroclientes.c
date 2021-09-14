#include <stdio.h>
#include <stdlib.h>

#define QUANTIDADE 2

enum casos {CADASTRO=0,REMOVER,MOSTRAR_MONTANTE,ZERAR_MONTANTE,LISTAR_MELHOR, SAIR};

struct pessoas {
    char nome[30];
    int  ano_nasc;
    float montante;
};

int main (){

    printf("Cadastro de Clientes\n");

    struct pessoas **base_pessoas;
    base_pessoas = (struct pessoas**) calloc(QUANTIDADE,sizeof(struct pessoas*));  

    int controle = 1;
    int opcao;
    int quantidade = QUANTIDADE;
    int indice_cadastro;
    int ultimo;
    float maior = -99999.0;


    while(controle){
        printf("print com opcoes do cadastro\n");
        printf("digite sua opcao: ");
        scanf("%d",&opcao);
        printf("a opcao escolhida foi %d\n",opcao);
        switch(opcao){
            case CADASTRO:
                printf("CADASTRO\n");
                indice_cadastro = -1;
                for (int i = 0; i < quantidade; i++){
                    //verificar lugar vazio
                    if(base_pessoas[i] == NULL){
                        indice_cadastro = i;
                        break;
                    }
                }
                if(indice_cadastro < 0){
                    printf("\nQuantidade antes: %d\n",quantidade);
                    indice_cadastro = quantidade;
                    quantidade += QUANTIDADE;
                    base_pessoas= (struct pessoa**) realloc(base_pessoas,quantidade*sizeof(struct pessoa**));

                    for (int i = indice_cadastro; i < quantidade; i++){
                        base_pessoas[i] = NULL;
                    }
                    printf("\nQuantidade agora: %d\n",quantidade);
                }

                printf("Dados cadastrais\n");
                base_pessoas[indice_cadastro] = (struct pessoas*) calloc(1,sizeof(struct pessoas));
                scanf("%s",&base_pessoas[indice_cadastro]->nome);
                scanf("%d",&base_pessoas[indice_cadastro]->ano_nasc);
                scanf("%f",&base_pessoas[indice_cadastro]->montante);

                printf("\n cadatro realizado para\npessoa nome: %s, pessoa ano: %d montante %.2f\n", 
                    base_pessoas[indice_cadastro]->nome, base_pessoas[indice_cadastro]->ano_nasc, base_pessoas[indice_cadastro]->montante);
                break;
            
            case REMOVER:
                ultimo = -1;
                printf("\nvou remover o ultimo porque sim\n ");
                for (int i = 0; i < quantidade; i++){
                    //verificar lugar vazio
                    //printf("\n%d valor %d\n",i, base_pessoas[i]);

                    if(base_pessoas[i] != NULL){
                        ultimo = i;
                    }
                }
                if(ultimo >= 0){
                  printf("\n removido pessoa nome: %s, pessoa ano: %d montante %.2f\n", 
                            base_pessoas[ultimo]->nome, base_pessoas[ultimo]->ano_nasc, base_pessoas[ultimo]->montante);
                  free(base_pessoas[ultimo]);
                  base_pessoas[ultimo] = NULL;

                }else {
                  printf("\nNao existe ninguem cadastrado\n");
                }
                break;
            case MOSTRAR_MONTANTE:
                printf("MOSTRAR_MONTANTE\n");
                for (int i = 0; i < quantidade; i++){
                    //verificar lugar vazio
                    //printf("\n%d valor %d\n",i, base_pessoas[i]);

                    if(base_pessoas[i] != NULL){
                         printf("\npessoa nome: %s, pessoa ano: %d montante %.2f\n", 
                            base_pessoas[i]->nome, base_pessoas[i]->ano_nasc, base_pessoas[i]->montante);
                    }
                }
               
                break;
            case ZERAR_MONTANTE:
                printf("ZERAR_MONTANTE\n");
                for (int i = 0; i < quantidade; i++){
                    //verificar lugar vazio
                    //printf("\n%d valor %d\n",i, base_pessoas[i]);

                    if(base_pessoas[i] != NULL){
                        base_pessoas[i]->montante = 0.0;
                    }
                }
                break;
            case LISTAR_MELHOR:
                printf("LISTAR_MELHOR\n");
                maior = -99999.0;
                ultimo = -1; //aqui guarda o indide da pessoa mais bombada
                for (int i = 0; i < quantidade; i++){
                    //verificar lugar vazio
                    //printf("\n%d valor %d\n",i, base_pessoas[i]);

                    if(base_pessoas[i] != NULL){
                        if (base_pessoas[i]->montante > maior){
                          maior = base_pessoas[i]->montante;
                          ultimo = i;
                        }
                    }
                }
                if(ultimo < 0){
                  printf("\ntudo liso ou devendo\n");
                }else{
                  printf("\nmelhor pagador foi pessoa nome: %s, pessoa ano: %d montante %.2f\n", 
                            base_pessoas[ultimo]->nome, base_pessoas[ultimo]->ano_nasc, base_pessoas[ultimo]->montante);
                }
                break;
            case SAIR:
                controle = 0;
                break;
            default:
                printf("erro\n");
                break;
        }
        
    }

    return 0;
}