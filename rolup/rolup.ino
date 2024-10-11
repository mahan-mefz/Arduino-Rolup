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

      // do {
      //   // کالیبره کردن کد 
      // digitalWrite(motorbala, LOW);
      // digitalWrite(motorpain, LOW);
      // if (microsowich == HIGH){
      //   return;
      // }  
      // } while (an == 2);

  if (btna == LOW && btnb == LOW) {
      
      // مودل هوشمند 
      if (phtosel == LOW && motorstats == 0) {
            digitalWrite(motorbala, LOW);
            digitalWrite(motorpain, LOW);
            motorstats = 1;
          if (microsowich == HIGH ){ 
            return;
          }
      } else if (phtosel == HIGH && motorstats == 1){
          digitalWrite(motorbala, HIGH);
          digitalWrite(motorpain, HIGH);
          // موتور روشن شود 
          delay(1900);
          // بعد از تایم مد نظر 
          digitalWrite(motorbala, LOW);
          digitalWrite(motorpain, LOW);
          //موتور خاموش شود 
          motorstats = 0 ;
          // وضعیت موتور 
        } else {

      }
  }else if (btna == HIGH && btnb == LOW && motorstats == 1) { 
    // بالا رفتن 
    // موتور روشن شود 
    digitalWrite(motorbala,HIGH);
    digitalWrite(motorpain, HIGH);
    //  بعد از تمام شدن تایم
      delay(1000);
    //  بعد از تمام شدن تایم
    digitalWrite(motorbala,LOW);
    digitalWrite(motorpain,LOW);
    // موتور خاموش شود 
    motorstats = 0 ;

  } else if (btnb == HIGH && motorstats == 0) {
    // پایین اومد
    digitalWrite(motorbala,HIGH);
    digitalWrite(motorpain, HIGH);
    //روشن شدن موتور
      delay(1000);
    // تایمر برای موتور 
    digitalWrite(motorbala,LOW);
    digitalWrite(motorpain,LOW);
    // موتور در خاموش شود 

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