#define ATtiny_PIN3   4     //ATtiny Pin 3
#define ATtiny_PIN2   3     //ATtiny Pin 2
byte data[2] = {};
unsigned int mask = 1;
byte startByte = 0xFF;
//byte endByte = 0x55;
unsigned int all_the_datas = 0;
void setup() {
// no need to set up, just run through the loop
data[0] = 0x55;
data[1] = 0x55;
pinMode(ATtiny_PIN2, OUTPUT);
pinMode(ATtiny_PIN3, OUTPUT);
digitalWrite(ATtiny_PIN2, LOW);
digitalWrite(ATtiny_PIN3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(ATtiny_PIN2, HIGH);
  //blinkLED();
  //sendStart();
  all_the_datas = (data[0] << 8) | data[1];
  //sendData(data[1]);
  sendData(all_the_datas);
  //sendEnd();
  
}/*
void sendStart(){
   for (mask = 10000000; mask>0; mask >>= 1) { //iterate through bit mask //Most significant bit gets sent out first
    if (startByte & mask){ // if bitwise AND resolves to true
      digitalWrite(ATtiny_PIN2,HIGH); // send 1
    }
    else{ //if bitwise and resolves to false
      digitalWrite(ATtiny_PIN2,LOW); // send 0
    }
    delay(50); //delay
  } 
}*/
void sendData(unsigned int data){
   /*for (mask = 10000000; mask>0; mask >>= 1) { //iterate through bit mask //Most significant bit gets sent out first
    if (startByte & mask){ // if bitwise AND resolves to true
      digitalWrite(ATtiny_PIN2,HIGH); // send 1
    }
    else{ //if bitwise and resolves to false
      digitalWrite(ATtiny_PIN2,LOW); // send 0
    }
    delay(50); //delay
  } */
  for(int x = 0;x<7;x++){
    digitalWrite(ATtiny_PIN2,HIGH);
    delay(50);
}
   for (mask = 0x8000; mask>0; mask >>= 1) { //iterate through bit mask //Most significant bit gets sent out first
    if (data & mask){ // if bitwise AND resolves to true
      digitalWrite(ATtiny_PIN2,HIGH); // send 1
    }
    else{ //if bitwise and resolves to false
      digitalWrite(ATtiny_PIN2,LOW); // send 0
    }
    delay(50); //delay
  }  
}


/*#define ATtiny_PIN3   4     //ATtiny Pin 3
#define ATtiny_PIN2   3     //ATtiny Pin 2




//byte *ptr;
//ptr =  data;
//byte endByte = 0x55;
void setup() {
// no need to set up, just run through the loop

data = 0x5555;

pinMode(ATtiny_PIN2, OUTPUT);
pinMode(ATtiny_PIN3, OUTPUT);
digitalWrite(ATtiny_PIN2, LOW);
digitalWrite(ATtiny_PIN3, LOW);
digitalWrite(ATtiny_PIN3,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(ATtiny_PIN2, HIGH);
  //blinkLED();
  //digitalWrite(ATtiny_PIN2, LOW);
  sendStart();
  sendData(data);
  digitalWrite(ATtiny_PIN2, LOW);
  //digitalWrite(ATtiny_PIN2, LOW);
  //sendEnd();
  //delay(10000);
  
}
void sendStart(){
  byte startByte = 0xFF;
  byte mask2 = 1;
   for (mask2 = 10000000; mask2>0; mask2 >>= 1) { //iterate through bit mask //Most significant bit gets sent out first
    if (startByte & mask2){ // if bitwise AND resolves to true
      digitalWrite(ATtiny_PIN2,HIGH); // send 1
    }
    else{ //if bitwise and resolves to false
      digitalWrite(ATtiny_PIN2,LOW); // send 0
    }
    delay(50); //delay
  } 
}
void sendData(unsigned int data){
  int mask = 1;
  
   for (mask = 1000000000000000; mask>0; mask >>= 1) { //iterate through bit mask //Most significant bit gets sent out first
    
    if (data & mask){ // if bitwise AND resolves to true
      digitalWrite(ATtiny_PIN2,HIGH); // send 1
    }
    else{ //if bitwise and resolves to false
      digitalWrite(ATtiny_PIN2,LOW); // send 0
    }
    delay(50); //delay
  }  
}*/
/*
void sendEnd(){
   for (mask = 10000000; mask>0; mask >>= 1) { //iterate through bit mask //Most significant bit gets sent out first
    if (endByte & mask){ // if bitwise AND resolves to true
      digitalWrite(ATtiny_PIN2,HIGH); // send 1
    }
    else{ //if bitwise and resolves to false
      digitalWrite(ATtiny_PIN2,LOW); // send 0
    }
    delay(500); //delay
  }  
}*/
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
