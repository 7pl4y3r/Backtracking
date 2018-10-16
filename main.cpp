#include <iostream>
#include <fstream>

using namespace std;

ifstream in("lab.txt");
int n,m,L[10][10],xs,ys,xb,yb;
int Dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int Dy[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

void makeBorder()
{
    for(int i = 0; i <= n+1; i++)
        L[i][0] = L[i][m+1] = 1;

    for(int j = 0; j <= m+1; j++)
        L[0][j] = L[n+1][j] = 1;
}

void read()
{
    in >> n >> m >> xs >> ys >> xb >> yb;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        in>>L[i][j];
}

void write()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m;j++)
            if(L[i][j] == 2)
                cout << "* ";
            else
                cout << L[i][j] << ' ';

        cout << endl;
    }

    cout << endl;
}

void det_drum(int x, int y)
{
    L[x][y] = 2;

        for(int directie = 1; directie <= 8; directie++)
            if(L[x+Dx[directie]][y+Dy[directie]] == 0)
                det_drum(x+Dx[directie], y+Dy[directie]);

    write();
    L[x][y] = 5;
}

int main()
{
    read();
    makeBorder();
    write();

    int c = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        if(L[i][j] == 0){
            c++;
            det_drum(i, j);
        }

         cout << c;

    return 0;
}
