#include <displayer.h>

class SerialMonitor : public Displayer {
  
  public: 
	SerialMonitor() : Displayer() {
	  //initDisplayer();
	}

    void initDisplayer() override {
	  if (!Serial) Serial.begin(9600);
	  Serial.println("Init displayer");
	  Serial.println("Init displayer");
	  Serial.println("Init displayer");
    }

    void displayMessage(String* messages)  override {
      Serial.println(messages[0]);
	  Serial.println(messages[1]);
	  Serial.println(messages[2]);
	  Serial.println(messages[3]);
    }
};