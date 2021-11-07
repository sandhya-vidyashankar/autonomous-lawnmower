#define M1dir 2
#define M1pwm 9
#define M1pwr 4
#define M2dir 3
#define M2pwm 10
#define M2pwr 5
#define r1 A3 
#define IRLgnd A2
#define r2 A1
#define IRCgnd A0
#define r3 8
#define IRRgnd 7
#define IRRvcc 6
#define cA 12
#define cB 13
#define cpwm 11

void setup() {

 pinMode(M1dir, OUTPUT);
 pinMode(M1pwm, OUTPUT);
 pinMode(M1pwr, OUTPUT);
 pinMode(M2dir, OUTPUT);
 pinMode(M2pwm, OUTPUT);
 pinMode(M2pwr, OUTPUT);
 //sensor
 pinMode(r1,INPUT);
 pinMode(r2,INPUT);
 pinMode(r3,INPUT);
 pinMode(IRLgnd, OUTPUT);
 digitalWrite(IRLgnd, LOW);
 pinMode(IRCgnd, OUTPUT);
 digitalWrite(IRCgnd, LOW);
 pinMode(IRRgnd, OUTPUT);
 digitalWrite(IRRgnd, LOW);
 pinMode(IRRvcc, OUTPUT);
 digitalWrite(IRRvcc, HIGH);
//cutter
   pinMode(cA, OUTPUT);
  pinMode(cB, OUTPUT);
  pinMode(cpwm, OUTPUT);
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH); //5V FOR LOGIC
}
void loop() {
    int IR1, IR2, IR3, IR4;
  IR1=digitalRead(r1);
  IR2=digitalRead(r2); //
  IR3=digitalRead(r3);
  // IR reading of 1 means no obstacle!!
if ((IR1!=0)&&(IR2!=0)&&(IR3!=0))
   {
     Forward();
   }
   else if ((IR1!=1)&&(IR2!=0)&&(IR3!=0)) //Left obstacle
   {
    Backward();
    delay(4000);
    Right();
    delay(4000);
   }
   else if ((IR1!=0)&&(IR2!=0)&&(IR3!=1)) //Right obstacle
   {
    Backward();
    delay(4000);
    Left();
    delay(4000);
   }
   else 
   {
     Backward();
    delay(4000);
    Right();
    delay(4000);
   }
}
 
//individual motor control
void Motor1Forward(){
  digitalWrite(M1dir, HIGH);
  analogWrite(M1pwm, 255);
}
 void Motor2Forward(){
  digitalWrite(M2dir, HIGH);
  analogWrite(M2pwm, 72);
}
void Motor1Backward(){
  digitalWrite(M1dir, LOW);
  analogWrite(M1pwm, 255);
}
void Motor2Backward(){
  digitalWrite(M2dir, LOW);
  analogWrite(M2pwm, 72);
}
//Cutter control
void CutterOn(){
 analogWrite(cpwm, 150);
 digitalWrite(cA, HIGH);
 digitalWrite(cB, LOW);
}
void CutterOff(){
  analogWrite(cpwm, 0);
 digitalWrite(cA, LOW);
 digitalWrite(cB, LOW);
}
//Drive control - cutter operates only when forward
 void Forward(){
  Motor1Forward();
  Motor2Forward();
  CutterOn();
}
void Backward(){
  Motor1Backward();
  Motor2Backward();
  CutterOn();
}
void Left(){
  Motor1Backward();
  Motor2Forward();
  CutterOff();
  }
void Right(){
  Motor2Backward();
  Motor1Forward();
  CutterOff();
  }
void Stop(){
 analogWrite(M1pwm, 0);
 analogWrite(M2pwm, 0);
 CutterOff();
}
