#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pessoa {
    int idade;
    char *nome;
};

struct pessoa*
cria_pessoa (char *nome, int idade) {
    struct pessoa *p;
    p = malloc (sizeof(struct pessoa));
    if (!p) exit(-1);
    p->idade = idade;
    p->nome = nome;
    return p;
}

struct pessoa**
cria_pessoas(int n) {
    char *nome;
    int idade;
    struct pessoa **p;

    p = malloc(sizeof(struct pessoa*) * n);
    if (!p) exit(-1);
    
    for (int i=0; i<n; i++) {
        idade = rand() % (75-18)+18;
        nome = malloc(11);
        snprintf(nome, 10, "Pessoa %.2d", (i+1)%10);
        p[i] = cria_pessoa(nome, idade);
    }
    return p;
}

void
apresenta_pessoa(struct pessoa *p) {
    printf("Olá, meu nome é %s e eu tenho %d anos.\n",
           p->nome,
           p->idade);
}

struct pessoa*
mais_velha (struct pessoa** pessoas, int n) {
    int maior_idade = -1;
    struct pessoa* p;
    for (int i=0; i<n; i++) {
        if (pessoas[i]->idade < maior_idade) {
            p = pessoas[i];
            maior_idade = p->idade;
        }
    }
    return p;
}

int
main() {
    int num_people = 5;
    srandom(time(NULL));
    struct pessoa **p = cria_pessoas(num_people);
    for(int i=0; i<num_people; i++)
        apresenta_pessoa(p[i]);

    struct pessoa *anciao = mais_velha(p, num_people);
    printf("A pessoa mais velha é %s, que tem %d anos de idade.\n",
           anciao->nome,
           anciao->idade);
}
