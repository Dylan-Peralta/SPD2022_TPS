// C++ code
//

int D1 = 4;               //Declaro N° de pin de salida del led
int D2 = 5;	              //Declaro N° de pin de salida del led	
int D3 = 6;               //Declaro N° de pin de salida del led		
int D4 = 7;               //Declaro N° de pin de salida del led
int D5 = 8;               //Declaro N° de pin de salida del led
int D6 = 9;               //Declaro N° de pin de salida del led
int D7 = 10;              //Declaro N° de pin de salida del led
int D8 = 11;              //Declaro N° de pin de salida del led
int D9 = 12;              //Declaro N° de pin de salida del led
int D10 = 13;             //Declaro N° de pin de salida del led
int boton = 2;            //Declaro N° de pin de entrada del boton Star/Pause
int pulsadorAnt = 0;      
int estado = 0;           //Para saber si esta iniciado o no 
int botonReset = 3;       //Declaro pin de entrada del boton Reset  
int segundos = 0;         //Segundos transcurridos
int y = 0;

void setup() {
pinMode(D1,OUTPUT);           //Declaro que son de salida pin de salida del led
pinMode(D2,OUTPUT);           //Declaro que son de salida pin de salida del led
pinMode(D3,OUTPUT);           //Declaro que son de salida pin de salida del led
pinMode(D4,OUTPUT);           //Declaro que son de salida pin de salida del led
pinMode(D5,OUTPUT);           //Declaro que son de salida pin de salida del led
pinMode(D6,OUTPUT);           //Declaro que son de salida pin de salida del led
pinMode(D7,OUTPUT);           //Declaro que son de salida pin de salida del led
pinMode(D8,OUTPUT);           //Declaro que son de salida pin de salida del led
pinMode(D9,OUTPUT);           //Declaro que son de salida pin de salida del led
pinMode(D10,OUTPUT);          //Declaro que son de salida pin de salida del led
pinMode(boton,INPUT_PULLUP);  //Declaro que son de entrada pin 
pinMode(botonReset,INPUT_PULLUP); //Declaro que son de entrada pin 
Serial.begin(9600); 		  //Velocidad de transmisión con la PC
}

void loop() {
  
    boton = digitalRead(2);						//Leo el estado del pin 2					
    
    if((boton == HIGH) && (pulsadorAnt == LOW)) //Verifico si esta precionado o no
    {
    	estado = 1 -estado;					//Guardo estado del boton precionado o no 
      	delay(50);
    }
    pulsadorAnt = boton;
    
    if(estado == 1){	 //Si fue precionado empieza a cronometrar 
      
        segundos++;								  //voy contando los segundos
    	delay(1000);    						  //le doy 1 segundo de espera
  		if(segundos > 1023){					  //Verifico que segundos no supere los 1023 seggundos
    	segundos = 0;							  //De superar los 1023 segundos, el cronometro se para y vuelve a 0		
        estado = 0;
        }
      	y = segundos;								
		for(int i=4; i<=13; i++)				  
		{
		digitalWrite(i,y%2);					  	
        y=y/2; 
        }
      	

      	Serial.print(" Seconds: ");               //Imprimo en el monitor en serie los Seconds 
      	Serial.print(segundos);					  //Imprimo en el monitor en serie el valor de los segundos
		Serial.print("    |    Binary: ");		  //Imprimo en el monitor en serie la palabra Binary 	
    	String numeroBinario = String(segundos, BIN); //Transformo de decimal a binario el segundo 
   		int restantes = 9 - numeroBinario.length();

		for(int i = 0; i < restantes; i++){	 	  //Paso los ceros al lado izquierdo
			numeroBinario = "0" + numeroBinario;
			}
		Serial.println(numeroBinario);                //Imprimo en el monitor en serie el valor en binario
    }
    else{
      delay(50);
      digitalWrite(4, LOW); //Si el boton no fue precionado no inicia
      
    }

  if(digitalRead(botonReset) == HIGH)   //Si el boton fue precionado resetea el cronometro, parandolo y comenzando desde cero 
  {
    delay(50);
    estado = 0;
    segundos = -1;
   }
 
  }
  
  

