#include <Arduino.h>

class BombSystem;
class State {
  public:
    const static int MAX_STATES = 3;
    int nbpreferedNextStates = 0;
    State* preferedNextStates[MAX_STATES];
	String messages[4];
  
  public:
    State();

    virtual ~State() {
      for (int i=nbpreferedNextStates-1; i>=0; i++) {
        delete preferedNextStates[i];
      }
      delete preferedNextStates;
    }

    void addExpectedNextState(State* nextState);
    //virtual void getMessage(String* messages);
    virtual State* cutRedWire() { return new Explosion();}
    virtual State* cutBlueWire() { return new Explosion();}
    virtual State* cutBlackWire() { return new Explosion();}
    virtual State* cutYellowWire() { return new Explosion();}
    virtual String toString() {return "";};
	State* timeout();
	void copyProp(State* newInstance);
};

class Idle : public State {
  public:    
    Idle();
    State* cutRedWire() override;
    String toString() override;
};

class Finish : public State {
  public:
    String toString() override;  
    //void getMessage(String* messages) override;
};

class Explosion : public State {
  public:
    String toString() override;  
    //void getMessage(String* messages) override;
};


class WireCut : public State {
  public:
	WireCut() : State() {}
};

class RedWireCut : public WireCut {
  public:
    RedWireCut();
    State* cutBlueWire() override;
    String toString() override;
};

class BlueWireCut : public WireCut {
  public:
    BlueWireCut();
    State* cutYellowWire() override;
    String toString() override;
};

class YellowWireCut : public WireCut {
  public:
    YellowWireCut();
    State* cutBlackWire() override;
    String toString() override;
};

class BlackWireCut : public WireCut {
  public:
    BlackWireCut();
    String toString() override;
};