const int pin_PWM = 9; // Pin válido para PWM en Arduino Mega

const float frec_seno = 2.0;
const unsigned long intervalo = 5;
unsigned long tiempoAnterior = 0;

void setup() {
  // Velocidad más estable para el Virtual Terminal de Proteus
  Serial.begin(115200); 
  pinMode(pin_PWM, OUTPUT);
}

void loop() {
  unsigned long tiempoActual = millis();

  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;

    float t = tiempoActual / 1000.0;
    float senoNormalizado = (sin(2.0 * PI * frec_seno * t) + 1.0) / 2.0;

    int duty = (int)(senoNormalizado * 255);

    // Función estándar de Arduino para PWM
    analogWrite(pin_PWM, duty);

    Serial.println(duty);
  }
}
