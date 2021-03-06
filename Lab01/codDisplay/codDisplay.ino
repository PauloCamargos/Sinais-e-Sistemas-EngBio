 
 //http://www.arduinoecia.com.br/2013/07/display-7-segmentos.html
                            //{ A,B,C,D,E,F,G}
byte display_7seg[11][7] = {  { 1,1,1,1,1,1,0 },  // = Digito 0
                              { 1,0,0,1,1,1,1 },  // = Digito 1
                              { 0,0,1,0,0,1,0 },  // = Digito 2
                              { 0,0,0,0,1,1,0 },  // = Digito 3
                              { 1,0,0,1,1,0,0 },  // = Digito 4
                              { 0,1,0,0,1,0,0 },  // = Digito 5
                              { 0,1,0,0,0,0,0 },  // = Digito 6
                              { 0,0,0,1,1,1,1 },  // = Digito 7
                              { 0,0,0,0,0,0,0 },  // = Digito 8
                              { 0,0,0,1,1,0,0 },  // = Digito 9
                              { 1,1,1,1,1,1,1 }   // OFF
                             }; 

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // A pino 2 ardunido, 7 (no display)
  pinMode(3, OUTPUT); // B pino 3 ardunido, 6 (no display)
  pinMode(4, OUTPUT); // C pino 4 ardunido, 4 (no display)
  pinMode(5, OUTPUT); // D pino 5 ardunido, 2 (no display)
  pinMode(6, OUTPUT); // E pino 6 ardunido, 1 (no display)
  pinMode(7, OUTPUT); // F pino 7 ardunido, 9 (no display)
  pinMode(8, OUTPUT); // G pino 8 ardunido, 10 (no display)
  pinMode(9, OUTPUT); // ponto pino 9 ardunido, 5 (no display)
}

void exibeNumero(byte numero){
    byte pino_atual = 2;
    for (byte i = 0; i < 7; ++i){
      digitalWrite(pino_atual, display_7seg[numero][i]);
      ++pino_atual;
    }
}

void desligaDisplay(){
    byte pino_atual = 2;
    for (byte i = 0; i < 7; ++i){
      digitalWrite(pino_atual, display_7seg[10][i]);
      ++pino_atual;
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  byte numero = 0;
  for(numero; numero<10; numero++){
    exibeNumero(numero);
    delay(300);
  }
  digitalWrite(9, 0);
  desligaDisplay();
  delay(1000);
}
