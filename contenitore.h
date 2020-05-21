#ifndef CONTENITORE_H
#define CONTENITORE_H
#include "rinoceronte.h"
#include "orso.h"
#include "serpente.h"
template <class T>
class Contenitore
{
    friend class iteratore;
private:
    class nodo{
    public:
        nodo():b(T()),prev(nullptr),next(nullptr){}
        nodo(const T& an, nodo* p ,nodo* n):b(an),prev(p),next(n){}
        T b;
        nodo* prev;
        nodo* next;
    };
    nodo* first;
    nodo* last;
    int nel;
public:
    Contenitore():first(nullptr),last(nullptr),nel(0) {}
    class iteratore{
    friend class Contenitore;
    private:
    nodo* ptr;
    public:
    iteratore():ptr(nullptr){}
    iteratore(nodo* p):ptr(p){}
    nodo* getptr() const {return ptr;};
    bool operator==(const iteratore& it) const {
        return ptr==it.ptr;
    }
    bool operator!=(const iteratore& it) const {
        return ptr!=it.ptr;
    }
    iteratore& operator++() {
        if(ptr) ptr=ptr->next;
        return *this;
    }
    iteratore& operator--() {
        if(ptr) ptr=ptr->prev;
        return *this;
    }
    iteratore operator++(int){
        iteratore temp = *this;
        if(ptr) ptr=ptr->next;
        return temp;
    }
    iteratore operator--(int){
        iteratore temp = *this;
        if(ptr) ptr=ptr->prev;
        return temp;
    }
    nodo& operator*()const {
        return *ptr;
    }
    };
    int size() const{return nel;}
        bool isEmpty() const{return nel<=0;}
        void push_back(const T& b){
            if(first && last){
                last->next=new nodo(b,last,0);
                last=last->next;
            }else first=last=new nodo(b,0,0);
            nel++;
        }
        void pop_back(){ // funziona
            if(!isEmpty()){
                nel--;
                nodo* tmp=last;
                last=last->prev;
                if(last) last->next=0;
                delete tmp;
            }
        }
        iteratore delete_node(nodo* tmp){
            iteratore aux;
            if(tmp){
                   if(tmp==first){
                       first=aux.punt=first->next;
                       if(first) first->prev=0;
                   }else if(tmp==last){
                       last=last->prev;
                       if(last) last->next=0; // non servirebbe il controllo su last perchè se entro in questo if => ho almeno due nodi
                   }else{
                       tmp->prev->next=aux.punt=tmp->next;
                       tmp->next->prev=tmp->prev;
                   }
                   delete tmp;
                   nel--;
               }
            return aux;
        }

        iteratore pop(const iteratore& it){
            if(!isEmpty()) return delete_node(it.getPunt());
            else return iteratore();
        }

        void drop(){ // dealloca tutta la lista
                while(!isEmpty()) pop_back(); // dealloca dall'ultimo al primo
        }

        nodo& operator[](const iteratore& it) const{return *(it.punt);}

        iteratore begin() const{
            iteratore tmp;
            tmp.punt=first;
            return tmp;
        }
        iteratore end() const{
            iteratore tmp;
            tmp.punt=0;
            return tmp;
        }
        ~Contenitore(){ // deve deallocare la lista al termine del programma
            drop();
        }
    };

#endif // CONTENITORE_H
