
int rec = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(rec, INPUT);
  Serial.begin(9600);
}

bool flag = false;

char reciever_rx(void);

int interval_fn(void);
void loop() {
  int time_ = interval_fn();
  Serial.println(time_);
  char cmd_rtn = recieve_rx(time_);
}


char recieve_rx(int interval_arg) {
  if ( interval_arg > 1500 && interval_arg < 2500) {
    //		Serial.println("on");/
    return 'n';
  }
  else if ( interval_arg > 2600 && interval_arg < 3200) {
    //		Serial.println("off");
    return 'f';
  }
  else if (interval_arg > 3300 && interval_arg < 5000) {
    //  Serial.println("end");/
    return 'e';
  }
}

int interval_fn() {
  unsigned long int lasttime;
  unsigned long int interval;
  unsigned long int rec_time = pulseIn(rec, HIGH);
  if (rec_time > 300) {
    //    Serial.println(interval);/
    lasttime = millis();
  }
  else {
    interval = millis() - lasttime;
    return interval;
  }
}
