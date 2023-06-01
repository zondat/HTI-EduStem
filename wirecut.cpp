#include <bombsystem.h>

WireCut::WireCut(BombSystem* system) : State(system) {}
    
void WireCut::cutRedWire() {
  this->owner->setCurrentState(this->owner->explosionState);
  this->owner->triggerExplosion();
}

void WireCut::cutBlueWire() {
  this->owner->setCurrentState(this->owner->explosionState);
  this->owner->triggerExplosion();
}

void WireCut::cutBlackWire() {
  this->owner->setCurrentState(this->owner->explosionState);
  this->owner->triggerExplosion();
}

void WireCut::cutYellowWire() {
  this->owner->setCurrentState(this->owner->explosionState);
  this->owner->triggerExplosion();
}

String WireCut::toString() {
  return "";
}

RedWireCut::RedWireCut(BombSystem* owner) : WireCut(owner) {}

void RedWireCut::cutBlueWire() {
  this->owner->setCurrentState(this->owner->blueWireCutState);
}

String RedWireCut::toString() {
  return "Red wire";
}  

BlueWireCut::BlueWireCut(BombSystem* owner) : WireCut(owner) {}

void BlueWireCut::cutYellowWire() {
  this->owner->setCurrentState(this->owner->yellowWireCutState);
}

String BlueWireCut::toString() {
  return "Blue wire";
}  

YellowWireCut::YellowWireCut(BombSystem* owner) : WireCut(owner) {}

void YellowWireCut::cutBlackWire() {
  this->owner->setCurrentState(this->owner->finishState);
}

String YellowWireCut::toString() {
  return "Yellow wire";
}  

BlackWireCut::BlackWireCut(BombSystem* owner) : WireCut(owner) {}

String BlackWireCut::toString() {
  return "Black wire";
}  