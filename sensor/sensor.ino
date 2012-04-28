//Smart Table 4
//April 27th, 2012
//


int detectorPin = A4;

void setup(){
  Serial.begin(9600);
  pinMode(detectorPin, INPUT);
}

void loop(){  
  int sensor = analogRead(detectorPin);
  Serial.println(sensor);
  delayMicroseconds(2500);
}
