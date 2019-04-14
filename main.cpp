#include "telefon.cpp"

int main(int argc, char** argv)	{

// 100 ferohelyes katalogus letrehozasa
    TelefonKatalogus tk(100);

    //2 telefon es 3 szupernetezo
	Telefon t1(1,1300.0);
    Telefon t2(2,1300.0);
    SzuperNetezoTelefon sznt1(3,1300.0, true);
    SzuperNetezoTelefon sznt2(4,1400.0, true);
    SzuperNetezoTelefon sznt3(5,1500.0, true);

// telefonok hozzaadasa a katalogushoz
    tk.add(t1);
    tk.add(t2);
    tk.add(sznt1);
    tk.add(sznt2);
    tk.add(sznt3);

//katalogus kiiratasa
    cout << tk;
    cout << endl;

//++ operator meghivas
    tk++;

//memoria felszabaditas, tesztelve.
    tk.~TelefonKatalogus();
/*  tk[1].adatok();
    tk[2].adatok();
    tk[3].adatok();
    tk[4].adatok();
    tk[5].adatok();
*/

/*
        I. Merfoldko futtatas.
		Telefon* nokia = new Telefon(203464943, 500);
		
		SzuperNetezoTelefon* huaweip20 = new SzuperNetezoTelefon(203933021,3000,true);
		nokia->Telefon::adatok();
		huaweip20->Telefon::adatok();
		huaweip20->SzuperNetezoTelefon::internetetHasznal();
		huaweip20->SzuperNetezoTelefon::adatok();
		huaweip20->SzuperNetezoTelefon::internetetHasznal(440);
		huaweip20->SzuperNetezoTelefon::adatok();
		huaweip20->save("save.txt");
*/		
	
	
	return 0;
}
