#include <iostream>

using namespace std;

class punkt{
int x,y;
string nazwa;
public:
    punkt(string n,int xx,int yy){
       nazwa=n;
        x=xx;
        y=yy;}
   void wyswietl() {
     cout<<nazwa<<" wspolrzedne: "<<x<<y<<endl;}
    };


class kolo :public punkt{
    protected:
int r;
string nazwa;
public:
 kolo(string n,string np,int xx,int yy,int pr)
:punkt(np,xx,yy)
{
  nazwa=n;
    r=pr;
}
void wyswietl(){
cout<<nazwa<<endl;
punkt::wyswietl();
cout<<"promien"<<r<<endl;
cout<<"pole:"<<3.14*r*r<<endl;

}


};

class kula :public kolo{
string nazwa;
public:
kula(string nk,string n, string np, int xx ,int yy ,int pr)
:kolo(n,np,xx,yy,pr)
{nazwa=nk;}
void wyswietl()
{
    kolo::wyswietl();
    cout<<"pole kuli: "<<3.13*r*r*r<<endl;
}
};





int main()
{
    kula k1("kuleczka","kolko","srodek",3,3,19);
    k1.wyswietl();
    return 0;
}
