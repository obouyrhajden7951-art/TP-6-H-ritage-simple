/*
 * Ex3.cpp
 *
 *  Created on: 29 oct. 2026
 *      Author: hP
 */

#include <iostream>
#include <string>
using namespace std;

class Produit {
protected:
    string nom;
    double prix;

public:
    Produit(string n, double p) : nom(n), prix(p) {}
    virtual ~Produit() {}

    virtual void afficherInfos() const {
        cout << "Produit : " << nom << " | Prix : " << prix << " DH" << endl;
    }
};

class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;

public:
    ProduitAlimentaire(string n, double p, string date)
        : Produit(n, p), dateExpiration(date) {}

    void afficherInfos() const override {
        cout << "[Alimentaire] " << nom << " | Prix : " << prix
             << " DH | Expire le : " << dateExpiration << endl;
    }
};

class ProduitElectronique : public Produit {
private:
    int garantie; // en mois

public:
    ProduitElectronique(string n, double p, int g)
        : Produit(n, p), garantie(g) {}

    void afficherInfos() const override {
        cout << "[Electronique] " << nom << " | Prix : " << prix
             << " DH | Garantie : " << garantie << " mois" << endl;
    }
};

int main() {
    Produit* produits[3];
    produits[0] = new ProduitAlimentaire("Lait", 8.5, "15/12/2026");
    produits[1] = new ProduitElectronique("Casque", 350, 24);
    produits[2] = new Produit("Cahier", 12);

    for (int i = 0; i < 3; i++) {
        produits[i]->afficherInfos(); // polymorphisme
    }

    for (int i = 0; i < 3; i++) {
        delete produits[i];
    }
    return 0;
}



