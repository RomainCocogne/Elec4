#include <iostream>
#include "exo2.hpp"

using namespace std;

class valueException: public std::exception{
public:
    const char* what() const noexcept override{
        return "Erreur de valeur";
    }
};

int main()
{
    hlm<int>  *h = new hlm<int>();
    cout << "Creation de l'ensemble d'entiers..." << endl;
    cout << "Ensemble vide ? " << h->vide() << endl;

    int bi, bs;
    while(1){
        cout << endl << "----------" << endl;
        cout << "Ensemble vide ? " << h->vide() << endl;
        cout << "6 appartient a l'ensemble ?" << h->appartient(6) << endl;
        cout << "Rentrer nouvel ensemble: "<< endl;
        try{
            cout << "Borne inferieure: "; if(!(cin >> bi)) throw valueException();
            cout << "Borne superieure: "; if(!(cin >> bs)) throw valueException();

            if(bi==bs) h->ajouter( new singleton<int> (bi));
            h->ajouter( new intervalle<int> (bi,bs));
            cout << "ensemble: "<< *h << endl;
        }
        catch(intervalException &e){
            cerr << e.what() << endl;
            break;
        }
        catch(valueException &e2){
            cerr << e2.what() << endl;
            break;
        }

    }
    return 0;
}
