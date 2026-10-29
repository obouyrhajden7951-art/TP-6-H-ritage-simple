/*
 * Ex2.cpp
 *
 *  Created on: 29 oct. 2026
 *      Author: hP
 */

#include <iostream>
#include <string>
using namespace std;

class Compte {
protected:
    string numero;
    double solde;

public:
    Compte(string num, double s = 0) : numero(num), solde(s) {}

    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depot de " << montant << " DH effectue." << endl;
        } else {
            cout << "Montant invalide." << endl;
        }
    }

    void retirer(double montant) {
        if (montant <= 0) {
            cout << "Montant invalide." << endl;
        } else if (montant > solde) {
            cout << "Solde insuffisant." << endl;
        } else {
            solde -= montant;
            cout << "Retrait de " << montant << " DH effectue." << endl;
        }
    }

    void afficherSolde() const {
        cout << "Compte " << numero << " | Solde : " << solde << " DH" << endl;
    }
};

class CompteEpargne : public Compte {
private:
    double tauxInteret; // en pourcentage

public:
    CompteEpargne(string num, double s, double taux)
        : Compte(num, s), tauxInteret(taux) {}

    double calculerInteret() const {
        return solde * tauxInteret / 100;
    }
};

int main() {
    CompteEpargne ce("MA-12345", 1000, 3.5);

    ce.afficherSolde();
    ce.deposer(500);
    ce.retirer(200);
    ce.retirer(5000);
    ce.afficherSolde();

    cout << "Interet calcule : " << ce.calculerInteret() << " DH" << endl;
    return 0;
}


