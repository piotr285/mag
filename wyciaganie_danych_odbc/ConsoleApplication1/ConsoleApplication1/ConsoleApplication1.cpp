// ConsoleApplication1.cpp : Defines the entry point for the console application.
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
//graohx
int licznosci_przejazdow(SQLHANDLE hdlStmt, SQLHANDLE hdlStmt2, string nr_kamery, string czas_startu, string czas_przed)
{
	fstream FILE, logLicz;
	SQLINTEGER I;
	SQLRETURN kod_zwrotny;
	char* statement = new char[300];
	int licznosc=-1, rekord=-1;
	vector<int> id_tab;
	string tmp = "";
	string wyszukanie = "select count(Czas_Rejestracji) from DPTKamera_Pomiar where Id_Globalny=";
	tmp += nr_kamery;
	tmp += " and Czas_Rejestracji between ( CONVERT(datetime, CONVERT(\"varchar\"(23), '";
	tmp += czas_przed;
	tmp += "', 23), 111)) and ( CONVERT(datetime, CONVERT(\"varchar\"(23), '";
	tmp += czas_startu;
	tmp += "', 23), 111))";
	wyszukanie += tmp;
	statement = (char*)wyszukanie.c_str();
	string plikLog = "C:/Users/E431/Desktop/magisterka/czasy_przejazdu_txteki/log_licznosc.txt";
	logLicz.open(plikLog, ios::out | ios::app);
	logLicz << statement << endl;
	//cout << wyszukanie << endl;
	kod_zwrotny = SQLExecDirect(hdlStmt, (SQLCHAR*)statement, SQL_NTS);
	if (SUCCEEDED(kod_zwrotny))
	{
		while (SQL_SUCCEEDED(SQLFetch(hdlStmt)))
		{
			kod_zwrotny = SQLGetData(hdlStmt, 1, SQL_C_SLONG, &rekord, 0, &I);//SLONG to jest format dla integer
			if (SQL_SUCCEEDED(kod_zwrotny))
			{
				id_tab.push_back(rekord);
			}
		}
	}
	else
	{
		cout << "niepowodzenie zliczenia rekordów" << endl;
	}
	string nazwa_pliku = "C:/Users/E431/Desktop/magisterka/czasy_przejazdu_txteki/licz_kamera_";
	tmp = "";
	tmp += nr_kamery;
	//tmp += "_dnia";
	//tmp += czas_startu.substr(0,10);
	//tmp += "14_05_2014";
	tmp += ".txt";
	nazwa_pliku = nazwa_pliku + tmp;
	FILE.open(nazwa_pliku, ios::out | ios::app);
	for (int i = 0; i < id_tab.size();i++)
	{
		FILE << id_tab[i]<<" ";
	}
	FILE.close();
	//cout << nazwa_pliku << endl;
	cout << "wypisano licznosc przejazdów z " << czas_startu << "_05_2014 z " << nr_kamery << endl;

	return 0;
}

std::vector<std::string> czasy_przejazdu(SQLHANDLE hdlStmt, SQLHANDLE hdlStmt2, int dzienInt, string numer, string numer2)
{//dane z okresu miÄ™dzy 14.05.2014 a 24.05.2014
	fstream FILE, DATY, logARTR;
	SQLINTEGER I;
	SQLRETURN kod_zwrotny;
	TIMESTAMP_STRUCT ts;
	string wyszukanie = "SELECT Czas_Przejazdu FROM DPTPrzejazd WHERE Id_Globalny_Punkt_A=";
	string dzien, tmp = "";// 
	int rekord = 0;
	const int num = 512; //wielkosc bufora na daty
	char* statement = new char[300];
	vector<int> czasy_przejazdow;
	vector<string> czasy_startu;
	string czas_startowy = "select Czas_Punkt_A from DPTPrzejazd where Id_Globalny_Punkt_A=";
	//cout << "podaj identyfikator globalny kamery ARTR poczÄ…tkowej (startowej):" << endl;
	//cin >> numer;
	//cout << "podaj identyfikator globalny kamery ARTR koĹ„cowej:" << endl;
	//cin >> numer2;
	//cout << "podaj nr dnia miesiÄ…ca(1-31) (uwaga!dane tylko z dni 14.05.2014 a 24.05.2014)" << endl;
	//cin >> dzien;
	dzien = to_string(dzienInt);
	tmp += numer;
	tmp += " AND Id_Globalny_Punkt_B=";
	tmp += numer2;
	tmp += " AND (Czas_Punkt_A >= CONVERT(datetime, CONVERT(\"varchar\"(23), '2014-05-";//odpowiednie paramerty funkcji CONVERT sqlowej
	tmp += dzien;
	tmp += " 07:00:00.000', 23), 111)) AND (Czas_Punkt_A < CONVERT(datetime, CONVERT(\"varchar\"(23), '2014-05-";
	tmp += dzien;
	tmp += " 09:00:00.000', 23), 111))";
	czas_startowy += tmp;
	wyszukanie += tmp;
	statement = (char*)wyszukanie.c_str();	
	string plikLog = "C:/Users/E431/Desktop/magisterka/czasy_przejazdu_txteki/log_ARTR.txt";
	logARTR.open(plikLog, ios::out | ios::app);
	logARTR << statement << endl;
	kod_zwrotny = SQLExecDirect(hdlStmt, (SQLCHAR*)statement, SQL_NTS);//realizacja zapytania 
	if (SUCCEEDED(kod_zwrotny))
	{
		while (SQL_SUCCEEDED(SQLFetch(hdlStmt)))
		{//fetch przycina do jednej linii, GetData pobiera 
			kod_zwrotny = SQLGetData(hdlStmt, 1, SQL_C_SLONG, &rekord, 0, &I);//SLONG to jest format dla integer
			if (SQL_SUCCEEDED(kod_zwrotny))
			{
				czasy_przejazdow.push_back((int)rekord);
			}
			else
			{
				cout << "blad pobrania czasu przejazdu" << endl;
			}
		}
	}//koniec if SUCCEEDED
	statement = (char*)czas_startowy.c_str();
	//cout << statement << endl;
	kod_zwrotny = SQLExecDirect(hdlStmt2, (SQLCHAR*)statement, SQL_NTS);//realizacja zapytania 
	if (SUCCEEDED(kod_zwrotny))
	{
		while (SQL_SUCCEEDED(SQLFetch(hdlStmt2)))
		{//fetch przycina do jednej linii, GetData pobiera
			kod_zwrotny = SQLGetData(hdlStmt2, 1, SQL_C_TYPE_TIMESTAMP, &ts, sizeof(ts), &I);
			if (SQL_SUCCEEDED(kod_zwrotny))
			{			
				char dane[num];
				sprintf_s(dane, num, "%04d-%02d-%02d %02d:%02d:%02d.%03d \n", ts.year, ts.month, ts.day, ts.hour, ts.minute, ts.second, ts.fraction);
				string start_przejazd(dane);
				czasy_startu.push_back(start_przejazd);
			}
			else
			{
				cout << "blad pobrania startu przejazdu" << endl;
				SQLCHAR       SQLStmt[100], SqlState[6], Msg[SQL_MAX_MESSAGE_LENGTH];
				SQLINTEGER    NativeError;
				SQLSMALLINT   i = 1, MsgLen;
				if (kod_zwrotny == SQL_ERROR)
				{
					while ((kod_zwrotny = SQLGetDiagRec(SQL_HANDLE_STMT, hdlStmt, i, SqlState, &NativeError,
						Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA) {
						cout << "retcode" << kod_zwrotny << endl;
						cout << "error record #" << i++ << endl;
						cout << "sqlstate: " << SqlState << endl;
						cout << "detailed msg: " << Msg << endl;
						cout << "native error code: " << NativeError << endl;
					}
				}

			}
		}
	}//koniec if SUCCEEDED
	else
	{
		SQLCHAR       SQLStmt[100], SqlState[6], Msg[SQL_MAX_MESSAGE_LENGTH];
		SQLINTEGER    NativeError;
		SQLSMALLINT   i = 1, MsgLen;
		if (kod_zwrotny == SQL_ERROR)
		{
			while ((kod_zwrotny = SQLGetDiagRec(SQL_HANDLE_STMT, hdlStmt, i, SqlState, &NativeError,
				Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA ) {
				cout << "retcode" << kod_zwrotny << endl;
				cout << "error record #" << i++ << endl;
				cout << "sqlstate: " << SqlState << endl;
				cout << "detailed msg: " << Msg << endl;
				cout << "native error code: " << NativeError << endl;
			}
		}
		cout << kod_zwrotny<<"  niepowodzenie zliczenia rekordów" << endl;
	}
	
	//trzy sigma
	if (czasy_przejazdow.size() != 0) {
		int sum = 0, squareSum = 0;
		for (int i = 0; i < czasy_przejazdow.size(); i++) {
			sum += czasy_przejazdow[i];
			squareSum += (czasy_przejazdow[i] * czasy_przejazdow[i]);
		}
		int average = sum / czasy_przejazdow.size();
		int squareAverage = squareSum / czasy_przejazdow.size();
		int sigma = sqrt(squareAverage - average ^ 2);
		//for (int i = 0; i <czasy_przejazdow.size() ; i++) {
		for (int i = czasy_przejazdow.size() - 1; i > -1; i--) {
			if (czasy_przejazdow[i]<(average - 3 * sigma) || czasy_przejazdow[i]> (average + 3 * sigma)) {
				czasy_przejazdow.erase(czasy_przejazdow.begin() + i);
				czasy_startu.erase(czasy_startu.begin() + i);
			}
		}
	}
	string nazwa_pliku = "C:/Users/E431/Desktop/magisterka/czasy_przejazdu_txteki/z";
	string nazwa_pl = nazwa_pliku + "DATY";
	tmp = "";
	tmp += numer;
	tmp += "_do";
	tmp += numer2;
	//tmp += "_dnia";
	//tmp += dzien;
	tmp += "_05_2014.txt";
	nazwa_pliku = nazwa_pliku + tmp;
	FILE.open(nazwa_pliku, ios::out | ios::app);
	nazwa_pl = nazwa_pl + tmp;
	DATY.open(nazwa_pl, ios::out | ios::app);
	for (int i = 0; i < czasy_przejazdow.size();i++)
	{
		FILE << czasy_przejazdow[i] << endl;
		DATY << czasy_startu[i];
	}
	FILE.close();
	DATY.close();
	cout << "wypisano czasy przejazdĂłw z "<< dzien << "_05_2014 z " << numer << " do " << numer2 << endl;
	return czasy_startu;
}

int main(void)
{
	//string fname;//wczytywanie trasy
	for (int iterator = 14; iterator <25; iterator++){//docelowo 25
		if (iterator == 17) {
			iterator = 19;//aby przeskoczyc weekend
		}

	SQLHANDLE hdlEnv, hdlStmt, hdlStmt2, hdlDbc; //referencje do: srodowika, warunku przeszkukiwania, bazy danych 
	SQLRETURN retcode, retcode2; //kody zwracane przez funkcje
	SQLCHAR* stmt = nullptr;
	SQLCHAR       SQLStmt[100], SqlState[6], Msg[SQL_MAX_MESSAGE_LENGTH];
	SQLINTEGER    NativeError;
	SQLSMALLINT   i = 1, MsgLen;
	SQLRETURN     rc1, rc2;
	vector<string> daty_przejazdow;
	vector<string> kamery_liczace;
	string startARTR = "676", koniecARTR = "674";
	kamery_liczace.push_back("1129");
	kamery_liczace.push_back("1130");
	kamery_liczace.push_back("1079");
	kamery_liczace.push_back("1080");
	kamery_liczace.push_back("1034");
	kamery_liczace.push_back("1035");
	
	// przypianie wartosci zmiennej srodowiskowej
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hdlEnv);//kody zwracane przez funkcje
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		//ustawienie wersji sterownika ODBC
		retcode = SQLSetEnvAttr(hdlEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3_80, 0);

		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		{
			cout << "ODBC ready +" << endl;
			//powiazanie srodowiska z baza danych
			retcode = SQLAllocHandle(SQL_HANDLE_DBC, hdlEnv, &hdlDbc);

			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			{
				cout << "Environment ready +" << endl;
				//polaczenie z baza danych
				retcode = SQLConnect(hdlDbc, (SQLCHAR*)"MSSQLBaza_Danych", SQL_NTS, NULL, 0, NULL, 0);				
				//retcode = SQLConnect(hdlDbc, (SQLCHAR*)"SQL Server (SQLEXPRESS)", SQL_NTS, NULL, 0, NULL, 0);
					if (SQL_SUCCEEDED(retcode))
					{
						cout << "Connected to database ITS +" << endl;
						//przypisanie zmiennej warunku do bazy
						retcode2 = SQLAllocHandle(SQL_HANDLE_STMT, hdlDbc, &hdlStmt);
						retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdlDbc, &hdlStmt2);
						if (SQL_SUCCEEDED(retcode) && SQL_SUCCEEDED(retcode2))
						{
							///////////////////////////////////////////////////////////////
							cout << "Starting..." << endl << endl;

							//identyfikatory_kamer(hdlStmt);
							//licznosci_przejazdow(hdlStmt, hdlStmt2, iterator);
							//czasy_przejazdu(hdlStmt, hdlStmt2, iterator);
							daty_przejazdow = czasy_przejazdu(hdlStmt, hdlStmt2, iterator, startARTR, koniecARTR);
							SQLFreeHandle(SQL_HANDLE_STMT, hdlStmt);
							SQLFreeHandle(SQL_HANDLE_STMT, hdlStmt2);
							
						}
						else
						{
							cout << "blad wykonania zapytan";
						}
						
							for (int i = 0; i < kamery_liczace.size();i++)
							{
								for (int j = 0;j < daty_przejazdow.size();j++)
								{
									retcode2 = SQLAllocHandle(SQL_HANDLE_STMT, hdlDbc, &hdlStmt);
									retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdlDbc, &hdlStmt2);
									if (SQL_SUCCEEDED(retcode) && SQL_SUCCEEDED(retcode2))
									{
										cout<<daty_przejazdow[j];
										string zmiana = daty_przejazdow[j];
										int godzina = (int)zmiana.at(12) -1 -48;//-48, bo taki kod ASCII
										string godz = to_string(godzina);
										//cout << godzina<<" a teraz string:"<<godz << endl;
										zmiana.replace(12, 1, godz);
										//cout << zmiana << endl;
										licznosci_przejazdow(hdlStmt, hdlStmt2, kamery_liczace[i], daty_przejazdow[j], zmiana);
									}
									else
									{
										cout << "blad wykonania zapytan";
									}
									SQLFreeHandle(SQL_HANDLE_STMT, hdlStmt);
									SQLFreeHandle(SQL_HANDLE_STMT, hdlStmt2);
								}
							}
						
						SQLDisconnect(hdlDbc);
					}
					else
					{
						if (retcode == SQL_ERROR)
						{
							while ((retcode = SQLGetDiagRec(SQL_HANDLE_DBC, hdlDbc, i, SqlState, &NativeError,
								Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA) {
								cout << "retcode" << retcode << endl;
								cout << "error record #" << i++ << endl;
								cout << "sqlstate: " << SqlState << endl;
								cout << "detailed msg: " << Msg << endl;
								cout << "native error code: " << NativeError << endl;
							}
							//retcode = SQLGetDiagField(SQL_HANDLE_DBC, hdlDbc, i, SqlState, &N )
						}
						cout << "blad sql connect" << endl<<endl;
					}//koniec SQL_SUCCEEDED(retcode)

				
				SQLFreeHandle(SQL_HANDLE_DBC, hdlDbc);
			}
			else
			{
				cout << "bĹ‚Ä…d3";
			}
			SQLFreeHandle(SQL_HANDLE_ENV, hdlEnv);
		}//koniec retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO
		else
		{
			cout << "bĹ‚Ä…d2";
		}
	}
	else
	{
		cout << "bĹ‚Ä…d1";
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	}//koniec super fora
	system("pause"); //działa tylko na windowsach!
	return 0;
}

