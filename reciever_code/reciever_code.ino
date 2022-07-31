
int rec = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(rec,INPUT);
  Serial.begin(9600);
}
unsigned long int lasttime;
unsigned long int interval;
bool flag =false;
void loop() {

  // put your main code here, to run repeatedly:
unsigned long int rec_time = pulseIn(rec,HIGH);
if(rec_time > 300){
//Serial.println(rec_time);
Serial.println(interval);
lasttime = millis();

}
else{
interval = millis()-lasttime;

}

/*
 * int ondelay = 300;
int offdelay = 1000;
int enddelay = 2000;
 * 
 * */
 */

//if (interval > 3600 && interval < 4500)
//Serial.println("end");

if ( interval > 1500 && interval <2500){
  Serial.println("on");
}
else if ( interval > 2600 && interval <3200){
  Serial.println("off");
}
}
