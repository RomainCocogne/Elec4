#include <iostream>
#include "animaux.hpp"

using namespace std;

int main()
{
    animal *faune[] = { new omnivore(10), new herbivore(60), new carnivore(7)};
    for (animal *a: faune){
        cout << "Je mange ";
        a->jeMange(); cout << endl;
    }
    return 0;
}
