#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
 int silnia(int);
class nk{
   private:
int n,k,w;
 public:
//void wczytaj(){
    nk(){
cout<<"wpisz k i n"<<endl;
cin>>k;
cin>>n;}
friend int silnia(int);
void show(){
cout<<n<<"  -<n i k->"<<k<<endl;
}
int licz(){
return (silnia(n))/(silnia(k)*silnia(n-k));

}
};

int main()
{ int o,i;
nk *obt;
cin>>o;

obt= new nk[o];//(nk*)malloc(o*sizeof(nk));
//for(i=0;i<o;++i)
  //obt[i].wczytaj();
  for(i=0;i<o;++i)
//
//Sleep(2000);
for(i=0;i<o;++i){
        obt[i].show();
/*if(obt[i].licz() % 2 == 0)
    cout<<" P "<<endl;
else
    cout<<" N "<<endl;*/
delete [] obt;7

}
    return 0;
}
int silnia(int n){

if(n==1)
    return 1;
    else
    return n*silnia(n-1);
}
