//Heat controlled fan
//UNO R3 + L293D motor

int tempPin = 2;       //thermistor wired to pin A2
const int onTemp = 80;
const int offTemp = 77; //hysteresis, intentional gap to prevent fan from rapid switching
bool fanOn = false;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(3, HIGH);  // Determines counter-clockwise rotation
  digitalWrite(4, LOW);   // Turns off clockwise rotation
  Serial.begin(9600);
}

void loop() {
double tempK = log(10000.0 * ((1024.0 / analogRead(2) - 1)));  //converts voltage reading to thermistor resistance
tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );
float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
float tempF = (tempC * 9.0)/ 5.0 + 32.0 - 15.0; // Convert Celcius to Fahrenheit as well as an offset due to an inaccurate reading I experienced

if (tempF >= onTemp) { 
  fanOn = true;
}

if (tempF <= offTemp){
fanOn = false;
}

if (fanOn) {
  digitalWrite(5, HIGH);
} else {
  digitalWrite (5,LOW);
}

Serial.println(tempF); 
delay(500);       // serial monitor reads twice per second
}

