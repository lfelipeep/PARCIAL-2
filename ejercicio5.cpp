#include <iostream>
#include <string>
using namespace std;

int main() {
    string nom1, fec1, hor1, mot1;
    string nom2, fec2, hor2, mot2;
    string nom3, fec3, hor3, mot3;

    int menu;
    do {
        cout << "\n========== CONSULTORIO MÉDICO ==========\n";
        cout << "1. Agendar nueva cita\n";
        cout << "2. Ver citas por fecha\n";
        cout << "3. Cancelar cita\n";
        cout << "4. Historial de pacientes\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            cout << "\n--- REGISTRO DE CITA ---\n";

            string* nom = nullptr;  
            string* fec = nullptr;
            string* hor = nullptr;
            string* mot = nullptr;

            if (nom1.empty()) { nom = &nom1; fec = &fec1; hor = &hor1; mot = &mot1; }
            else if (nom2.empty()) { nom = &nom2; fec = &fec2; hor = &hor2; mot = &mot2; }
            else if (nom3.empty()) { nom = &nom3; fec = &fec3; hor = &hor3; mot = &mot3; }

            if (nom == nullptr) {
                cout << "No hay espacio disponible para más citas.\n";
            } else {
                cout << "Nombre del paciente: "; getline(cin, *nom);
                cout << "Fecha (YYYY-MM-DD): "; getline(cin, *fec);
                cout << "Hora (HH:MM): "; getline(cin, *hor);
                cout << "Motivo: "; getline(cin, *mot);
                cout << " Cita registrada con éxito.\n";
            }
        }

        else if (menu == 2) {
            cout << "\n--- CONSULTAR AGENDA ---\n";
            string fecha;
            cout << "Ingrese la fecha (YYYY-MM-DD): ";
            getline(cin, fecha);
            bool encontrada = false;

            auto mostrar = [&](string n, string f, string h, string m, int pos) {
                if (!n.empty() && f == fecha) {
                    cout << "\nCita #" << pos << "\n";
                    cout << "  Paciente: " << n << "\n  Hora: " << h << "\n  Motivo: " << m << "\n";
                    encontrada = true;
                }
            };

            mostrar(nom1, fec1, hor1, mot1, 1);
            mostrar(nom2, fec2, hor2, mot2, 2);
            mostrar(nom3, fec3, hor3, mot3, 3);

            if (!encontrada)
                cout << "No hay citas programadas para esa fecha.\n";
        }

        else if (menu == 3) {
            cout << "\n--- CANCELAR CITA ---\n";
            string n, f;
            cout << "Ingrese nombre del paciente: "; getline(cin, n);
            cout << "Ingrese la fecha (YYYY-MM-DD): "; getline(cin, f);
            bool eliminada = false;

            auto borrar = [&](string &no, string &fe, string &ho, string &mo) {
                if (no == n && fe == f) {
                    no = fe = ho = mo = "";
                    eliminada = true;
                }
            };

            borrar(nom1, fec1, hor1, mot1);
            borrar(nom2, fec2, hor2, mot2);
            borrar(nom3, fec3, hor3, mot3);

            cout << (eliminada ? " Cita cancelada correctamente.\n" : "No se encontró esa cita.\n");
        }

        else if (menu == 4) {
            cout << "\n--- HISTORIAL DE PACIENTES ---\n";
            bool hay = false;

            auto mostrarHist = [&](string n, string f, string h, string m, int id) {
                if (!n.empty()) {
                    cout << "Cita #" << id << ": " << n << " | " << f << " " << h << " | " << m << endl;
                    hay = true;
                }
            };

            mostrarHist(nom1, fec1, hor1, mot1, 1);
            mostrarHist(nom2, fec2, hor2, mot2, 2);
            mostrarHist(nom3, fec3, hor3, mot3, 3);

            if (!hay) cout << "No hay pacientes registrados.\n";
        }

        else if (menu == 5) {
            cout << "Saliendo del sistema...\n";
        }

        else {
            cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (menu != 5);

    return 0;
}
