#include <iostream>
//#include <cstdlib>
#include "klasa.h"


using namespace std;
void judge(pkt p,prostokat pr){
if(((p.x>pr.x)&&(p.y>pr.y))&&((p.x<pr.x+pr.w)&&(p.y<pr.y+pr.h)))
    cout<<p.name<<" nalezy do "<<pr.name<<endl;
    else
   cout<<p.name<<" nie nalezy do "<<pr.name<<endl;
}

int main()
{
    pkt p1;//("first",3,3);
    prostokat pr1 ;//("second",2,28,4,4);
    judge(p1,pr1);
    return 0;
}
