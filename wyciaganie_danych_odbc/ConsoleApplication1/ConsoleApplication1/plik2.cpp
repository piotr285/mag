#include "stdafx.h"

/*
int identyfikatory_kamer(SQLHANDLE hdlStmt)
{
	fstream FILE;
	SQLINTEGER I;
	SQLRETURN kod_zwrotny; //kody zwracane przez funkcje
	string wyszukanie = "SELECT Id_Globalny FROM GITKamera WHERE Id_Typ_Kamery=67";
	char* statement = new char[300];
	int id_kamery = 0;// kamer ARTR, powinno byÄ‡ 38
	vector<int> id_tab;

	char* odpowiedz = new char[300];
	//vector<char*> odp;
	//wyszukanie = "SELECT * FROM SysObjects WHERE Type = 'u' ORDER BY Name";
	statement = (char*)wyszukanie.c_str();
	kod_zwrotny = SQLExecDirect(hdlStmt, (SQLCHAR*)statement, SQL_NTS);//realizacja zapytania 
	if (SUCCEEDED(kod_zwrotny))
	{
		while (SQL_SUCCEEDED(SQLFetch(hdlStmt)))
		{//fetch przycina do jednej linii, GetData pobiera
		 

			kod_zwrotny = SQLGetData(hdlStmt, 1, SQL_C_SLONG, &id_kamery, 0, &I);//SLONG to integer
			if (SQL_SUCCEEDED(kod_zwrotny))
			{
				id_tab.push_back(id_kamery);
			}
			else
			{
				cout << "znowu bledy" << endl;
			}
		}
	}//koniec if SUCCEEDED

	
	FILE.open("C:/Users/E431/Desktop/magisterka/identyfikatory_kamer_ARTR.txt", ios::out | ios::app);
	for (int i = 0; i < id_tab.size();i++)
	{
		FILE << id_tab[i] << ", ";
	}
	FILE.close();
	cout << "wypisano identyfikatory kamer ARTR" << endl;
	return 0;
}
*/

//cout << "podaj identyfikator globalny kamery zliczaj¹cej:" << endl;
//cin >> numer;
//	numer = "1196";
//cout << "podaj nr dnia miesi¹ca(1-31) (uwaga!dane tylko z dni 14.05.2014 a 24.05.2014)" << endl;
//cin >> dzien;
//dzien = to_string(dzienInt);
//tmp += numer;
//tmp += " and Czas_Rejestracji between ( CONVERT(datetime, CONVERT(\"varchar\"(23), '2014-05-";
//tmp += dzien;
//tmp += " 07:00:00.000', 23), 111)) and ( CONVERT(datetime, CONVERT(\"varchar\"(23), '2014-05- ";
//tmp += dzien;
//tmp += " 08:15:00.000', 23), 111))";