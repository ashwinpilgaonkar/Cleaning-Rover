//Obstacle Avoiding Cleaning Robot - Assuming a square/rectangular, empty room (for best performance)


#define echoPin 12 // Echo Pin
#define trigPin 11 // Trigger Pin
#define defaultDistance 9999999 //OutofRange Value

int maximumRange = 400; // Maximum range needed
int minimumRange = 6; // Minimum range needed
int ctr=0;

int motor_left[] = {2, 4};
int motor_right[] = {7, 8};

 
void setup()
{ 
   Serial.begin (9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

   int i;
   for(i=0; i<2; i++)
   {
      pinMode(motor_left[i], OUTPUT);
      pinMode(motor_right[i], OUTPUT);
   }

   initi();
} 




/////// INTITIALIZATION - RUNS ONLY ONCE ////////
void initi()
{
   int distance1 = getDistance();  //straight (pos 1)
   
   turnLeft();
   int distance2 = getDistance();  //left (pos 2)

   turnLeft();
   int distance3 = getDistance(); //behind (pos 3)

   turnLeft();
   int distance4 = getDistance(); //right (pos 4)

   if(shortestDist(distance1, distance2, distance3, distance4) == 1)
   {
      turnLeft();
      goStraight();
      turnRight();
      goStraight();
   }

   else if(shortestDist(distance1, distance2, distance3, distance4) == 2)
   {
      turnLeft();
      turnLeft();
      goStraight();
      turnRight();
      goStraight();
   }

   else if(shortestDist(distance1, distance2, distance3, distance4) == 3)
   {
      turnRight();
      turnRight();
      goStraight();
      turnRight();
      goStraight();
   }

   else if(shortestDist(distance1, distance2, distance3, distance4) == 4)
   {
      goStraight();
      turnRight();
      goStraight();
   }
}





///// CALCULATES DISTANCE AND RETURNS IT /////////////
int getDistance()
{
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
 
    digitalWrite(trigPin, LOW);
    int duration = pulseIn(echoPin, HIGH);
    int distance = duration/57;           //Calculates distance from ping

    if(distance > maximumRange)
      return defaultDistance;

      else
        return distance;
}




///// CALCULATES THE SHORTEST DISTNACE WHEN GIVEN 3 VALUES AND RETURNS IT /////////////
int shortestDist(int d1, int d2, int d3, int d4)
{
   if(d1<=d2 && d1<=d3 && d1<=d4)
      return d1;

   else if(d2<d1 && d2<=d3, d2<=d4)
      return d2;

   else if(d3<d2 && d3<d1 && d3<=d4)
      return d3;

   else if(d4<d1 && d4<d2 && d4<d3)
      return d4;
}




///// TURNS THE ROBOT 90 DEGREES TO THE LEFT /////////////
void turnLeft()
{
  digitalWrite(motor_left[0], LOW); 
  digitalWrite(motor_left[1], HIGH); 

  digitalWrite(motor_right[0], HIGH); 
  digitalWrite(motor_right[1], LOW);
  delay(1200);

  MotorStop();
}

///// TURNS THE ROBOT 90 DEGREES TO THE RIGHT /////////////
void turnRight()
{
  digitalWrite(motor_left[0], HIGH); 
  digitalWrite(motor_left[1], LOW); 

  digitalWrite(motor_right[0], LOW); 
  digitalWrite(motor_right[1], HIGH); 
  delay(1200);

  MotorStop();
}




///// TAKES A SMALL STEP /////////////
void takeStep()
{
  if(getDistance()>minimumRange)
  {
      digitalWrite(motor_left[0], HIGH); 
      digitalWrite(motor_left[1], LOW); 

      digitalWrite(motor_right[0], HIGH); 
      digitalWrite(motor_right[1], LOW); 
      delay(300);
      MotorStop();
  }
}


////// STOPS THE MOTOR ////////
void MotorStop()
{
  digitalWrite(motor_left[0], LOW); 
  digitalWrite(motor_left[1], LOW); 

  digitalWrite(motor_right[0], LOW); 
  digitalWrite(motor_right[1], LOW);
  delay(1000);
}



//////// GOES STRAIGHT TILL IT DETECTS AN OBSTACLE //////////
void goStraight()
{   
   while(getDistance() > minimumRange)
   {
      digitalWrite(motor_left[0], HIGH); 
      digitalWrite(motor_left[1], LOW); 

      digitalWrite(motor_right[0], HIGH); 
      digitalWrite(motor_right[1], LOW); 
   }
      MotorStop();
}




///////TELLS THE ROBOT WHAT TO DO WHEN IT DETECTS AN OBSTACLE. RUNS TILL IT COVERS THE AREA OF ENTIRE ROOM///////////////
void obsDetect()
{
   if(ctr%2==0)
   {
      turnRight();
      takeStep();
      turnRight();
   }

    else
    {
      turnLeft();
      takeStep();
      turnLeft();
    }

    ctr++;
    goStraight();
}

void loop()
{ 
    obsDetect();
} 

