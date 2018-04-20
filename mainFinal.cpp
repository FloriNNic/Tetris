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
    int a[h+2][l+2]{}, i, j, k;

    for(i = 0; i < n; i++)
    {
        int N,q = *p[i],Q = p[i][1], r = p[i][2], R = p[i][3], L = h;

        for(k = 0; h/++k;)

            for(j = q; j < q + Q; j++)

                if(a[k][j])
                {
                    L = k - 1;
                    goto e;
                }
        e:;

        for(k = L; k > max(0,L - r); k--)
            for(j = q; j < q + Q; j++)
                a[k][j] = R;

        if (r>L) break;

        for(N=l;N==l;){
            N=0;
            for(j=0; l / ++j; )
                N += !!a[h][j];

            for(j=h; j>0 && N==l; j--)
                for(k=0; l / ++k;)
                    a[j][k] = a[j-1][k];

        }
    }
    for(i = 1; i < h + 2; i++)

        for(j = 0; j < l + 3; j++)

            putchar(j == l + 2 ? '\n' : i == h+1 ? j % (l + 1) ? '-' : ' ' : j % (l + 1) ? a[i][j] ? : '.' : '|');

}
int main()
{

unsigned char l = 6, h = 10, n = 3;
unsigned char p[3][4];
p[0][0] = 1; p[0][1] = 3; p[0][2] = 4; p[0][3] = 'X';
p[1][0] = 1; p[1][1] = 3; p[1][2] = 2; p[1][3] = '#';
p[2][0] = 4; p[2][1] = 3; p[2][2] = 5; p[2][3] = '*';

f(l,h,n,p);
    return 0;


