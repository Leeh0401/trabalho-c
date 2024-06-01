#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float valor;
    int qtde;
    float total;
} Item;

int main() {
    int n;
    float total_final = 0;

    printf("Digite o numero de itens que deseja inserir: ");
    scanf("%d", &n);

    Item itens[n];

    for (int i = 0; i < n; i++) {
        int id_exists; 
        do {
            id_exists = 0; 
            printf("Digite o codigo do item %d: ", i + 1);
            scanf("%d", &itens[i].id);

            for (int j = 0; j < i; j++) {
                if (itens[j].id == itens[i].id) {
                    printf("Codigo ja existe. Digite um codigo diferente.\n");
                    id_exists = 1;
                    break;
                }
            }
        } while (id_exists);

        
        printf("Digite o nome do item %d: ", i + 1);
        scanf(" %[^\n]", itens[i].nome);

        
        printf("Digite o valor do item %d: ", i + 1);
        scanf("%f", &itens[i].valor);

        
        printf("Digite a quantidade do item %d: ", i + 1);
        scanf("%d", &itens[i].qtde);

       
        itens[i].total = itens[i].valor * itens[i].qtde;
        total_final += itens[i].total;
    }

 
    printf("\n%-10s%-25s%-10s%-10s%-10s\n", "CODIGO", "NOME", "QTDE", "UNIT", "TOTAL");
    for (int i = 0; i < n; i++) {
        printf("%05d\t%-24s\t%d\t%.2f\t%.2f\n", itens[i].id, itens[i].nome, itens[i].qtde, itens[i].valor, itens[i].total);
    }
    printf("\n%-10s%-25s%-10s%-10s%.2f\n", "", "", "", "TOTAL FINAL: ", total_final);

    return 0;
}





