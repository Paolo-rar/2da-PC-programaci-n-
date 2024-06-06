#include <iostream>
using namespace std;

int main()
{

  struct tClientes{
    char nombre [50];
    char apellidos [100];
    char Estado_Factura;
    int unidades;
    float Valor_Unidad;
  };
  const int dimension = 100;
  tClientes listaClientes[dimension];
  tClientes tempClientes;
  int Cont_Clientes=0;
  char G_Continuar='S';
  int contadorMoroso= 0,contadorAtrasado= 0,contadorPagado= 0,  sumatoriaClientes= 0;
  int opcion1;
  float totalFacturas = 0.0; // Variable para almacenar la sumatoria de todas las facturas

  for (int i = 0; i < dimension; i++) {
    cout << "Registro de Clientes #" << i+1 << '\n';
    cout << "Ingrese los nombres" << '\n';
    cin >> tempClientes.nombre;
    cout << "Ingrese los apellidos" << '\n';
    cin >> tempClientes.apellidos;
    cout << "Número de unidades solicitadas" << '\n';
    cin >> tempClientes.unidades;
    cout << "El precio de cada unidad" << '\n';
    cin >> tempClientes.Valor_Unidad;
    cout << "Estado de la Factura(M: Moroso  A: Atrasado  P: PAgado)" << '\n';
    cin >> tempClientes.Estado_Factura;
    cout << " " << '\n';

    listaClientes[i]= tempClientes;
    Cont_Clientes++;

    cout << "Desea Registrar un Nuevo Cliente " << '\n';
    cout << ">>Presione (n o N) para Ir al Menu de Opciones" << '\n';
    cout << ">>Presione (s o S) para un Nuevo Registro" << '\n';
    cin >> G_Continuar;
    if (G_Continuar == 'n' || G_Continuar == 'N')
      break;
  }

  while(true){
    contadorMoroso    = 0;
    contadorAtrasado  = 0;
    contadorPagado    = 0;
    sumatoriaClientes = 0;
    totalFacturas = 0.0;

    int promedioFacturas; // Variable para almacenar el promedio de todas las facturas

    do{
      system("cls");
      cout << "----------- MENU PRINCIPAL -------------" << '\n';
      cout << "1. La lista de nombres de los clientes con facturas en estado moroso." << '\n';
      cout << "2. La lista de nombres de clientes en estado pagado con factura mayor a una cantidad ingresada" << '\n';
      cout << "3. Calcular promedio de facturas." << '\n';
      cout << "4. Salir del Programa" << '\n';
      cout << "Digite la Opcion deseada" << '\n';
      cin >> opcion1;
    } while(opcion1 < 1 || opcion1 > 4);

    switch(opcion1){
      case 1:
        for (int i = 0; i < Cont_Clientes; i++){
          tempClientes = listaClientes[i];
          if (tempClientes.Estado_Factura == 'M'){
            cout << "\t" << tempClientes.nombre << "\t" << tempClientes.apellidos
                 << "\t" << tempClientes.Estado_Factura << "\t" << tempClientes.unidades
                 << "\t" << tempClientes.Valor_Unidad << endl ;
            contadorMoroso++;
          }
        }
        cout << "La lista de nombres de los clientes con facturas en estado moroso : " << contadorMoroso <<'\n';
        break;

      case 2:
        for (int i = 0; i < Cont_Clientes; i++){
          tempClientes = listaClientes[i];
          if (tempClientes.Estado_Factura == 'P'){
            cout << "\t" << tempClientes.nombre << "\t" << tempClientes.apellidos
                 << "\t" << tempClientes.Estado_Factura << "\t" << tempClientes.unidades
                 << "\t" << tempClientes.Valor_Unidad << endl ;
            contadorPagado++;
          }
        }
        cout << "La lista de nombres de clientes en estado pagado con factura mayor a una cantidad ingresada : " << contadorPagado <<'\n';
        break;

      case 3:
        for (int i = 0; i < Cont_Clientes; i++){
          tempClientes = listaClientes[i];
          totalFacturas += tempClientes.unidades * tempClientes.Valor_Unidad;
        }
        promedioFacturas = totalFacturas / Cont_Clientes;
        cout << "El promedio de las facturas es: $" << promedioFacturas << '\n';
        break;

      case 4:
        return 0;
    }
    system("pause");
  }

  return 0;
}








