
int txr = D5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(txr, OUTPUT);
}
int ondelay = 800;
int offdelay = 600;
int enddelay = 2000;
String cmd = "null";

void input_cmd (String);
void loop() {
  
//cmd = Serial.readStringz();
//Serial.println(cmd);
input_cmd("on");
  delay(2000);
//  input_cmd("off");

}

void send_tx(int cmd) {
  digitalWrite(txr, HIGH);
  delay(cmd);
  digitalWrite(txr, LOW);
  delay(enddelay);
}

void input_cmd (String cmd_) {

  int ondelay = 300;
  int offdelay = 1000;
  int enddelay = 2000;

  if (cmd_.compareTo("on")==0) {
    Serial.println("on send");
    send_tx(ondelay);
  }
  else if (cmd_.compareTo("off")==0) {
    Serial.println("off send");
    send_tx(offdelay);
  }
  else if (cmd_.compareTo("end")==0) {
    Serial.println(" END ");
    send_tx(enddelay);
  }
}
