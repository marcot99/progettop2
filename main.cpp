#include <iostream>
#include "animale.h"
#include "erbivoro.h"
#include "carnivoro.h"
#include "onnivoro.h"
#include "rinoceronte.h"
#include "orso.h"
#include "serpente.h"
using namespace std;

int main()
{
    std::list<Tipo> t;
    Rinoceronte a (1,2,3,4,"lol",false,"lol",true,"lol" ,t ,7);
    cout << a.getAltezza();
}
