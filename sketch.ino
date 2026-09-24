/** App Info:
* BUTTON_1 => Silent SOS (BLUE)
* BUTTON_2 => Loud Alarm (RED)
*/

//Imports

// ESP Pins
const int BUTTON_1 = 4;
const int BUTTON_2 = 5;

const int RED_PIN = 27;
const int GREEN_PIN = 26;
const int BLUE_PIN =25;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  digitalWrite(GREEN_PIN, LOW); // don't need green for this
}


void loop() {  
  // read button states and match em with LED
  bool btn1Pressed = (digitalRead(BUTTON_1) == LOW);
  bool btn2Pressed = (digitalRead(BUTTON_2) == LOW);

  digitalWrite(BLUE_PIN, btn1Pressed ? HIGH : LOW);
  digitalWrite(RED_PIN,  btn2Pressed ? HIGH : LOW);

  // Print button states to serial monitor
  if (btn1Pressed) {
    Serial.println("Button 1: ON  | Button 2: OFF (LED: BLUE)");
  } 
  else if (btn2Pressed) {
    Serial.println("Button 1: OFF | Button 2: ON  (LED: RED)");
  } 
  else {
    Serial.println("Button 1: OFF | Button 2: OFF (LED: OFF)");
  }

  delay(1000); 
  
}
