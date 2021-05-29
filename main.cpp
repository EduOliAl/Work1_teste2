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
        getline(fileIn, popularity, ',');

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
        fileOut.write((char*)&(art1.id), sizeof(Artista));
        fileOut.write((char*)&(art1.followers), sizeof(Artista));
        fileOut.write((char*)&(art1.name), sizeof(Artista));
        fileOut.write((char*)&(art1.popularity), sizeof(Artista));

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

        fileI.read((char*)&id, sizeof(Artista));
        fileI.read((char*)&followers, sizeof(Artista));
        fileI.read((char*)&name, sizeof(Artista));
        fileI.read((char*)&popularity, sizeof(Artista));

        cout << "id: " << id << endl;
        cout << "followers: " << followers << endl;
        cout << "name: " << name << endl;
        cout << "popularity: " << popularity << endl;

        fileI.close();
    }
    else
    {
        cout << "Erro" << endl;
        exit(1);
    } 


return 0;
}