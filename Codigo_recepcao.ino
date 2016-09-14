//Programa: Comunicação RF - Emissor

#include <VirtualWire.h>

int pinLed = 6; // define o pino do led

int valor_recebido;
char char_RF_recebido[4];

void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT); // define o pino do led como saída.
  vw_set_rx_pin(7);// define o pino ligado ao pino DATA do receptor(rx)
  vw_setup(2000);// velocidade da comunicação(bits por segundo)
  vw_rx_start();// inicio da recpção
  Serial.println("Recebendo dados - aguarde...");

}
void loop() {

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf,&buflen)){
    
    int i;

      for(i = 0; i < buflen; i++){
        
        char_RF_recebido[i] = char(buf[i]);
        
        }

      char_RF_recebido[buflen] = '\0';

      valor_recebido = atoi(char_RF_recebido);

      Serial.print("Recebido: ");
      Serial.print(valor_recebido);

      if(valor_recebido == 1){
        
          digitalWrite(pinLed,true);
          Serial.println("Led Acesso - Dado Recebido.");
         
        }
    
    if(valor_recebido == 0){
      
        digitalWrite(pinLed, LOW);
        Serial.println("Led apagado - Dado não recebido");
      }
    
    }
}
