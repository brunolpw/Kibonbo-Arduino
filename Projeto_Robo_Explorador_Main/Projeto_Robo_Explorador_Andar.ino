/*
 * posL = 300
 * posR = 0
 * 
 * Para o robô andar para frente, pois um tem de ficar invertido com relação ao outro.
 * */

void parar()
{
  //posL = 85;
  //posR = 90;
  wheel_L.write(posL);
  wheel_R.write(posR);
} // End of parar();

void andarFrente()
{
  wheel_L.write(posL + 250);
  wheel_R.write(posR - 250);
} // End of andarFrente();

void virarEsquerda()
{
  wheel_L.write(posL + 250);
  wheel_R.write(posR);
} // End of virarEsquerda();

void virarDireita()
{
  wheel_L.write(posL);
  wheel_R.write(posR - 250);
} // End of virarDireita();

void andarRe()
{
  wheel_L.write(posL - 250);
  wheel_R.write(posR + 250);
} // End of andarRe();
