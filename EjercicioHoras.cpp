#include <iostream>
using namespace std;
void Horas () {
   int hora, minuto, seg;
   do {
        cout << "Ingresa la hora (00 a 23): ";
        cin >> hora;
   }while (hora < 0 || hora > 23);
   do {
        cout << "Ingresa el minuto (00 a 59): ";
        cin >> minuto;
    } while (minuto < 0 || minuto > 59);

    do {
        cout << "Ingresa el segundo (00 a 59): ";
        cin >> seg;
    } while (seg < 0 || seg > 59);

    cout << "Hora registrada: ";
    if (hora < 10) cout << "0";
    cout << hora << ":";

    if (minuto < 10) cout << "0";
    cout << minuto << ":";

    if (seg < 10) cout << "0";
    cout << seg << endl;
}

int main (){
   int Op;
   cout << "Bienvenido al sistema de registro de horas" << endl;
   do {
        Horas();

        cout << "\n¿Deseas cambiar la hora registrada? 1 = Si ; 0 = No: ";
        cin >> Op;

    } while (Op != 0);

    cout << "Hora registrado, programa finalizado." << endl;
    return 0;
}


