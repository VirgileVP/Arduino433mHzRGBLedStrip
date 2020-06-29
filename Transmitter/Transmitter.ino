#include <VirtualWire.h>
 
const char *msg = "Hello World !!";
 
void setup()
{
    Serial.begin(9600);
    vw_setup(2000);
}
 
void loop()
{
    Serial.print("Transmission ...");
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    Serial.println("Done !");
    delay(500);
}