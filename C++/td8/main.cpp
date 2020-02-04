#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "MonException.hpp"
#include "MonException1.hpp"
#include "MonException2.hpp"
#include "Tableau.hpp"
#include "../td4/complexe.hpp"

using namespace std;

int intrandom(){
    srand(time(nullptr));
    int r = rand()%4;
    switch (r){
        case 0: throw 10; break;
        case 1: throw MonException(); break;
        case 2: throw "Exception"; break;
        default:;
    }
    return r;
}

void f () { throw MonException(); }
void g(){
    try{
        f();
    }catch(MonException e){
        cerr << e << " attrapee par g" << endl;
        throw;
    }
}

void f1() { throw MonException1();}
void g1() { throw MonException2();}

void finir () { cerr  <<"c est fini , adieu !"<< endl;}

int main()
{
    set_terminate(finir);

    try{
        cout << intrandom() << endl;
        cout << "apres execution" << endl;
    }
    catch(int e1){
        cerr << e1 << endl;
    }
    catch (MonException &e2){
        cerr << e2 << endl;
    }
    catch(...){
        cerr << "autre" << endl;
    }

    try{
        g();
    }
    catch (MonException &e){
        cerr << e << " attrapee dans main" << endl;
    }

    try{
        f1(); g1();
    }
    catch (MonException2 &e2){
        cout << e2.what() << endl;
    }catch(MonException1 &e1){
        cout << e1.what() << endl;
    }
    cout << endl << "----- Tableau -----" << endl;

    Tableau<5, Complexe> tc;
    cout << tc.longueur() <<endl;
    tc[0] = Complexe(1,3);
    try{
        cout << tc[0] << endl;
    }catch(IndexException &ei){
        cerr << ei.what() << endl;
    }
    cout << tc << endl;

    Tableau <10, int> ti1,ti2;
    ti1[5]=10;
    cout << ti1[5]<< endl;
    ti2=ti1;
    ti2[5]=20;
    cout << ti1[5] << endl;
    cout << ti2[5] << endl;

    return 0;
}
