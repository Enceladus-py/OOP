//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Berat Dalsuna
//---Student Number: 150200002
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------/

#include <iostream>
using namespace std;
#include "Robot.h"



/*
****************
BEGIN: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/
int Robot::unqID = 1;

Robot::Robot(const string type, float sp, int dub, int manucost, float maincost) : RobotType(type), manufactureCost(manucost){
    RobotName = type + "-" + to_string(Robot::unqID); 
    Robot::unqID++;
    speed = sp;
    durability = dub;
    maintenanceCost = maincost;
    canMove = true;
}

// Constructor for explorer and miner class
// Sets manufacture cost to 3000 if type = explorer
Robot::Robot(const string type, float sp, int dub) : RobotType(type), manufactureCost(type == "exp" ? 3000:5000){ 
    RobotName = type + "-" + to_string(unqID); 
    unqID++;
    speed = sp;
    durability = dub;
    canMove = false;
}

void Robot::operator = (Robot const& r){
    RobotName = r.RobotName;
    speed = r.speed;
    durability = r.durability;
    maintenanceCost = r.maintenanceCost;
}

void Robot::showInfo() const{
    cout << "Name: " << RobotName << endl;
    cout << "Type: " << RobotType << endl;
    cout << "Speed: " << speed << endl;
    cout << "Durability: " << durability << endl;
    cout << "ManufactureCost: " << manufactureCost << endl;
    cout << "MaintenanceCost: " << maintenanceCost << endl;
    cout << "Can Move: " << canMove << endl;
}

//GETTERS AND SETTERS

bool Robot::getCanMove() const{
    return canMove;
}

void Robot::setCanMove(bool b){
    canMove = b;
}

int Robot::getDurability() const{
    return durability;
}

void Robot::decreaseDurability(){
    durability -= 1;
}

float Robot::getMaintenanceCost() const{
    return maintenanceCost;
}

int Robot::getManufactureCost() const{
    return manufactureCost;
}

string Robot::getType() const{
    return RobotType;
}

string Robot::getName() const{
    return RobotName;
}

/*
****************
END: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/
// Static variables
float Explorer::totalExploredArea = 0;
int Explorer::totalNumberOfSeleniumArea = 0;

Explorer::Explorer(string type, float sp, int dub):Robot(type, sp, dub){ //Default constructor
    maintenanceCost = 450/sp;
}

bool Explorer::move() const{
    return getCanMove();
}

void Explorer::explore(){ 
    int number = rand() % 101;

    if(number >= 40){
        detectedSelenium = true;
        totalNumberOfSeleniumArea++;
    }
    else detectedSelenium = false;

    totalExploredArea += 1500;
    exploredArea = 1500;
}

void Explorer::operator = (Explorer const& r){
    RobotName = r.RobotName;
    speed = r.speed;
    durability = r.durability;
    maintenanceCost = r.maintenanceCost;
    exploredArea = r.exploredArea;
    detectedSelenium = r.detectedSelenium;
}

void Explorer::showInfo() const{
    Robot::showInfo();
    cout << "explored area: " << exploredArea << endl;
}

/*
****************
END: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: MINER CLASS FUNCTION DECLARATIONS 
****************
*/
//Static variables
int Miner::totalGatheredSelenium = 0;
int Miner::currentSelenium = 0;

Miner::Miner(string type, float sp, int dub):Robot(type, sp, dub){ //Default constructor
    maintenanceCost = 750/sp;
    gatheredSelenium = 0;
}

void Miner::mine(){ 
    int number = (rand() % 91) + 10;
    gatheredSelenium = (number * 5);
    currentSelenium = (number * 5);
    Explorer::totalNumberOfSeleniumArea--;
    totalGatheredSelenium += gatheredSelenium;
}

bool Miner::move() const{
    if(canMove && Explorer::totalNumberOfSeleniumArea > 0)
        return true;
    return false;
}

void Miner::operator = (Miner const& r){
    RobotName = r.RobotName;
    speed = r.speed;
    durability = r.durability;
    maintenanceCost = r.maintenanceCost;
    gatheredSelenium = r.gatheredSelenium;
}

void Miner::showInfo() const{
    Robot::showInfo();
    cout << "# of gathered selenium: " << gatheredSelenium << endl;
}
/*
****************
END: MINER CLASS FUNCTION DECLARATIONS 
****************
*/

