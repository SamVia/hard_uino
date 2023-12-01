#define LM335_PIN A3 // Pin collegato al sensore LM335
#define Vint 5.0 // Tensione di alimentazione
#define Nb 10 // Risoluzione ADC
//#define Nb 12
//#define Nb 14
#define A 3.9083E-3
#define B -5.775E-7
//valori delle resistenze
#define R0 100.0
#define Rf 0.0
//Rf e' uguale a R0 apparentemente, uso di Rf = 1kOhm? 
int sensorValue;
double Rt = R0*(1+A*theta+B*pow(theta,2));
double Vf = Vint*Rf/(Rf+Rt);
double theta = -A/(2*B)-sqrt(pow(A,2)/(4*pow(B,2))-1/(R0*B)*(R0+Rf-Vs/Vf*Rf)); //inserire valore corretto
//double theta = -A/(2*B)-sqrt(pow(A,2)/(4*pow(B,2))-1/(R0*B)*(R0+Rf-pow(2,Nb)/sensorValue*Rf));


double new_temperature;
double temperature;
float C_temperature;


void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
}

void loop() {
  if (Serial.available()) {
    serialEvent();
  }
  // se la seriale è avviabile avvia la comunicazione 
}
void serialEvent(){
  while (Serial.available()) {
    sensorValue = analogRead(LM335_PIN); // Legge il valore dal sensore
    Serial.print("Dout ");
    Serial.print(sensorValue);
  }
}