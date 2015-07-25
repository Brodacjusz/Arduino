bool status = true;

void setup() 
{
  pinMode(13, OUTPUT); //czerwone
  pinMode(12, OUTPUT); //zolte
  pinMode(11, OUTPUT); //zielone
  status = true;
}

void czer_ziel()
{
  digitalWrite(13, HIGH); 
  delay(3000);
  digitalWrite(12, HIGH); 
  delay(3000);
  digitalWrite(13, LOW);    
  digitalWrite(12, LOW); 
  digitalWrite(11, HIGH); 
}

void ziel_czer()
{
  digitalWrite(11, HIGH); 
  delay(3000);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH); 
  delay(3000);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);  
}

void loop() 
{
  if (status == true) //zaczyna zawsze od zielonego
  {
    ziel_czer();
    delay(5000);
    status = false;
  }   
  else
  {
    czer_ziel();
    delay(5000);
    status = true; 
  }
}
