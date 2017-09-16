
 
// Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo servoMotor;

// Definiendo pines
const int trigPin = 3;
const int echoPin = 5;
const int servoPin = 9;

int const count = 7;
int posiciones[count] = {0,30,60,90,120,150,180};

// varialbes
long duration;
int distance;
int timeDelay =700; // tiempo de espera de servo para calcular la distancia
 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(servoPin);
  pinMode(trigPin, OUTPUT); // Setear trigPin como Salida
  pinMode(echoPin, INPUT); // Setear echoPin como Entrada
  
}
 
void loop() {
  int i;
  int tmpdist;
  for (i = 0; i < count; i = i + 1) {
    servoMotor.write(posiciones[i]);
    delay(timeDelay); // esperar a que se mueva el servo
    tmpdist = calcDist();
    Serial.print(posiciones[i]);
    Serial.print(";");
    Serial.println(tmpdist);
  }
}

int calcDist() {
  // Limpiar el trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // encender el trigPinpor 10 micro segundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Lee el echoPin, devuelve el tiempo de recorrido de la onda sonora en microsegundos
  duration = pulseIn(echoPin, HIGH);
  // Calculad la distancia
  distance= duration*0.034/2;
  return distance;
}