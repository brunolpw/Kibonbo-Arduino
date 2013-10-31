void moveCabeca()
{
   head.write(posH);
   delay(300);
   
  for(int pos = posH; pos < 180; pos++)
  {
    head.write(pos);
    delay(resposta);
  }
  moveL = verifica();
  //Serial.print(moveL);
  //Serial.println(" CM Left");
  
  for(int pos = 180; pos > -1; pos--)
  {
    head.write(pos);
    delay(resposta);
  }
  moveR = verifica();
  //Serial.print(moveR);
  //Serial.println(" CM Right");
  
  for(int pos = 0; pos < posH; pos++)
  {
    head.write(pos);
    delay(resposta);
  }
  moveC = verifica();
  //Serial.print(moveC);
  //Serial.println(" CM Center");
  
  if((moveC >= moveL) && (moveC >= moveR)){/*Serial.println("Move Center");*/ andarFrente(); delay(500); }
  if((moveL > moveC) && (moveL > moveR)){/*Serial.println("Move Left");*/ virarEsquerda(); delay(500); }
  if((moveR > moveL) && (moveR > moveC)){/*Serial.println("Move Right");*/ virarDireita(); delay(500); }
  
  if((moveC <= 30) && (moveL <= 30) && (moveR <= 30))
  {
    andarRe();
    delay(500);
    if(moveR > moveL){ virarDireita(); }
    if(moveL > moveR){ virarEsquerda(); }
  }
} // End of moveCabeca();
