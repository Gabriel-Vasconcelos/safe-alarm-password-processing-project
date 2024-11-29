// Pinos do circuito
int portaBuzzer = 2;
int portaLDR = A0;
int potPin = A1;         // Pino do potenciômetro
int buttonPin = 3;       // Pino do botão
int portaLED = 4;    

// Variáveis de senha
int senha[3] = {0, 0, 0}; 
int input[3];                  // Valores inseridos pelo usuário
int index = 0;                 // Índice para rastrear tentativas
bool senhaCorreta = false;     // Indicador para desativação do alarme

void setup() {
  pinMode(portaLED, OUTPUT);
  pinMode(portaBuzzer, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Ativa o resistor interno do botão
  Serial.begin(9600);              
} 

void loop() {
  int valorLDR = analogRead(portaLDR); // Lê o valor do LDR
  //Serial.println( map(analogRead(potPin), 0, 1023, 0, 255));
  Serial.println(valorLDR);

  // Verifica a luz no LDR e o estado da senha
  if (valorLDR < 500 && !senhaCorreta) {
    ativarAlarme();
  } else {
    desativarAlarme();
  }
  
  // Sistema de senha com potenciômetro e botão
  if (digitalRead(buttonPin) == LOW) {
    delay(150); // Debounce do botão
    verificarSenha(); // Chama a função de verificação
  }
}

void ativarAlarme() {
  tone(portaBuzzer, 200);
  digitalWrite(portaLED, HIGH); 
  delay(100);
  digitalWrite(portaLED, LOW);
  delay(100);
}

void desativarAlarme() {
  noTone(portaBuzzer); // Desativa o alarme
  digitalWrite(portaLED, LOW); 
}

void verificarSenha() {
  int potValue = analogRead(potPin);  // Lê o valor do potenciômetro
  int numero = map(potValue, 0, 1023, 0, 255); // Converte o intervalo de 0 a 1023 para 0 a 255

  // Armazena o número ajustado
  input[index] = numero;
  Serial.print("Digito inserido: ");
  Serial.println(numero);
  index++;

  // Quando três números forem inseridos
  if (index == 3) {
    if (compararSenha()) {
      Serial.println("Senha correta! Alarme desativado.");
      senhaCorreta = true; // Marca o alarme como desativado
    } else {
      Serial.println("Senha incorreta! Tente novamente.");
    }
    index = 0; // Reinicia o índice para nova tentativa
  }
}

bool compararSenha() {
  for (int i = 0; i < 3; i++) {
    if (input[i] != senha[i]) {
      return false;
    }
  }
  return true;
}
