//Nigel RTOS test 1 ------------------------------- blinky at different rates --------------------------------------


#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif



#define LED_BUILTIN 2


void blink_led_300 (void *parameter) {

  while(1){
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(300 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

void blink_led_550 (void *parameter) {

  while(1){
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(550 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(550 / portTICK_PERIOD_MS);
  }
}








void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  xTaskCreatePinnedToCore(
    blink_led_550,
    "blink_led_550",
    1024,
    NULL,
    1,
    NULL,
    app_cpu
  );

  xTaskCreatePinnedToCore(
    blink_led_300,
    "blink_led_300",
    1024,
    NULL,
    1,
    NULL,
    app_cpu
  );

}

void loop() {
  // put your main code here, to run repeatedly:

}
