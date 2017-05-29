#include<iostream>
#include<cstdio>
#include<ctime>
 using namespace std;

  class Czas{
  public:
  int g,m,s;
  char tekst[200];

   Czas();
   Czas(int);
   Czas(int,int,int);
  void odczytaj(int &,int & ,int & );
  void wczytaj(int , int ,int );
   void wczytaj(char *);

  void odczytaj(char *);

    };
Czas::Czas(int a,int b ,int c){
g=a;
m=b;
s=c;}
Czas::Czas(int strefa){
    time_t czas;
    time(&czas);
    tm *zegar=localtime(&czas);
    if(zegar->tm_hour+strefa>=24){
        g=zegar->tm_hour+strefa-24;
    }
    else
    g=zegar->tm_hour +strefa  ;
    m=zegar->tm_min;
    s=zegar->tm_sec;}
Czas::Czas(){
    time_t czas;
    time(&czas);
    tm *zegar=localtime(&czas);
    g=zegar->tm_hour;
    m=zegar->tm_min;
    s=zegar->tm_sec;
}
void Czas::odczytaj(int &a,int &b,int &c){
   a=g;
   b=m;
   c=s;
  }
  void Czas::wczytaj(int a, int b,int c){
	g=a;
	m=b;
	s=c;
	}
   void Czas::wczytaj(char *tekst){
	sscanf(tekst,"%d:%d:%d",&g,&m,&s);}

  void Czas::odczytaj(char *tekst ){
    sprintf(tekst,"%d:%d:%d",g,m,s);}



  int main(){
  int a,b,c;
  char tekst[200];
  Czas z1(12,34,15);

  //z1.wczytaj(12,34,15);

  z1.odczytaj(tekst);
 z1.wczytaj("11:11:11");
  z1.odczytaj(a,b,c);
cout<<a<<":"<<b<<":"<<c<<endl;
cout<<tekst;
  return 0;
  }

