//MIT License

//Copyright (c) 2017 @newtonianxzc @isaacdarcilla

//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:

int layer[4]={A3,A2,A1,A0};
int led[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4}; int time = 250;
void setup()
{
  for(int i = 0; i<16; i++){pinMode(led[i], OUTPUT);}
  for(int i = 0; i<4; i++){pinMode(layer[i], OUTPUT);}
  randomSeed(analogRead(10));
}
void loop()
{
  turnEverythingOff();turnEverythingOn();randomflicker();randomRain();goThroughAllLedsOneAtATime();
  turnEverythingOff();delay(2000);
}
void turnEverythingOff()
 {
   for(int i = 0; i<16; i++){digitalWrite(led[i], 1);}
   for(int i = 0; i<4; i++){digitalWrite(layer[i], 0);}
 }
void turnEverythingOn()
{
  for(int i = 0; i<16; i++){digitalWrite(led[i], 0);}
  for(int i = 0; i<4; i++){digitalWrite(layer[i], 1);}
}
void randomflicker()
{
  turnEverythingOff();int x = 10;for(int i = 0; i !=750; i+=2){int randomLayer = random(0,4);
  int randomLed = random(0,16);digitalWrite(layer[randomLayer], 1);digitalWrite(led[randomLed], 0);
  delay(x);digitalWrite(layer[randomLayer], 0);digitalWrite(led[randomLed], 1);delay(x); }
}
void randomRain()
{
  turnEverythingOff();int x = 100;for(int i = 0; i!=60; i+=2){int randomLed = random(0,16);
  digitalWrite(led[randomLed], 0);digitalWrite(layer[3], 1);delay(x+50);digitalWrite(layer[3], 0);
  digitalWrite(layer[2], 1);delay(x);digitalWrite(layer[2], 0);digitalWrite(layer[1], 1);delay(x);
  digitalWrite(layer[1], 0);digitalWrite(layer[0], 1);delay(x+50);digitalWrite(layer[0], 0);
  digitalWrite(led[randomLed], 1);}
}
void goThroughAllLedsOneAtATime()
{
  int x = 15;turnEverythingOff();for(int y = 0; y<5; y++){for(int count = 4; count != 0; count--){
  digitalWrite(layer[count-1], 1);for(int i = 0; i<4; i++){digitalWrite(led[i], 0);delay(x);
  digitalWrite(led[i], 1);delay(x);}digitalWrite(layer[count-1], 0);}for(int count = 0; count < 4; count++)
  {digitalWrite(layer[count], 1);for(int i = 4; i<8; i++){digitalWrite(led[i], 0);delay(x);
  digitalWrite(led[i], 1);delay(x);}digitalWrite(layer[count], 0);}for(int count = 4; count != 0; count--)
  {digitalWrite(layer[count-1], 1);for(int i = 8; i<12; i++){digitalWrite(led[i], 0);delay(x);
  digitalWrite(led[i], 1);delay(x);}digitalWrite(layer[count-1], 0);}for(int count = 0; count < 4; count++)
  {digitalWrite(layer[count], 1);for(int i = 12; i<16; i++){digitalWrite(led[i], 0);delay(x);
  digitalWrite(led[i], 1);delay(x);}digitalWrite(layer[count], 0);}}
}
