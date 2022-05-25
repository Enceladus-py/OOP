//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Berat Dalsuna
//---Student Number: 150200002
//--------------------------//
#include <iostream>
#ifndef _H
#define _H
using namespace std;
class Robot {
	protected:
		static int unqID;
		string RobotName;
		const string RobotType;
		float speed; 
		int durability; 
		const int manufactureCost; 
		float maintenanceCost;
		bool canMove;
	
	public:
		Robot(const string, float, int, int, float);
		Robot(const string, float, int);
		virtual ~Robot() { cout << RobotName << ": Goodbye." << endl; };
		void operator = (Robot const&);
		virtual void showInfo() const;
		void setCanMove(bool);      
		bool getCanMove() const;     
		int getDurability() const;   
		float getMaintenanceCost() const;   
		int getManufactureCost() const;   
		string getType() const;
		string getName() const;
		void decreaseDurability();   
}; 

class Explorer: public Robot{
	private:
		static float totalExploredArea;
		static int totalNumberOfSeleniumArea;
		float exploredArea;
		bool detectedSelenium;
		
	public:
		friend class Miner;
		friend class CommandCenter;
		Explorer(const string, float, int);
		virtual ~Explorer(){};
		bool move() const;
		void explore();
		void operator = (Explorer const&);
		void showInfo() const;
};

class Miner: public Robot{
	private:
		static int totalGatheredSelenium;
		int gatheredSelenium;
		static int currentSelenium;
		
	public:
		Miner(string, float, int);
		virtual ~Miner() {};
		friend class CommandCenter;
		void showInfo() const;
		void mine();
		bool move() const;
		void operator = (Miner const&);

};


#endif