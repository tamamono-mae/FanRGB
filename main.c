#define ts 67
#define pinVCC 8
#define pinR 10
#define pinG 9
#define pinB 11

unsigned int i = 0;
unsigned int j = 0;
//float k = 0;
/*
unsigned int ts = 5;//59
unsigned int pinR = 10;
unsigned int pinG = 9;
unsigned int pinB = 11;
unsigned int pinVCC = 8;
*/
//sin plus
unsigned int sin_rise(unsigned int val){
  return round(sin(val*PI/510)*255);
}

unsigned int sin_fall(unsigned int val){
  return round(sin((val+255)*PI/510)*255);
}
/*
//sin minus
unsigned int sin_rise(unsigned int val){
  return round((sin((val-255)*PI/510)+1)*255);
}

unsigned int sin_fall(unsigned int val){
  return round((sin((val+510)*PI/510)+1)*255);
}
*/

/*
//10 power
unsigned int log_rise(unsigned int val){
  return round((pow(10,(val/255))-1)*255/9);
}

unsigned int log_fall(unsigned int val){
  return round((pow(10,(1-val/255))-1)*255/9);
}
*/

/*
//log
unsigned int log_rise(unsigned int val){
  return round(255*log(1+val*9/255));
}

unsigned int log_fall(unsigned int val){
  return round(255*log(10-val*9/255));
}
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(pinVCC,OUTPUT);  //pin 12V
  pinMode(pinG,OUTPUT);  //pin G
  pinMode(pinR,OUTPUT); //pin R
  pinMode(pinB,OUTPUT); //pin B
  digitalWrite(pinVCC,HIGH);
  analogWrite(pinR,0);
  analogWrite(pinG,0);
  analogWrite(pinB,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Wrhte to Red
  for(i=0;i<255;i++){
    j = sin_rise(i);
    analogWrite(pinG,j);
    analogWrite(pinB,j);
    delay(ts);
  }
  //Red to Yellow
  for(i=0;i<255;i++){
    j = sin_fall(i);
    analogWrite(pinG,j);
    delay(ts);
  }
  //Yellow to Green
  for(i=0;i<255;i++){
    j = sin_rise(i);
    analogWrite(pinR,j);
    delay(ts);
  }
  //Green to Cyan
  for(i=0;i<255;i++){
    j = sin_fall(i);
    analogWrite(pinB,j);
    delay(ts);
  }
  //Cyan to Blue
  for(i=0;i<255;i++){
    j = sin_rise(i);
    analogWrite(pinG,j);
    delay(ts);
  }
  //Blue to Purple
  for(i=0;i<255;i++){
    j = sin_fall(i);
    analogWrite(pinR,j);
    delay(ts);
  }
  //Purple to White
  for(i=0;i<255;i++){
    j = sin_fall(i);
    analogWrite(pinG,j);
    delay(ts);
  }
}
