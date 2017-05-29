#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

class mac
{
public:
    int **tab;
    int roz;
    mac()
    {
        tab=NULL;
    }
    mac & operator+(mac &);
    mac & operator=(mac &);
    mac & operator*(mac &);
    bool operator==(mac  );
    bool operator!=(mac);
    bool operator<(mac);
    bool operator>(mac);
    bool operator<=(mac);
    bool operator>=(mac);
    mac(const mac &m){
        roz=m.roz;
    tab= new int *[m.roz];
    for(int i=0; i<m.roz; ++i)
        tab[i] = new int[i];

    for(int i=0; i<m.roz; ++i)
        for(int j=0; j<m.roz; ++j)
            tab[i][j]=m.tab[i][j];

    }
    ~mac()
    {
        if(tab!=NULL)
        {
            for(int i=0; i<roz; ++i)
                delete [] tab[i];
            delete [] *tab;
            //	cout<<"dzialam";
        }
//cout<<tab[1][1];
    }
};
