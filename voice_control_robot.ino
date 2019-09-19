#include <SoftwareSerial.h>
int MR1=3;
int MR2=4;
int ML1=7;
int ML2=8;

SoftwareSerial BT(10, 11); //TX, RX respetively
String readvoice;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
}
//-----------------------------------------------------------------------//  
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  }  
  if (readvoice.length() > 0) {
    Serial.println(readvoice); 

  if(readvoice == "forward") 
  {
    digitalWrite(MR1, HIGH);
    digitalWrite (ML1, HIGH);
    digitalWrite(MR2,LOW);
    digitalWrite(ML2,LOW);
    delay(100);
  } 
  
  else if(readvoice == "backward") 
  {
    digitalWrite(MR1, LOW);
    digitalWrite(ML1, LOW);
    digitalWrite(MR2, HIGH);
    digitalWrite(ML2,HIGH);
    delay(100);
  }
  
  else if (readvoice == "right")
  {
    digitalWrite (ML1,HIGH);
    digitalWrite (MR1,LOW);
    digitalWrite (MR2,LOW);
    digitalWrite (ML2,LOW);
    delay (100);
    
  }
    
 else if ( readvoice == "left")
 {
   digitalWrite (MR2, LOW);
   digitalWrite (MR1, HIGH);
   digitalWrite (ML1, LOW);
   digitalWrite (ML2, LOW);
   delay (100);
 }
 
 else if (readvoice == "stop")
 {
   digitalWrite (MR1, LOW);
   digitalWrite (MR2, LOW);
   digitalWrite (ML1, LOW);
   digitalWrite (ML2, LOW);
   delay (100);
 }
 
   

readvoice==(""); //Reset the variable
}
} 
