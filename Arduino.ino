#include <SoftwareSerial.h>
#include <NewPing.h>
#define TRIGGER_PIN  9
#define ECHO_PIN     8
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int tx = 7;
int rx = 6;

SoftwareSerial bluetooth(tx, rx);

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(13,1);
  pinMode(2,0);
   pinMode(3,0);
}

void loop()
{ 
   
 delay(50);
   int uS = sonar.ping();
  Serial.print("Ping: ");
  int cm=uS / US_ROUNDTRIP_CM;
  Serial.print(cm);
  Serial.println("cm");
  
   int a=digitalRead(2);
    int b=digitalRead(3);
  Serial.print("Ob1:-");
  Serial.println(a);
  Serial.print("Ob2:-");
  Serial.println(b);
  
  if(cm<15&&cm>0)
 {
   bluetooth.print("1 ");
      delay(1500);
 }    
  else if(cm>15)
  {
  bluetooth.print("0 ");
    delay(1500);
  }
  else if(a==0&&b==0)
  {
  bluetooth.print("4 ");
   delay(1500);
  }
   else if(a==0)
  {
  bluetooth.print("2 ");
    delay(1500);
  }
  else if(b==0)
  {
  bluetooth.print("3 ");
   delay(1500); 
  }
  }
