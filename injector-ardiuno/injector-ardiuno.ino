/**
 * The value on the variable mode change the comportment of the program.
 * Four 4 pulse mode available:
 * Mode 1: outputs 1 pulse, pulse width about 250ms is which.
 * Mode 2: 50 Output impulse, each pulse pulse width is about 7ms.
 * Mode 3: 100 Output pulses, every pulse width/pulse rate is about 3.5ms.
 * Mode 4: Output impulse continuously at a speed of 50 pulses per approx. 1450MS, pulse pulse width approx. 7ms.
 **/
/* USER config part */
unsigned int sig_pin=15; // Pin 15 = A1 on the arduino nano
unsigned int mode = 3; // 4 modes possibles

/* pulse mode config part */
// number of pulse for each mode
unsigned int modes_nb_pulse[4] = {1, 50, 100, 50}; 
// width of the pulse for each mode in ms or µs
unsigned int modes_pulse_width_ms[4] = {1, 1, 0, 1};
// width of the pulse for each mode
unsigned int modes_pulse_width[4] = {250, 7, 3500, 7};
// if repetetion the interval between in ms
unsigned long modes_pulse_repetition_ms[4] = {0, 0, 0, 1450};

/**
 * The setup function runs once when you press reset or power the board
 */
void setup() {
  // initialize digital pin "sig_pin" as LOW.
  digitalWrite(sig_pin, LOW);  // LOW
  // initialize digital pin "sig_pin" as an output.
  pinMode(sig_pin, OUTPUT);
  
  // initialize digital pin LED_BUILTIN as an output.
  digitalWrite(LED_BUILTIN, LOW);  // LOW
  pinMode(LED_BUILTIN, OUTPUT);
}

/**
 * wait for the duration of one pulse
 */
void wait_pulse(){
  if(modes_pulse_width_ms[mode] == 1){ //delay in ms
    delay(modes_pulse_width[mode]);
  }
  else{ //delay in µs
    delayMicroseconds(modes_pulse_width[mode]);
  }
}
/**
 * Produce a cycle of pulses
 */
void do_pulse(){
  for(int pulse = 0; pulse < modes_nb_pulse[mode]; pulse++){
    //open the injector
    digitalWrite(sig_pin, HIGH);  // HIGH
    digitalWrite(LED_BUILTIN, HIGH);  // HIGH
    //wait.
    wait_pulse();
    //close the injector
    digitalWrite(sig_pin, LOW);  // LOW
    digitalWrite(LED_BUILTIN, LOW);  // LOW
    wait_pulse();
  } 
}

/**
 * The loop function runs over and over again forever
 * But in this case is stop by one infinite loop at this end: only execute one.
 */
void loop(){
  // check the value of the mode variable
  if(mode >=1 && mode <= 4){
    mode--; 
    // check if we do only one pulse cycle or multiple cycle
    if(modes_pulse_repetition_ms[mode] == 0){
      // we do only one cycle of pulse
      do_pulse();
    }
    else{
      //we do a loop of cycle of pulse
      while(1){
        do_pulse();
        delay(modes_pulse_repetition_ms[mode]); //delay in ms
      }
     }
  }
  while(1){ //stop the loop
    delay(1000);
  }
}
