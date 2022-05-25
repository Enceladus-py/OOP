//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Berat Dalsuna
//---Student Number: 150200002
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------//
#include "CommandCenter.h"
#include "Robot.h"
#include <iostream>
using namespace std;
/*
****************
BEGIN: CREW CLASS FUNCTION DECLARATIONS 
****************
*/
Crew::Crew(int maxexp, int maxmin, int expsize, int minsize){ //Constructor for Crew Class

    //Sets 2 if input is incorrect
    if(maxexp<1 || maxexp>5)
        maxExplorers = 2;
    else if(maxexp>0 && maxexp<6)
        maxExplorers = maxexp;
    if(maxmin<1 || maxmin>5)
        maxMiners = 2;
    else if(maxmin>0 && maxmin<6)
        maxMiners = maxmin;

    if(expsize>0 && expsize<=maxExplorers)
        explorerCrewSize = expsize;
    else if (expsize<0 || expsize>maxExplorers) explorerCrewSize = maxExplorers;

    if(minsize>0 && minsize<=maxMiners)
        minerCrewSize = minsize;
    else if (minsize<0 || minsize>maxMiners) minerCrewSize = maxMiners;

    crewMaintenanceCost = 0;
    crewManufactureCost = 0;

    // uniqueID increases every time manufactureRobot is called.
    // Sets the elements NULL after the max limit is reached.
    ExplorerCrew = new Explorer*[maxExplorers];
    for(int i=0;i<maxExplorers;i++){
        if(i<explorerCrewSize){
            ExplorerCrew[i] = static_cast<Explorer*>(manufactureRobot("explorer"));
            ExplorerCrew[i]->setCanMove(true);
            crewManufactureCost += ExplorerCrew[i]->getManufactureCost();
        }
        else if(i>=explorerCrewSize){
            ExplorerCrew[i] = NULL;
        }
    } 

    MinerCrew = new Miner*[maxMiners]; 
    for(int i=0;i<maxMiners;i++){
        if(i<minerCrewSize){
            MinerCrew[i] = static_cast<Miner*>(manufactureRobot("miner"));
            MinerCrew[i]->setCanMove(true);
            crewManufactureCost += MinerCrew[i]->getManufactureCost();
        }
        else if(i>=minerCrewSize){
            MinerCrew[i] = NULL;
        }
    } 
    
}

Crew::~Crew(){ //Destructor for the Crew.
    for(int i=0;i<maxExplorers;i++){
        delete ExplorerCrew[i];
    }
    for(int i=0;i<maxMiners;i++){
        delete MinerCrew[i];
    }
    delete[] ExplorerCrew;
    delete[] MinerCrew;
}

Robot* Crew::manufactureRobot(string type){

    if(type=="def"){
        cout << "Type: ";
        cin >> type;
    }

    int n1 = 1 + (rand() % 5);
    if(type=="explorer" && explorerCrewSize<=maxExplorers){
        float n2 = 1.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1.5)));
        return new Explorer("exp", n2, n1);
    }
    else if(type=="miner" && minerCrewSize<=maxMiners){
        float n3 = 1.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-1.0)));
        return new Miner("mnr", n3, n1);
    }

    return NULL;

}

void Crew::initMovement(){
    for(int i=0;i<explorerCrewSize;i++){
        ExplorerCrew[i]->setCanMove(true);
    }
    for(int i=0;i<minerCrewSize;i++){
        MinerCrew[i]->setCanMove(true);
    }
}

void Crew::updateDurability(){
    for(int i=0;i<explorerCrewSize;i++){

        if(ExplorerCrew[i]->getDurability() != 1){
            ExplorerCrew[i]->decreaseDurability();
        }
        else{
            this->operator-=(ExplorerCrew[i]->getName());
        }
         
    }

    for(int i=0;i<minerCrewSize;i++){

        if(MinerCrew[i]->getDurability() != 1){
            MinerCrew[i]->decreaseDurability();
        }
        else{
            this->operator-=(MinerCrew[i]->getName());
        }

    }
}

void Crew::operator+=(Robot* const r){ 

    // static_cast() for converting robot pointer to derived class pointer.

    if(r->getType()=="exp" && explorerCrewSize<maxExplorers){
        ExplorerCrew[explorerCrewSize] = static_cast<Explorer*>(r);
        crewManufactureCost += ExplorerCrew[explorerCrewSize]->getManufactureCost();
        explorerCrewSize++;
        return;
    }
    else if(r->getType()=="exp" && explorerCrewSize>=maxExplorers){
        cout << "This robot cannot be added, check maximum size of the crew." << endl;
        delete r;
        return;
    }

    if(r->getType()=="mnr" && minerCrewSize<maxMiners){
        MinerCrew[minerCrewSize] = static_cast<Miner*>(r);
        crewManufactureCost += MinerCrew[minerCrewSize]->getManufactureCost();
        minerCrewSize++;
        return;
    }
    else if(r->getType()=="mnr" && minerCrewSize>=maxMiners){
        cout << "This robot cannot be added, check maximum size of the crew." << endl;
        return;
    }

}

void Crew::operator-=(const string name){ 

    for(int i=0;i<explorerCrewSize;i++){
        if(ExplorerCrew[i]->getName() == name){
            if(explorerCrewSize != 1){
                delete ExplorerCrew[i];
                ExplorerCrew[i] = NULL;
                shiftCrew("exp");
                explorerCrewSize--;
            }
            else{
                cout << name << ": " << "Goodbye." << endl;
            }
            return;
        }
        
    }

    for(int i=0;i<maxMiners;i++){
        if(MinerCrew[i] != NULL){
            if(MinerCrew[i]->getName() == name){
                if(minerCrewSize != 1){
                    delete MinerCrew[i];
                    MinerCrew[i] = NULL;
                    shiftCrew("mnr");
                    minerCrewSize--;
                }  
                else{
                    cout << name << ": " << "Goodbye." << endl;
                }
                return;
            }
        }
    }

}

void Crew::shiftCrew(string s){ //Shifts the crew to left after the deletion operation. Sets NULL other elements.

    if(s=="exp"){
        for(int i=0;i<explorerCrewSize-1;i++){
            if(ExplorerCrew[i]==NULL){
                ExplorerCrew[i] = ExplorerCrew[i+1];
                ExplorerCrew[i+1] = NULL;
            }
        }
        return;
    }

    else if(s=="mnr"){
        for(int i=0;i<minerCrewSize-1;i++){
            if(MinerCrew[i]==NULL){
                MinerCrew[i] = MinerCrew[i+1];
                MinerCrew[i+1] = NULL;
            }
        }
        return;
    }
}

void Crew::showInfo() const{

    cout << "explorerCrew Size:" << explorerCrewSize << endl;
    cout << "minerCrew Size:" << minerCrewSize << endl;
    for(int i=0;i<explorerCrewSize;i++){
        ExplorerCrew[i]->showInfo();
    }
    for(int i=0;i<minerCrewSize;i++){
        MinerCrew[i]->showInfo();
    }
    cout << "Total manufacture cost: " << crewManufactureCost << endl;
    cout << "Total maintenance cost: " << crewMaintenanceCost << endl;

}

int Crew::getExplorerCrewSize() const{
    return explorerCrewSize;
}

int Crew::getMinerCrewSize() const{
    return minerCrewSize;
}

Explorer** Crew::getExplorers() const{
    return ExplorerCrew;
}

Miner** Crew::getMiners() const{
    return MinerCrew;
}

float Crew::getCrewMaintenanceCost() const{
    return crewMaintenanceCost;
}

void Crew::setCrewMaintenanceCost(float x){
    crewMaintenanceCost = x;
}
/*
****************
END: CREW CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/

CommandCenter::CommandCenter(int needse, float search, int selworth) : neededSelenium(needse), searchArea(search), seleniumWorth(selworth){
    turnCount = 0;
    totalCrewMaintenanceCost = 0;
    totalCrewManufactureCost = 0;
    profit = 0;
}

bool CommandCenter::isGameEnded() const{
    if(Explorer::totalExploredArea >= searchArea){
        if(profit>0 && neededSelenium <= Miner::totalGatheredSelenium){
            cout << "Congrats!" << endl;
            return true;
        }
        cout << "Mission Failed!" << endl;
        return true;
    }
    return false;
}


void CommandCenter::calculateProfit(const Crew& c){

    for(int i=0;i<c.explorerCrewSize;i++){
        totalCrewMaintenanceCost += c.ExplorerCrew[i]->maintenanceCost;
        totalCrewManufactureCost += c.ExplorerCrew[i]->manufactureCost;
    }

    for(int i=0;i<c.minerCrewSize;i++){
        totalCrewMaintenanceCost += c.MinerCrew[i]->maintenanceCost;
        totalCrewManufactureCost += c.MinerCrew[i]->manufactureCost;
    }

    profit = (Miner::totalGatheredSelenium*seleniumWorth) - (c.crewMaintenanceCost + c.crewManufactureCost);
    cout << "Profit:" << profit << endl;
    cout << "Expenses:" << c.crewMaintenanceCost + c.crewManufactureCost << endl;
    cout << "Selenium Revenue:" << Miner::totalGatheredSelenium*seleniumWorth << endl;
}

void CommandCenter::operator++(){
    turnCount++;
}

void CommandCenter::showInfo() const{

    cout << "Current turn: " << turnCount + 1 << endl;
    cout << "Aim: " << neededSelenium << " selenium." << endl;
    cout << "Collected: " << Miner::totalGatheredSelenium << endl;
    cout << "Total Search Area: " << searchArea << endl;
    cout << "Total Explored Area: " << Explorer::totalExploredArea << endl;
    cout << "Currently, there are " << Explorer::totalNumberOfSeleniumArea << " area/s that include selenium." << endl;
}
/*
****************
END: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/