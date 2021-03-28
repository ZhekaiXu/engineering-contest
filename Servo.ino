#include <Servo.h>
unsigned long timerL = 0;
unsigned long timerR = 0;

unsigned long prevtimeL = 0;
unsigned long prevtimeR = 0;
int reachL = 30;
int reachR = 30;


int pos1;
int pos2;
int pos3;
int pos4;
int pos5;
int pos6;


Servo L1;
Servo L2;
Servo L3;
Servo L4;
Servo L5;
Servo R1;
Servo R2;
Servo R3;
Servo R4;
Servo R5;


/*
void hello()
{
  C3.write(30);
  B3.write(30);

  pos1 = 30;
  prevtime = millis();
  
  if( pos1 < 91)
  {
    timer = millis();
    if ((timer - prevtime) > 60)
    {
      C3.write(pos1);
      B3.write(pos1);
      pos1++;
      prevtime = millis();
    }
  }
  
}

void world()
{
  pos2 = 0;
  prevtime = millis();
  if (pos2 < 31)
  {
    timer = millis();
    
    if ((timer - prevtime)> 50)
    {
      C5.write((90 + pos2)*0.95);
      leftarm.write(97-pos2);
      C4.write((90 - 2* pos2) *1.1);
      pos2++;
      prevtime = millis();
      
    }
  }

  
}


*/
void pinout()
{
  pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);


L1.attach(9);
L2.attach(8);
L3.attach(7);
L4.attach(10);
L5.attach(11);
R1.attach(6);
R2.attach(5);
R3.attach(4);
R4.attach(2);
R5.attach(3);

}

void startup()
{
  L1.write(90);
L2.write(90);
L3.write(97);
L4.write(90);
L5.write(90);

R1.write(90);
R2.write(90);
R3.write(90);
R4.write(90);
R5.write(90);
}

void Lreach()
{
   pos2 = 0;
  prevtimeL = millis();
  while (pos2 < (reachL+1))                                    
  {
    timerL = millis();
    
    if ((timerL - prevtimeL)> 50)
    {
      L5.write((90 + pos2)*0.95);
      L3.write(97-pos2);
      L4.write((90 - 2* pos2) *1.1);
      pos2 ++;
      prevtimeL = millis();
      
    }
  }
}

void Rreach()
{
   pos1 = 0;
  prevtimeR = millis();
  while (pos1 < reachR)                                    //这里调整向前伸的距离
  {
    timerR = millis();
    
    if ((timerR - prevtimeR)> 50)
    {
      L5.write((90 + pos1)*0.95);
      L3.write(97-pos1);
      L4.write((90 - 2* pos1) *1.1);
      pos1 ++;
      prevtimeR = millis();
      
    }
  }
}
//void end

void Lretract()
{
   pos2 = 0;
  prevtimeL = millis();
  if (pos2 > 91)                                    //这里调整向后的距离
  {
    timerL = millis();
    
    if ((timerL - prevtimeL)> 50)
    {
      L5.write((reachL - pos2)*0.95);
      L3.write(reachL+pos2);
      L4.write((reachL - 2* pos2) *1.1);
      pos2 ++;
      prevtimeL = millis();
      
    }
  }
}


void Rretract()
{
   pos1 = 0;
  prevtimeR = millis();
  if (pos1 > 91)                                    //这里调整向后的距离
  {
    timerR = millis();
    
    if ((timerR - prevtimeR)> 50)
    {
      R5.write((reachR - pos2)*0.95);
      R3.write(reachR+pos2);
      R4.write((reachR - 2* pos2) *1.1);
      pos1 ++;
      prevtimeL = millis();
      
    }
  }
}






void setup() {
  // put your setup code here, to run once:

pinout();

startup();






}

void loop() {
  // put your main code here, to run repeatedly:



}
