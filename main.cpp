#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <bitset>
#include <vector>
#include <sstream>
using namespace std;

// l - latime tabla joc, h - inaltime table joc, n - numar piese tetris; p - informatii despre piese

void f(unsigned char l, unsigned char h, unsigned char n, unsigned char p[][4])
{
    int a[h+2][l+2]{}, i, j, k, L, nr; //L = level

    for(i = 0; i < n; i++)
    {
        nr = 0;
        L = h;

        for(k = 1; k <= h; k++)
        {
            for(j = p[i][0]; j < p[i][0] + p[i][1]; j++)
            {
                if(a[k][j])
                {
                    L = k - 1;

                    goto endOfLoop;
                }
            }
        }
        endOfLoop:;

        for(k = L; k > max(0,L - p[i][2]); k--)
        {
            for(j = p[i][0]; j < p[i][0] + p[i][1]; j++)
            {
                a[k][j] = p[i][3];
            }
        }

        if (L - p[i][2] < 0) break;

        for(j=1; j<=l; j++)
            if(a[h][j])
                nr++;

        while(nr==l){
            nr = 0;
            for(j=1; j<=l; j++)
                a[h][j]=0;

            for(j=h-1; j>=1; j--)
                for(k=1; k<=l; k++)
                    swap(a[j+1][k],a[j][k]);

            for(j=1; j<=l; j++)
            if(a[h][j])
                nr++;
       }

    }
    for(i = 1; i <= h + 1; i++)
    {
        for(j = 0; j < l + 3; j++)
        {
            putchar(j == l + 2 ? '\n' : i == h+1 ? j % (l + 1) ? '-' : ' ' : j % (l + 1) ? a[i][j] ? : '.' : '|');
        }
    }

}
int main()
{

unsigned char l = 6, h = 10, n = 3;
unsigned char p[3][4];
p[0][0] = 1; p[0][1] = 3; p[0][2] = 3; p[0][3] = 'X';
p[1][0] = 1; p[1][1] = 3; p[1][2] = 1; p[1][3] = '#';
p[2][0] = 4; p[2][1] = 3; p[2][2] = 2; p[2][3] = '*';

f(l,h,n,p);
    return 0;

/*    unsigned char p[][4] = {
                                {1, 6, 1, 'a'}, /// 1
                                {6, 1, 2, 'b'}, /// 2
                                {3, 2, 5, 'c'}, /// 3
                                {5, 1, 8, 'd'}, /// 4
                                {6, 1, 6, 'e'}, /// 5
                                {2, 3, 1, 'f'}, /// 6
                                {3, 4, 1, 'g'}, /// 7
                                {2, 1, 7, 'h'}, /// 8
                                {1, 5, 3, 'i'}, /// 9
                                {2, 1, 4, 'j'}, ///10
                                {3, 1, 5, 'k'}, ///11
                                {4, 1, 6, 'l'}, ///12
                                {2, 4, 9, 'm'}  ///13
                               };

*/    f(6, 20, 8, p);
}
