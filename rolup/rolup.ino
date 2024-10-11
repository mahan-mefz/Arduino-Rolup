int phtosel = 13 ;
int microsowich = 12 ;
int motorbala = 11 ;
int motorpain = 10 ;
int btna  = 9 ;
int btnb = 8 ;



int motorstats = 0 ;
bool btnstatus = false ; 
bool swith = false ; 




int an = 1 ;
 
void setup() {
  
  pinMode(motorbala,OUTPUT); 
    // موتور بالا 
  pinMode(motorpain,OUTPUT);
    // موتور پایین 
  pinMode(btna,INPUT);
  pinMode(btnb,INPUT);
    // کلید  
  pinMode(phtosel,INPUT);
    // فوتوسل 
  pinMode(microsowich,INPUT);
    // میکروسویچ
}

void loop() {

      do {
        // کالیبره کردن کد 
      digitalWrite(motorbala, LOW);
      digitalWrite(motorpain, LOW);
      if (microsowich == HIGH){
        return;
      }  
    } while (return);

  if (btna == LOW && btnb == LOW) {
      
      // مودل هوشمند 
      if (phtosel == LOW && motorstats == 0) {
            digitalWrite(motorbala, LOW);
            digitalWrite(motorpain, LOW);
            motorstats = 1;
          if (microsowich == HIGH ){
            swith = true ; 
            return;
          }
      } else if (phtosel == HIGH && motorstats == 1){
          digitalWrite(motorbala, HIGH);
          digitalWrite(motorpain, HIGH);
          // موتور روشن شود 
          delay(190);
          // بعد از تایم مد نظر 
          digitalWrite(motorbala, LOW);
          digitalWrite(motorpain, LOW);
          //موتور خاموش شود 
        } else {

      }
  }else if (btna == HIGH && btna ) { 
    digitalWrite(motorbala,HIGH);
    digitalWrite(motorpain, HIGH);
      delay(100);
    digitalWrite(motorbala,LOW);
     digitalWrite(motorpain,LOW);
    an = 1 ; 

  } else if (btnb == HIGH && motorstats == false) {

    digitalWrite(motorbala,HIGH);
    digitalWrite(motorpain, HIGH);
      delay(100);
    digitalWrite(motorbala,LOW);
      digitalWrite(motorpain,LOW);
    an = 2 ; 


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