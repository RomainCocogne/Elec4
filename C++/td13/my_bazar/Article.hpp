#pragma once
#include <string>

using std::string;
/*
    classe article qui encapsule toute les infos d'un article
*/
class Article {
 private:
    int id_;
    string name_;
    double prix_;
 public:
    Article(int id, string name, double prix):
        id_{id}, name_{name}, prix_{prix} {}

    int getId_Ref() {return id_;}
    string getLabel() { return name_;}
    double getPrix() {return prix_;}

    bool operator==(const Article &art) const{
        return id_ == art.id_;
    }
    bool operator < (const Article &art)const{
        return id_<art.id_;
    }
};
