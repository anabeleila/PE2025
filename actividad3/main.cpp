#include <iostream>
using namespace std;

const int MAX = 500;

struct Pelicula{
    string idPelicula;
    string titulo;
    bool disponible;
    float duracion;
    int anioEstreno;
};

typedef Pelicula tvector[MAX];

void agregarPelicula(tvector &v, int &ocup, Pelicula nueva){
    if (ocup == MAX-1)
    return;
    ocup++;
    v[ocup]=nueva;
}

int busquedaSecuencial(tvector v, int ocupado, string id){
    if (ocupado<0)
    return-1;
    else{
        if(v[ocupado].idPelicula==id)
        return ocupado;
        else
        return busquedaSecuencial(v, ocupado-1,id);
    }
}

int mayorDuracion(tvector v, int ocupado){
    if(ocupado==0)
    return 0;
    int mayor=mayorDuracion(v, ocupado-1);
    if(v[ocupado].duracion > v[mayor].duracion)
    return ocupado;
    else
    return mayor;
}

void mostrarVec(tvector v, int ocupado){
    if(ocupado<0)
    return;
    mostrarVec(v, ocupado-1);
        cout<<"Titulo: "<<v[ocupado].titulo<<endl;
        cout<<"Año: "<<v[ocupado].anioEstreno<<endl;
        cout<<"Duracion: "<<v[ocupado].duracion<<endl;
        cout<<"Disponible: "<<(v[ocupado].disponible? "Si" : "No")<<endl;
    
}
