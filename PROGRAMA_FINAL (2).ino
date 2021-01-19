#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     7

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

int mdf = 11, mdt = 6, mef = 5, met = 3;
int sdx = A3, sd = 10, sc = 2, se = 9, sex = 4, cord = A2, core = A1;
int lsdx = 0, lsd = 0, lsc = 0, lsex = 0, lse = 0, lcord = 0, lcore = 0;
int controle = 0;
int ultra = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(mdf, OUTPUT);
  pinMode(mdt, OUTPUT);
  pinMode(mef, OUTPUT);
  pinMode(met, OUTPUT);
  pinMode(sdx, INPUT);
  pinMode(sd, INPUT);
  pinMode(sc, INPUT);
  pinMode(sex, INPUT);
  pinMode(se, INPUT);
  pinMode(core, INPUT);
  pinMode(cord, INPUT);
  delay (2000);
}

void loop() {

  lsd = digitalRead(sd);
  lsc = digitalRead(sc);
  lse = digitalRead(se);
  lsdx = digitalRead(sdx);
  lsex = digitalRead(sex);
  lcord = analogRead(cord);
  lcore = analogRead(core);

  // Seguir Linha
  if (lsex == 1 && lse == 1 && lsc == 0 && lsd == 1 && lsdx == 1) {
    analogWrite (mdt, 0);
    analogWrite (met, 0);
    analogWrite (mef, 255);
    analogWrite (mdf, 255);
  }

  // Alinhar Esquerdo
  if (lsex == 1 && lse == 0 && lsc == 1 && lsd == 1 && lsdx == 1) {
    analogWrite (mdt, 0);
    analogWrite (mef, 0);
    analogWrite (mdf, 255);
    analogWrite (met, 255);
  }

  // Alinhar Esquerdo Extremo
  if (lsex == 0 && lse == 1 && lsc == 1 && lsd == 1 && lsdx == 1) {
    analogWrite (mdt, 0);
    analogWrite (mef, 0);
    analogWrite (mdf, 255);
    analogWrite (met, 255);
  }

  // Alinhar Direito
  if (lsex == 1 && lse == 1 && lsc == 1 && lsd == 0 && lsdx == 1) {
    analogWrite (met, 0);
    analogWrite (mdf, 0);
    analogWrite (mdt, 255);
    analogWrite (mef, 255);
  }

  // Alinhar Direito Extremo
  if (lsex == 1 && lse == 1 && lsc == 1 && lsd == 1 && lsdx == 0) {
    analogWrite (met, 0);
    analogWrite (mdf, 0);
    analogWrite (mdt, 255);
    analogWrite (mef, 255);
  }

  //Quadradinho Verde Meia Volta
  if (lcore >= 53 && lsex == 0 && lse == 0 && lsc == 0 && lsd == 0 && lsdx == 0  && lcord >= 34) {
    //virar pra esquerda em 180 graus
    analogWrite (mdf, 0);
    analogWrite (mef, 0);
    analogWrite (met, 0);
    analogWrite (mdt, 0);
    delay (300);
    analogWrite (mdf, 255);
    analogWrite (met, 255);
    delay (1500);
  }

  // Curva de 90º Esquerda
  if (lsex == 0 && lse == 0 && lsc == 0 && lsd == 1 && lsdx == 1) {
    analogWrite (mdf, 0);
    analogWrite (mef, 0);
    analogWrite (met, 0);
    analogWrite (mdt, 0);
    analogWrite (mdf, 255);
    analogWrite (mef, 255);
    delay (500);
    analogWrite (mdf, 0);
    analogWrite (mef, 0);
    controle = 1;
  }
  // Segundo If Curva de 90° esquerda
  if (lsex == 1 && lse == 1 && lsc == 1 && lsd == 1 && lsdx == 1 && controle == 1) {
    analogWrite (met, 255);
    analogWrite (mdt, 255);
    delay (600);
    analogWrite (met, 0);
    analogWrite (mdt, 0);
    analogWrite (met, 255);
    analogWrite (mdf, 255);
    delay (300);
    controle = 0;
  }

  //Curva de 90° Direita
  if (lsex == 1 && lse == 1 && lsc == 0 && lsd == 0 && lsdx == 0) {
    analogWrite (mdf, 0);
    analogWrite (mef, 0);
    analogWrite (met, 0);
    analogWrite (mdt, 0);
    analogWrite (mdf, 255);
    analogWrite (mef, 255);
    delay (500);
    analogWrite (mdf, 0);
    analogWrite (mef, 0);
    controle = 2;
  }
  //Segundo IF Curva de 90° Direita
  if (lsex == 1 && lse == 1 && lsc == 1 && lsd == 1 && lsdx == 1 && controle == 2) {
    analogWrite (mdt, 255);
    analogWrite (met, 255);
    delay (600);
    analogWrite (mdt, 0);
    analogWrite (met, 0);
    analogWrite (mef, 255);
    analogWrite (mdt, 255);
    delay (300);
    controle = 0;
  }

  // GAP E CRUZAMENTO
  if (lsex == 0 && lse == 0 && lsc == 0 && lsd == 0 && lsdx == 0) {
    analogWrite (mdt, 0);
    analogWrite (met, 0);
    analogWrite (mef, 255);
    analogWrite (mdf, 255);
  }

  // Quadradinho Verde Esquerda e Cruzamento
  if (((lcore >= 53) && (lsex == 0 && lse == 0 && lsc == 0 && lsd == 1 && lsdx == 1 && ( lcord <= 30))) || ((lcore >= 53) && (lsex == 0 && lse == 0 && lsc == 0 && lsd == 0 && lsdx == 0 && ( lcord <= 30)))) {
    analogWrite (mdf, 0);
    analogWrite (mef, 0);
    analogWrite (met, 0);
    analogWrite (mdt, 0);
    delay (300);
    analogWrite (mdf, 255);
    analogWrite (met, 255);
    delay (500);
  }

  // Quadradinho Verde Direita e cruzamento
  if ((((lcore <= 50) && lsex == 1 && lse == 1 && lsc == 0 && lsd == 0 && lsdx == 0) && (lcord >= 34)) || (((lcore <= 50) && lsex == 0 && lse == 0 && lsc == 0 && lsd == 0 && lsdx == 0) && (lcord >= 34))) {
    analogWrite (mdf, 0);
    analogWrite (mef, 0);
    analogWrite (met, 0);
    analogWrite (mdt, 0);
    delay (300);
    analogWrite (mef, 255);
    analogWrite (mdt, 255);
    delay (500);
  }

  //Quadradinho Verde Meia Volta
  if (lcore >= 53 && lsex == 0 && lse == 0 && lsc == 0 && lsd == 0 && lsdx == 0  && lcord >= 34) {
    //virar pra esquerda em 180 graus
    analogWrite (mdf, 0);
    analogWrite (mef, 0);
    analogWrite (met, 0);
    analogWrite (mdt, 0);
    delay (300);
    analogWrite (mdf, 255);
    analogWrite (met, 255);
    delay (1500);
  }

  long distancia = ultrasonic.timing();

  //ultrassonico
  if (distancia <= 400) {

    //virar direita
    analogWrite(mdf, 0);
    analogWrite(met, 0);
    analogWrite(mdt, 255);
    analogWrite(mef, 255);
    delay (800);

    // seguir reto
    analogWrite(mdt, 0);
    analogWrite(met, 0);
    analogWrite(mdf, 255);
    analogWrite(mef, 220);
    delay (1000);

    //virar esquerda
    analogWrite(mdf, 0);
    analogWrite(mdf, 0);
    analogWrite(mdf, 255);
    analogWrite(met, 255);
    delay (1200);

    //seguir reto
    analogWrite(mdt, 0);
    analogWrite(met, 0);
    analogWrite(mdf, 255);
    analogWrite(mef, 225);
    delay (2200);

    //virar esquerda
    analogWrite(mdf, 0);
    analogWrite(mdf, 0);
    analogWrite(mdf, 255);
    analogWrite(met, 220);
    delay (1500);

    //seguir reto
    analogWrite(mdt, 0);
    analogWrite(met, 0);
    analogWrite(mdf, 255);
    analogWrite(mef, 255);
    delay (1500);
    ultra = 1;
  }

  //alinhar para voltar a linha
  if (lsex == 0 && lse == 0 && lsc == 0 && lsd == 0 && lsdx == 0 && ultra == 1 ) {
    analogWrite(mdf, 0);
    analogWrite(mef, 0);
    analogWrite(mdf, 255);
    analogWrite(met, 220);
    delay (500);
    ultra = 0;
  }
}
