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
#include "Bazar.hpp"
#include "Article.hpp"

int main(int argc, char const *argv[]) {
    Bazar bazar("id", "psw");
    bazar.add_rayon("legumes");
    bazar.add_rayon("fromage");
    Article courgette(10, "courgette", 10.1);
    Article poivron(13, "poivron", 15.1);
    Article chevre(20, "chevre", 70.1);
    bazar.add_article("legumes", courgette);
    bazar.add_article("legumes", poivron);
    bazar.add_article("fromage", chevre);
    bazar.print_bazar();
    return 0;
}
