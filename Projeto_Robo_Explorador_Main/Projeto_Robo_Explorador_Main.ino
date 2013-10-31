#include <Servo.h>

/* Servo da cabeça do robô. */
#define SERVO_HEAD 3 // Define que o pino 3 será usado para o servo da cabeça.

/* Servos das rodas do robô. */
#define SERVO_LEFT 5 // Define que o pino 5 será usado para a roda esquerda.
#define SERVO_RIGHT 6 // Define que o pino 6 será usado para a roda direita.

/* Definições do sonar. */
#define TRIG 11 // Define o pino 11 como o gatilho do sonar.
#define ECHO 12 // Define o pino 12 como o receptor do sonar.

#define resposta 10 //Define o valor de resposta padrão para o sensor.

/* Servos */
Servo head;
Servo wheel_L;
Servo wheel_R;

int posH = 90, posL = 85, posR = 90;

/* Sonar. */
int distancia = 0, duracao = 0;
int moveC = 0, moveL = 0, moveR = 0, verify = 0;

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  head.attach(SERVO_HEAD); // Recebe o valor do pino atribuido.
  wheel_L.attach(SERVO_LEFT); // Recebe o valor do pino atribuido.
  wheel_R.attach(SERVO_RIGHT); // Recebe o valor do pino atribuido.
  
  head.write(posH); // Inicia a cabeça com 90.
  wheel_L.write(posL); // Inicia a roda esquerda com 85.
  wheel_R.write(posR); // Inicia a roda direita com 90.
  
  pinMode(TRIG, OUTPUT); // Define o gatilho como uma saida.
  pinMode(ECHO, INPUT); // Define o retorno como uma entrada.
} // End of setup();

void loop()
{
  verify = verifica();
  if((verify <= 30) && (verify >= 2))
  {
    parar();
    //Serial.println("Distancia da frente fora do limite!");
    moveCabeca();
  }
  Serial.println(verify);
  //Serial.println(" CM");
  andarFrente();
  delay(50);
} // End of loop();

