#include "Shelf.h"
#include "Rack.h"

int Rack::shelfCapacity = 0;

Rack::Rack(): shelfs(Vector<Shelf>()), name(0), haveSpace(shelfCapacity) {}

Rack::Rack(unsigned int name): name{name}, haveSpace(shelfCapacity) {

    int index = 1;
    for (int i = 0; i < shelfCapacity; i++)
    {
        shelfs.pushBack(Shelf(index));
        index++;
    }
    
}

Rack::Rack(const Rack& r): name{r.name}, haveSpace{r.haveSpace} {

    shelfs = r.shelfs;
}

Rack::Rack(Rack&& r): name{r.name}, haveSpace{r.haveSpace}, shelfs{r.shelfs} {

    r.shelfs = Vector<Shelf>();
    r.name = 0;
    r.haveSpace = 0;
}
Rack& Rack::operator=(const Rack& r) {

    if (this != &r)
    {
        name = r.name;
        haveSpace = r.haveSpace;
        shelfs = r.shelfs;
    }
    return *this;
}

void Rack::spaceCheck() {

    int count = 0;
    for (int i = 0; i < shelfCapacity; i++)
    {
        count += (shelfs.getAt(i).isSFull()) ? count++ : 0;
    }
    haveSpace -= count;
}

bool Rack::isRFull() const { return haveSpace == 0; }
