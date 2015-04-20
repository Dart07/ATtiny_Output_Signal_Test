
#define ATtiny_PIN3   4     //ATtiny Pin 3
#define ATtiny_PIN2   3     //ATtiny Pin 2
byte data[2] = {};
byte mask = 1;
byte startByte = 0x55;
void setup() {
// no need to set up, just run through the loop
data[0] = 0xFF;
data[1] = 0xFF;
pinMode(ATtiny_PIN2, OUTPUT);
pinMode(ATtiny_PIN3, OUTPUT);
digitalWrite(ATtiny_PIN2, LOW);
digitalWrite(ATtiny_PIN3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(ATtiny_PIN2, HIGH);
  //blinkLED();
  sendStart();
  /*sendData(data[1]);
  sendData(data[0]);
  sendEnd();
  */
}
void sendStart(){
   for (mask = 00000001; mask>0; mask <<= 1) { //iterate through bit mask
    if (startByte & mask){ // if bitwise AND resolves to true
      digitalWrite(ATtiny_PIN2,HIGH); // send 1
    }
    else{ //if bitwise and resolves to false
      digitalWrite(ATtiny_PIN2,LOW); // send 0
    }
    delay(1000); //delay
  } 
}
// not going to work since it is a btye and not separate bits in an array...
/*void sendStart(){
 byte startByte = B10101010;
   for (int x = 0; x < 7; x++){
     if(startByte[x] == 1){
       digitalWrite(ATtiny_PIN2, HIGH);
       delay(1000);
     }
     else{
       digitalWrite(ATtiny_PIN2, LOW);
       delay(1000);
     }   
   } 
  
}*/
/*void blinkLED(){
  while(true){
    digitalWrite(ATtiny_PIN2, HIGH);
    delay(1000);
    digitalWrite(ATtiny_PIN2, LOW);
    delay(1000);
  }
}
*/
/*void sendStart(){
  byte startByte = B10101010;
  for(int x = 0; x < 7; x++){
    if(startByte & B00000001 == B00000001){
      digitalWrite(ATtiny_PIN2, HIGH);
      delay(1000);
    }
    else{
      digitalWrite(ATtiny_PIN2, LOW);
      delay(1000);
    }
    startByte >> 1;    
  }
}*/
/*
void sendData(byte data){
  for(int i = 0; i < sizeof(data)-1; i++){
    if(data & 1){
      digitalWrite(ATtiny_PIN2, HIGH);
      delay(2000);
    }
    else{
      digitalWrite(ATtiny_PIN2, LOW);
    }
    data >> 1;
  }
}

void sendEnd(){
  byte endByte = B11111111;
  for(int i = 0; i < sizeof(endByte)-1; i++){//
   if(endByte & 1){
      digitalWrite(ATtiny_PIN2, HIGH);
      delay(2000);
   }
   else{
      digitalWrite(ATtiny_PIN2, LOW);
      delay(2000);
   }
  endByte >> 1;
  }
} */
