#ifndef CONTENITORE_H
#define CONTENITORE_H
#include "rinoceronte.h"
#include "orso.h"
#include "serpente.h"
#include <QDebug>


template <class T> class Contenitore;

template <class T> std::ostream& operator<< (std::ostream&,const Contenitore<T>&);

template<class T>
class Contenitore{
    friend class iteratore;
private:
    class nodo{
    public:
        nodo():b(T()),prev(0),next(0){}
        nodo(const T& bag, nodo* p, nodo* n): b(bag),prev(p),next(n){}
        T b;
        nodo* prev;
        nodo* next;
    };
    nodo* first, *last;
    int n_el;
public:
    nodo* getFirst() const{return first;}
    Contenitore():first(0),last(0),n_el(0){}
    class iteratore{
        friend class Contenitore;
    private:
        nodo* punt;
    public:
        iteratore(){punt=0;}
        iteratore(nodo* ptr){punt=ptr;}
        nodo* getPunt() const{return punt;}
        bool operator ==(const iteratore& it) const{return punt == it.punt;}
        bool operator !=(const iteratore& it) const{return punt != it.punt;}
        iteratore& operator ++() // prefissi
        {
            if(punt) punt=punt->next;
            return *this;
        }
        iteratore& operator --(){
            if(punt) punt=punt->prev;
            return *this;
        }
        iteratore operator ++(int) // postfissi
        {
            iteratore tmp=*this;
            if(punt) punt=punt->next;
            return tmp;
        }
        iteratore operator--(int){
            iteratore tmp=*this;
            if(punt) punt=punt->prev;
            return tmp;
        }
        nodo& operator *() const{ return *punt;}
        // non ridefinisco ~iteratore in quanto quell std
        // fa ciò di cui ho bisogno: deallocare il ptr.
        // La deallocazione del nodo è compito di ~Lista
    };

    int size() const{return n_el;}
    bool isEmpty() const{return n_el<=0;}
    void push_back(const T& b){
        if(first && last){
            last->next=new nodo(b,last,0);
            last=last->next;
        }else first=last=new nodo(b,0,0);
        n_el++;
    }
    void pop_back(){ // funziona
        if(!isEmpty()){
            n_el--;
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
               n_el--;
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
        qDebug() << "aaaaaaaaaaaa";
        drop();
    }

    /*Contenitore<T>& operator=(const Contenitore<T>& c){
        if (this != &c){
            delete first,last,n_el;
            first = c.first;
            last = c.last;
            n_el = c.n_el;
        }
        return *this;
    }*/
};

#endif // CONTENITORE_H
