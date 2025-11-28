#include <iostream>                              // Incluye la biblioteca para entrada/salida estándar
using namespace std;                             // Evita escribir std:: antes de cout, cin, endl



void establecerSaldo(float &saldo, bool &inicializado) { // Procedimiento que carga el saldo inicial (por referencia)
    float monto;                                   // Variable local para leer el monto ingresado
    cout << "Ingrese el saldo inicial: ";          // Pide al usuario que ingrese el saldo inicial
    cin >> monto;                                  // Lee el monto desde teclado y lo guarda en 'monto'

    if (monto >= 0) {                              // Valida que el monto sea mayor o igual a cero
        saldo = monto;                             // Asigna el monto al saldo (modifica la variable original)
        inicializado = true;                       // Marca que ya se estableció el saldo inicial
        cout << "Saldo inicial establecido correctamente" << endl; // Mensaje de confirmación
    } else {
        cout << "ERROR: El saldo debe ser positivo" << endl; // Mensaje de error si el monto es negativo
    }
}

void depositar(float &saldo, bool inicializado) {  // Procedimiento para depositar; recibe saldo por referencia 
    if (!inicializado) {                           // Verifica que el saldo inicial ya haya sido establecido
        cout << "Primero debe establecer el saldo inicial" << endl; // Si no, avisa y retorna
        return;                                   
    }

    float monto;                                   // Variable local para el monto a depositar
    cout << "Ingrese monto a depositar: ";         // Pide el monto a depositar
    cin >> monto;                                  // Lee el monto

    if (monto > 0) {                               // Verifica que el monto sea positivo (mayor que 0)
        saldo += monto;                            // Suma el monto al saldo (modifica la variable original)
        cout << "Deposito realizado correctamente" << endl; // Mensaje de confirmación
    } else {
        cout << "ERROR: El monto debe ser positivo" << endl; // Mensaje de error si el monto no es válido
    }
}

void extraer(float &saldo, bool inicializado) {   // Procedimiento para extraer dinero; saldo por referencia
    if (!inicializado) {                           // Verifica que el saldo inicial esté establecido
        cout << "Primero debe establecer el saldo inicial" << endl; // Si no, avisa y retorna
        return;
    }

    float monto;                                   // Variable local para el monto a extraer
    cout << "Ingrese monto a extraer: ";           // Pide el monto a extraer
    cin >> monto;                                  // Lee el monto

    if (monto <= 0) {                              // Valida que el monto sea positivo (> 0)
        cout << "ERROR: El monto debe ser positivo" << endl; // Error si es 0 o negativo
    } else if (monto > saldo) {                    // Verifica que haya fondos suficientes
        cout << "FONDOS INSUFICIENTES" << endl;    // Mensaje si no hay suficiente saldo
    } else {
        saldo -= monto;                            // Resta el monto del saldo si todo está ok
        cout << "Extraccion realizada correctamente" << endl; // Mensaje de confirmación
    }
}

void consultarSaldo(float saldo, bool inicializado) { // Procedimiento para mostrar el saldo; recibe copia del saldo
    if (!inicializado) {                           // Verifica que el saldo inicial esté establecido
        cout << "Primero debe establecer el saldo inicial" << endl; // Si no, avisa y retorna
        return;
    }

    cout << "Saldo actual: $" << saldo << endl;   // Muestra el saldo actual en pantalla
}


int main() {
    float saldo = 0;                              // Inicializa la variable saldo en 0
    bool inicializado = false;                    // indica si ya se cargó el saldo inicial
    int opcion;                                   // Variable para almacenar la opción elegida por el usuario

    do {                                          // Bucle que muestra el menú repetidamente hasta elegir salir
        cout << endl;                             // Línea en blanco para separar iteraciones del menú
        cout << "************* Simulador de ATM *************" << endl; // Título del menú
        cout << "1- Establecer saldo inicial" << endl; // Opción 1
        cout << "2- Realizar un deposito" << endl; // Opción 2
        cout << "3- Realizar una extraccion" << endl; // Opción 3
        cout << "4- Consultar saldo" << endl;     // Opción 4
        cout << "5- Salir" << endl;               // Opción 5
        cout << "********************************************" << endl; // Separador
        cout << "Elija una opcion: ";             // Pide al usuario que elija una opción
        cin >> opcion;                            // Lee la opción ingresada

        switch (opcion) {                         // Evalúa la opción elegida
            case 1:                              // Si eligió 1
                establecerSaldo(saldo, inicializado); // Llama al procedimiento para establecer saldo inicial
                break;                           // Rompe el switch y vuelve al menú
            case 2:                              // Si eligió 2
                depositar(saldo, inicializado);  // Llama al procedimiento para depositar
                break;
            case 3:                              // Si eligió 3
                extraer(saldo, inicializado);    // Llama al procedimiento para extraer
                break;
            case 4:                              // Si eligió 4
                consultarSaldo(saldo, inicializado); // Llama al procedimiento para consultar saldo
                break;
            case 5:                              // Si eligió 5
                cout << "FIN DE OPERACIONES" << endl; // Muestra mensaje de despedida
                break;
            default:                             // Si ingresó cualquier otra cosa
                cout << "OPCION INCORRECTA, intente de nuevo" << endl; // Mensaje de opción inválida
                break;
        }

    } while (opcion != 5);                       // Repite mientras la opción sea distinta de 5

    return 0;                                     // Fin del programa, devuelve 0 al sistema operativo
}
