#pragma once
/** Classe  abstraite  pour  réprésenter  un  thread  défini  par la
*   classe  héritière  qui  devra  implémenter  la  méthode  run.
*
*   Note : Patron  de  méthode
*
*   @author: Vincent  GranetVincent.Granet@univ-cotedazur.fr
*/

#include <thread>

class Thread {
 private:
    std::thread p;

 protected:
    virtual void run() = 0;
    virtual ~Thread() = default;
 public:
 // Rôle : crée et démarre l’exécution du thread courant
    void start() {
        this->p = std::thread(&Thread::run, this);
    }
    void join() {
        this->p.join();
    }
};
