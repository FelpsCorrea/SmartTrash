#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define LED_PIN 13
void setup() {
 // Definir o pino do Trigger como saída
 pinMode(TRIGGER_PIN, OUTPUT);
 
 // Definir o pino do Echo como entrada
 pinMode(ECHO_PIN, INPUT);
 
 // Definir o pino do LED como saída
 pinMode(LED_PIN, OUTPUT);
 
 Serial.begin(9600); // Iniciar a comunicação serial
}
void loop() {
 // Começar com o Trigger em nível baixo
 digitalWrite(TRIGGER_PIN, LOW);
 
 // Aguardar 2 microssegundos
 delayMicroseconds(2);
 
 // Enviar um pulso de 10 microssegundos no Trigger
 digitalWrite(TRIGGER_PIN, HIGH);
 
 // Aguardar 10 microssegundos
 delayMicroseconds(10);
 
 // Retornar o Trigger para nível baixo
 digitalWrite(TRIGGER_PIN, LOW);
 // Medir o tempo que o pulso no Echo fica em nível alto
 long duration = pulseIn(ECHO_PIN, HIGH);
 
 /*
 Calcular a distância em cm.
 
 A velocidade do som no ar é de aproximadamente 340 metros por segundo, 
 ou 0.034 centímetros por microssegundo.
 
 O pino ECHO fica em alta tensão calculando o tempo que o pulso ultrassom leva para 
retornar ao sensor.
 Devido a esse tempo considerar a ida e a volta do pulso,
 divide-se por 2 para obter a distância do objeto até o sensor.
 */
 float distance = duration * 0.034 / 2; 
 /* Caso a distância seja menor que 10cm,
 significa que há um objeto próximo da borda da lixeira,
 considerando que o sensor ficaria no topo dela.
 Assim, acende o led para demonstrar que a lixeira está cheia
 O que poderia ser substituído por uma chamada para o setor de limpeza.
 */
 if (distance < 10) { // Se a distância for menor que 10 cm
 digitalWrite(LED_PIN, HIGH); // Acender o LED
 } else {
 digitalWrite(LED_PIN, LOW); // Apagar o LED
 }
 delay(1000); // Aguardar 1 segundo antes de fazer a próxima leitura
}
