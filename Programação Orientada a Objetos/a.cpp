// C++ code
//

int numero = 0;
int alt =    4;

int pin_a =  2;
int pin_b =  3;
int pin_c =  4;
int pin_d =  5;
int pin_e =  6;
int pin_f =  7;
int pin_g =  8;


int alternator = 15;
int button = 14;
int counter = 16;

int led_red = 10;
int led_green = 11;
int led_blue = 12;
int led_sup = 9;


void setup(){
  
  pinMode(button, INPUT_PULLUP);
  pinMode(alternator, INPUT_PULLUP);
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_c, OUTPUT);
  pinMode(pin_d, OUTPUT);
  pinMode(pin_e, OUTPUT);
  pinMode(pin_f, OUTPUT);
  pinMode(pin_g, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(led_sup, OUTPUT);
  Serial.begin(9600);
  
}

void loop(){

    if(alt == 4){
      digitalWrite(led_red,LOW);
      digitalWrite(led_green,LOW);
      digitalWrite(led_blue,HIGH);
    }
    if(alt == 6){
      digitalWrite(led_red,LOW);
      digitalWrite(led_green,HIGH);
      digitalWrite(led_blue,LOW);
    }

    if(alt == 8){
      digitalWrite(led_red,HIGH);
      digitalWrite(led_green,LOW);
      digitalWrite(led_blue,LOW);
    }
    if(alt == 10){
      digitalWrite(led_red,LOW);
      digitalWrite(led_green,HIGH);
      digitalWrite(led_blue,HIGH);
    }
    if(alt == 12){
      digitalWrite(led_red,HIGH);
      digitalWrite(led_green,HIGH);
      digitalWrite(led_blue,LOW);
    }

    if(alt == 20){
      digitalWrite(led_red,HIGH);
      digitalWrite(led_green,HIGH);
      digitalWrite(led_blue,HIGH);
    }
      	
  	if(digitalRead(alternator) == HIGH){
      Serial.print("alt antes: ");
      Serial.println(alt);
      switch (alt){
      
      	case 4:
      		alt = 6;
        	delay(300);
      		break;
      	case 6:
      		alt = 8;
      		delay(300);
        	break;	
      	case 8:	
      		alt = 10;
    		delay(300);
        	break;
        case 10:	
      		alt = 12;
        	delay(300);
        	break;
        case 12:	
      		alt = 20;
        	delay(300);
        	break;
        case 20:	
      		alt = 4;
        	delay(300);
    		break;
      	default:
      		alt = 4;
        	delay(300);
      		break;
       
      }
      Serial.print("alt depois: ");
      Serial.println(alt);
    }

  // Quando aperta o botão, Leds ligam alternadamente
  while (digitalRead(button) == HIGH){
		Serial.print("Numero antes: ");
  		Serial.println(numero);
        // Cada LED liga e desliga o anterior.
        digitalWrite(pin_a, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_b, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_a, LOW);
        digitalWrite(pin_c, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_b, LOW);
        digitalWrite(pin_d, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_c, LOW);
        digitalWrite(pin_e, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_f, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_a, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_f, LOW);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_a, LOW);
        delay(100); // Wait for 100 millisecond(s)
        // Quando chega no último, todos começam a ligar.
        digitalWrite(pin_f, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_e, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_d, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_c, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_b, HIGH);
        delay(100); // Wait for 100 millisecond(s)
        digitalWrite(pin_a, HIGH);
        delay(400); // Wait for 400 millisecond(s)
        // Todos desligam.
        digitalWrite(pin_a, LOW);
        digitalWrite(pin_b, LOW);
        digitalWrite(pin_c, LOW);
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, LOW);
        digitalWrite(pin_g, LOW);
        delay(600); // Wait for 600 millisecond(s)

      	if(alt == 4){
        	numero = random(1, 4 + 1);
      	}
      	if(alt == 6){
        	numero = random(1, 6 + 1);
      	}

      	if(alt == 8){
        	numero = random(1, 8 + 1);
      	}
        if(alt == 10){
        	numero = random(1, 10 + 1);
      	}
        if(alt == 12){
        	numero = random(1, 12 + 1);
      	}
        if(alt == 20){
        	numero = random(1, 20 + 1);
      	}
      	Serial.print("Numero depois: ");
  		  Serial.println(numero);
    }
  while (digitalRead(counter) == HIGH){
		Serial.print("Numero antes: ");
  		Serial.println(numero);
		numero++;
    	delay(300);
      	Serial.print("Numero depois: ");
    	Serial.println(numero);
    }
  
    // Dependendo do número sorteado, liga os LEDs
    // correspondentes.
    if (numero == 1) {
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, LOW);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, LOW);
        digitalWrite(pin_g, LOW);
    
    }
    if (numero == 2) {
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, LOW);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, HIGH);
        digitalWrite(pin_f, LOW);
        digitalWrite(pin_g, HIGH);
    
    }
    if (numero == 3) {
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, LOW);
        digitalWrite(pin_g, HIGH);

    }
    if (numero == 4) {
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, LOW);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);

    }
    if (numero == 5) {
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, LOW);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);

    }
    if (numero == 6) {
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, LOW);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, HIGH);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);

    }
    if (numero == 7) {
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, LOW);
        digitalWrite(pin_g, LOW);

    }
    if (numero == 8) {
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, HIGH);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);
        
    }
    if (numero == 9) {
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);
        
    }
    if(numero == 10){
        //Display 2
        digitalWrite(led_sup,LOW);
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, HIGH);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, LOW);
    }
    if(numero == 11){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, LOW);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, LOW);
        digitalWrite(pin_g, LOW);
    }
    if(numero == 12){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, LOW);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, HIGH);
        digitalWrite(pin_f, LOW);
        digitalWrite(pin_g, HIGH);
    }
    if(numero == 13){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, LOW);
        digitalWrite(pin_g, HIGH);
    }
    if(numero == 14){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, LOW);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);
    }
    if(numero == 15){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, LOW);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);
    }
    if(numero == 16){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, LOW);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, HIGH);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);
    }
    if(numero == 17){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, LOW);
        digitalWrite(pin_g, LOW);
    }
    if(numero == 18){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, HIGH);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);
    }
    if(numero == 19){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, LOW);
        digitalWrite(pin_e, LOW);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, HIGH);
    }
    if(numero == 20){
        //Display 1
        digitalWrite(led_sup,HIGH);
        //Display 2
        digitalWrite(pin_a, HIGH);
        digitalWrite(pin_b, HIGH);
        digitalWrite(pin_c, HIGH);
        digitalWrite(pin_d, HIGH);
        digitalWrite(pin_e, HIGH);
        digitalWrite(pin_f, HIGH);
        digitalWrite(pin_g, LOW);
    }


    
    
}