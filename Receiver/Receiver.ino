#include <VirtualWire.h> // import de la librairie VirtualWire
 
int RF_TX_PIN = 12; // Data Connecté à la pin 2 de l'arduino
 
void setup()
{
  vw_set_tx_pin(RF_TX_PIN);
  vw_setup(2000); // Vitesse de transmission en Bits par secondes
}
 
void loop()
{
  const char *msg = "Hello World !!"; // Message a envoyer
  vw_send((uint8_t *)msg, strlen(msg));  // Envoi le message ...
  delay(400); // ... toute les 400 millisecondes
 
}
