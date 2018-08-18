//2017-12-20 Milewski Krzysztof
//Dev-C++ 5.11 (TDM-GCC 4.9.2 32-bit Release)
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int labi[22][22];
int poz_x=2;
int poz_y=19;
int rozbr=3;

void zerowanie();
void wczytanie();
void rysuj();
void plapki();



int main()
{
	zerowanie();
	wczytanie();
	plapki();
	rysuj();
	int kroki=0;

	do
		{
			if (labi[poz_y+1][poz_x]==3||labi[poz_y-1][poz_x]==3||labi[poz_y][poz_x+1]==3||labi[poz_y][poz_x-1]==3)
				{
					cout << "IT'S A TRAP!!!" << endl
					<< "Nacisnij 'R' by rozbroic plapke" << endl
					<< "Pozostale rozbroienia: " << rozbr << endl;
				}
			char opcja=getch();
	
			system("cls");
			switch (opcja)
			{
				
				case 'w':
					if (labi[poz_y-1][poz_x]==1)
					{
						break;
					}
					else
					{
						labi[poz_y][poz_x]=2;
						poz_y=poz_y-1;
						break;
					}
				case 's':
					if (labi[poz_y+1][poz_x]==1)
					{
						break;
					}
					else
					{
						labi[poz_y][poz_x]=2;
						poz_y=poz_y+1;
						break;
					}
				case 'd':
					if (labi[poz_y][poz_x+1]==1)
					{
						break;
					}
					else
					{
						labi[poz_y][poz_x]=2;
						poz_x=poz_x+1;
						break;
					}
				case 'a':
					if (labi[poz_y][poz_x-1]==1)
					{
						break;
					}
					else
					{
						labi[poz_y][poz_x]=2;
						poz_x=poz_x-1;
						break;
					}
				case 'r':
					if (labi[poz_y+1][poz_x]==3 && rozbr>0)
					{
						labi[poz_y+1][poz_x]=0;
						rozbr=rozbr-1;
						break;
					}
					if (labi[poz_y-1][poz_x]==3 && rozbr>0)
					{
						labi[poz_y-1][poz_x]=0;
						rozbr=rozbr-1;
						break;
					}
					if (labi[poz_y][poz_x+1]==3 && rozbr>0)
					{
						labi[poz_y][poz_x+1]=0;
						rozbr=rozbr-1;
						break;
					}
					if (labi[poz_y][poz_x-1]==3 && rozbr>0)
					{
						labi[poz_y][poz_x-1]=0;
						rozbr=rozbr-1;
						break;
					}
					else
					{
						break;	
					}

				default:
            	break;			
				
			}
			if (labi[poz_y][poz_x]==3)
			{
				break;
			}
			rysuj();
			kroki=kroki+1;
		} 
	while(labi[poz_y][poz_x]!=4);
	if (labi[poz_y][poz_x]==4)
	{
		system ("cls");
		cout << "Gratulacje! Dotarles do wyjscia!" << endl
		<< "Liczba krokow: " << kroki << endl;
	}
	if (labi[poz_y][poz_x]==3)
	{
		system ("cls");
		cout << "Przegrales!" << endl
		<< "Liczba krokow: " << kroki << endl;
	}
	system("PAUSE");
	return 0;
	
	
}

void zerowanie()
{	
	for (int i=0; i<22; i++)
	{
		for (int j=0; j<22; j++)
		{
			labi[i][j]=0;
		}
	}
}

void wczytanie()
{
	ifstream plik("labirynt.txt");
	if (plik.is_open()) 
	{
		while (!plik.eof())
        {
            for (int i=1; i<21; i++)
            {
            	for (int j=1; j<21; j++)
                {
                    plik >> labi[i][j];
				}
			}
		}
                         
	}
	else
      {
          cout << "Niepoprawne wczytanie pliku" << endl;
      }
      plik.close();
}

void rysuj()
{
	int m,n;
	
	if (poz_y<11 && poz_x<11)
	{
		m=11;
		n=11;
	}
	if (poz_y<11 && poz_x>=11)
	{
		m=11;
		n=21;
	}
	if (poz_y>=11 && poz_x<11)
	{
		m=21;
		n=11;
	}
	if (poz_y>=11 && poz_x>=11)
	{
		m=21;
		n=21;
	}
	for (int i=(m-10); i<(m); i++)
	{
		for (int j=(n-10); j<(n); j++)
		{
			if (i==poz_y && j==poz_x)
			{
				cout << "#";
			}
			else if (labi[i][j]==1)
			{
				if (labi[i+1][j]==1 || labi[i-1][j]==1)
				{
					if (labi[i][j+1]==1 || labi[i][j-1]==1)
					{
						cout << "+";
					}
					else
					{
						cout << "|";
					}
				}
				else
				{
					cout << "-";
				}
			}
			else if (labi[i][j]==2)
			{
				cout << ".";
			}
			else if (labi[i][j]==0||labi[i][j]==3||labi[i][j]==4)
			{
				cout << " ";
			}
		
			
		}

		cout << endl;
	}
}

void plapki()
{
	int plapka=4;
	int m,n;
	
	srand( time(NULL));
	
	while(plapka>0)
	{
		m=(rand() %20)+1;
		n=(rand() %20)+1;
		if(labi[m][n]==0)
		{
			labi[m][n]=3;
			plapka=plapka-1;
		}	
	}
	
}
