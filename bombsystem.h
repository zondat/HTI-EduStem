#include <serialmonitor.h>
#include <electricwire.h>
#include <wirecut.h>
#include <bomb.h>

class BombSystem {
  public:
	int countDownTime = 30; 
    Bomb *bomb = nullptr;
    ElectricWire *redWire = nullptr, *blueWire = nullptr, *yellowWire = nullptr, *blackWire = nullptr;
    //Displayer *displayer  = nullptr;
    State *currentState   = nullptr;

  public:
	BombSystem();
	
    virtual ~BombSystem() {
      //delete displayer;
      delete currentState;
      delete redWire;
      delete blueWire;
      delete blackWire;
      delete yellowWire;
      delete bomb;
    }

	Bomb* createBomb(int id);
	ElectricWire* createWire(EColor color);
	//State* createRedWireCutState();
	//State* createBlueWireCutState();
	//State* createYellowWireCutState();
	//State* createBlackWireCutState();
	//State* createIdleState();
	//State* createFinishState();
	//State* createExplosionState();
	
	State* getCurrentState();
	void setCurrentState(State* state);
	
	void updateTimeCountDown();
	void triggerExplosion();	
	void cutWire(EColor color);
	void displayMessage(String* mess);
	void displayMessage();
};