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
    mac & operator=(mac & );
    ~mac()
    { if(tab!=NULL){
        for(int i=0; i<roz; ++i)
            delete [] tab[i];
        delete [] *tab;
        cout<<"dzialam";}
//cout<<tab[1][1];
    }
};

mac & mac::operator=(mac & m){
    //jesli to te same obiekty
    if(this==&m)
        return *this;
        //zwalniamy pamiec
    if(tab!=NULL){
        for(int i=0; i<roz; ++i)
            delete [] tab[i];
        delete [] *tab;}
        //tworzymy obiekt
     roz=m.roz;
  tab= new int *[m.roz];
    for(int i=0; i<m.roz; ++i)
        tab[i] = new int[i];

for(int i=0; i<m.roz; ++i)
        for(int j=0; j<m.roz; ++j)
           tab[i][j]=m.tab[i][j];


           return *this;
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
{  cout<<"Wprowadz rozmiar"<<endl;
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

    cin >> mb;
   cin >> mc;


    mc=mb;
   cout << mc;

    cout << mb;

    return 0;
}


