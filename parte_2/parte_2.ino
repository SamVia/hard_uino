#define LM335_PIN A3 // Pin collegato al sensore LM335
#define Vint 1.109 // Tensione di alimentazione
#define ADC_RESOLUTION 1024.0 // Risoluzione ADC
#define S 0.01 
//valori delle resistenze
#define R2 21800 
#define R3 9700

int sensorValue;
float new_temperature;
float temperature;
float C_temperature;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(INTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:
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

    //FSR*Dout/(10mV/K)*2^Nb
    //((Dout*Vint)/(2^nb*S))*(1+(R2/R3))
    double a = Vint/ADC_RESOLUTION;
    float b = R2/R3;
    Serial.print(" K ");
    temperature = (sensorValue)*(a)*(1/S)*(1+(R2/R3)); // Converte il valore in tensione
    Serial.print(temperature);

    Serial.print(" Celsius ");
    C_temperature = temperature - 273.15; // Converte Kelvin in Celsius
    Serial.print(C_temperature);
    Serial.print("\n");
    delay(1500);
  }
}