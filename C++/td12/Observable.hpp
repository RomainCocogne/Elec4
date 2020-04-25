#pragma once
#include <list>
#include "Observateur.hpp"

template <typename T>
class Observable {
 private :
    std::list<Observateur <T> *> list_observateurs;
 public :
    void notifierObservateurs(T info) {
        for (auto obs : this->list_observateurs) obs->update(info);
    }
    void ajouterObservateur(Observateur<T>* observateur) {
        this->list_observateurs.push_back(observateur);
    }
};
