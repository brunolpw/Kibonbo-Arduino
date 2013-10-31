int verifica()// retorna um inteiro que é a distancia.
{
  digitalWrite(TRIG, 1);
  delayMicroseconds(10);
  digitalWrite(TRIG, 0);
  
  duracao = pulseIn(ECHO, 1);
  //distancia = (duracao/29/2);
  distancia = (duracao/58);

  return distancia;
} // End of verifica();
