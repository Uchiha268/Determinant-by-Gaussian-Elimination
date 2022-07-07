#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;
class Determinant
{	public:
			float input();
			float row_echelon();
			float display_row_echelon();
			float determinant();
			Determinant();
		 	double a[50][50], b[50][50];
			int i, j, n, x, count, flag, flag1;
			double k, det, temp;
			void add_rows(int j, int x, float k);
			void swap_rows(int j, int x);  
};

Determinant::Determinant()
{
	count=0;
	det=1;
	flag=0;

}

float Determinant::input()
{
	cout << "Enter the order of the square matrix" << endl;
	cin >> n;
	cout << "Enter the elements of the array" << endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			{cin >> a[i][j];}
		cout << endl;
	}
	return 0;
}


float Determinant::display_row_echelon()
{
	cout << "The original matrix is" << endl << endl;
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
				{printf("%10.2f", a[i][j]);}
			cout << endl << endl << endl;
		}
	if (flag==1)
	{
		cout << "The row echelon form of this matrix is not needed" << endl << endl;
		det=0;
	}
	else
	{
		cout << "The row echelon form of the given matrix is" << endl << endl;
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
				{printf("%10.2f", b[i][j]);}
			cout << endl << endl << endl;
		}
	}
	
	return 0;
}


void Determinant::add_rows(int j,int x,float k)
{
	int y;
	for (y=0; y<n; y++)
	{
		b[x][y]=((k*(b[j][y]))+(b[x][y]));
		if (abs(b[x][y]) <0.0001)
		{
			b[x][y]=0;
		}
		
	}
}

void Determinant::swap_rows(int j, int x)
{
	int y;
	for (y=0;y<n;y++)
	{
		temp=b[j][y];
		b[j][y]=b[x][y];
		b[x][y]=temp;
	}
	count++;
}

float Determinant::row_echelon()
{
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			{ b[i][j]=a[i][j];}
		
	}
	for (j=0; j<n-1 && flag!=1;j++)
	{
	label:	if (b[j][j]==0)              //if the main diagonal element has a 0
			{
				for (x=j+1; x<n  ; x++)
				{
					if(b[x][j]!=0)
					{
						swap_rows(j,x);
						goto label;
					}
				}
				if (x==n)
				{
					flag=1;
				}
			}		
		
		else 
		{
			for (x=j+1; x<n; x++)
				if( (b[x][j]) != 0)          //two add the multiple of one row to the other to make the elements below the main
				{                            //diagonal 0.
					k= -((b[x][j])/(b[j][j]));
					add_rows(j, x, k);
				}
		}
	}
	return 0;
} 

float Determinant::determinant()
{
		if (flag!=1)
		
		{
			for (j=0;j<n;j++)
			{
				det= (det)*(b[j][j]);
			}
		}
	if( ((count)%2)==1 )
	{
		det= -(det);
	}
	cout << "The determinant of the given matrix is " << det;
	return 0;
}
int main()
{
	Determinant d;
	d.input();
	d.row_echelon();
	d.display_row_echelon();
	d.determinant();
	getch();
	return 0;
}