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


class Rayon {
 private:
    string name_;
    vector<Article> articles_;
    map<Article, int> qte_;

 public:
    Rayon(string rayon_name): name_{rayon_name} {}

    void add_article(Article art){
        if(qte_.find(art) != qte_.end())
            ++qte_[art];
        else{
            articles_.push_back(art);
            qte_[art] = 1;
        }
    }

    void print_rayon(){
        for(auto art : articles_){
            std::cout << art.getId_Ref() << " "
                      << name_ << " "
                      << art.getLabel() << " "
                      << art.getPrix() << " "
                      << qte_[art] << " ";
        }
    }

    vector<Article> get_articles(){
        return articles_;
    }

    int qte(Article art){
        if(qte_.find(art) != qte_.end())
            return qte_[art];
        return 0;
    }

    string name() { return name_;}
    
};