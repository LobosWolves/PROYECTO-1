#include <iostream>
#include <fstream>
using namespace std;



void agregarAlumno()
{
	string alumno;
  ofstream myfile;
cout << "escribe los datos de un nuevo alumno"<<endl;
cin >> alumno;
  myfile.open("baseDatosAlumnos.txt");
  myfile << alumno+"\n";
  myfile.close();
}
void eliminarAlumno()
{
	string carne;
  ofstream archivo;
  archivo.open("baseDatosAlumnos.txt");
  cout << "escribe el carne que quieres buscar" << endl;
  cin >> carne;
  while (getline(archivo, fila))
  {
    if (fila.find(carne))
    {
      fila = "";
    }
  }
}
void buscarAlumno()
{
	string carne;
  ofstream archivo;
  archivo.open("baseDatosAlumnos.txt");
  cout << "escribe el carne que quieres buscar" << endl;
  cin >> carne;
  while (getline(archivo, fila))
  {
    if (fila.find(carne))
    {
      cout << fila;
    }
  }
}
void mostrarAlumnos()
{
  ofstream archivo;
  archivo.open("baseDatosAlumnos.txt");
  while (getline(archivo, fila))
  {
    cout << fila;
  }
}
void modificarAlumno()
{
	string carne;
	string alumno;
  ofstream archivo;
  archivo.open("baseDatosAlumnos.txt");
  cout << "escribe el carne que quieres editar" << endl;
  cin >> carne;
  cout << "escribe un nuevo alumno" << endl;
  cin alumno while (getline(archivo, fila))
  {
    if (fila.find(carne))
    {
      fila = alumno;
    }
  }
}



int main () {
  int opcion;
  cout << "**********BIENVENIDO********" << endl;
  cout << "Que desea hacer?" << endl;
  cout << "1. ver todos los alumnos"<< endl;
  cout << "2. buscar un alumno" <<endl;
  cout << "3. modificar un alumno"<< endl;
  cout << "4. eliminar un alumno"<< endl;
  cout << "5. salir" <<endl;
  cin >> opcion;
  switch (opcion)
{
   case 1:
   	{
      mostrarAlumnos();
      system("PAUSE");
		break ;
	}
   case 2:
    	{
      buscarAlumno();
      system("PAUSE");
		break ;
	}
   case 3:
     	{
      modificarAlumno();
      system("PAUSE");
		break ;
	}
	case 4:
      	{
      eliminarAlumno();
      system("PAUSE");
		break ;
	}
   default:
      cout << "probando default";
}
  return 0;
}