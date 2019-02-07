USE ITS;


CREATE TABLE DPTPrzejazd
(
Nr_Rejestracyjny NVARCHAR (15)  NOT NULL,
Id_Globalny_Punkt_A INT NOT NULL,
Id_Globalny_Punkt_B INT NOT NULL,
Czas_Punkt_A DATETIME NOT NULL,
Czas_Punkt_B DATETIME NOT NULL,
Czas_Przejazdu INT NOT NULL,
Czas_Wprowadzenia DATETIME NOT NULL
);

CREATE TABLE DPTKamera_Pomiar
(
Id_Globalny INT NOT NULL,
Czas_Rejestracji DATETIME2 NOT NULL,
Czas_Wprowadzenia DATETIME2 NOT NULL,
Dlugosc VARCHAR(50),
Predkosc FLOAT,
Id_Pas_Kamera SMALLINT, 
Typ_Pojazdu VARCHAR(50)
);
create index czas_pocz on DPTKamera_Pomiar (Czas_Rejestracji);
create index global_id on DPTKamera_Pomiar (Id_Globalny);
CREATE TABLE GITKamera
(
OBJECTID INT NOT NULL,
Id_Typ_Kamery INT NOT NULL,
Id_Kamera NVARCHAR (50) ,
Sys_Zewn INT,
Nr_Seryjny NVARCHAR (50) ,
Model NVARCHAR (50) ,
Id_Globalny INT,
Nazwa NVARCHAR (50) ,
Lokalizacja_Opis NVARCHAR (100) ,
Publikacja BIT DEFAULT 0,
Shape INT,
Historyczny SMALLINT DEFAULT 0,
Klasyfikacja NVARCHAR (50) NULL,
Indeks_Na_Wlocie NVARCHAR (50) NULL,
Id_Wlot NVARCHAR (50) NULL
);

CREATE TABLE BRDObiekt_Globalny
(
Id_Globalny INT NOT NULL,
Typ_Tabeli INT NOT NULL,
Nazwa NVARCHAR (50) ,
Opis NVARCHAR (100) ,
Data_Modyfikacji DATETIME NOT NULL,
Usuniety BIT NOT NULL DEFAULT 0,
Stan INT,
Adres_IP NVARCHAR (15) ,
Adres_MAC NVARCHAR (17) ,
Port NVARCHAR (20) NULL, --int null ewentualnie
Id_Sys_Zewn NVARCHAR (255) NULL,
Point_X NVARCHAR (50) NULL,
Point_Y NVARCHAR (50) NULL,
Nr_Skrzyzowania NVARCHAR (50) NULL
);