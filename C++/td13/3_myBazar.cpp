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
#include "MyBazar.hpp"
#include "Article.hpp"

int main(int argc, char const *argv[]) {
    Bazar magasin("id", "psw");
    Rayon maison("maison");
    std::vector<Article> va1 = {
            Article(11180, "tapis", 8.0),
            Article(11180, "tapis", 8.0),
            Article(11170, "fenetre", 0.99)
        };
    for (auto art : va1)
        maison.add_article(art);

    Rayon vetements("vetements");
    std::vector<Article> va2 = {
            Article(11190, "chaussette", 80.0),
            Article(11190, "chaussette", 80.0),
            Article(11190, "chaussette", 80.0),
            Article(11200, "pull", 140.0),
            Article(11200, "pull", 140.0),
            Article(11200, "pull", 140.0),
            Article(11200, "pull", 140.0),
            Article(11200, "pull", 140.0),
            Article(11200, "pull", 140.0)
        };
    for (auto art : va2)
        vetements.add_article(art);

    magasin.add_rayon(maison); 
    magasin.add_rayon(vetements);

    std::cout << "magasin: " << std::endl;
    magasin.display_bazar();
    std::cout << std::endl;

    std::cout << "rayon vetements: " << std::endl;
    magasin.display_rayon("vetements");

    std::cout << std::endl;
    std::cout << "approvisionnement en fenetre: " << std::endl;
    maison.add_article(Article(11170, "fenetre", 0.99));
    magasin.update_rayon(maison);
    magasin.display_bazar();

    std::cout << std::endl;
    std::cout << "inf a 3 exemplaires: " << std::endl;
    magasin.printSolde(3);
    
    return 0;
}
