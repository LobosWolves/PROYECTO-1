#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void eliminarAlumno()
{
 string carne;
  string alumno;
  string fila;
  ifstream leerArchivo("baseDatosAlumnos.txt");
  ofstream escribirArchivo("temporal.txt");
  cout << "escribe el carne que quieres eliminar" << endl;
  cin >> carne;
  while (getline(leerArchivo, fila))
  {
    if (!fila.find(carne))
    {
      	fila = "";
    }
	fila = fila+"\n";
    escribirArchivo << fila;
  }
  leerArchivo.close();
  escribirArchivo.close();
  remove("baseDatosAlumnos.txt");
  rename("temporal.txt","baseDatosAlumnos.txt"); 
}
void buscarAlumno()
{
	string fila;
  string carne;
  ifstream leerArchivo("baseDatosAlumnos.txt");
  cout << "escribe el carne que quieres buscar" << endl;
  cin >> carne;
  while (getline(leerArchivo, fila))
  {
    if (!fila.find(carne))
    {
  	cout<< "resultado es:\n";
      cout << fila<<endl;
    }
  }
  leerArchivo.close();
}
void mostrarAlumnos()
{
	string fila;
  ifstream leerArchivo("baseDatosAlumnos.txt");
  while (getline(leerArchivo, fila))
  {
    cout << fila<<endl;
  }
  leerArchivo.close();
}
void modificarAlumno()
{
  string carne;
  string alumno;
  string fila;
  ifstream leerArchivo("baseDatosAlumnos.txt");
  ofstream escribirArchivo("temporal.txt");
  cout << "escribe el carne que quieres editar" << endl;
  cin >> carne;
  cout << "escribe un nuevo alumno" << endl;
  getline(cin >> ws, alumno);
  while (getline(leerArchivo, fila))
  {
    if (!fila.find(carne))
    {
      	fila = alumno;
    }
	fila = fila+"\n";
    escribirArchivo << fila;
  }
  leerArchivo.close();
  escribirArchivo.close();
  remove("baseDatosAlumnos.txt");
  rename("temporal.txt","baseDatosAlumnos.txt");
}

void menu(){
	int opcion;
  cout << "**********BIENVENIDO********" << endl;
  cout << "Que desea hacer?" << endl;
  cout << "1. ver todos los alumnos" << endl;
  cout << "2. buscar un alumno" << endl;
  cout << "3. modificar un alumno" << endl;
  cout << "4. eliminar un alumno" << endl;
  cout << "5. salir" << endl;
  cin >> opcion;
  switch (opcion)
  {
  case 1:
  {
  	system("cls");
    mostrarAlumnos();
    system("pause");
    system("cls");
	menu();
    break;
  }
     case 2:
     {
     	system("cls");
       	buscarAlumno();
    	system("pause");
    	system("cls");
       	menu();
       	break;
     }
     case 3:
     {
     	system("cls");
       	modificarAlumno();
    	system("cls");
    	menu();
       break;
     }
     
     case 4:
     {
     	system("cls");
       eliminarAlumno();
	   system("cls");
    	menu();
       break;
     }
  default:
    break;
  }
}
int main()
{
  menu();
  return 0;
}
