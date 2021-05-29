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
        string id;
        string followers;
        string name;
        string popularity;

        getline(fileIn, id, ',');
        getline(fileIn, followers, ',');
        getline(fileIn, name, ',');
        getline(fileIn, popularity, '\n');

        art1.id = id;
        art1.followers = followers;
        art1.name = name;
        art1.popularity = popularity;

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
        fileOut.write((char*)&art1, sizeof(Artista));

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
        string followers;
        string name;
        string popularity;

        Artista art;

        fileI.read((char*)&art, sizeof(Artista));

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