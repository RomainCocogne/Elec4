/*
mysql -h localhost -u root -p
CREATE USER 'id'@'localhost' IDENTIFIED BY 'psw'
GRANT ALL PRIVILEGES ON '*' TO 'id'@'localhost';
*/


#include <stdlib.h>
#include <iostream>
#include <vector>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "Article.hpp"

int main(int argc, char const *argv[]) {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *res;
    sql::PreparedStatement *prep_stmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        conn = driver->connect("tcp://localhost", "id", "psw");
        stmt = conn->createStatement();
        
        std::cout << "CONNECTION OK" << std::endl;

        stmt->execute("DROP DATABASE IF EXISTS Test_BD");
        stmt->execute("CREATE DATABASE Test_BD");
        stmt->execute("USE Test_BD");
        stmt->execute("DROP TABLE IF EXISTS article");
        stmt->execute("CREATE TABLE article(id_ref INT PRIMARY KEY NOT NULL , label VARCHAR (100) , prix DOUBLE)");
        stmt->execute("INSERT INTO article(id_ref, label, prix) VALUES (11179, 'ballon', 10.)");
        stmt->execute("INSERT INTO article(id_ref, label, prix) VALUES (11123, 'matelas', 300.)");
        stmt->execute("INSERT INTO article(id_ref, label, prix) VALUES (11159, 'lampe', 55.9)");
        stmt->executeUpdate("UPDATE article SET prix=49.99 WHERE id_ref =11159");

        prep_stmt = conn->prepareStatement("INSERT INTO article(id_ref, label, prix) VALUES (? , ? , ?)");
        std::vector<Article> va = {
            Article(11180, "tapis", 8.0),
            Article(11120, "chaussette", 800.5),
            Article(11170, "fenetre", 0.99)
        };
        for (Article a : va) {
            prep_stmt->setInt(1, a.getId_Ref());
            prep_stmt->setString(2, a.getLabel());
            prep_stmt->setDouble(3, a.getPrix());
            // lancer la requête INSERT
            prep_stmt->execute();
        }

        // res = stmt->executeQuery("SELECT * FROM article ORDER BY id_ref ASC");
        res = stmt->executeQuery("SELECT * FROM article WHERE prix < 100");
        while (res->next()) {
            std::cout << res->getInt("id_ref") << " ";
            std::cout << res->getString("label") << " ";
            std::cout << res->getDouble("prix") << std::endl;
        }

        delete stmt;
        delete prep_stmt;
        delete conn;
        delete res;
    }
    catch(sql::SQLException &e) {
        std::cerr << "# ERR: SQLException in " << __FILE__;
        std::cerr << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cerr << "# ERR: " << e.what();
        std::cerr << "(MySQL error code: " << e.getErrorCode();
        std::cerr << ", SQLState: " << e.getSQLState() << ")" << std::endl;
    }
    return 0;
}
