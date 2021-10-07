
                           //-------->>>>>>>>> Obstacle Avoidance Robot <<<<<<<<<----------//
                           

int trig = 3;     // Ultrasonic Sensor     
int echo = 4;     // Ultrasonic Sensor 
int in1 = 11;    //Motor Driver
int in2 = 10;    //Motor Driver
int in3 = 9;     //Motor Driver
int in4 = 8;     //Motor Driver
int ena = 6;    //Motor Driver
int enb = 5;     //Motor Driver
                                                                       
long duration;
float distance,x, area , circle_area;                                          
 void setup()
{
  // put your setup code here, to run once:
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
                                                         
 pinMode(in1, OUTPUT);  
 pinMode(in2, OUTPUT);  
 pinMode(in3, OUTPUT); 
 pinMode(in4, OUTPUT);  
pinMode(ena, OUTPUT);  
pinMode(enb, OUTPUT); 
  Serial.begin(9600);   // This tells the Arduino to get ready to exchange messages with the Serial Monitor at a data rate of 9600 bit/s. 
}

void loop()   // The code inside the loop function runs over and over as long as the Maker Board is turned ON.
{
int dist=calculateDistance();      
    delay(100);
    Serial.println(distance);  // It is use to show the output (while robot is connected) in the software Serial Monitor
    
 
    if (dist <= 25 )           // Ultrasonic Sensor Sense object distance(35cm)      
    {
  
analogWrite(ena, 230);           
analogWrite(enb, 230);
  digitalWrite(in1,LOW);           // For Left or Right purpose whenever the object(35cm) infont of the Robot then it get turn
  digitalWrite(in2,LOW);      
  digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 Serial.println("Objects");
    }
    else                               
    {
  analogWrite(ena, 90);
analogWrite(enb, 90);    
 digitalWrite(in1,HIGH);                 // In Forward Direction
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
                                     
Serial.println("No objects");           // Serial.println is use to show ouput in the Serial Monitor
    }
}
int calculateDistance()
{
  digitalWrite(trig,LOW);              // It is for the Backward Direction
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  return distance;
}
