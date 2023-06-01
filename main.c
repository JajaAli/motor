#include <avr/io.h>
#include <util/delay.h>

// motor pin definitions
#define MOTOR1_ENABLE_PIN PB0
#define MOTOR1_IN1_PIN PB1
#define MOTOR1_IN_2_PIN PB2
#define MOTOR1_IN_2_PIN PB2
#define MOTOR2_ENABLE_PIN PB3
#define MOTOR2_IN1_PIN PB4
#define MOTOR2_IN2_PIN PB5

//function to initialize the motor pins
void intMotors(){
DDRB |= (1 << MOTOR1_ENABLE_PIN) | (MOTOR1_IN1_PIN) | (1 << MOTOR1_IN2_PIN) |
        (1 << MOTOR2_ENABLE_PIN) | (MOTOR2_IN1_PIN) | (1 << MOTOR2_IN2_PIN);

}
// Function to move the car forward
void moveForward() {
PORTB |= (1 << MOTOR1_IN1_PIN) | (1 << MOTOR2_IN1_PIN);
PORTB &= ~((1 << MOTOR1_IN2_PIN) | (1 << MOTOR2_IN2_PIN));
PORTB |= (1 << MOTOR1_ENABLE_PIN) | (1 << MOTOR2_ENABLE_PIN);
}
//Function to stop the car
void stopCar() {
PORTB &= ~((1 << MOTOR1_ENABLE_PIN) | (1 << MOTOR2_ENABLE_PIN));
}
int main(void) {
initMotors ();
 while (1) {
        moveForward();
        _delay_ms(2000); // Move forward for 2 seconds
        stopCar();
        _delay_ms(1000); // Stop for 1 second
    }

    return 0;

}

