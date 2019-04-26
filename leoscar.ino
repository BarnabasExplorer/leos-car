int echoPin = 8;
int trigPin = 7;
int distance;

long ultrasonic() 
{
  //DONT YOU DARE MESS AROUND WITH MY PROGRAM LIKE YOU DID AT 9:10!!!!!!!!!!!!!!!!!!!          AND IF YOU SEE THIS WARNING, GET OUT OF MY CODE, ARDUBLOCK USER!!!!!     angry,leo.
  long duration;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  duration = duration / 59;
  if ((duration < 2) || (duration > 300)) return false;
  return duration;
}

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  Serial.begin(9600);
}

bool button = 0;

void right90() {
  analogWrite(11, 255);
  analogWrite(10, 0);
  analogWrite(6, 0);
  analogWrite(5, 255);
  delay(350);
}

void left90() {
  analogWrite(11, 0);
  analogWrite(10, 255);
  analogWrite(6, 255);
  analogWrite(5, 0);
  delay(350);
}

void rightCurve(int curveF, int curveB) {
  analogWrite(11, curveF);
  analogWrite(10, 0);
  analogWrite(6, curveB);
  analogWrite(5, 0);
}

void leftCurve(int curveF, int curveB) {
  analogWrite(11, curveB);
  analogWrite(10, 0);
  analogWrite(6, curveF);
  analogWrite(5, 0);
}

void right() {
  analogWrite(11, 255);
  analogWrite(10, 0);
  analogWrite(6, 0);
  analogWrite(5, 255);
}

void left() {
  analogWrite(11, 0);
  analogWrite(10, 255);
  analogWrite(6, 255);
  analogWrite(5, 0);
}

void foreward() {
  analogWrite(11, 0);
  analogWrite(10, 255);
  analogWrite(6, 255);
  analogWrite(5, 0);
}

void backward() {
  analogWrite(11, 255);
  analogWrite(10, 0);
  analogWrite(6, 0);
  analogWrite(5, 255);
}

void stopCar() {
  analogWrite(11, 0);
  analogWrite(10, 0);
  analogWrite(6, 0);
  analogWrite(5, 0);
}

void loop() {
  
 // foreward();
 // delay(1000);
  //backward();
  //delay(1000);
  distance = ultrasonic();
  
  Serial.println(ultrasonic());

  if(distance<40)
  {
    stopCar();
  }
 else {
   foreward();
  }
}
