/*
write on the windows cmd to change the folder address
  cd C:\git\ADIS16405
Execute the interface
  python plot_data.py -p COM3 -r 9600
*/


#include "ADIS16405.h"
#include <SPI.h>

// Instantiate ADIS16 class as iSensor with CS pin 53
// ****Use this for Mega 2560 setup****
//ADIS16364 iSensor(53);

// Instantiate ADIS16364 class as iSensor with CS pin 10
ADIS16364 iSensor(10);

void setup (){
  // Start serial
  Serial.begin(9600);
  delay(100);  
}

void loop()
{

  // Print out debug information
  // ****NOTE****
  // this will mess up the plotting program if you do this at the same time
  // so only use it if you want to verify setup before plotting 
  //iSensor.debug();
  
  // If serial has received 
  if(Serial.available() > 0)
  {   
    // if the recieved character is 'D'
      if(Serial.read() == 'D'){
        // Perform burst read on iSensor
        iSensor.burst_read();
  
        // Formating is specific to the python script provided
        Serial.print("[ ");
        for(int i = 0; i < 12; i++){
              if (i==1 || i==2 || i==3 || i==4 || i==5 || i==6){
                  Serial.print(iSensor.sensor[i]);
                  if(i<=6)
                  Serial.print(" ");
                  }
            }
        Serial.println("]");
        
       }
  }
  
}
