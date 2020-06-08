#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <queue>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


struct osoba
{
        string imie, nazwisko;
        int wiek;

};

class klasa
{
                vector <struct osoba> spis;
                
       
        public:

                void zapiszDoPliku(const char *);
                void wczytajZPliku(const char *);                
};






   




void klasa::zapiszDoPliku(const char *nazwa)
{
	 
        ofstream plik;
        plik.open(nazwa);
        plik <<"["<<endl;
        int liczba;
        if(plik.good())
        for (vector<struct osoba>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
			
                plik <<" {"<<endl;
				plik << '"'<<"title"<<'"'<<":"<<'"'<< it->imie << " "
                         << it->nazwisko <<'"'<<","<<"\n"<<'"'<< "subtitle" <<'"'<<":"
                         <<'"'<< it->wiek <<'"'<<"\n";
                         
                plik <<"},"<<"\n" ;        
                         
                        liczba++;
                        if(liczba<spis.size());
    
        }
        plik <<"]";
        plik.close();  
}


void klasa::wczytajZPliku(const char *nazwa)
{
	int p=0;
queue<string>kolejka;
	char t[1000];
	ifstream plik;
	plik.open(nazwa);
	struct osoba s;
	if(plik.good())
    while(!plik.eof())   
    {
    	
    	plik >> s.wiek >> s.imie >> s.nazwisko ;

    
    cout <<"Imie: " << s.imie <<", Nazwisko: "
	<< s.nazwisko <<", Wiek: " 
	<< s.wiek  <<"\n";
    spis.push_back(s);
	

    
	}
	plik.close();

}

	

	




int main(int argc, char** argv) {
        klasa TI;
        
        TI.wczytajZPliku("C:\\Users\\szymo\\OneDrive\\Pulpit\\populacja.txt");
        
        TI.zapiszDoPliku("C:\\Users\\szymo\\OneDrive\\Pulpit\\dopopulacja.txt");


        
        return 0;
}
