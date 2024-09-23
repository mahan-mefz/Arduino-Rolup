int phtosel = 13 ;
int microsowich = 12 ;
int motorbala = 11 ;
int motorpain = 10 ;
int btna  = 9 ;
int btnb = 8 ;

boolean motorstats = false ;
boolean btnstatus = false ; 
boolean swith = false ; 

void setup() {
  // put your setup code here, to run once:
  pinMode(motorbala,OUTPUT); 
  pinMode(motorpain,OUTPUT);
  pinMode(btnb,INPUT);
  pinMode(phtosel,INPUT);
  pinMode(btna,INPUT);
  pinMode(microsowich,INPUT);
}

void loop() {
  if (btna == LOW && btnb == LOW) {
      
      if (phtosel == LOW && motorstats == false) {
            digitalWrite(motorbala, LOW);
            digitalWrite(motorpain, LOW);
            motorstats = true;
          if (microsowich == HIGH ){
            swith = true ; 
            return;
            
          }
      } else if (phtosel == HIGH && motorstats == true){
          digitalWrite(motorbala, HIGH);
          digitalWrite(motorpain, HIGH);
          delay(190);
          digitalWrite(motorbala, LOW);
          digitalWrite(motorpain, LOW);
            swith = false;
            motorstats = false ;
        } else {

      }
  }else if (btna == HIGH ) {
      return;
  } else if (btnb == HIGH) {
    return;

  }

}
// void dasti(){

//   if (dupol == HIGH && motorstats == false){
//           digitalWrite(motorbala, HIGH);
//           digitalWrite(motorpain, HIGH);
//           delay(190);
//           digitalWrite(motorbala, LOW);
//           digitalWrite(motorpain, LOW);
//           swith = false ; 
        
//   }else if (dupol == LOW && motorstats == true) {
//             digitalWrite(motorbala, LOW);
//             digitalWrite(motorpain, LOW);
//             motorstats = true;
//               if (microsowich == HIGH ){
//                 swith = true ;
//                 return;
                
//               }
//   }
// }