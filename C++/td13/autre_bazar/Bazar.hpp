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

using std::string;
using std::vector;
using std::unique_ptr;
using std::make_unique;

class Bazar {
 private:
        sql::mysql::MySQL_Driver *driver_;
        unique_ptr<sql::Connection> conn_;
        unique_ptr<sql::Statement> setup_bazar_;

 public:
    Bazar(string id, string psw) {
        try {
            driver_ = sql::mysql::get_mysql_driver_instance();
            conn_.reset(driver_->connect("tcp://localhost", id, psw));
            setup_bazar_.reset(conn_->createStatement());
            std::cout << "CONNECTION OK" << std::endl;

            setup_bazar_->execute("DROP DATABASE IF EXISTS Bazar");
            setup_bazar_->execute("CREATE DATABASE Bazar");
            setup_bazar_->execute("USE Bazar");

        } catch (sql::SQLException &e) {
            std::cerr << "# ERR: SQLException in " << __FILE__;
            std::cerr << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
            std::cerr << "# ERR: " << e.what();
            std::cerr << "(MySQL error code: " << e.getErrorCode();
            std::cerr << ", SQLState: " << e.getSQLState() << ")" << std::endl;
        }
    }
    ~Bazar() = default;

    void add_rayon(string rayon) {
        string drop_cmd = "DROP TABLE IF EXISTS "+rayon;
        string create_cmd = "CREATE TABLE "+rayon+"(id_ref INT PRIMARY KEY NOT NULL , label VARCHAR (100) , prix DOUBLE)";
        if(conn_->isValid()){
            setup_bazar_->execute(drop_cmd);
            setup_bazar_->execute(create_cmd);
        }
    }
    void add_article(string rayon, Article article) {
        std::ostringstream create_cmd;
        create_cmd << "INSERT INTO " << rayon
                   << "(id_ref, label, prix) VALUES ("
                   << article.getId_Ref()
                   << ", '"<< article.getLabel() << "', "
                   << article.getPrix() << ")";
        if (conn_->isValid()) {
            try {
                setup_bazar_->execute(create_cmd.str());
            } catch (sql::SQLException &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    void print_bazar() {
        if (conn_->isValid()) {
            sql::ResultSet *rayons;
            sql::ResultSet *rayon;
            string create_cmd;
            rayons = setup_bazar_->executeQuery("SHOW TABLE STATUS FROM Bazar");
            while (rayons->next()) {
                create_cmd = "SELECT * FROM " + rayons->getString("Name") + " ORDER BY id_ref ASC";
                rayon = setup_bazar_->executeQuery(create_cmd);
                std::cout << "Rayon " << rayons->getString("Name") << ": "<< std::endl;
                while (rayon->next()) {
                    std::cout << "\t"
                              << rayon->getInt("id_ref") << " "
                              << rayon->getString("label") << " "
                              << rayon->getDouble("prix") << std::endl;
                }
                delete rayon;
            }
            delete rayons;
        }
    }
};
