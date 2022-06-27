#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encriptar(string texto, int clave){
    string encriptado = texto;
    int longitud = texto.length();
    for(int i = 0; i < longitud; i++){
          if(encriptado[i] >= 32 && encriptado[i] <= 122){
             encriptado[i] = encriptado[i] + clave;
          if(encriptado[i] > 122){
                  encriptado[i] = encriptado[i] - 122 + 32 - 1;
          }
           }
    }
    return encriptado;
}
string desencriptar(string texto, int clave){
    string desencriptado = texto;
    int longitud = texto.length();
    for(int i = 0; i < longitud; i++){
          if(desencriptado[i] >= 32 && desencriptado[i] <= 122){
             desencriptado[i] = desencriptado[i] - clave;
          if(desencriptado[i] < 32){
                  desencriptado[i] = desencriptado[i] + 122 - 32 + 1;
           }
           }
    }
    return desencriptado;
}


//funcion principal
int main(){
      ifstream archivo;
      ofstream archivo1;
      ifstream archivo2;

      int opcion, clave,clave2,i;
      string men, cif, men_en;

      archivo.open("mensaje.txt",ios::in);
      while(!archivo.eof()){
            getline(archivo,men);
      }
      archivo.close();

      do{
      cout<<"\t.:MENU:."<<endl;
      cout<<"1. Escriptar"<<endl;
      cout<<"2. Desencriptar"<<endl;
      cout<<"3. Salir"<<endl;
      cout<<"Opcion: ";
      cin>>opcion;

      switch(opcion){

            case 1:{
            cout << "Ingrese clave: ";
            cin >> clave;
            cout << "El mensaje encriptado es: " <<encriptar(men,clave)<<endl;

                  archivo1.open("encriptado.txt",ios::out);
                  archivo1 << encriptar(men,clave);
                  archivo1.close();
                  system("pause");
                  break;
            }
            case 2:{
                  cout<<"Ingrese la clave: ";
                  cin>>clave2;
                  if(clave2 == clave ){
                        cout<<"Correcto!"<<endl;

                  archivo2.open("encriptado.txt",ios::in);
                  while(!archivo2.eof()){
                        getline(archivo2,men_en);
                  }
                  archivo2.close();
                        cout << "El mensaje desencriptado es: " <<desencriptar(men_en,clave) <<endl;
                  }
                  else cout<<"Error!, Clave incorrecta"<<endl;
                  system("pause");
                  break;
            }
      }

      system("cls");
      }while(opcion!=3);

return 0;
}
