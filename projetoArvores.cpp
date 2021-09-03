#include <iostream>
#include <cstring>
 
using namespace std;
 
// Struct para cada treenode
struct treenode
{
    char info;
    treenode *esq;
    treenode *dir;
};
typedef treenode *treenodeptr;
 
// Struct para cada no
struct no
{
    treenodeptr info;
    no *next;
};
typedef no* noptr;
 
// Funcao que acrescenta os elementos na pilha
void push (noptr &pilha, treenodeptr x)
{
    noptr p;
    p = new no;
    p->info = x;
    if (pilha == NULL) // Primeiro da pilha
        pilha = p;
    else
        p->next = pilha->next; // Existe outros elementos
    pilha->next = p;
}
 
// Funcao que apaga os elementos da lista
int pop (noptr &pilha, treenodeptr &x)
{
    noptr p;
    if (pilha == NULL)
        return -1;
    else
    {
        p = pilha->next;
        x = p->info;
        if (p == pilha)
            pilha = NULL;
        else
            pilha->next = p->next;
        delete p;
        return 0;
    }
}
 
// Funcao que acrescenta os parenteses  
void parentese(treenodeptr a, int x){
 
    treenodeptr p = a;
    treenodeptr aux = new treenode;
     
    if(x == 0){
         
        while(p->esq != NULL)
            p = p->esq;
         
        aux->info = '(';
        aux->esq = NULL;
        aux->dir = NULL;
        p->esq = aux;
    }else{
 
        while(p->dir != NULL)
            p = p->dir;
         
        aux->info = ')';
        aux->esq = NULL;
        aux->dir = NULL;
        p->dir = aux;
    }
}

// Funcao que vai conectar conectar a folheras 
void conecta(treenodeptr e, treenodeptr d, treenodeptr &op){
    op->esq = e;
    op->dir = d;
}

// Funcao geral, onde será colocado na pilha e removido, até sobrar a raiz
treenodeptr cria(treenodeptr arvore[], int cont){
     
    treenodeptr d, e;
    noptr lista = NULL;
     
    for(int i = 0; i < cont; i++){
        if(arvore[i]->info == '+' || arvore[i]->info == '-'){
            pop(lista, d);
            pop(lista, e);
            if(i != cont-1){
            	parentese(e, 0);
            	parentese(d, 1);				   	
			}
            conecta(e, d, arvore[i]);
            push(lista, arvore[i]);
        }else if(arvore[i]->info == '*' || arvore[i]->info == '/'){
            pop(lista, d);
            pop(lista, e);
            conecta(e, d, arvore[i]);
            push(lista, arvore[i]);
        }else
            push(lista, arvore[i]);
    }
     
    return lista->info;
}
 
// Funcao que percorre a arvore 
void emOrdem (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->esq);
        cout << arvore->info;
        emOrdem(arvore->dir);
    }
}

// Funcao que remove os elementos da arvore
void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}
 
int main(){
     
    treenodeptr v = NULL;
    treenodeptr arvore[100];
     
    int cont = 0;
    char frase[100];
     
    cin.getline(frase, 100);
     
    for(int i = 0; i < strlen(frase); i++){
         
        if(frase[i] != ' '){
            arvore[cont] = new treenode;
            arvore[cont]->info = frase[i];
            arvore[cont]->esq = NULL;
            arvore[cont]->dir = NULL;
            cont++;
        }
         
    }
     
    v = cria(arvore, cont);
     
    emOrdem(v);
    cout << endl;
     
	tDestruir(v);
	  
    return 0;
}