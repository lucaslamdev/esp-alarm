int esp8266Led = 02; // é uma constante que indica o LED do ESP8266

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
