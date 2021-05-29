#include <iostream>
#include <fstream>
using namespace std;

// ********** atual

struct Artista
{
    string id;
    string followers;
    string name;
    string popularity;
};


int main()
{
    //pega dados de .csv e salva em struct
    ifstream fileIn;
    fileIn.open("artistas.csv");
    Artista art1;

    if(fileIn.is_open())
    {
        getline(fileIn, art1.id, ',');
        getline(fileIn, art1.followers, ',');
        getline(fileIn, art1.name, ',');
        getline(fileIn, art1.popularity, '\n');

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
        fileOut.write((char*)(&art1), sizeof(Artista));
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
        Artista art;

        fileI.read((char*)(&art), sizeof(Artista));

        cout << "\nLendo dados no arquivo em binario: " << endl;
        cout << "id: " << art.id << endl;
        cout << "followers: " << art.followers << endl;
        cout << "name: " << art.name << endl;
        cout << "popularity: " << art.popularity << endl;

        fileI.close();
    }
    else
    {
        cout << "Erro" << endl;
        exit(1);
    } 



return 0;
}