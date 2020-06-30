#include <VirtualWire.h>

#define PIN_RED 3
#define PIN_GREEN 5
#define PIN_BLUE 11

int pot_values[3] = {0, 0, 0};

void setup()
{
    Serial.begin(9600);    
    vw_setup(2000);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    vw_set_rx_pin(7);
    vw_rx_start();
}

void loop()
{
    byte receive_size = sizeof(pot_values);
    vw_wait_rx();
    if (vw_get_message((byte *) &pot_values, &receive_size))
    {
       pot_values[0] = map(pot_values[0], 0, 1024, 0, 255);
       pot_values[1] = map(pot_values[1], 0, 1024, 0, 255);
       pot_values[2] = map(pot_values[2], 0, 1024, 0, 255);
       Serial.print("Receiving ...\n");
       Serial.print("R : ");
       Serial.print(pot_values[0]);
       Serial.print(" G : ");
       Serial.print(pot_values[1]);
       Serial.print(" B : ");
       Serial.print(pot_values[2]);
       Serial.print("\n");
       analogWrite(PIN_RED, pot_values[0]);
       analogWrite(PIN_GREEN, pot_values[1]);
       analogWrite(PIN_BLUE, pot_values[2]);
    }
}