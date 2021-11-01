static const int esp8266Led = 02; // é uma constante que indica o LED do ESP8266
static const int rele1 = 05, rele2 = 04;

void setup()
{
  pinMode(esp8266Led, OUTPUT); 
}

void loop()
{
  digitalWrite(esp8266Led, LOW);  
  delay(500);
  digitalWrite(esp8266Led, HIGH);
  delay(500);
}

void tocarAlarme()
{
  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
}


void desligarAlarme()
{
  digitalWrite(rele1, LOW);
  digitalWrite(rele2, LOW);
}