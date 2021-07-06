#include <iostream>
#include <fstream>
#include <string>

using namespace std;


const int Max=2;
typedef struct{
    string nombre;
    int score;
    string tiempo;
}tscore;
typedef tscore tarray[Max];
typedef struct{
    tarray elementos;
    int contador;
}tlist;
void save_score(tlist lista);
void recover_score(tlist list);
int main(){
    tlist lista;
    tscore corredor[Max];
    recover_score(lista);
    lista.contador =0;
    corredor[0] = {"Maria",200,"3:02"};
    corredor[1] = {"Jose",150,"2:04"};
    for(int i = 0; i < Max; i++)
    {
        lista.elementos[lista.contador] = corredor[i];
        cout << lista.elementos[lista.contador].nombre << endl;
        cout << lista.elementos[lista.contador].score << endl;
        cout << lista.elementos[lista.contador].tiempo << endl;
        lista.contador++;
    }
      save_score(lista);
     return 0;
}

void save_score(tlist lista){
    ofstream file;
    file.open("score.txt", ios::out);
    if(file.is_open()){
        for(int i =0;i< lista.contador;i++){
            file << lista.elementos[i].nombre << " " << lista.elementos[i].score << " " << lista.elementos[i].tiempo << endl;
        }}
        file.close();
}

void recover_score(tlist lista){
    ifstream file;
    file.open("score.txt",ios::in);
    if(file.is_open()){
        while(!file.eof()){
            file >> lista.elementos[lista.contador].nombre;
            file.get();
            file >> lista.elementos[lista.contador].score;
            file.get();
            file >> lista.elementos[lista.contador].tiempo;
            file.get();
            if((!lista.elementos[lista.contador].nombre.empty())&&(!lista.elementos[lista.contador].score != 0)&&(!lista.elementos[lista.contador].tiempo.empty())){
                lista.contador++;
            }
        }
    }
    file.close();
}