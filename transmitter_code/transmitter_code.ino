
int txr = D5;

void setup() {
  // put your setup code here, to run once:
  Serial.println(9600);
  pinMode(txr, OUTPUT);
}
int ondelay = 300;
int offdelay = 1000;
int enddelay = 2000;
void loop() {
  // put your main code here, to run repeatedly:

  //digitalWrite(txr,HIGH);
  //delay(ondelay);
  //digitalWrite(txr,LOW);

  //delay(offdelay);
  //digitalWrite(txr,HIGH);
  //delay(ondelay);
  //digitalWrite(txr,LOW);
  //delay(offdelay);
  //digitalWrite(txr,HIGH);

  //delay(enddelay);
  //
  digitalWrite(txr, HIGH);
  delay(enddelay);
  digitalWrite(txr, LOW);
  delay(enddelay);
}

void send_tx(int cmd) {
  digitalWrite(txr, HIGH);
  delay(cmd);
  digitalWrite(txr, LOW);
  delay(enddelay);
}

