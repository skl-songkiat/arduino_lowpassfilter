int counter = 0;
float noise = 0.0;
float filter = 0.0;
float DC = 1.0;
float noiseDC = 0.0;
float offset = 0.95; // filter constant

void setup() {               
  Serial.begin(9600);
  randomSeed(100);
}

void loop() {
  counter ++; 
  if (counter <= 500) {
  noise = (float) random(0,500)/500;
  Serial.println("\t");
  Serial.print("\t");
  Serial.print(noiseDC);
  Serial.print("\t");
  Serial.print(filter);
  Serial.print("\t");
  Serial.print("");  
  }
  noiseDC = DC + noise;
  filter = EWMA(noiseDC, offset, filter);
  delay(100);

}

float EWMA(float noiseDC, float offset, float filter){
  filter = (noiseDC*(1-offset))+(filter*offset);
  return filter;
}
