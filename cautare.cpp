#include <iostream>
#include <fstream>
using namespace std;
int poz=0;
class Masina{
    public:
        int id;
        string denumire;
        int cai_putere;
        string cutia;
        int pretul;
    Masina(){id=-1;};
    Masina(Masina &S){
        id=S.id;
        denumire=S.denumire;
        cai_putere=S.cai_putere;
        cutia=S.cutia;
        pretul=S.pretul;
    };
    Masina(string file){
        poz++;//linia curenta
        int c=0;//contor de linii citite pina la linia curenta
        ifstream f;
        f.open(file);
        if(f.fail()){//testul de deschidere fisier
            cout << "Input file opening failed.\n";
            exit(1);
		}
		string line;
		while(c<poz){//citim in gol pina ajungem la linia curenta
            getline(f, line);
            c++;}
        f.close();
        //operam cu ultima linie citita
        size_t s;//salvam pozitia caracterului in linia citita
        string sir;
        //id
        s=line.find(" ");//cautam prima despartire
        sir=line.substr(0,s);//salvam subsirul dat
        id=atoi(sir.c_str());//convertim subsirul in numar intreg

        //denumire
        line=line.substr(s+1);//excludem subsirul citit
        s=line.find(" ");//cautam prima despartire
        denumire=line.substr(0,s);//salvam subsirul dat

        //cai_putere
        line=line.substr(s+1);//excludem subsirul citit
        s=line.find(" ");//cautam prima despartire
        sir=line.substr(0,s);//salvam subsirul dat
        cai_putere=atoi(sir.c_str());//convertim subsirul in numar intreg

        //cutia
        line=line.substr(s+1);//excludem subsirul citit
        s=line.find(" ");//cautam prima despartire
        sir=line.substr(0,s);//salvam subsirul dat
        cutia=atoi(sir.c_str());//convertim subsirul in numar intreg

        //pretul
        line=line.substr(s+1);//excludem subsirul citit
        s=line.find(" ");//cautam prima despartire
        pretul=atoi(line.c_str());//convertim subsirul in numar intreg
        }

void afisare(){
cout<<"ID Denumire    Cai_putere   Cutia  pretul"<<endl;
cout<<id<<" "<<denumire<" "<<cai_putere<<" "<<cutia<<" "<<pretul<<endl<<endl;}

};