int potValue = 128; // Valor do Potenciômetro
int[] senhaInserida = {0, 0, 0}; // Mock da senha digitada
boolean alarmeAtivado = true; // Mock do estado do alarme

void setup() {
  size(400, 400);
  textAlign(CENTER, CENTER);
}

void draw() {
  // Fundo com gradiente
  for (int y = 0; y < height; y++) {
    stroke(30 + y / 10, 30 + y / 20, 50 + y / 15); // Tons de azul
    line(0, y, width, y);
  }
  
  //background(30);
  
  // Exibição do valor do potenciômetro
  fill(255);
  textSize(16);
  text("Valor do Potenciômetro:", width / 2, height / 4 - 32);
  textSize(32);
  text(potValue, width / 2, height / 4);

  // Exibição das senhas inseridas
  textSize(16);
  text("Senhas Inseridas:", width / 2, height / 2 - 32);
  textSize(32);
  text("[" + senhaInserida[0] + "] [" + senhaInserida[1] + "] [" + senhaInserida[2] + "]", width / 2, height / 2);

  // Indicador do estado do alarme
  fill(alarmeAtivado ? color(222, 0, 0) : color(0, 222, 0)); // Vermelho para ativado, verde para desativado
  ellipse(width / 2, 3 * height / 4, 44, 44);
  fill(255);
  textSize(16);
  text(alarmeAtivado ? "Alarme Ativado" : "Alarme Desativado", width / 2, 3 * height / 4 + 40);
}
