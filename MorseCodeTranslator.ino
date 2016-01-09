#include<string.h>

#define RED RED_LED
#define GREEN GREEN_LED
#define BLUE BLUE_LED

  char alphabet[36][6] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; 
                       //  0        1        2        3        4        5        6        7        8        9        A     B       C       D      E    F       G      H       I     J       K     L        M     N     O      P       Q       R      S      T    U      V       W      X       Y       Z  
  int speed = 1;

void setup() {  
  pinMode(RED, OUTPUT);      // 1 Unit Long
  pinMode(GREEN, OUTPUT);    // 3 Units Long
  pinMode(BLUE, OUTPUT);     // Denotes the end of the plaintext string.
}

void loop() {

  char plaintext[] =  "Enter text here";


  int i = 0;

  for(i = 0; plaintext[i] != '\0'; i++){
    
    if(plaintext[i] >= 48 && plaintext[i] <= 57)        signal(plaintext[i] - 48);
    else if(plaintext[i] >= 65 && plaintext[i] <= 90)   signal(plaintext[i] - 65 + 10); 
    else if(plaintext[i] >= 97 && plaintext[i] <= 122)  signal(plaintext[i] - 97 + 10);
    else if(plaintext[i] == 32)                         delay(4000/speed);
    
  }  
    turnOn(4000, 'B');
    delay(3000/speed);
}

void turnOn(int duration, char colour){      
  
    if(colour == 'R'){
      digitalWrite(RED, HIGH);  
      delay(duration/speed); 
      digitalWrite(RED, LOW); 
    }
    
    else if(colour == 'G'){
      digitalWrite(GREEN, HIGH);  
      delay(duration/speed); 
      digitalWrite(GREEN, LOW);
    }
    
    else if(colour == 'B'){  
      digitalWrite(BLUE, HIGH);  
      delay(duration/speed); 
      digitalWrite(BLUE, LOW);
    }  
}

void signal(int index){
    
    int i = 0;  
    
    for(i = 0; alphabet[index][i] != '\0'; i++){
   
      char code = alphabet[index][i];
      
      if(code == '-'){
        turnOn(3000, 'G');
        delay(1000/speed);
      }
      
      else if(code == '.'){
        turnOn(1000, 'R');
        delay(1000/speed);
      }
   }
       delay(2000/speed);
}
