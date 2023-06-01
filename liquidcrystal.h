#include <displayer.h>

class LiquidCrystal : public Displayer {
  public:
    LiquidCrystal_I2C* lcd;  
    
  public: 
	LiquidCrystal() : Displayer() {
	  initDisplayer();
	}

    virtual ~LiquidCrystal() {
      delete lcd;
    }

    void initDisplayer() override {
      lcd = new LiquidCrystal_I2C(0x27, 16, 4);
      lcd->init();
      lcd->setBacklight(true); 
    }

    void displayMessage(String* messages)  override {
      lcd->setCursor(0, 0);
      lcd->print(messages[0]);
      lcd->setCursor(0, 1);
      lcd->print(messages[1]);
      lcd->setCursor(16, 0);
      lcd->print(messages[2]);
      lcd->setCursor(16, 1); 
      lcd->print(messages[3]);      
    }
};