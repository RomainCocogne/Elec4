#pragma once
#include <string>

using std::string;

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
};
