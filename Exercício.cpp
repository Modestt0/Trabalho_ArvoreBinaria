//André Luis Modesto de Paula
//Código: 2077447

#include<iostream>
#include<iomanip>
#include<fstream>
#include"A_PREFIXO.h"
using namespace std;

int main(){
    
    string msg;
    ARVORE_PREFIXO bst(msg);
    cout << endl << "caractere  " << "bits  " << "codificação" << endl;
    cout << setfill('-') << setw(28) << "-" << setfill(' ') << endl;
    bst.Lista();
    //Chama as informações da tabela

    cout << endl << "Código: " << msg << endl;
    cout << "Frase: ";
    bst.Ler_msg(msg);
    //Exibe o código, a frase, número de bits, número de caracteres e taxa de compressão
    
}