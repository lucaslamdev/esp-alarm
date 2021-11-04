
#include <Ultrasonic.h>
#include <SPI.h>
#include <MFRC522.h>

#define LED 16 // D0 Proprio led da placa
#define SDA_PIN 4      // D2
#define RST_PIN 2      // D4
#define MOSI 13        // D7
#define MISO 12        // D6
#define SCK 14         // D5
#define pino_trigger 0 // D3
#define pino_echo 5    // D1
#define porta_rele1 15 // D8
Ultrasonic ultrasonic(pino_trigger, pino_echo);
MFRC522 mfrc522(SDA_PIN, RST_PIN); // Create MFRC522 instance.

long distancia;

bool alarme_status = false;
bool disparo = false;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(porta_rele1, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  alarme_status = false;
  mfrc522.PCD_DumpVersionToSerial();
  delay(1000);
  Serial.println("Aproxime o seu cartao do leitor...");
}

void loop()
{

  if (mfrc522.PICC_IsNewCardPresent())
  {
    Serial.println("Cartão presente!");
    if (alarme_status == false)
    {
      alarme_status = true;
      Serial.println("Alarme ligado!");
      delay(2000);
    }
    else if (alarme_status == true)
    {
      alarme_status = false;
      Serial.println("Alarme desligado!");
      delay(1000);
    }
  }

  if (alarme_status == false)
  {
    rotinaAlarmeDesligado();
  }
  else
  {
    digitalWrite(LED, HIGH);
    disparo = rotinaAlarmeLigado();
  }
}

bool rotinaAlarmeLigado()
{
  digitalWrite(LED, HIGH);
  Serial.println("Alarme ligado.");
  delay(200);
  long medidas[10];
  for (int i = 0; i < 10; i++)
  {
    distancia = ultrasonic.Ranging(CM);
    Serial.print("Distância: ");
    Serial.println(distancia);
    delay(100);
    medidas[i] = distancia;
  }
  if (medidas[0] > 12 && medidas[1] > 12 && medidas[2] > 12 && medidas[3] > 12 && medidas[4] > 12 && medidas[5] > 12 && medidas[6] > 12 && medidas[7] > 12 && medidas[8] > 12 && medidas[9] > 12)
  {
    disparo = true;
    tocarAlarme();
    Serial.println("Disparo do alarme!");
  }
  return disparo;
}

void rotinaAlarmeDesligado()
{
  desligarAlarme();
  delay(1000);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
}

void tocarAlarme()
{
  delay(50);
  digitalWrite(porta_rele1, HIGH); //Liga rele 1
}

void desligarAlarme()
{
  digitalWrite(porta_rele1, LOW); //Desliga rele 1
}
