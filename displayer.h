#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Displayer {
    
  public: 
    Displayer() {
      initDisplayer();
    }

    virtual ~Displayer() {}
    virtual void initDisplayer() {}
    virtual void displayMessage(String* messages){}
};