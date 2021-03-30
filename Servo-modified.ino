#include <Servo.h>
unsigned long timerL = 0;
unsigned long timerR = 0;
unsigned long timermaster = 0;

unsigned long prevtimeL = 0;
unsigned long prevtimeR = 0;
unsigned long prevtimemaster = 0;
int reachL = 30;
int reachR = 30;
int countL = 0;
int countR = 0;

int pos1 = 0;
float pos2 = 0;
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

void LReach(int reachL){
    if (!(millis() % 50)){
        pos2 += 0.25 * (reachL >= pos2) - 0.125 + (reachL == pos2);
        L5.write((90 + pos2)*0.95);
        L3.write(97-pos2);
        L4.write((90 - 2* pos2) *1.1);
    }
}

void Rreach()
{
   pos1 = 0;
  prevtimeR = millis();
  while (pos1 < reachR)                                    //这里调整向前伸的距离
  {
    timerR = millis();
    
    if ((timerR - prevtimeR)> 70)
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

  prevtimeL = millis();
  if (pos2 < 61)                                    //这里调整向后的距离
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


void Lgrab()
{
  L1.write(85);
  
}

void Rgrab()
{
  R1.write(85);
  
}

void Lrelease()
{
  L1.write(100);
  
}

void Rrelease()
{
  R1.write(100);
  
}

void Lshake()
{
 //保留设置摇晃次数的选项，默认摇晃四次
  L2.write(60);
  L3.write(97);
  delay(300);
  
  L2.write(100);
  L3.write(100);
  

 delay(200);
 L2.write(80);
 L3.write(90);
  delay(200);
  L2.write(100); 
    L3.write(100);
  delay(200);
  L2.write(80);
   L3.write(90);
  delay(200);
  L2.write(100);
     L3.write(100);
  delay(200);
  L2.write(80);
    L3.write(90);
  delay(200);
  L2.write(100);
   L3.write(100);   
  delay(200);

    //归位
  L2.write(90);
  L3.write(97);
  
  
}

void Rshake()
{
 //保留设置摇晃次数的选项，默认摇晃四次
  R2.write(70);
  R3.write(70);
  R2.write(110);
  R3.write(110);
    R2.write(70);
  R3.write(70);
  R2.write(110);
  R3.write(110);
    R2.write(70);
  R3.write(70);
  R2.write(110);
  R3.write(110);
    R2.write(70);
  R3.write(70);
  R2.write(110);
  R3.write(110);

    //归位
  R2.write(90);
  R3.write(90);
  
  
}

void setup() {
  // put your setup code here, to run once:

pinout();

startup();
delay(500);

Lshake();




}

void loop() {
  // put your main code here, to run repeatedly:




}
