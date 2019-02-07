// formatter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ofstream outputFILE;
	ifstream inputFILE, kameraIF1, kameraIF2, kameraIF3, kameraIF4, kameraIF5, kameraIF6, kameraIF7, kameraIF8, kameraIF9, kameraIF10, kameraIF11, kameraIF12, kameraIF13, kameraIF14, kameraIF15, kameraIF16, kameraIF17, kameraIF18;
	string nazwa_pliku_artr = "C:\\Users\\E431\\Desktop\\magisterka\\czasy_przejazdu_txteki\\1B\\";
	string nazwa_wyj = "C:\\Users\\E431\\Desktop\\";
	string nr_kamer ="z680_do682_05_2014";
	int licznosc =-1, wartoscArtr=-1;//zmienna tymczasowa
	double normalizacja = -0.1;
	string kamera1 = nazwa_pliku_artr + "licz_kamera_1020.txt";
	string kamera2 = nazwa_pliku_artr + "licz_kamera_1387.txt";
	string kamera3 = nazwa_pliku_artr + "licz_kamera_850.txt";
	string kamera4 = nazwa_pliku_artr + "licz_kamera_849.txt";
	/*string kamera5 = nazwa_pliku_artr + "licz_kamera_1234.txt";
	string kamera6 = nazwa_pliku_artr + "licz_kamera_1042.txt";
	string kamera7 = nazwa_pliku_artr + "licz_kamera_707.txt";
	string kamera8 = nazwa_pliku_artr + "licz_kamera_708.txt";
	string kamera9 = nazwa_pliku_artr + "licz_kamera_718.txt";*/
	//string kamera10 = nazwa_pliku_artr + "licz_kamera_1252.txt";
	//string kamera11 = nazwa_pliku_artr + "licz_kamera_1253.txt";
	//string kamera12 = nazwa_pliku_artr + "licz_kamera_1303.txt";
	//string kamera13 = nazwa_pliku_artr + "licz_kamera_1304.txt";
	//string kamera14 = nazwa_pliku_artr + "licz_kamera_1334.txt";
	//string kamera15 = nazwa_pliku_artr + "licz_kamera_1335.txt";
	//string kamera16 = nazwa_pliku_artr + "licz_kamera_1126.txt";
	//string kamera17 = nazwa_pliku_artr + "licz_kamera_1403.txt";
	//string kamera18 = nazwa_pliku_artr + "licz_kamera_924.txt";
	
	nazwa_pliku_artr += nr_kamer;
	nazwa_pliku_artr += ".txt";
	nazwa_wyj += nr_kamer;
	nazwa_wyj += ".txt";
	string reset_artr = nazwa_pliku_artr;
	outputFILE.open(nazwa_wyj, ios::out | ios::app);
	outputFILE << "No. of patterns : 11\nNo. of input units : 1\nNo. of output units : 1\n";
	inputFILE.open(nazwa_pliku_artr, std::ios::in | std::ios::out);
	kameraIF1.open(kamera1, std::ios::out);
	kameraIF2.open(kamera2, std::ios::out);
	kameraIF3.open(kamera3, std::ios::out);
	kameraIF4.open(kamera4, std::ios::out);
	/*kameraIF5.open(kamera5, std::ios::out);
	kameraIF6.open(kamera6, std::ios::out);
	kameraIF7.open(kamera7, std::ios::out);
	kameraIF8.open(kamera8, std::ios::out);
	kameraIF9.open(kamera9, std::ios::out);*/
	//kameraIF10.open(kamera10, std::ios::out);
	//kameraIF11.open(kamera11, std::ios::out);
	//kameraIF12.open(kamera12, std::ios::out);
	//kameraIF13.open(kamera13, std::ios::out);
	//kameraIF14.open(kamera14, std::ios::out);
	//kameraIF15.open(kamera15, std::ios::out);
	//kameraIF16.open(kamera16, std::ios::out);
	//kameraIF17.open(kamera17, std::ios::out);
	//kameraIF18.open(kamera18, std::ios::out);
	int licznik = 1;
	/*cout << kamera1 << endl;
	cout << nazwa_pliku_artr << endl;*/
	if (inputFILE.good() && kameraIF1.good() && kameraIF2.good() && kameraIF3.good() && kameraIF4.good())
	{
		while(inputFILE.good()){
			inputFILE >> wartoscArtr;
			if (inputFILE.eof()) break;
			normalizacja = wartoscArtr;
			outputFILE << "\n#Input pattern ";
			outputFILE << licznik;
			outputFILE << ":\n";
			
			kameraIF1 >> licznosc;
			outputFILE << licznosc / normalizacja;// +licznosc * ((rand() % 100)*0.001) / normalizacja;//dodane zaburzenie
			/*outputFILE << " ";
			kameraIF2 >> licznosc;
			outputFILE << licznosc / normalizacja;// + licznosc*((rand()%100)*0.001)/normalizacja;*/
						
			outputFILE << " ";
			kameraIF3 >> licznosc;
			outputFILE << licznosc / normalizacja;//+licznosc * ((rand() % 100)*0.001) / normalizacja;
			
			outputFILE << " ";
			kameraIF4 >> licznosc;
			outputFILE << licznosc / normalizacja;

			/*outputFILE << " ";
			kameraIF5 >> licznosc;
			outputFILE << licznosc / normalizacja;

			outputFILE << " ";
			kameraIF6 >> licznosc;
			outputFILE << licznosc / normalizacja;

			outputFILE << " ";
			kameraIF7 >> licznosc;
			outputFILE << licznosc / normalizacja;

			outputFILE << " ";
			kameraIF8 >> licznosc;
			outputFILE << licznosc / normalizacja;*/
			/*outputFILE << " ";
			kameraIF9 >> licznosc;
			outputFILE << licznosc / normalizacja;
			outputFILE << " ";
			kameraIF10 >> licznosc;
			outputFILE << licznosc / normalizacja;
			outputFILE << " ";
			kameraIF11 >> licznosc;
			outputFILE << licznosc / normalizacja;*/
			/*outputFILE << " ";
			kameraIF12 >> licznosc;
			outputFILE << licznosc / normalizacja;
			outputFILE << " ";
			kameraIF13 >> licznosc;
			outputFILE << licznosc / normalizacja;*/
			/*outputFILE << " ";
			kameraIF14 >> licznosc;
			outputFILE << licznosc / normalizacja;
			outputFILE << " ";
			kameraIF15 >> licznosc;
			outputFILE << licznosc / normalizacja;*/
			/*outputFILE << " ";
			kameraIF16 >> licznosc;
			outputFILE << licznosc / normalizacja;*/
			/*outputFILE << " ";
			kameraIF17 >> licznosc;
			outputFILE << licznosc / normalizacja;*/
			/*outputFILE << " ";
			kameraIF18 >> licznosc;
			outputFILE << licznosc / normalizacja;*/
			
			outputFILE << "\n#Output pattern ";
			outputFILE << licznik;
			outputFILE << ":\n";
			outputFILE << wartoscArtr / normalizacja;
			licznik++;
		}
	}
	else std::cout << "Dostep do pliku z czasami zostal zabroniony!" << std::endl;
	outputFILE.close();
	inputFILE.close();
	kameraIF1.close();
	kameraIF2.close();
	kameraIF3.close();
	kameraIF4.close();
	kameraIF5.close();
	kameraIF6.close();
	kameraIF7.close();
	kameraIF8.close();
	kameraIF9.close();
	kameraIF10.close();
	kameraIF11.close();
	kameraIF12.close();
	kameraIF13.close();
	kameraIF14.close();
	kameraIF15.close();
	kameraIF16.close();
	kameraIF17.close();
	kameraIF18.close();
	//system("pause");
	return 0;
}

/*for (int i = 14;i<25;i++)
{
nazwa_pliku_artr = reset_artr;
nazwa_pliku_wej = reset_wej;
tmp = "";
dzien = to_string(i);
tmp += dzien;
tmp += "_05_2014.txt";
nazwa_pliku_artr += tmp;
nazwa_pliku_wej += tmp;
cout << nazwa_pliku_artr << endl;
cout << nazwa_pliku_wej << endl;
cout << nazwa_wyj << endl;
inputFILE.open(nazwa_pliku_wej, std::ios::in | std::ios::out);

if (inputFILE.good())
//if(inputFILE.is_open())
{
std::cout << "Uzyskano dostep do pliku z licznosciami!" << std::endl;
outputFILE << "\n#Input pattern ";
outputFILE << to_string(i - 13);
outputFILE << ":\n";
inputFILE >> tekst;
outputFILE << tekst;
}
else std::cout << "Dostep do pliku z licznosciami zostal zabroniony!" << std::endl;

artrInputFILE.open(nazwa_pliku_artr, std::ios::in | std::ios::out);
if (artrInputFILE.good())
{
std::cout << "Uzyskano dostep do pliku z czasami!" << std::endl;
outputFILE << "\n#Output pattern ";
outputFILE << to_string(i - 13);
outputFILE << ":\n";
artrInputFILE >> tekst;
outputFILE << tekst;
}
else std::cout << "Dostep do pliku z czasami zostal zabroniony!" << std::endl;
inputFILE.close();
artrInputFILE.close();
}
*/