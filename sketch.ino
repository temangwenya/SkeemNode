
//Imports

// ESP Pins
const int BUTTON_1 = 4;
const int LED = 2; 
const int VALUE = digitalRead(BUTTON_1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, !digitalRead(BUTTON_1));

  //timer on
  //GPS on

  // if button is clicked
  /*if (BUTTON_1 == LOW) {
    digitalWrite(LED, HIGH);
  }*/
  
  
}

// When button is pushed, LED flashes
