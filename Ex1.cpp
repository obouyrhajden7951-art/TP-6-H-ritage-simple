/*
 * Ex1.cpp
 *
 *  Created on: 29 oct. 2026
 *      Author: hP
 */
#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom;
    int age;

public:
    Personne(string n, int a) : nom(n), age(a) {}

    void afficher() const {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << " ans" << endl;
    }
};

class Etudiant : public Personne {
private:
    string niveau;

public:
    // Appel du constructeur de la classe de base
    Etudiant(string n, int a, string niv) : Personne(n, a), niveau(niv) {}

    void afficher() const {
        Personne::afficher();
        cout << "Niveau : " << niveau << endl;
    }
};

int main() {
    Etudiant e("Ahmed", 20, "L2 Informatique");
    e.afficher();
    return 0;
}

