#include <iostream>
#include <fstream>
using namespace std;

// ********** atual

struct Artista
{
    string id;
    float followers;
    string name;
    int popularity;
};


int main()
{
    //pega dados de .csv e salva em struct
    ifstream fileIn;
    fileIn.open("artistas.csv");
    Artista art1;

    if(fileIn.is_open())
    {
        string line;
        getline(fileIn, line, ',');
        art1.id = line;
        fileIn.close();
    }
    else
    {
        cout << "Erro" << endl;
        exit(1);
    } 

    //pega o q tá no struct e salva em arquivo binário
    ofstream fileOut;
    fileOut.open("artistas.dat", ios::out | ios::binary);

    if(fileOut.is_open())
    {
        fileOut.write((char*)&(art1.id), sizeof(Artista));
        fileOut.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    } 

    //lê o que tá no arquivo binário artistas.dat
    ifstream fileI;
    fileI.open("artistas.dat", ios::in | ios::binary);

    if(fileI.is_open())
    {
        string id;
        fileI.read((char*)&id, sizeof(Artista));
        cout << "Deu certo: " << id << endl;
        fileI.close();
    }
    else
    {
        cout << "Erro" << endl;
        exit(1);
    } 


return 0;
}