#include <bombsystem.h>

BombSystem::BombSystem() {
 
  // Create bombes
  createBomb(0);

  // Init wires
  createWire(EColor::RED);
  createWire(EColor::BLUE);
  createWire(EColor::YELLOW);
  createWire(EColor::BLACK);

  // Init states
  currentState = new Idle();

  // Set prefered next-states
  //idle->addExpectedNextState(redWireCutState);
  //redWireCutState->addExpectedNextState(blueWireCutState);
  //blueWireCutState->addExpectedNextState(yellowWireCutState);
  //yellowWireCutState->addExpectedNextState(blackWireCutState);
  
  // Display current state's instructions
  displayMessage();
}

void BombSystem::displayMessage(String* mess) {
	
	//displayer->displayMessage(mess);
	Serial.println(mess[0]);
	Serial.println(mess[1]);
	Serial.println(mess[2]);
	Serial.println(mess[3]);
}

void BombSystem::displayMessage() {
  displayMessage(currentState->messages);
}

void BombSystem::triggerExplosion() {
  bomb->explode();
}

Bomb* BombSystem::createBomb(int id) {
  bomb = new Bomb(id);
  return bomb;
}

ElectricWire* BombSystem::createWire(EColor color) {
  ElectricWire* wire = new ElectricWire(color);
  return wire;
}

//State* BombSystem::createRedWireCutState() {
//  redWireCutState = new RedWireCut(this);
//  return redWireCutState;
//}

//State* BombSystem::createBlueWireCutState() {
//  blueWireCutState = new BlueWireCut(this);
//  return blueWireCutState;
//}

//State* BombSystem::createYellowWireCutState() {
//  yellowWireCutState = new YellowWireCut(this);
//  return yellowWireCutState;
//}

//State* BombSystem::createBlackWireCutState() {
//  blackWireCutState = new BlackWireCut(this);
//  return blackWireCutState;
//}

//State* BombSystem::createIdleState() {
//  idle = new Idle(this);
//  return idle;
//}

//State* BombSystem::createFinishState() {
//  finishState = new Finish(this);
//  return finishState;
//}

//State* BombSystem::createExplosionState() {
//  explosionState = new Explosion(this);
//  return explosionState;
//}
	
void BombSystem::setCurrentState(State* state) {
  this->currentState = state;
}

State* BombSystem::getCurrentState() {
  return this->currentState;
}

void BombSystem::cutWire(EColor color) {
  if (color == EColor::RED) {
	currentState->cutRedWire();
  } 
  else if (color == EColor::BLUE) {
    currentState->cutBlueWire();
  }
  else if (color == EColor::BLACK) {
	currentState->cutBlackWire();
  }
  else if (color == EColor::YELLOW) {
	currentState->cutYellowWire();
  }
  
  displayMessage();
  if (dynamic_cast<Explosion*>(currentState)) {
	 triggerExplosion();
  } 
}

void BombSystem::updateTimeCountDown() {
  countDownTime --;
  if (countDownTime <= 0) {
	  currentState->timeout();
	  displayMessage();
  }
}