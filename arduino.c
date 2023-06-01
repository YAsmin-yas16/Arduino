DSE
sensor de presença
#include<Servo.h>
Servo serv;
int led = 13;
int pir = 2;
int valor;
void setup(){
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(pir, INPUT);
serv.attach(5);
}
void loop(){
valor = digitalRead(pir);
if(valor == HIGH){
digitalWrite(13,HIGH);
serv.write(90);
delay(2000);
}else{
digitalWrite(led,LOW);
serv.write(0);
delay(2000);
}
delay(100);

}

sensor de umidade
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int cont = 0;
float tempMedia = 0;
float umidade;
float temperatura;
void setup()

{
Serial.begin(9600);
dht.begin();
}
void loop()
{
umidade = dht.readHumidity();
temperatura = dht.readTemperature();
if(cont == 5)(
cont = 0;
Serial.print("Média = ");
Serial.println(tempMedia/5);
tempMedia = 0;
)
else (
tempMedia += temperatura;
cont==;
)
delay(1000);
}

sensor de temperatura
const int LM35 = A0;
float temperatura;
int led_1 = 2;
int led_2 = 3;
int led_3 = 4;
int buzzer = 5;
float x = 0;
void setup(){
pinMode(led_1, OUTPUT);
pinMode(led_2, OUTPUT);
pinMode(led_3, OUTPUT);
pinMode(buzzer, OUTPUT);
}
void loop(){
float valor = analogRead(LM35);
float tensao = (valor/1024)*5;
float temperatura = (tensao-0.5)/0.01;
Serial.println(temperatura);
x = temperatura;
delay(1000);
if(x < 24){

digitalWrite(led_2, LOW);
digitalWrite(led_1, LOW);
digitalWrite(led_3, HIGH);
}
else if (x >= 25 & x <= 35){
noTone(buzzer);
digitalWrite(led_3, LOW);
digitalWrite(led_1, LOW);
digitalWrite(led_2, HIGH);
}
else if (x > 35){
digitalWrite(led_1, LOW);
digitalWrite(led_2, LOW);
digitalWrite(led_1, HIGH);
tone(buzzer,261);
delay(10);
}
}
Display 7 segmento
#include <LiquidCrystal.h>
const int rs = 3, en = 4, d3 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en , d3, d5, d6, d7);
byte trigger=6, echo=5;
int buzzer = 8, verde = 10, amarelo = 9, tempo = 100, freq = 0, time = 250;
float conversao, leitura, calcdist;
unsigned long millis1 = millis();
void setup()
{
pinMode(verde, OUTPUT);
pinMode(amarelo, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
lcd.begin(16, 2);
}
void pisca_led()
{
if (millis() - millis1 > time)
{
digitalWrite(verde, HIGH);
digitalWrite(amarelo, LOW);
}

else
{
digitalWrite(verde, LOW);
digitalWrite(amarelo, HIGH);
}
if ((millis() - millis1) > (2 * time))
{
millis1 = millis();
}
digitalWrite(verde, LOW);
digitalWrite(amarelo, LOW);
}
void distShort()
{
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Distance");
delay(1000);
lcd.setCursor(8, 1);
lcd.print(conversao);
delay(2000);
for(freq = 150; freq < 1800; freq += 1)
{
pisca_led();
tone(buzzer, freq, tempo);
delay(1);
}
for(freq = 1800; freq > 150; freq -= 1)
{
pisca_led();
tone(buzzer, freq, tempo);
delay(1);
}
lcd.clear();
}
void distLong(){
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Distance");
delay(1000);
lcd.setCursor(8, 1);
lcd.print(conversao);

delay(2000);
lcd.clear();
}
void loop(){
conversao = distancia();
Serial.print(conversao);
if(conversao < 50)
{
distShort();
}
else
{
distLong();
}
}
float distancia(){
digitalWrite(trigger, LOW);
delayMicroseconds(5);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
leitura = pulseIn(echo, HIGH);
calcdist = (leitura/2) * 0.0343;
if(calcdist >= 331)
{
calcdist = 0;
}
return calcdist;
}

ultrassonico
float cm, leitura, calculaDistancia;
byte trigger=4, echo=5;
void setup() {
pinMode(trigger, OUTPUT); // transmissor
pinMode(echo, INPUT); // receptor
Serial.begin(9600);
}
void loop() {
cm = distancia(); // em centímetros

Serial.print("Distancia em cm: ");
Serial.print(cm);
Serial.println(" cm");
delay(1000);
}
float distancia() {
digitalWrite(trigger, LOW); //corta sinal para "limpar o pino"
delayMicroseconds(5);
digitalWrite(trigger, HIGH); //envia um pulso para o sensor
delayMicroseconds(10);
digitalWrite(trigger, LOW); //desliga o pino para habilitar o que
recebe -
//echo
leitura = pulseIn(echo, HIGH); //calcula o tempo, em microssegundos, do
//pulso para ir e voltar
calculaDistancia= (leitura/2) * 0.0343; //divide por 2 porque conta ida
e
//volta
if (calculaDistancia<=5)
{
Serial.print("Buraco razo ");
}
if (calculaDistancia>5 & calculaDistancia<=10)
{
Serial.print("Buraco normal ");
}
if (calculaDistancia>10)
{
Serial.print("Buraco fundo ");
}
return calculaDistancia;
}
buzzer
void setup() {
// put your setup code here, to run once
pinMode(11,OUTPUT);
}
void loop() {
digitalWrite(11,HIGH);
delay(1000);
digitalWrite(11,LOW);
delay(1000);

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466

#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define PAUSE 0
}

servo motor
#include<Servo.h>

Servo mm;
void setup() {
mm.attach(3);
pinMode(13,OUTPUT);
}
void loop() {
Serial.println(analogRead(A1));
mm.write(map (analogRead(A1),0,1023,1, 180));

}
potenciometro
int led = 3;
void setup()
{
Serial.begin(9600);
pinMode(led,OUTPUT);
}
void loop()
{
digitalWrite(led, map(analogRead(A1), 0 , 1023, 0 ,255));
delay(30);
}