#include <ArduinoJson.h>

const int ANALOG_INPUT_R = 5;
const int ANALOG_INPUT_G = 4;
const int ANALOG_INPUT_B = 3;

const int CMD_GET_COLOR = 1;

void setup() {
  Serial.begin( 9600 );
}

float convertToFloat(int param, int maxvalue){
  return param * maxvalue / 1023.0;
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    int incomingByte = Serial.read();
//    if(incomingByte == CMD_GET_COLOR){
      int r = analogRead( ANALOG_INPUT_R );
      int g = analogRead( ANALOG_INPUT_G );
      int b = analogRead( ANALOG_INPUT_B );
    
      StaticJsonBuffer<200> jsonBuffer;
      JsonObject& root = jsonBuffer.createObject();
      root["r"] = convertToFloat(r, 1);
      root["g"] = convertToFloat(g, 1);
      root["b"] = convertToFloat(b, 1);
      root["receive"] = incomingByte;
    
      root.printTo(Serial);
      Serial.println();
//    }
  }

}

