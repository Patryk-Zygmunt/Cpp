#include <iostream>

using namespace std;
class ksztalt{
    public:
        string nazwa;
virtual void show(){
cout<<nazwa;}
virtual void pole()=0;
};

class kolo:public ksztalt{
    public:
float r;
string nazwa;

kolo(int rr,string n){
r=rr;
nazwa=n;}
void show(){
cout<<"fffffh";}
virtual void pole(){
cout<<"pole kola wynosi: "<<r*r*3.14<<endl;
}
} ;

class kwadrat:public ksztalt{
    public:
float a;
string nazwa;
kwadrat(int aa){
a=aa;}
virtual void pole(){
cout<<"pole kwadratu wynosi: "<<a*a<<endl;
}
} ;
void oblicz(ksztalt *wsk){
wsk->pole();}
int main()
{
   ksztalt *wsk;
   kolo k(3,"opona");
   wsk=&k;
   k.show();
   wsk->show();
   oblicz(wsk);
    return 0;
}
