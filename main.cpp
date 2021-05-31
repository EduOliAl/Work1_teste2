#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define MAX_NAME 512
#define MAX_ID 50
#define MAX_FOLLOWERS 10
#define MAX_POPULARITY 10


struct Artista
{
    char id[MAX_ID]; 
    float followers;
    char name[MAX_NAME]; 
    int popularity;
};


void Artista_Save(Artista &art, fstream &fileOut) 
{
    fileOut.write(art.id, sizeof(art.id));
    fileOut.write((char*)&art.followers, sizeof(art.followers));
    fileOut.write(art.name, sizeof(art.name));
    fileOut.write((char*)&art.popularity, sizeof(art.popularity));
}

void Artista_Read(Artista &art, fstream &fileOut) 
{
    fileOut.read(art.id, sizeof(art.id));
    fileOut.read((char*)&art.followers, sizeof(art.followers));
    fileOut.read(art.name, sizeof(art.name));
    fileOut.read((char*)&art.popularity, sizeof(art.popularity));
}

void Imprime_Artista(Artista &art)
{
    cout << art.id << endl;
    cout << art.name << endl;
    cout << art.popularity << endl;
    cout << art.followers << endl;
}

int main()
{
    //pega dados de .csv e salva em struct
    ifstream fileIn;
    fileIn.open("artistas.csv");
    Artista art1;


    if(fileIn.is_open())
    {
        string tmp;

        getline(fileIn, tmp, ',');
        strcpy(art1.id, tmp.c_str());

        getline(fileIn, tmp, ',');
        //strcpy(art1.followers, tmp.c_str());
        art1.followers = atof(tmp.c_str());

        cout << "*******" << tmp.c_str() << endl;
        cout << "*******" << art1.followers << endl;

        getline(fileIn, tmp, ',');
        strcpy(art1.name, tmp.c_str());

        getline(fileIn, tmp, '\n');
        //strcpy(art1.popularity, tmp.c_str());
        art1.popularity = atoi(tmp.c_str());

        Imprime_Artista(art1);

        fileIn.close();
    }
    else
    {
        cout << "Erro" << endl;
        exit(1);
    } 

    //pega o q tá no struct e salva em arquivo binário
    fstream fileOut;
    fileOut.open("artistas.bin", ios::out | ios::binary); 

    if(fileOut.is_open())
    {
        Artista_Save(art1, fileOut);
        fileOut.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    } 

    //lê o que tá no arquivo binário artistas.dat
    fstream fileI;
    fileI.open("artistas.bin", ios::in | ios::binary);

    if(fileI.is_open())
    {
        Artista art;

        Artista_Read(art, fileI);

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