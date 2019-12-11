
#include <cstdlib>
#include <iostream>

#define ANNEE_COURANTE 2019

using namespace std;

/*
	Arguments   : pointers to a and b integers
	Consequents	: swap values of a and b
*/
void swap (int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

/*
   Antecedant: a,b deux entiers
   Consequent: un entier resultat de la division entiere entre a et b
*/
void division (int a,int b, int &q, int &r){
	r=a;
	q=0;
	while(r>=b){
	    r=r-b;
	    q++;
	}
}

int max (int x, int y){
	if(x>y) return x;
	return y;
}

int max (int x, int y, int z){
	if (x>y && x>z) return x;
	if (y>x && y>z) return y;
	return z;
}

void p (int x, double y=12.1, char z='z'){
	cout << "x=" << x << " y=" << y << "; z=" << z << endl;
}

#define CARRE(x) x*x

inline int carre(int a){
	return a*a;
}

void printStr (string s){
	for (auto c : s)
		cout << c << '.';
	cout << endl;
}

int main(int argc, char const *argv[])
{
/* exo 1
	int naissance;
	cout << "Votre année de naissance: ";
	cin >> naisance;

	cout << "votre age est " << ANNEE_COURANTE - naissance << endl;

*/
/* exo 2 
	int a,b;
	cout << "a? "; cin >> a;
	cout << "b? "; cin >> b;
	
	swap (a,b);
	
	cout << "a=" << a << ", b=" << b << endl;
*/
/* exo 3 
	int a,b,q,r;

	cout << "a? "; cin >> a;
	cout << "b? "; cin >> b;

	division (a,b,q,r);

	cout << "q = " << q << endl << "r = " << r << endl;
	cout << a << " = " << b << " x " << q << " + " << r << endl;
*/
/* exo 4 
	int x,y,z;

	cout << "x? "; cin >> x;
	cout << "y? "; cin >> y;
	cout << "z? "; cin >> z;

	cout << "max of x and y : " << max (x,y) << endl;
	cout << "max of x,y and z : " << max(x,y,z) << endl;
*/
/* exo 5
	p (9,1.0,'a');
	p (3, 'a');
	p (5, 2.3);
	p (19);
*/
/* exo 6 
	int a = 3;
	cout << CARRE(a++) << endl;
	a = 3;
	cout << carre(a++) << endl;
*/
/* exo 7 
	bool p = true;
	cout << boolalpha;
	cout << p << endl;
	cout << noboolalpha;
	cout << p << endl;
*/
/* exo 8 
	wchar_t c = L'\u00C2';
	wcout << c << endl;
*/
/* exo 9 
	string name;
	cin >> name;
	cout << "Bonjour " << name << endl;
 */
 /* exo 10 
 	double tab_double[5] = {0.0,1.2,3.4,2.6,5.7};
 	for (double d : tab_double)
 		cout << d << endl;
*/
/* exo 11 */
	printStr ("Bonjour");

 	return EXIT_SUCCESS;
}