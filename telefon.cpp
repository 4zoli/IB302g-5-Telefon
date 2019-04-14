#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;

//Telefon osztaly, ami telefont reprezental.
class Telefon 
{
	public:
		int telefonszam;	//Telefon szama, 9 jegy� int sz�m.
		double internet;

//Konstruktor, ami parameterkent varja a szamot es az adatforgalmat.
	Telefon(int a, double b)	
	{
		this-> telefonszam = a;
		this-> internet = b;
	}

//Konstruktor , ami konzolrol olvassa be az adatokat. 
	Telefon()
	{
		cin>>this->telefonszam;
		cin>>this->internet;
	}
		
//Internetet hasznal metodus, csokkenti a parameterben kapott szammal az adatforgalmat.
	void internetetHasznal(double mennyivel)
	{
		this-> internet -= mennyivel;
	}

//Ha nem adunk meg akkor 1.2 vel csokken
	void internetetHasznal()
	{
		this-> internet -= 1.2;
	}

// Feltolt fuggveny, pontosan 500mb adatot ad de a keret max 1500 legyen.
	void feltolt(double a)
	{
		this-> internet += 500;
		if (internet > 1500)
		{
			this-> internet = 1500;
		}	
	}

//Adatok fgv, kiirja a szamot es a netet.
	void adatok()
	{
		cout<<"A telefon adatai: \n";
		cout<<"Szama: "<<this->telefonszam;
		cout<<'\n';
		cout<<"Adatmennyisege: "<<this->internet;
		cout<<'\n';
	}
};
	
//Szarmaztass le a Telefon osztalybol egy SzuperNetezoTelefon osztalyt, tarolhat e 4G vagy sem taggal
class SzuperNetezoTelefon : public Telefon	
{
	public :
		bool fourG;
			
//Konstruktor, ami varja hogy mi a szama, mennyi net van, van e 4G
	SzuperNetezoTelefon(int a, double b, bool c) : Telefon(a,b)	
	{
		this->fourG = c;
	}
		
//Save fuggveny , parameterul kapott fileba elmenti az adatokat.
	void save(string str1)	
	{
		ofstream myfile;
		myfile.open (str1);
		myfile<<this->telefonszam;
		myfile<<endl<<this->internet;
		myfile<<endl<<this->fourG;
		myfile.close();			
	}

//Feluldefinialt internetet hasznal metodus
	void internetetHasznal(double mennyivel)
	{
		this->internet -= mennyivel;
	}

//Ha nem adunk meg parametert akkor pont 23.5el csokkentsen			
	void internetetHasznal()	
	{
		this->internet -= 23.5;
	}

//Feluldefinialt feltolt() fuggveny
	void feltolt()	
	{
		this->internet += 500;
	}
};



class TelefonKatalogus
{
	public:
		Telefon **katalogus;
		int catalog_size;
		int count;

//Konstruktor, ami paraméterül kapott n számnra mutato pointernek foglal dinamikusan helyet
	TelefonKatalogus(int catalog_size) 
	{
		this->count = 0;
		katalogus = new Telefon*[catalog_size];
	}

//Add metodus, katalogushoz hozzaad egy erkezo objektumot majd hozzaadja a masolatait a katalogushoz
	bool add(Telefon objektum)
	{
		if(count < this->catalog_size)	{
			Telefon *tcopy = new Telefon(objektum);
			this->katalogus[count]	= tcopy;
			count++;	
			return true;
		}
		return false;
	}

//++ prefix
	void operator++()
	{
		for(int i=0; i<count; i++)
		{
			if(katalogus[i]->internet <= 1400)
			{
				katalogus[i]->internet += 100;
			}
		}
	}
//postfix ++
	void operator++(int k)
	{
		for(int i=0; i<count; i++)
		{
			if(katalogus[i]->internet <= 1400)
			{
				katalogus[i]->internet += 100;
			}
		}
	}

//[] feluldefinialasa
	Telefon& operator[](int index)
	{
		if(index<=count-1)
		{
			return *katalogus[index];
		} else return *katalogus[count-1];
	}

//ostream operator feluldefinialasa
friend ostream& operator<<(ostream &o,TelefonKatalogus &tk) {
    o << tk.count << " telefon van a katalogusban." << endl;

    for(int i = 0; i<tk.count; i++){
        tk.katalogus[i]->adatok();
    }
}

//destruktor
	~TelefonKatalogus() 
	{
		for(int i = 0; i<count; i++){
			delete &katalogus[i];
		}
		delete[] katalogus;
	}

};




