#pragma once
#include <iostream>
#include <sstream>

//classe d'exception pour les erreurs de bornes
class intervalException: public std::exception{
public:
    const char* what() const noexcept override{
        return "Bornes non valides";
    }
};

//classe intervalle qui contient une borne inf, sup et un pointeur vers l'intervalle suivant
template<typename T> class intervalle{
private:
   virtual std::string toString(){
        std::ostringstream str;
        str << "[" << this->getBinf() << "," << this->getBsup() << "]";
        return str.str();
    }
protected:
    T binf, bsup;
    intervalle<T> *suivant;

public:
        intervalle<T> (T i, T s){
            if (i>s) throw intervalException();
            this->binf=i; this->bsup=s;
           this-> suivant = nullptr;
        }

        T &getBinf() {return this->binf;}
        T &getBsup() {return this->bsup;}
        intervalle<T> *getSuivant(){return this->suivant;}
        void setSuivant(intervalle<T> *s) { this->suivant = s;}
        friend std::ostream& operator << (std::ostream &f, intervalle<T> &e){
            return f << e.toString();
        }
};

// un intervalle contenant une seule valeur
template<typename T> class singleton: public intervalle<T>{
private:
    std::string toString(){
        std::ostringstream str;
        str << "[" << this->getBinf() << "]";
        return str.str();
    }
public:
    singleton<T>(T i): intervalle<T>(i,i){}
};

//classe des grands ensembles contenant une suite chainee d'intervalles
template<typename T> class hlm{
private:
    intervalle<T> *sommet; // le sommet de la suite d'intervalles

    std::string toString(){
        std::ostringstream str;
        str << "[";
        intervalle<T> *s=this->sommet;
        while (s != nullptr){
            str << *s;
            s = s->getSuivant();
        }
        str << "]";
        return str.str();
    }
public:

    hlm(){this->sommet=nullptr;} //s'assurer que le sommet pointe bien vers le pointeur nul quand l'ensemble est vide

//test si l'ensemble est vide
    bool vide(){
        return (this->sommet==nullptr);
    }
//test si l'element x appartient a l'ensemble
    bool appartient(T x){
        intervalle<T> *s=this->sommet;
        while (s != nullptr){
            if (x < s->getBinf()) return false;
            if (x <= s->getBsup()) return true;
            s = s->getSuivant();
        }
        return false;
    }

//ajoute un intervalle a l'ensemble. regle les problemes de chevauchements des intervalles
    void ajouter(intervalle<T> *t){

        if (t->getBsup()< t->getBinf()) throw intervalException(); // si l'intervalle est inversé

        if(this->vide()){ // si l'ensemble est vide
            t->setSuivant(this->sommet);
            this->sommet=t;
            return;
        }
        else if( t->getBinf()<=this->sommet->getBsup()) { //si on doit inserer l'intervalle au debut
            if( t->getBsup() < this->sommet->getBinf()){
                t->setSuivant(this->sommet);
                this->sommet =t;
            }
            if(t->getBsup()>this->sommet->getBsup()){
                this->sommet->getBsup()=t->getBsup();
            }
            if(t->getBinf()<this->sommet->getBinf()){
                this->sommet->getBinf()=t->getBinf();
            }
        }
        else{
            intervalle<T> *s = this->sommet;
            while( s->getSuivant()!=nullptr && t->getBinf()>s->getSuivant()->getBsup()) s = s->getSuivant(); // on parcourt l'ensemble jusqu'a se placer au rang d'insertion de t

            if(s->getSuivant()==nullptr || t->getBsup() < s->getSuivant()->getBinf()){ // si t n'est inclu dans aucun intervalle
                t->setSuivant(s->getSuivant());
                s->setSuivant(t);
            }
            if(t->getBsup()>s->getSuivant()->getBsup()){ //si t est a cheval sur un intervalle
                s->getSuivant()->getBsup()=t->getBsup();
            }
            if(t->getBinf()<s->getSuivant()->getBinf()){
                s->getSuivant()->getBinf()=t->getBinf();
            }
        }


        // concatenation des sous ensembles si possible
        intervalle<T> **i = &this->sommet;
        intervalle<T> *itemp = *i;
        while ((*i)->getSuivant() !=nullptr){
            if((*i)->getBsup()+1 >= (*i)->getSuivant()->getBinf()){
                if((*i)->getBsup()> (*i)->getSuivant()->getBsup())
                    (*i)->setSuivant((*i)->getSuivant()->getSuivant());
                else{
                    (*i)->getBsup()=(*i)->getSuivant()->getBsup();
                    (*i)->setSuivant((*i)->getSuivant()->getSuivant());
                }

            }
            else{
                itemp =  ((*i)->getSuivant());
                i = &itemp;
            }
        }
    }

    friend std::ostream& operator << (std::ostream &f, hlm<T> &h){
        return f << h.toString();
    }
};
