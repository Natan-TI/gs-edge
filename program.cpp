#include <Servo.h>
#include <LiquidCrystal.h>

Servo servoMotorObj;

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int temp = A0; // pino do sensor de temperatura
int porcem = A0; //pino para conversão da umidade para porcentagem
int potenciometro = A2; //pino da umidade do solo
int sensorPh = A1; //pino do sensor do ph
int sensorPir = 6; //pino do sensor de movimento
int vldr = A3;
int ldr = A3;
int const servoMotorPin = 9;  

void setup()
{
  servoMotorObj.attach(servoMotorPin); 
  lcd.begin(16,2);             
  lcd.clear();                  
  lcd.setCursor(0,0);    
  Serial.begin(9600);
  pinMode(temp, INPUT);
  pinMode(sensorPir, INPUT);
  pinMode(ldr, INPUT);
}

void loop()
{
  //-----------------LUMINOSIDADE--------------------
  //lendo o valor do potenciômetro (intervalo entre 0 e 1023)
  vldr = analogRead(ldr); 
 
  //mapeando o valor para a escala do servo (entre 0 e 180)
  vldr = map(vldr, 0, 1023, -10, 190); 
  
  //definindo o valor/posição do servomotor
  servoMotorObj.write(vldr);
  if (vldr >= 45 && vldr <= 100){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Luz OK");
    lcd.setCursor(0,1);
    lcd.print("Luz = ");
    lcd.print(vldr);
    delay(2000);
  } else if (vldr > 100) {
    // Luminosidade alta
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Luz ALTA");
    lcd.setCursor(0,1);
    lcd.print("Luz = ");
    lcd.print(vldr);
    delay(2000);
  } else if (vldr < 45){
   // Luminosidade baixa
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Luz BAIXA");
    lcd.setCursor(0,1);
    lcd.print("Luz = ");
    lcd.print(vldr);
    delay(2000); 
  }
  
  //------------Temperatura------------- 
  int temperatura = analogRead(temp);
  float tensao = temperatura * 5;
  tensao /= 1024;
  float tempC = (tensao-0.5) * 100; // convertendo para Celsius
  
  // Temperatura ok
  if (tempC >= 20 && tempC <= 30){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp. OK");
    lcd.setCursor(0,1);
    lcd.print("Temp. = ");
    lcd.print(tempC);
    delay(2000);
  } else if (tempC > 30) {
    // Temperatura alta
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp ALTA");
    lcd.setCursor(0,1);
    lcd.print("Temp. = ");
    lcd.print(tempC);
    delay(2000);
  } else if (tempC < 20){
   // Temperatura baixa
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp BAIXA");
    lcd.setCursor(0,1);
    lcd.print("Temp. = ");
    lcd.print(tempC);
    delay(2000);
  }
      
  //-----------------UMIDADE--------------------
  int sensorUmid = analogRead(potenciometro);
  float porcem = map(sensorUmid, 0,1023,0,100);
  if (porcem > 60) {
   // Umidade alta
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Umidade ALTA");
    lcd.setCursor(0,1);
    lcd.print("Umid solo =");
    lcd.print(porcem);
    delay(2000);
  } else if (porcem < 20) {
   // Umidade baixa
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Umidade BAIXA");
    lcd.setCursor(0,1);
    lcd.print("Umid solo =");
    lcd.print(porcem);
    delay(2000);
  } else{
    // Umidade OK
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Umidade OK");
    lcd.setCursor(0,1);
    lcd.print("Umid solo =");
    lcd.print(porcem);
    delay(2000);
  }
  //-----------------MOVIMENTO--------------------
  int ervaDaninha = digitalRead(sensorPir);
  if (ervaDaninha){
    //Erva daninha detectada
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("CUIDADO! Erva");
    lcd.setCursor(0,1);
    lcd.print("daninha no solo!");
    delay(2000);
  } else{
    //Solo livre de erva daninha
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Solo OK");
    lcd.setCursor(0,1);
    lcd.print("Sem erva daninha");
    delay(2000);
  }
  //-----------------PH--------------------
  int sensorValue = analogRead(sensorPh);
  float ph = sensorValue * (14.0/1023.0);
  
  if (ph >= 5 && ph <= 7){
    // PH Neutro
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PH Neutro");
    lcd.setCursor(0,1);
    lcd.print("PH do solo: ");
    Serial.println(ph);
    lcd.setCursor(12, 1);
    lcd.print(ph);
    delay(2000);
  } else if (ph < 5){
    // PH Ácido
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PH Acido");
    lcd.setCursor(0,1);
    lcd.print("PH do solo: ");
    Serial.println(ph);
    lcd.setCursor(12, 1);
    lcd.print(ph);
    delay(2000);
  } else {
    // PH Alcalino
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PH Alcalino");
    lcd.setCursor(0,1);
    lcd.print("PH do solo: ");
    Serial.println(ph);
    lcd.setCursor(12, 1);
    lcd.print(ph);
    delay(2000);
  }
}
