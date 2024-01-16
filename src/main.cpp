#include <Arduino.h>

#define TAST1 27
#define TAST2 23

#define DEBOUNCE_TIME_MS 500

volatile int tasteTryk1 = 0;
volatile int tasteTryk2 = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("hej fra setup");
  pinMode(27, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(TAST1, INPUT_PULLUP);
  pinMode(TAST2, INPUT_PULLUP);
}

void loop()
{
  // Check TAST1 button state
  if (digitalRead(TAST1) == LOW)
  {
    if (millis() - tasteTryk1 >= DEBOUNCE_TIME_MS)
    {
      Serial.print("X");
      tasteTryk1 = millis();
    }
  }

  // Check TAST2 button state
  if (digitalRead(TAST2) == LOW)
  {
    if (millis() - tasteTryk2 >= DEBOUNCE_TIME_MS)
    {
      Serial.print("Y");
      tasteTryk2 = millis();
    }
  }
}
