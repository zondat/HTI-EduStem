#include <bombsystem.h>

State::State() {  
  messages[0] = this->toString() + " is cut!";
  messages[1] = "Cut next wire:";

  String mess = "";
  for (State* nextState : this->preferedNextStates) {
	mess += nextState->toString() + " ";
  }
  messages[2] = mess;
  //messages[3] = "Time: " + String(owner->countDownTime);
}
	
void State::addExpectedNextState(State* nextState) {
  this->preferedNextStates[nbpreferedNextStates++] = nextState;
}

State* State::timeout() {
  return new Explosion();
}

void State::copyProp(State* newInstance) {
  newInstance->preferedNextStates = this->preferedNextStates;
}

/****** Idle *******/
Idle::Idle() {
  messages[0] = "Rescue hostages!";
  messages[1] = "Instruction:";
  messages[2] = "Cut the ElectricWire:";

  String mess = "";
  for (State* nextState : this->preferedNextStates) {
	mess += nextState->toString() + " ";
  }
  messages[3] = mess;
}

State* Idle::cutRedWire() {
  State* newState = new RedWireCut();
  newState->addExpectedNextState(new RedWireCut());
  return newState;
}

String Idle::toString() {
  return "Idle";
}

/****** Finish *******/
Finish::Finish() {
  messages[0] = "";
  messages[1] = "  Congratulate!  ";
  messages[2] = "";
  messages[3] = "";
}

String Finish::toString() {
  return "Finish";
}    

/****** Explosion *******/
Explosion::Explosion() {
  messages[0] = "Too late, sorry";
  messages[1] = "  Boommm!  ";
  messages[2] = "";
  messages[3] = "";
}

String Explosion::toString() {
  return "Explosion";
}    


/********************** Wire Cut State ***************************/    
RedWireCut::RedWireCut() : WireCut() {}

State* RedWireCut::cutBlueWire() {
  State* newState = new BlueWireCut();
  newState->addExpectedNextState(new BlueWireCut());
  return newState;
}

String RedWireCut::toString() {
  return "Red wire";
}  

BlueWireCut::BlueWireCut() : WireCut() {}

State* BlueWireCut::cutYellowWire() {
  State* newState = new YellowWireCut();
  newState->addExpectedNextState(new YellowWireCut());
  return newState;
}

String BlueWireCut::toString() {
  return "Blue wire";
}  

YellowWireCut::YellowWireCut() : WireCut() {}

State* YellowWireCut::cutBlackWire() {
  State* newState = new Finish();
  newState->addExpectedNextState(new BlackWireCut());
  return newState;
}

String YellowWireCut::toString() {
  return "Yellow wire";
}  

BlackWireCut::BlackWireCut() : WireCut() {}

String BlackWireCut::toString() {
  return "Black wire";
}  