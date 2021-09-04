char data = 0;            //Variable for storing received data
const int left_m=7;   //left
const int right_m=6;   //right
const int con_m=5;

void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(left_m,OUTPUT);
    pinMode(right_m,OUTPUT);
    pinMode(con_m,OUTPUT);
    
}
void loop()
{
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");  
      if(data=='F' ){
           front();  
      }else if(data=='L'){
         left();
      }else if(data=='G'){
         left();
      }else if(data=='R'){
        right();
      }else if(data=='I'){
        right();
      }else if(data=='S'){
        Break();
      }
      
   }
}
void front(){
  Serial.println("Forward Move");
  digitalWrite(right_m,HIGH);
  
  digitalWrite(left_m,HIGH);
  digitalWrite(con_m,HIGH);

}

void left(){
  Serial.println("Left Move");
  
  digitalWrite(con_m,HIGH);
  digitalWrite(left_m,LOW);
  digitalWrite(right_m,HIGH);
}
void right(){
  Serial.println("Left Move");
  
  digitalWrite(con_m,HIGH);
  digitalWrite(left_m,HIGH);
  digitalWrite(right_m,LOW);
}

void Break(){
  Serial.println("BREAK");
  
  digitalWrite(con_m,LOW);
  digitalWrite(left_m,LOW);
  digitalWrite(right_m,LOW);
}
