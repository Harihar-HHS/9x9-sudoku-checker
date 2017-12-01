#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	system("CLS");                                          //clear screen

	int mat[9][9],i,j,f=0;

	cout<<"enter 9x9 sudoku ( row-wise ) :\n";
	for(i=0;i<9;i++)
    for(j=0;j<9;j++)
        cin>>mat[i][j];

	for(i=0;i<9;i++)
	for(j=0;j<9;j++)
	{
		if(f!=1)
		{
			for(int c=0;c<9;c++)
			if(mat[i][j]==mat[i][c]&&c!=j)                  //checking i th row
			{	f=1;
				cout<<"\nnot the correct solution\n";
				break;
			}
			for(int r=0;r<9;r++)
			if(mat[i][j]==mat[r][j]&&r!=i)                  //checking j th column
			{	f=1;
				cout<<"\nnot the correct solution\n";
				break;
			}
			int m=(i<3?0:(i<6?3:6));
			int n=(j<3?0:(j<6?3:6));
			for(int x=m;x<m+3;x++)
			for(int y=n;y<n+3;y++)
			if(mat[i][j]==mat[x][y]&&x!=i&&y!=j)            //checking the small 3x3 box
			{	f=1;
				cout<<"\nnot the correct solution\n";
				break;
			}
		}
	}

	if(f==0)
		cout<<"\ncorrect solution\n";

	getchar();

	return 0;
}
