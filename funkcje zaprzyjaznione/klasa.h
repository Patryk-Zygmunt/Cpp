#include <iostream>
//#include <cstdlib>

using namespace std;
class prostokat;
class pkt{

    string name;
int x,y;
 public:
 pkt(string="state" ,int=3,int=3);
 friend void judge(pkt,prostokat);
};

class prostokat{

    string name;
int x,y,w,h;
public:
    prostokat(string="lake",int=2,int=2,int=3,int=3);
friend void judge(pkt,prostokat);
};
