//sistem pendeteksi kebakaran ti-2a
int buzzer = 5;
int lampuRelayPin = 2;
int pompaRelayPin = 8;
int flamePin = 7;
int analogPinSmoke = A5;
int analogPinFlame = A0;
int analogValSmoke;
int analogValFlame;

int smokeThres = 100;

void setup() {
  pinMode(analogPinSmoke, INPUT);
  pinMode(flamePin, INPUT);
  pinMode(lampuRelayPin, OUTPUT);
  pinMode(pompaRelayPin, OUTPUT);
  pinMode(buzzer, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  int flameSensor = digitalRead(flamePin);
  analogValSmoke = analogRead(analogPinSmoke);
  analogValFlame = analogRead(analogPinFlame);

  Serial.print("Indikator Asap: ");
  Serial.println(analogValSmoke);
  Serial.print("Indikator Api: ");
  Serial.println(analogValFlame);
  Serial.println(" ");
  delay(1000);
  
  if (analogValSmoke > smokeThres || flameSensor == HIGH){
    tone(buzzer, 200, 10);    
    delay(1000);
  }
  if (analogValSmoke > smokeThres && flameSensor == HIGH){
    tone(buzzer, 2000);
    digitalWrite(pompaRelayPin, HIGH);    
    digitalWrite(lampuRelayPin, LOW);
    delay(800);
    digitalWrite(lampuRelayPin, HIGH);
    delay(100);    
  }
  else
  {
    digitalWrite(pompaRelayPin, LOW);
    digitalWrite(lampuRelayPin, HIGH);
    noTone(buzzer);
    delay(1000);
  }
}
