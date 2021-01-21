#include<NewPing.h>
int leftwheel1 = 3, leftwheel2 = 5, rightwheel1 = 6, rightwheel2 = 9;
int s1 = 11, s2 = 10, s3 = 8, s4 = 7, s5 = 4, s6 = 2;
int l1 , l2 , l3 , l4, l5 , l6 ;
int ledpin;
NewPing dist(trig_pin,echo_pin,30);
int ball_dist;
void forward()
{ analogWrite(leftwheel1, 150);
  analogWrite(leftwheel2, 0);
  analogWrite(rightwheel1, 150);
  analogWrite(rightwheel2, 0);
}
void pause()
{ analogWrite(leftwheel1, 0);
  analogWrite(leftwheel2, 0);
  analogWrite(rightwheel1, 0);
  analogWrite(rightwheel2, 0);
}
void setup()
{
  Serial.begin(9600);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(leftwheel1, OUTPUT);
  pinMode(leftwheel2, OUTPUT);
  pinMode(rightwheel1, OUTPUT);
  pinMode(rightwheel2, OUTPUT);
  forward();

}
void loop()
{ ball_dist= dist.ping_cm();
 if(ball_dist>0&&ball_dist<7)
 digitalWrite(ledpin,HIGH);
 else 
 digitalWrite(ledpin,LOW);
 
  l1 = digitalRead(s1);
  l2 = digitalRead(s2);
  l3 = digitalRead(s3);
  l4 = digitalRead(s4);
  l5 = digitalRead(s5);
  l6 = digitalRead(s6);


  //Forward.
  if (l1 == 0 && l2 == 0 && l3 == 0 && l4 == 1 && l5 == 1 && l6 == 1)
  {
    forward();
  }
  else if (l1 == 0 && l2 == 0 && l3 == 1 && l4 == 1 && l5 == 1 && l6 == 1)
  {
    analogWrite(leftwheel1, 0);
    analogWrite(leftwheel2, 0);
    analogWrite(rightwheel1, 120);
    analogWrite(rightwheel2, 0);
  }

  else if (l1 == 0 && l2 == 1 && l3 == 1 && l4 == 1 && l5 == 1 && l6 == 1)
  {
    analogWrite(leftwheel1, 0);
    analogWrite(leftwheel2, 0);
    analogWrite(rightwheel1, 120);
    analogWrite(rightwheel2, 0);
  }

  else if (l1 == 1 && l2 == 1 && l3 == 1 && l4 == 1 && l5 == 0 && l6 == 0)
  {
    analogWrite(leftwheel1, 120);
    analogWrite(leftwheel2, 0);
    analogWrite(rightwheel1, 0);
    analogWrite(rightwheel2, 0);
  }

  else if (l1 == 1 && l2 == 1 && l3 == 1 && l4 == 1 && l5 == 1 && l6 == 0)
  {
    analogWrite(leftwheel1, 120);
    analogWrite(leftwheel2, 0);
    analogWrite(rightwheel1, 0);
    analogWrite(rightwheel2, 0);
  }
  else if (l1 == 1 && l2 == 1 && l3 == 1 && l4 == 1 && l4 == 1 && l5 == 1 && l6 == 1)
  {
    pause();
  }
}
