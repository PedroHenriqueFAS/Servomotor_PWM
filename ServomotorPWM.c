#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_SERVO 22 // Pino para controle do servomotor

const float PWM_FREQUENCY = 50.0; // Frequência de 50Hz (Período de 20ms)
const uint16_t WRAP_PERIOD = 40000; // Valor máximo do contador PWM para 50Hz
const float PWM_DIVISER = 64.0; // Ajuste do clock do PWM

// Ciclos de trabalho para diferentes ângulos
uint16_t DUTY_180 = 2400; // 2400µs -> 180 graus
uint16_t DUTY_90 = 1470;  // 1470µs -> 90 graus
uint16_t DUTY_0 = 500;    // 500µs -> 0 graus

void pwm_setup(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(gpio);
    pwm_set_clkdiv(slice, PWM_DIVISER); 
    pwm_set_wrap(slice, WRAP_PERIOD);
    pwm_set_enabled(slice, true);
}

void set_servo_position(uint gpio, uint16_t duty_cycle_us) {
    uint slice = pwm_gpio_to_slice_num(gpio);

    // Converte tempo de pulso (µs) para nível do PWM (0 a WRAP_PERIOD)
    uint16_t level = (duty_cycle_us * WRAP_PERIOD) / 20000; // 20ms = 20000µs

    pwm_set_gpio_level(gpio, level);

}

int main() {
    stdio_init_all();
    pwm_setup(PWM_SERVO);

    // Movimentos iniciais para 180°, 90° e 0° respectivamente
    set_servo_position(PWM_SERVO, DUTY_180);
    sleep_ms(5000);

    set_servo_position(PWM_SERVO, DUTY_90);
    sleep_ms(5000);

    set_servo_position(PWM_SERVO, DUTY_0);
    sleep_ms(5000);

    // Movimentação suave entre 0° e 180° continuamente
    printf("Movimentação suave iniciada\n");
    uint16_t pos = DUTY_0;
    int direction = 5; // Incremento positivo inicialmente

    while (true) {

        pos += direction;

        if (pos >= DUTY_180) {
            pos = DUTY_180;
            direction = -5; // Inverte direção
        } 
        else if (pos <= DUTY_0) {
            pos = DUTY_0;
            direction = 5; // Inverte direção
        }
        pos += direction;
        set_servo_position(PWM_SERVO, pos);
        sleep_ms(10);
    }
}

