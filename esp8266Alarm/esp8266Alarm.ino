

void setup() 
{
    // Instrução para colocar o gpio que iremos utilizar como entrada,
    // podemos fazer a leitura nesse pino
    pinMode(D1, INPUT); // D1 é uma constante que indica o pino que ligamos nosso botão

    // Instrução para colocar o gpio que iremos utilizar como saída,
    // podemos alterar seu valor livremente para HIGH ou LOW
    pinMode(LED_BUILTIN, OUTPUT); // LED_BUILTIN é uma constante que indica o LED do ESP8266
} 

void loop() 
{
    // faz a leitura do pino D1 (no nosso caso, o botão está ligado nesse pino)
    byte valor = digitalRead(D1); 
    // checa se o botão está pressionado
    if(valor == HIGH) {         
       digitalWrite(LED_BUILTIN, LOW);  // Acende o LED   pino  16
    } 
   else {
       digitalWrite(LED_BUILTIN, HIGH);  // Apaga o LED
    }
}
