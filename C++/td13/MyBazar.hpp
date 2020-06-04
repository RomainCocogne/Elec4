#pragma once

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "Article.hpp"
#include "Rayon.hpp"

using std::string;
using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;

class Bazar {
 private:
    shared_ptr<sql::Connection> conn_;
    unique_ptr<sql::PreparedStatement> add_rayon_stmt_;
 public:
    Bazar(string id, string psw) {
        try {
            sql::mysql::MySQL_Driver *driver_;
            unique_ptr<sql::Statement> setup_bazar_;
            driver_ = sql::mysql::get_mysql_driver_instance();
            conn_.reset(driver_->connect("tcp://localhost", id, psw));
            setup_bazar_.reset(conn_->createStatement());
            std::cout << "CONNECTION OK" << std::endl;

            setup_bazar_->execute("DROP DATABASE IF EXISTS Bazar");
            setup_bazar_->execute("CREATE DATABASE Bazar");
            setup_bazar_->execute("USE Bazar");
            setup_bazar_->execute("DROP TABLE IF EXISTS rayons");
            setup_bazar_->execute("CREATE TABLE rayons (id_ref INT PRIMARY KEY NOT NULL , rayon VARCHAR (100), article VARCHAR (100) , qte INT, prix DOUBLE)");
            setup_bazar_->execute("CREATE PROCEDURE printSolde(IN n INT) SELECT * FROM rayons WHERE qte < n");

            add_rayon_stmt_.reset(conn_->prepareStatement("INSERT INTO rayons(id_ref, rayon, article, qte, prix) VALUES (? , ? , ?, ?, ?)"));

        } catch (sql::SQLException &e) {
            std::cerr << "# ERR: SQLException in " << __FILE__;
            std::cerr << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
            std::cerr << "# ERR: " << e.what();
            std::cerr << "(MySQL error code: " << e.getErrorCode();
            std::cerr << ", SQLState: " << e.getSQLState() << ")" << std::endl;
        }
    }
    ~Bazar() = default;

    void display_bazar(){
        if(conn_->isValid()){
            try{
                sql::ResultSet *res;
                sql::Statement *stmt = conn_->createStatement();
                res = stmt->executeQuery("SELECT * FROM rayons ORDER BY id_ref ASC");
                while (res->next()) {
                    std::cout << res->getInt("id_ref") << " ";
                    std::cout << res->getString("article") << " ";
                    std::cout << res->getString("rayon") << " ";
                    std::cout << res->getInt("qte") << " ";
                    std::cout << res->getDouble("prix") << std::endl;
                }
                delete stmt;
                delete res;
            } catch (sql::SQLException &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    void display_rayon(string r_name){
        if(conn_->isValid()){
            try{
                sql::ResultSet *res;
                sql::Statement *stmt = conn_->createStatement();
                res = stmt->executeQuery("SELECT * FROM rayons WHERE rayon = \'"+r_name+"\'");
                while (res->next()) {
                    std::cout << res->getInt("id_ref") << " ";
                    std::cout << res->getString("article") << " ";
                    std::cout << res->getString("rayon") << " ";
                    std::cout << res->getInt("qte") << " ";
                    std::cout << res->getDouble("prix") << std::endl;
                }
                delete stmt;
                delete res;
            } catch (sql::SQLException &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    void printSolde(int n){
        if(conn_->isValid()){
            try{
                sql::ResultSet *res;
                sql::Statement *stmt = conn_->createStatement();
                res = stmt->executeQuery("call printSolde("+std::to_string(n)+")");
                // res = stmt->executeQuery("SELECT @n");

                while (res->next()) {
                    std::cout << res->getInt("id_ref") << " ";
                    std::cout << res->getString("article") << " ";
                    std::cout << res->getString("rayon") << " ";
                    std::cout << res->getInt("qte") << " ";
                    std::cout << res->getDouble("prix") << std::endl;
                }
                delete stmt;
                delete res;
            } catch (sql::SQLException &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

        void add_rayon(Rayon r){
        if(conn_->isValid()){
            try{
                for (auto a : r.get_articles()) {
                    add_rayon_stmt_->setInt(1, a.getId_Ref());
                    add_rayon_stmt_->setString(2, r.name());
                    add_rayon_stmt_->setString(3, a.getLabel());
                    add_rayon_stmt_->setInt(4, r.qte(a));
                    add_rayon_stmt_->setDouble(5, a.getPrix());
                    // lancer la requête INSERT
                    add_rayon_stmt_->execute();
                }
            } catch (sql::SQLException &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    void update_rayon(Rayon r){
        if(conn_->isValid()){
            try{
                sql::Statement *stmt = conn_->createStatement();
                stmt->execute("DELETE FROM rayons WHERE rayon = \'"+r.name()+"\'");
                add_rayon(r);
                delete stmt;
            } catch (sql::SQLException &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    
};
