#define enableA 9
#define input1 6
#define input2 7

int forward = true;
int pwmValue = 0;

void setup() {

  Serial.begin(9600);
  
  pinMode(enableA, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);

  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);

}

void loop() {

  if(pwmValue >= 255){
    forward = false;
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
  }else if(pwmValue <= 0){
    forward = true;
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    
  }

  if(forward){
    analogWrite(enableA, pwmValue++);
  }else{
    analogWrite(enableA, pwmValue--);
  }
  

  Serial.println(pwmValue);  

  delay(150);
  
}
