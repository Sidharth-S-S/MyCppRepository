#include<iostream>
using namespace std;

//INSTRUMENT LIBRARIES.... all from the same VENDOR

class flute {public: void play(){cout <<"playing flute..." << endl;}};

class drums {public: void play(){cout <<"playing drums..." << endl;}};

class piano {public: void play(){cout <<"playing piano..." << endl;}};

class guitar {public: void play(){cout <<"playing guitar..." << endl;}};

//A new instrument from a DIFFERENT VENDOR...

class Tabla {public: void play_tabla(){   }};

//A library developer consuming the above INSTRUMENT LIBRARIES...

template<typename T1, typename T2, typename T3> class compose
{
private:
    T1 obj1;
    T2 obj2;
    T3 obj3;
public:
    void compose_music();    
};

template<typename T1, typename T2, typename T3> void compose<T1,T2,T3>::compose_music()
{
    obj1.play();
    obj2.play();
    obj3.play();
}

//**********consumer code ****************
/*
    The compose class consumer plans to strategize his music compositions by using the above
    compose class.
*/

int main()
{
    //composition-1
    compose<drums,piano,flute> music1;
    music1.compose_music();
    cout <<"***************************" << endl;
    //composition-2
    compose<piano,flute,flute> music2;
    music2.compose_music();
    //composition-3
    compose<flute,flute,flute> music3;
    music3.compose_music();
    //composition-4
    compose<piano,flute,guitar,drums> music4;
    music4.compose_music();
    return 0;
}