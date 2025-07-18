
const int pingPin = 7;
#define temp A0
#define LDRPin A2
const int motor = 6;
const int LedPin = 9;
const int mos = 11;

void setup() {
  Serial.begin(9600);
   
}

void loop() {
  pinMode(mos, OUTPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(LDRPin, INPUT);
  digitalWrite(LedPin, LOW); 
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  float tempValue = (analogRead(temp));
  int LDRValue = analogRead(LDRPin);
  duration = pulseIn(pingPin, HIGH);
  
  if (cm<100){
  	if (LDRValue > 300)			
  	{
    	digitalWrite(LedPin, LOW); 
  	}
  	else
  	{
    	digitalWrite(LedPin, HIGH);
  	}
  
  	if (tempValue>149){
    	analogWrite(mos, tempValue);
  	}
  	else if (tempValue<149){
    	analogWrite(mos, LOW);
  	}
  }
  
  else{
    digitalWrite(LedPin, LOW);
    analogWrite(mos, LOW);
    
  }
  
  
  

  //inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.println();
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1000);
  Serial.print("Tempreture: ");
  Serial.print(tempValue);
  delay(1000);
  Serial.println();
  Serial.print("LDR Value: ");
  Serial.print(LDRValue);
  
 
  
  

  

  delay(2000);
}

//long microsecondsToInches(long microseconds) {

  //return microseconds / 74 / 2;
//}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
