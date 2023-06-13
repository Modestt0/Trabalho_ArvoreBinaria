//Andre Luis Modesto de Paula
#include<string.h>
using namespace std;

#ifndef A_PREFIXO_H
#define A_PREFIXO_H

class ARVORE_PREFIXO{
    public:
        ARVORE_PREFIXO(string &msg);
        ~ARVORE_PREFIXO();
        void Lista();
        void Ler_msg(string mensagem);

    private:
        struct TreeNode{
            char Entry;
            TreeNode *RightNode;
            TreeNode *LeftNode;
        };//struct de nó para guardar os valores

        typedef TreeNode *TreePointer;

        TreePointer Root;

        void Destructor(TreePointer &p);
        void Lista(TreePointer &p, char codigo[], int &aux);
        void Insert(char x, TreePointer &p, bool &auxBool);
};

#endif