/*
 * Ex4.cpp
 *
 *  Created on: 29 oct. 2026
 *      Author: hP
 */
#include <iostream>
#include <string>
using namespace std;

class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    Employe(string n, int i, float s) : nom(n), id(i), salaireDeBase(s) {}

    virtual ~Employe() {
        cout << "Destruction de l'employe " << nom << endl;
    }

    virtual void afficherInfos() const {
        cout << "ID : " << id << " | Nom : " << nom
             << " | Salaire de base : " << salaireDeBase << " DH" << endl;
    }
};

class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(string n, int i, float s, float prime)
        : Employe(n, i, s), primeAnnuelle(prime) {}

    ~Permanent() {
        cout << "  -> Permanent detruit" << endl;
    }

    void afficherInfos() const override {
        cout << "[Permanent] ";
        Employe::afficherInfos();
        cout << "            Prime annuelle : " << primeAnnuelle << " DH" << endl;
    }
};

class Contractuel : public Employe {
private:
    int dureeContrat;   // en mois
    float tauxHoraire;

public:
    Contractuel(string n, int i, float s, int duree, float taux)
        : Employe(n, i, s), dureeContrat(duree), tauxHoraire(taux) {}

    ~Contractuel() {
        cout << "  -> Contractuel detruit" << endl;
    }

    float calculerSalaireMensuel(int heures) const {
        return salaireDeBase + heures * tauxHoraire;
    }

    void afficherInfos() const override {
        cout << "[Contractuel] ";
        Employe::afficherInfos();
        cout << "              Duree du contrat : " << dureeContrat
             << " mois | Taux horaire : " << tauxHoraire << " DH" << endl;
    }
};

int main() {
    const int N = 4;
    Employe** employes = new Employe*[N]; // tableau dynamique de pointeurs

    employes[0] = new Permanent("Ahmed", 1, 8000, 12000);
    employes[1] = new Contractuel("Sara", 2, 3000, 12, 50);
    employes[2] = new Permanent("Youssef", 3, 9500, 15000);
    employes[3] = new Contractuel("Salma", 4, 2500, 6, 45);

    cout << "===== Liste des employes =====" << endl;
    for (int i = 0; i < N; i++) {
        employes[i]->afficherInfos(); // polymorphisme
    }

    // Appel d'une methode propre a Contractuel (cast necessaire)
    Contractuel* c = dynamic_cast<Contractuel*>(employes[1]);
    if (c != nullptr) {
        cout << "\nSalaire mensuel de Sara (160 h) : "
             << c->calculerSalaireMensuel(160) << " DH" << endl;
    }

    cout << "\n===== Liberation de la memoire =====" << endl;
    for (int i = 0; i < N; i++) {
        delete employes[i]; // destructeur virtuel : appelle les deux destructeurs
    }
    delete[] employes;

    return 0;
}
