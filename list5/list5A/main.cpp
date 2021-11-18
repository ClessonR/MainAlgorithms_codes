#include <bits/stdc++.h>

using namespace std;

  class List{
private:
    void operator = (const List&){}
    List(const List&){}
public:
    List(){}
    virtual void inserir(int item) = 0;
    virtual int remover() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual void moveToEnd() = 0;
    virtual void moveToStart() = 0;
    virtual int getValue() = 0;
    virtual int length() = 0;
    virtual int currPos() = 0;
};

class Link {
    public:
    int element;
    Link *next;
    // construtores
    Link (int elemval, Link* nextval =NULL){
        element = elemval;
        next = nextval;
    }
    Link (Link* nextval =NULL){
        next = nextval;
    }
    };


class LList: public List{
    public:
        LList(int size=0) { init(); } // Constructor
        void print() const; // Printa conteudos da lista

        void inserir(int aq){ // insere elementos ao lado direito do cursor
            curr->next = new Link(aq, curr->next);
            if(tail == curr) tail = curr->next;
            cnt++;
        };
        int currPos(){
            Link* temp = head;
            int i;
            for (i = 0; curr != temp; i++){
                temp = temp->next;
            }
            return i;
        }
        int length() {return cnt;}
        int remover() { // remove elementos ao lado direito do cursor
            if(curr->next == NULL) return NULL;
            int it = curr->next->element;
            Link* ltemp = curr->next;
            if(tail == curr->next) tail = curr;
            curr->next = curr->next->next;
            delete ltemp;
            cnt--;
            return it;
        };
        void moveToStart(){ // Coloca o cursor no início da lista
            curr = head;
        }
        void moveToEnd(){ // Coloca o cursor no final da lista
            curr = tail;
        }
        void prev(){ // passa o cursor uma posição para a esquerda
            if(curr == head) return;
            Link* temp = head;
            while (temp->next != curr) temp=temp->next;
            curr = temp;
        }
        void next(){ // passa o cursor uma posição para a direita
            if(curr!= tail) curr = curr->next;
        }
        int getValue(){ // retorna o elemento atual
            if(curr->next != NULL) return curr->next->element;
        }
        int contar(int valor){ // conta o numero de vezes que o elemento inserido esta na lista
        Link* temp = head;
        int contador = 0;
        while (temp != NULL){
            if(temp->element == valor) contador++;
            temp = temp->next;
        }
        return contador;
        }
    private:
        Link* head;
        Link* tail;
        Link* curr;
        int cnt;
        void init(){
        curr = tail = head = new Link;
        cnt = 0;
        };

    };
class Grafo {
public:
    List** vertice;
    int *Mark;
    int numArestas;
    int numVertices;
    stack<int> pilha;

    Grafo(int n){
    numArestas = 0;
    numVertices = n;
    Mark = new int[n];
    vertice = new List*[n];
    for (int i = 0; i < n; i++){
        vertice[i] = new LList();
    }

    }

    int n(){return numVertices;}

    int first(int v){
    if (vertice[v]->length() == 0){return n();}
    vertice[v]->moveToStart();
    int E = vertice[v]->getValue();
    return E;
    }

    int next(int v, int w){
    int FDP;
    if((vertice[v]->currPos()+1) < vertice[v]->length()){
        vertice[v]->next();
        FDP = vertice[v]->getValue();
        return FDP;
        }
    return n();
    }


    int criarAresta(int i, int j){
    numArestas++;
    for(vertice[i]->moveToStart();vertice[i]->currPos() < vertice[i]->length(); vertice[i]->next()){
        int temp = vertice[i]->getValue();
        if(temp > j) break;
    }
    vertice[i]->inserir(j);
    }

    int getMark(int v) {return Mark[v];}
    void setMark(int v, int val) {Mark[v] = val;}

    void graphTraverse(){
    for(int i = 0; i < n(); i++){
        setMark(i, 0);
    }
    for(int v = 0; v < n(); v++){
        if (getMark(v) == 0){DFS(v, pilha);}
    }

    }

    void DFS(int v, stack<int> s){
    setMark(v, 1);
    int w = first(v);
    while (w < n()){
        if (getMark(w) == 0) {DFS(w, s);}
        w = next(v, w);
    }
    pilha.push(v);
    }

    void ImprimirPilha(){
         while(!pilha.empty()){
        cout << pilha.top() << endl;
        pilha.pop();
    }
    }

};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    int ar1, ar2;
    cin >> n >> e;
    Grafo G(n);
    for(int i = 0; i < e; i++){
        cin >> ar1 >> ar2;
        G.criarAresta(ar1, ar2);
    }
    G.graphTraverse();
    G.ImprimirPilha();

    return 0;
}
