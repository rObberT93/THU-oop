#pragma once

#include "Footman.h"
#include "Commander.h"
#include "Belong.h"
#include "Casern.h"
using namespace std;

class HumanFootman :  public Footman {
public:
    //TODO
    using Footman::Footman;
};

class OrcFootman :  public Footman {
public:
    //TODO
    using Footman::Footman;
};

class HumanCommander :  public Commander {
public:
    //TODO
    using Commander::Commander;
};

class OrcCommander :  public Commander {
public:
    //TODO
    using Commander::Commander;
};

class HumanBelong :  public Belong {
public:
    //TODO
    using Belong::Belong;
};

class OrcBelong :  public Belong {
public:
    //TODO
    using Belong::Belong;

};

class HumanCasern : public Casern {
     //TODO
    virtual string getKind() { return "HumanCasern"; }

};

class OrcCasern : public Casern {
    virtual string getKind() { return "OrcCasern"; }
};
