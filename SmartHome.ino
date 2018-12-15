int data = 0;                //Variable for storing received data
void setup() 
{
Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
pinMode(2, OUTPUT); //1
pinMode(3, OUTPUT); //2
pinMode(4, OUTPUT); //3
pinMode(5, OUTPUT); //4



pinMode(11,INPUT); // Dev 4
pinMode(10,INPUT); // Dev 3
pinMode(9,INPUT); // Dev 2
pinMode(8,INPUT); //Dev 1

pinMode(13,OUTPUT); // Power for Buttons

}
void loop()
{
 
  int dev;
  int state;
  
  if(Serial.available() > 0)  // Send data only when you receive data:
  {
  delay(20);
  dev = Serial.read();
  state= Serial.read();

  int nr= dev-48;
  if (state==49){ // TRUE ,ON
    turnON(nr);
  }
  else{ 
    turnOFF(nr);
  }

  
}// Serial.avaible                            

}
void turnOFF(int nr)
{
Serial.write("OFF:");
Serial.write(nr);
digitalWrite(nr+1,LOW);
Serial.println(); 

}

void turnON(int nr){
Serial.write("ON");
Serial.write(nr);
digitalWrite(nr+1,HIGH);
Serial.println(); 

}


