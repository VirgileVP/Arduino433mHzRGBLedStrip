#include <VirtualWire.h>
 
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
 
void setup()
{
    Serial.begin(9600);
    vw_setup(2000);
    vw_rx_start();
}
 
void loop()
{
    if (vw_wait_rx_max(200))
    {
        if (vw_get_message(buf, &buflen))
        {
            Serial.print("Receiving : ");
            for (byte i = 0; i < buflen; i++)
            {
                Serial.print(buf[i]- '0');
            }
            Serial.println("");
        }
        Serial.print("\nDone\n");
    }
}