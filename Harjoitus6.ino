void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

int bit1;
int bit2;

int num1 = 0;
int num2 = 0;
int sum = 0;

void loop() {

  bit1 = analogRead(0);
  bit2 = analogRead(1);
  if(bit1 > 500) {
    num1 = 1;
  }
  else {
    num1 = 0;
  }
  if(bit2 > 500) {
    num2 = 1;
  }
  else {
    num2 = 0;
  }

  sum = (num1 + num2);

  switch(sum) {

    case 0: {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      break;
    }
    case 1: {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      break;
    }
    case 2: {
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      break;
    }

  }

  // put your main code here, to run repeatedly:

}
