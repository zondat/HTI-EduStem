// #include <Arduino_FreeRTOS.h>
// #include <semphr.h>
#include <bombsystem.h>

/******* Hardware Setup *******/
#define BLUE_WIRE A0
#define RED_WIRE A1
#define BLACK_WIRE A2
#define YELLOW_WIRE A3

/*****************************/
// SemaphoreHandle_t mutex;
volatile BombSystem *bombSystem = nullptr;

// Callbacks
void cutRedWire() {
  bombSystem->cutWire(EColor::RED);
}

void cutBlueWire() {
  bombSystem->cutWire(EColor::BLUE);
}

void cutBlackWire() {
  bombSystem->cutWire(EColor::BLACK);
}

void cutYellowWire() {
  bombSystem->cutWire(EColor::YELLOW);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Init serial");


  bombSystem = new BombSystem(); 
  Serial.println("Died here");
  bombSystem->createBomb(0);

  // Init wires
  bombSystem->createWire(EColor::RED);
  bombSystem->createWire(EColor::BLUE);
  bombSystem->createWire(EColor::YELLOW);
  bombSystem->createWire(EColor::BLACK);

  // Init states
  // State* idle = bombSystem->createIdleState();
  // State* redWireCutState = bombSystem->createRedWireCutState();
  // State* blueWireCutState = bombSystem->createBlueWireCutState();
  // State* blackWireCutState = bombSystem->createBlackWireCutState();
  // State* yellowWireCutState = bombSystem->createYellowWireCutState();  
  // State* explosionState = bombSystem->createExplosionState();
  // bombSystem->setCurrentState(idle);
  
  // // Set prefered next-states
  // idle->addExpectedNextState(redWireCutState);
  // redWireCutState->addExpectedNextState(blueWireCutState);
  // blueWireCutState->addExpectedNextState(yellowWireCutState);
  // yellowWireCutState->addExpectedNextState(blackWireCutState);

  // bombSystem->displayMessage();

  // Hardware setup
  pinMode(BLUE_WIRE, INPUT);
  digitalWrite(BLUE_WIRE, LOW);
  pinMode(RED_WIRE, INPUT);
  digitalWrite(RED_WIRE, LOW);
  pinMode(BLACK_WIRE, INPUT);
  digitalWrite(BLACK_WIRE, LOW);
  pinMode(YELLOW_WIRE, INPUT);
  digitalWrite(YELLOW_WIRE, LOW);

  // External Interrupt setup
  attachInterrupt(digitalPinToInterrupt(BLUE_WIRE), cutBlueWire, RISING); 
  attachInterrupt(digitalPinToInterrupt(RED_WIRE), cutRedWire, RISING); 
  attachInterrupt(digitalPinToInterrupt(BLACK_WIRE), cutBlackWire, RISING); 
  attachInterrupt(digitalPinToInterrupt(YELLOW_WIRE), cutYellowWire, RISING); 

    // Initiate Bomber system
  
  pinMode(bombSystem->bomb->TRIGGER_PIN, OUTPUT);
}

void loop() {
  delay(1000);
  bombSystem->updateTimeCountDown();
  Serial.println("Time: " + String(bombSystem->countDownTime) + "s");
}
