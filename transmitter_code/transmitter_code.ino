
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

	char character = Serial.read();
	if (character == 'n'){
    Serial.println("on send");
		send_tx(ondelay);
	}
	if (character == 'f'){
    Serial.println("off send");
		send_tx(offdelay);
	}
 character = 'k';
delay(2000);
send_tx(enddelay);
}

void send_tx(int cmd) {
  digitalWrite(txr, HIGH);
  delay(cmd);
  digitalWrite(txr, LOW);
  delay(enddelay);
}
