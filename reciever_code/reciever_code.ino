
int rf_receiver_pin = 11;  // ASK RECEIVER PIN
void setup() {
	// put your setup code here, to run once:
	pinMode(rf_receiver_pin, INPUT);
	Serial.begin(9600);
}

String reciever_rx(int);

void loop() {

	//  String cmd_rtn = recieve_rx(time_);
	//    Serial.println(cmd_rtn);
	int pulseIN_rx = pulseIn(rf_receiver_pin,HIGH);
//	String cmd = recieve_rx(rf_receiver_pin);
//	Serial.println(cmd);
	Serial.println(pulseIN_rx);
	delay(300);
}
String recieve_rx(int rec_pin) {
	int off_sg_xf = 11000;	// OFF command pulseIN pulseIN_rx Mid value
	int on_sg_xf = 1000; /// ON command pulseIN pulseIN_rx Mid value
	const int tolerance = 2000;

	// set upper and lower threshold
	const int off_sg_up = off_sg_xf + tolerance; 
	const  int off_sg_lw = off_sg_xf - tolerance; 
	const  int on_sg_up = on_sg_xf + tolerance; 
	const  int on_sg_lw = on_sg_xf - tolerance;  

	const int noise_threshold = 800;   /// threshold value when no signal is transmitted

	int pulseIN_low = pulseIn(rec_pin,LOW);
	int pulseIN_rx = pulseIn(rec_pin,HIGH);
	if (pulseIN_rx > noise_threshold){
		if (on_sg_up > pulseIN_rx > on_sg_lw) {
			//		Serial.println("on");/
			return "LED ON";
		}
		else if (off_sg_up > pulseIN_rx > off_sg_lw) {
			//		Serial.println("off");
			return "LED OFF";
		}
	}
	else
	{
		// not receiving any signal from tx
	}
}
