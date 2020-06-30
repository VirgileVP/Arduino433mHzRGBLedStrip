#include <VirtualWire.h>

#define PIN_TX 5

#define PIN_POT0 0
#define PIN_POT1 1
#define PIN_POT2 2

int     pin_pot[3] = {PIN_POT0, PIN_POT1, PIN_POT2};
int     pot_values[3] = {0, 0, 0};
int     value_changed = 0;

void setup()
{
    Serial.begin(9600);
    vw_set_tx_pin(PIN_TX);
    vw_setup(2000);
}
 
void loop()
{
    Read_Pottard();
    if (value_changed)
    {
        vw_send((byte *) &pot_values, sizeof(pot_values));
        vw_wait_tx();
        Serial.print("Send ");
        Serial.print(pot_values[0]);
        Serial.print(" | ");
        Serial.print(pot_values[1]);
        Serial.print(" | ");
        Serial.print(pot_values[2]);
        Serial.print("\n");
        Serial.print("Sended ");
        Serial.print(map(pot_values[0], 0, 1024, 0, 255));
        Serial.print(" | ");
        Serial.print(map(pot_values[1], 0, 1024, 0, 255));
        Serial.print(" | ");
        Serial.print(map(pot_values[2], 0, 1024, 0, 255));
        Serial.print("\n\n\n");
        value_changed = 0;
    }
    delay(100);
}

void Read_Pottard()
{
    int index = 0;
    int tmp[3];

    value_changed = 0;
    while (index < 3)
    {
        tmp[index] = analogRead(pin_pot[index]);
        if (Value_changed_or_not(tmp[index], pot_values[index]) == 1)
        {
            pot_values[index] = tmp[index];
            value_changed = 1;
        }
        index++;
    }
}

int  Value_changed_or_not(int readed, int actual)
{
    if (readed == actual || readed == actual - 1 || readed == actual + 1)
      return (0);
    return (1);
}
