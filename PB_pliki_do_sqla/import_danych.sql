USE ITS;



BULK INSERT GITKamera
   FROM 'C:\Users\E431\Desktop\magisterka\its\GITKamera.csv'
   WITH
     (
        FIRSTROW = 3,
        FIELDTERMINATOR = ';', --CSV field delimiter
        ROWTERMINATOR = '\n',--'0x0a',--'\n', --Use to shift the control to next row
		--ERRORFILE = 'C:\Users\E431\Desktop\magisterka\moje\error_data2.csv',
        KEEPNULLS
     )
GO
