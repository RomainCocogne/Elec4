#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "Article.hpp"

using std::shared_ptr;
using std::string;
using sql::Connection;
using std::map;
using std::vector;

/*
    classe rayon qui gère un rayon du bazar
*/
class Rayon {
 private:
    string name_;
    vector<Article> articles_;  // liste des articles du rayon
    map<Article, int> qte_; // quantite de chaque article dans le rayon

 public:
    Rayon(string rayon_name): name_{rayon_name} {}

    // ajoute un article au rayon
    void add_article(Article art){
        // si il est deja dans le rayon, on augmente la quantite
        if(qte_.find(art) != qte_.end())
            ++qte_[art];
        else{   // sinon, on l'ajoute
            articles_.push_back(art);
            qte_[art] = 1;
        }
    }

    // afichage d'un rayon
    void print_rayon(){
        for(auto art : articles_){
            std::cout << art.getId_Ref() << " "
                      << name_ << " "
                      << art.getLabel() << " "
                      << art.getPrix() << " "
                      << qte_[art] << " ";
        }
    }

    // recupere le vecteur d'articles
    vector<Article> get_articles(){
        return articles_;
    }

    // recupere la quantite d'un article (si non present dans le rayon renvoie 0)
    int qte(Article art){
        if(qte_.find(art) != qte_.end())
            return qte_[art];
        return 0;
    }

    // renvoie le nom du rayon
    string name() { return name_;}
    
};