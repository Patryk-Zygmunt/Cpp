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

mac & mac::operator=(mac & m)
{
    //jesli to te same obiekty
    if(this==&m)
        return *this;
    //zwalniamy pamiec
    if(tab!=NULL)
    {
        for(int i=0; i<roz; ++i)
            delete [] tab[i];
        delete [] *tab;
    }
    //rezerwujemy pamiec
    roz=m.roz;
    tab= new int *[m.roz];
    for(int i=0; i<m.roz; ++i)
        tab[i] = new int[i];

    for(int i=0; i<m.roz; ++i)
        for(int j=0; j<m.roz; ++j)
            tab[i][j]=m.tab[i][j];


    return *this;
}
mac & mac::operator+(mac & m)
{

    static mac suma;

     if(m.roz!=roz){
    cout<<"Dodawane macierze maja rozne wymiary";
    return m;}

    if(suma.tab!=NULL)
    {
        for(int i=0; i<suma.roz; ++i)
            delete [] suma.tab[i];
        delete [] *suma.tab;

    }
    suma.roz=roz;
    suma.tab= new int *[suma.roz];
    for(int i=0; i<suma.roz; ++i)
        suma.tab[i] = new int[i];

    for(int i=0; i<suma.roz; ++i)
        for(int j=0; j<suma.roz; ++j)
            suma.tab[i][j]=0;

    for(int i=0; i<suma.roz; ++i)
        for(int j=0; j<suma.roz; ++j)
            suma.tab[i][j]=tab[i][j]+m.tab[i][j];

    return suma;
}

mac & mac::operator*(mac & m)
{

    static mac suma;

    if(m.roz>roz){
            cout<<"Macierze maja rozne wymiary"<<endl;
        return m;}
    if(m.roz<roz){
    cout<<"Macierze maja rozne wymiary"<<endl;
        return *this;}




    if(suma.tab!=NULL)
    {
        for(int i=0; i<suma.roz; ++i)
            delete [] suma.tab[i];
        delete [] *suma.tab;

    }


    suma.roz=roz;
    suma.tab= new int *[suma.roz];
    for(int i=0; i<suma.roz; ++i)
        suma.tab[i] = new int[i];

    for( int i=0; i<suma.roz; ++i)
        for(int j=0; j<suma.roz; ++j)
            suma.tab[i][j]=0;

    for(int i = 0; i < suma.roz; i++)
        for(int j = 0; j < suma.roz; j++)
            for(int k = 0; k < suma.roz; k++)
                suma.tab[i][j] = suma.tab[i][j] + tab[i][k] * m.tab[k][j];
    return suma;
}


bool mac::operator==(mac  m)
{
    if(roz!=m.roz)
        return false;
    else
    {
        int suma=0;
        for(int i=0; i<roz; ++i)
            for(int j=0; j<roz; ++j)
            {
                suma=(tab[i][j]-m.tab[i][j]);
                if(suma!=0)
                    return false;
            }
        if(suma==0)
            return true;
    }
}

bool mac::operator!=(mac  m)
{
    if(roz!=m.roz)
        return true;
    else
    {
        int suma=0;
        for(int i=0; i<roz; ++i)
            for(int j=0; j<roz; ++j)
            {
                suma=(tab[i][j]-m.tab[i][j]);
                if(suma!=0)
                    return true;
            }
        if(suma==0)
            return false;
    }
}

bool mac::operator>(mac  m)
{
    if(roz<m.roz)
        return false;
    if(roz>m.roz)
        return true;
    else
    {
        int suma=0;
        for(int i=0; i<roz; ++i)
            for(int j=0; j<roz; ++j)
                suma=suma+(tab[i][j]-m.tab[i][j]);
        if(suma>0)
            return true;
        if(suma<=0)
            return false;
    }
}
bool mac::operator<(mac  m)
{
    if(roz<m.roz)
        return true;
    if(roz>m.roz)
        return false;
    else
    {
        int suma=0;
        for(int i=0; i<roz; ++i)
            for(int j=0; j<roz; ++j)
                suma=suma+(tab[i][j]-m.tab[i][j]);
        if(suma>=0)
            return false;
        if(suma<0)
            return true;
    }
}
bool mac::operator>=(mac  m)
{
    if(*this==m)
        return true;
    if(roz<m.roz)
        return false;
    if(roz>m.roz)
        return true;
    else
    {
        int suma=0;
        for(int i=0; i<roz; ++i)
            for(int j=0; j<roz; ++j)
                suma=suma+(tab[i][j]-m.tab[i][j]);
        if(suma>0)
            return true;
        if(suma<0)
            return false;
    }
}

bool mac::operator<=(mac  m)
{
    if(*this==m)
        return true;
    if(roz<m.roz)
        return true;
    if(roz>m.roz)
        return false;
    else
    {
        int suma=0;
        for(int i=0; i<roz; ++i)
            for(int j=0; j<roz; ++j)
                suma=suma+(tab[i][j]-m.tab[i][j]);
        if(suma>0)
            return false;
        if(suma<0)
            return true;
    }
}




ostream & operator<<(ostream& wyj,mac& m)
{
    for(int i=0; i<m.roz; ++i)
    {
        for(int j=0; j<m.roz; ++j)
            wyj<<m.tab[i][j];
        wyj<<endl;
    }
    return wyj;
}
istream & operator>>(istream& wej,mac& m)

{
    if(m.tab!=NULL)
    {
        for(int i=0; i<m.roz; ++i)
            delete [] m.tab[i];
        delete [] *m.tab;
    }
    cout<<"Wprowadz rozmiar"<<endl;
    wej>>m.roz;
    m.tab= new int *[m.roz];
    for(int i=0; i<m.roz; ++i)
        m.tab[i] = new int[i];
    cout<<"Wypelnij tablice"<<endl;
    for(int i=0; i<m.roz; ++i)
        for(int j=0; j<m.roz; ++j)
            wej>>m.tab[i][j];
    return wej;
}

int main()
{
    mac mc,mb;
    while(1)
    {
        cin >> mc;
        cin >> mb;
        mac ma(mb);
       /* if( mc==mb)
            cout<<"Macierze sa takie same"<<endl;
        if( mc!=mb)
            cout<<"Macierze sa rozne"<<endl;
        if( mc>mb)
            cout<<"Macierz a > b"<<endl;
        if( mc<mb)
            cout<<"Macierz b > a "<<endl;
        if( mc>=mb)
            cout<<"Macierz a >= b"<<endl;
        if( mc<=mb)
            cout<<"Macierz b => a "<<endl;*/
            cout << ma;
    }

    return 0;
}






