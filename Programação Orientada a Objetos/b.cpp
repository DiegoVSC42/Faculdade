// C++ code
//
int N_C3_BAmero = 0;

int numero = 0;
int pin_a = 1;
int pin_b = 2;
int pin_c = 3;
int pin_d = 4;
int pin_e = 5;
int pin_f = 6;
int pin_g = 7;
int pin_p = 8;
int button = 13;
void setup()
{
  pinMode(button, INPUT);
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_c, OUTPUT);
  pinMode(pin_d, OUTPUT);
  pinMode(pin_e, OUTPUT);
  pinMode(pin_f, OUTPUT);
  pinMode(pin_g, OUTPUT);
  pinMode(pin_p, OUTPUT);
  
}

void loop()
{
  // Quando aperta o botão, Leds ligam alternadamente
  while (digitalRead(9) == HIGH) {
    // Cada LED liga e desliga o anterior.
    digitalWrite(2, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(3, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(2, LOW);
    digitalWrite(5, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(8, LOW);
    digitalWrite(6, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(7, LOW);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(6, LOW);
    delay(100); // Wait for 100 millisecond(s)
    // Quando chega no último, todos começam a ligar.
    digitalWrite(6, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(7, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(8, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(4, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(5, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(3, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(2, HIGH);
    delay(300); // Wait for 300 millisecond(s)
    // Todos desligam.
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(500); // Wait for 500 millisecond(s)
    // Sorteia o número
    numero = random(1, 6 + 1);
  }
  // Dependendo do número sorteado, liga os LEDs
  // correspondentes.
  if (numero == 1) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  if (numero == 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  if (numero == 3) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  if (numero == 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }
  if (numero == 5) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }
  if (numero == 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}