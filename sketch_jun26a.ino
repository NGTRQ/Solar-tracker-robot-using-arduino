  #include <Servo.h>
//defining Servos
Servo servohori;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;

Servo servoverti; 
int servov = 0; 
int servovLimitHigh = 160;
int servovLimitLow = 20;
//Assigning LDRs
int ldrtop = 2; //top left LDR green
int ldrtopl = 1; //top right LDR yellow
int ldrtopr = 0; // bottom left LDR blue
int ldrbot = 3; // bottom right LDR orange

 void setup () 
 {
  servohori.attach(10);

  servoverti.attach(9);
 
  delay(500);
 }

void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  //capturing analog values of each LDR
  int ldrtop = analogRead(ldrtop);
  int ldrtopl = analogRead(ldrtopl);
  int ldrtopr = analogRead(ldrtopr);
  int ldrbot = analogRead(ldrbot);
  // calculating average
  int avgtop = (ldrtop + ldrtopr + ldrtopl) / 2; //average of top LDRs
  int avgbot = (ldrbot) / 2; //average of bottom LDRs
  int avgleft = (ldrtopl) / 2; //average of left LDRs
  int avgright = (ldrtopr) / 2; //average of right LDRs

  if (avgtop < avgbot)
  {
    servoverti.write(servov +1);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov -1);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(10);
  }
  else 
  {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh -1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(10);
  }
  else 
  {
    servohori.write(servoh);
  }
  delay(50);
}
