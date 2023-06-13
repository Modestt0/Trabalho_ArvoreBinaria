//André Luis Modesto de Paula
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include"A_PREFIXO.H"
using namespace std;

ARVORE_PREFIXO::ARVORE_PREFIXO(string &msg){
    //Pré-condição: Nenhuma
    //Pós-condição: Cria uma árvore binária já adicionando os caracteres necessários

    Root = NULL;

    string lerArquivo;

    ifstream inBSTree("abra.pre", ios::in);
    //Abre o arquivo com os caracteres
    
    getline(inBSTree, lerArquivo);
    getline(inBSTree, msg);
    
    for(int i=0; lerArquivo[i]!='\0'; i++){
        bool auxBool = false;

        Insert(lerArquivo[i], Root, auxBool);

    }//Para cada valor de "i" ele adiciona um caractere do arquivo

    inBSTree.close();
    //Fecha o arquivo

}

ARVORE_PREFIXO::~ARVORE_PREFIXO(){
    //Usado para chamar uma função recursiva que destroi a árvore

    Destructor(Root);
}

void ARVORE_PREFIXO::Destructor(TreePointer &p){
    //Pré-condição: A árvore já tenha sido criada
    //Pós-condição: Deleta todos os caracteres da árvore usando recursividade e deixa ela vazia
    
    if(p != NULL){
        Destructor(p->LeftNode);
        Destructor(p->RightNode);
        delete p;
        p = NULL;
    }//Percorre toda a árvore e deleta o nó sempre que chega em uma folha
    
}

void ARVORE_PREFIXO::Insert(char x, TreePointer &p, bool &auxBool){
    //Pré-condição: Árvore já tenha sido criada e não está cheia
    //Pós-condição: Novos caracteres são adicionados usando recursividade

    if(Root == NULL){
        p = new TreeNode;
        p->Entry = x;
        p->LeftNode = NULL;
        p->RightNode = NULL;
        Root = p;
        return;
    }//if para caso a raiz esteja vazia 

    if(p == NULL){
        p = new TreeNode;
        p->Entry = x;
        p->LeftNode = NULL;
        p->RightNode = NULL;
        auxBool=true;
        return;
    }//if para adicionar um nó
    else{
        //else para percorrer a árvore
        if(p->Entry == '*'){
            Insert(x, p->LeftNode, auxBool); 
            //Entra nó esquerdo

            if(!auxBool){
                Insert(x, p->RightNode, auxBool);
                //If para percorrer o nó direito caso não possa ir pelo esquerdo
                //Usado uma variável "auxBool" para saber quando ir para a direita  
            }
        }
    }

}

void ARVORE_PREFIXO::Lista(){
    //Usado para chamar uma função recursiva que exibe informações da árvore

    char codigo[50];
    int aux=-1;
    Lista(Root, codigo, aux);
}

void ARVORE_PREFIXO::Lista(TreePointer &p, char codigo[], int &aux){
    //Pré-condição: Árvore já tenha sido criada e não está vazia
    //Pós-condição: Percorre a árvore usando recursividade e exibe as informações necessárias

    if(p != NULL){
        if(p->Entry == '*'){
            aux++;
            codigo[aux] = '0';
            Lista(p->LeftNode, codigo, aux);
            aux++;
            codigo[aux] = '1';
            Lista(p->RightNode, codigo, aux);
            aux--;
        }//if para caso o caractere do nó seja "*" ele continue percorrendo
        else{
            codigo[aux+1] = '\0';
            string s_codigo(codigo);
            cout << setw(4) << p->Entry;
            cout << setw(9) << s_codigo.size();
            cout << setw(8+s_codigo.size()) << s_codigo << endl;
            aux--;
        }//else para caso o nó seja diferente de "*" ele imprima o caractere e seu respectivo código
        
    }//if para caso o nó seja nulo
    
}

void ARVORE_PREFIXO::Ler_msg(string mensagem){
    //Pré-condição: Árvore já tenha sido criada e não está vazia
    //Pós-condição: Exibe a mensagem descomprimida

    TreePointer t = Root;
    int quantidade=0;
    float taxacp=0;

    for(int i=0; i <= mensagem.size(); i++){
        
        if(t->Entry != '*'){
            quantidade++;
            cout << t->Entry;
            t = Root;

        }
        if(mensagem[i] == '0'){
            t = t->LeftNode;
        }
        else{
            t = t->RightNode;
        }

    }//Percorre os números da mensagem comprimida e descomprime ela

    taxacp = (mensagem.size() * 100.0) / (quantidade * 8.0);

    cout << endl << endl << "Número de bits = " << mensagem.size() << endl;
    cout << "Número de caracteres = " << quantidade << endl;
    cout << "Taxa de compressão = " << taxacp << "%" << endl << endl;

}

