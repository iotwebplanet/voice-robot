#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

int val=0;
//motor 1 
int IN1=5;   //7
int IN2=6;   //8
//motor 2
int IN3=2; 
int IN4=4; 

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

//new
pinMode(IN1,OUTPUT); 
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

 Serial.println("Start waiting for input:");
}


//funtion
void forward()
{
  
Serial.println(val);
digitalWrite(IN1,LOW); 
digitalWrite(IN2,HIGH);

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);

}


void backward()
{
  
Serial.println(val);
digitalWrite(IN1,HIGH); // Motor drivers may have difference setting, change it accordingly
digitalWrite(IN2,LOW);

digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);

}


void left()
{
  
  Serial.println(val);
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);

digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);

}


void right()
{
  
  Serial.println(val);

digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW); 
}


void stop()
{
Serial.println(val);
delay(500); 
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
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

  if(readvoice == "move" || readvoice == "F" )
  {
   
    forward();
    Serial.println("forward");
  }

  else if(readvoice == "back" || readvoice == "B" )
  {
  
    backward();
    Serial.println("backward");
  }

  else if (readvoice == "left" || readvoice == "L" )
  {
    
  right();
 //delay(7000);
 //forward();
 
  
  
  }

 else if ( readvoice == "right" || readvoice == "R" )
 {
  
    left();
    //delay(7000);
    //forward();
 }

 else if (readvoice == "stop" || readvoice == "S" )
 {
  
   stop();
   
 }
 else if (readvoice == "*keep watch in all direction#")
 {
   digitalWrite (3, HIGH);
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   delay (100);
 }
  else if (readvoice =="dance")
 {
    left();
    delay(1000);
    right();
    delay(1000);
    backward();
    delay(1000);
    forward();
   delay(1000);
    stop();
 }


 readvoice="";}//if command length
 
 } //Reset the variable//loop
