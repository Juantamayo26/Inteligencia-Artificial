#include <bits/stdc++.h>

using namespace std;

const map<string, std::vector<pair<string, double>>> enfermedades = {
    {"gripa", {{"fiebre", 0.2}, {"malestar", 0.9}, {"tos", 0.7}}},
    {"faringitis", {{"dolorDeGarganta", 0.8}, {"malestar", 0.6}}}};

const map<string, pair<string, string>> tratamiento = {
    {"gripa", {"acetaminofen", "analgesico"}},
    {"faringitis", {"diclofenaco", "anti inflamatorio"}}};

struct EnfermedadUsuario {
  string nombre;
  double probabilidad;
};

void agregarSintomas(vector<string> &sintomas) {
  string sintoma;
  while (cin >> sintoma) {
    if (sintoma == "0") {
      break;
    }
    sintomas.push_back(sintoma);
  }
}

void imprimirSintomas(vector<string> &sintomas) {
  cout << "Sus sintomas son: ";
  for (int i = 0; i < sintomas.size(); i++) {
    cout << sintomas[i];
    if (i < sintomas.size() - 1) {
      cout << ",";
    }
  }
  cout << endl;
}

void solucion(vector<string> sintomas) {
  map<string, double> sol;
  int gripa, faringitis;
  gripa = faringitis = 0;
  for (auto sintoma : sintomas) {
    for (const auto &enfermedad : enfermedades) {
      for (auto sintomasEnfermedad : enfermedad.second) {
        if (sintomasEnfermedad.first == sintoma) {
          sol[enfermedad.first] += 1;
        }
      }
    }
  }
  cout << "POSIBLE SOLUCION" << endl;
  cout << "Es muy probable que usted tenga ";
  EnfermedadUsuario s;
  for (auto enfermedad : sol) {
    if (s.probabilidad < enfermedad.second) {
      s.nombre = enfermedad.first;
      s.probabilidad = enfermedad.second;
    }
  }
  pair<string, string> trat = tratamiento.find(s.nombre)->second;
  cout << "Se le recomienda tomar un " << trat.second << ", "
       << "pruebe con un " << trat.first << endl;
}

void init(vector<string> &sintomas) {
  cout << "Que sintomas presenta?" << endl;
  cout << "Cuando acabe de ingresar los sintomas, escriba 0" << endl;
  agregarSintomas(sintomas);
  imprimirSintomas(sintomas);
  solucion(sintomas);
}

int main() {
  vector<string> sintomas;
  init(sintomas);
  return 0;
}
