#include <iostream>
#include "Robot.h"
using namespace std;
class Crew{
	private:
		int maxExplorers;
		int maxMiners;
		int crewManufactureCost;
		float crewMaintenanceCost;
		int explorerCrewSize;
		int minerCrewSize;
		//Pointer arrays for explorers and miners.
		Explorer **ExplorerCrew; 
		Miner **MinerCrew;
		
	public:
		Crew(int, int, int, int);
		~Crew();
		friend class CommandCenter;
		Robot* manufactureRobot(string s="def"); //default parameter, if it is equal to def, it asks user to enter a type.
		void initMovement();
		void updateDurability();
		void operator+=(Robot* const);
		void operator-=(const string);
		void showInfo() const;
		int getExplorerCrewSize() const;
		int getMinerCrewSize() const;
		Explorer** getExplorers() const;
		Miner** getMiners() const;
		float getCrewMaintenanceCost() const;
		void setCrewMaintenanceCost(float);
		void shiftCrew(string); //shifts elements to left, called in operator-= function
};

class CommandCenter{
	private:
		const int neededSelenium;
		const float searchArea;
		const int seleniumWorth;
		int turnCount;
		float totalCrewMaintenanceCost;
		int totalCrewManufactureCost;
		float profit;
	public:
		CommandCenter(const int, const float, const int);
		bool isGameEnded() const;
		void calculateProfit(const Crew&);
		void operator++();
		void showInfo() const;

};



