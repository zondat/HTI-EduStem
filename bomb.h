#include <Arduino.h>
class Bomb {
  public:
    int id;
	int TRIGGER_PIN = 10;

    Bomb() {}
    Bomb(int id) {
      this->id = id;
    }
	Bomb(int id, int pin) : Bomb(id) {
      this->TRIGGER_PIN = pin;
    }

    void explode() {
      digitalWrite(TRIGGER_PIN, HIGH);
    }

    virtual ~Bomb(){}
};