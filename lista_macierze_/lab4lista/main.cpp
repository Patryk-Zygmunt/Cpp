#include<iostream>
#include "mac.h"
using namespace std;

/*ostream & operator<<(ostream& wyj,mac& m)
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
}*/
template< class t>
class lista;

template< class t>
class element {
    public:
 friend class lista<t>;
 protected:
	t wart;
	element *next;
	public:
 element(){
 next=NULL;
 }
      	};
template< class t>
class lista{
    public:
 element<t> *head;

 lista(){
  head=NULL;
}
void sort();
 friend ostream & operator<<(ostream & wyj,lista<t> & lt);
 friend istream & operator>>(istream & wej,lista<t> &lt);
lista<t> & operator=(lista<t> &lt);
lista<t> & operator+(lista<t> & );

~lista(){
    element<t> *wsk,*buf;
    wsk=head;
 while(wsk!=NULL){
         buf=wsk;
        wsk=wsk->next;
        delete buf;
       // cout<<"dwstruction";
       }
    }

  };
template< class t>
istream & operator>>(istream & wej,lista<t> &lt) {
 element<t> *wsk,*nowy;

 if(lt.head==NULL){
	nowy= new element<t>;
	wej>> nowy->wart;
	nowy->next=NULL;
	lt.head=nowy;}
  else{

	wsk=lt.head;
  while(wsk->next!=NULL){
	wsk=wsk->next;}
	nowy=new element<t>;
	wsk->next=nowy;
	wej >> nowy->wart;
	nowy->next=NULL;}
	return wej;
   }

  /* void dod(lista &lt){
   element. *wsk,*nowy;

 if(lt.head==NULL){
	nowy= new element;
	cin>> nowy->wart;
	nowy->next=NULL;
	lt.head=nowy;}
  else{
3
4
2
	wsk=lt.head;
  while(wsk->next!=NULL){
	wsk=wsk->next;}
	nowy=new element;
	wsk->next=nowy;
	cin >> nowy->wart;
	nowy->next=NULL;}}
*/


template< class t>
  ostream & operator<<(ostream & wyj,lista<t> & lt){
//void print(lista lt){
   element<t> *wsk;

 	wsk=lt.head;

   while(wsk!=NULL){
    	cout<<wsk->wart<<endl ;
    	wsk=wsk->next;}
    	return wyj;
 	}



 	template< class t>
 	 void lista<t>::sort(){
 element<t> *wsk,*tmp,*mini;
 t buf;
 tmp=head;

 while(tmp!=NULL){
     wsk=tmp;
        buf=wsk->wart;
        mini=wsk;
  while(wsk!=NULL){
  if(wsk->wart<buf){
   buf=wsk->wart;
mini=wsk;}
   wsk=wsk->next;}
   mini->wart=tmp->wart;
   tmp->wart=buf;
   tmp=tmp->next;}
   }

template< class t>
lista<t> & lista<t>::operator+(lista<t> & lt){
 element<t> *del,*wsk,*wsk2,*buf,*nowy;
  static lista<t> sum;

  if(sum.head!=NULL){

         del=sum.head;
        while(del!=NULL){
            cout<<"kasuje";
        buf=del;
        del=del->next;
        delete buf;}
        sum.head=NULL ;}
        nowy=new element<t>;
        nowy=head;
        nowy->wart=head->wart;
       nowy->next=head->next;
        sum.head=nowy;

 wsk2=head->next;
 while(wsk2->next!=NULL){
        cout<<"111"<<endl;
nowy=new element<t>;
nowy->wart=wsk2->wart;
nowy->next=wsk2->next;
wsk2=wsk2->next;}
  cout<<"hhhhhhhhhhhhhhh"<<endl;
nowy=new element<t>;
nowy=wsk2;
nowy->next=lt.head;
nowy->wart=wsk2->wart;
 wsk=lt.head->next;
 while(wsk!=NULL){
        cout<<"222"<<endl;
nowy=new element<t>;
nowy->wart=wsk->wart;
nowy->next=wsk->next;
wsk=wsk->next;}

return sum;}

template< class t>
lista<t> & lista<t>::operator=(lista<t> & lt){
    element<t> *wsk,*buf,*nowy;

if(head==NULL)
    {
        nowy=new element<t>;
        nowy->wart=lt.head->wart;
        nowy->next=lt.head->next;
        head=nowy;
        wsk=lt.head;
        while(wsk->next!=NULL){
              //  cout<<"while null";
            nowy=new element<t>;
        nowy->wart=wsk->wart;
        nowy->next=wsk->next;
        wsk=wsk->next;
        }
    }
if(head!=NULL){
    while(wsk!=NULL){
        buf=wsk;
        wsk=wsk->next;
        delete buf;
    }

     nowy=new element<t>;
        nowy->wart=lt.head->wart;
        nowy->next=lt.head->next;
        head=nowy;
        while(wsk!=NULL){
            nowy=new element<t>;

        nowy->wart=wsk->wart;
        nowy->next=wsk->next;
        wsk=wsk->next;}

}


}
/*lista & lista::operator+(lista & lt){
 element *wsk3,*wsk,*wsk2,*buf,*nowy;
  static lista sum1,sum2;
  sum1=*this;
  sum2=lt;
  wsk=sum1.head;
  while(wsk->next!=NULL){
    wsk=wsk->next;}
  wsk->next=sum2.head;
  return sum1;
}
*/

 int main(){

 lista<double> a,c,l,d;
cout<<"lista a"<<endl;
cin>>a>>a;
//cin >> l   >>l>>l>>l;
cout<<"lista c"<<endl;
cin >>c>>c>>c;
cout<<"lista a"<<endl;
 cout << a;
 c.sort();
 cout<<"lista c"<<endl;
 cout << c;
 cout<<"lista l"<<endl;
l=c+a;
  cout << l ;
  cout<<"lista d"<<endl;
  d=c+a;
  cout << d ;
  return 0;}









