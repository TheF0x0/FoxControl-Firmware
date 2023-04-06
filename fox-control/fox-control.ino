/**
 * @author F0x0
 * @since 03/04/2023
 */

constexpr uint8_t FC_BUTTON_POWER = 2;
constexpr uint8_t FC_BUTTON_MODE = 3;
constexpr uint8_t FC_BUTTON_LOWER = 4;
constexpr uint8_t FC_BUTTON_HIGHER = 5;

constexpr uint32_t FC_BAUD_RATE = 19200;
constexpr uint32_t FC_INIT_DELAY = 500;
constexpr uint32_t FC_PRESS_DELAY = 100;

constexpr char FC_MESSAGE_ON = 'i';
constexpr char FC_MESSAGE_OFF = 'o';
constexpr char FC_MESSAGE_MODE = 'm';
constexpr char FC_MESSAGE_LOWER = 'l';
constexpr char FC_MESSAGE_HIGHER = 'h';

inline auto press_button(uint8_t button) noexcept -> void {
  digitalWrite(button, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(FC_PRESS_DELAY);
  digitalWrite(button, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(FC_PRESS_DELAY);
}

auto setup() -> void {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(FC_BUTTON_POWER, OUTPUT);
  pinMode(FC_BUTTON_MODE, OUTPUT);
  pinMode(FC_BUTTON_LOWER, OUTPUT);
  pinMode(FC_BUTTON_HIGHER, OUTPUT);

  Serial.begin(FC_BAUD_RATE);
  delay(FC_INIT_DELAY); // Wait for a moment to initialize
}

auto loop() -> void {
  if(Serial.available()) {
    switch(Serial.read()) {
      case FC_MESSAGE_ON:
        press_button(FC_BUTTON_POWER);
        Serial.println("power_on");
        break;
      case FC_MESSAGE_OFF:
        press_button(FC_BUTTON_POWER);
        Serial.println("power_off");
        break;
      case FC_MESSAGE_MODE:
        press_button(FC_BUTTON_MODE);
        Serial.println("change_mode");
        break;
      case FC_MESSAGE_LOWER:
        press_button(FC_BUTTON_LOWER);
        Serial.println("speed_down");
        break;
      case FC_MESSAGE_HIGHER:
        press_button(FC_BUTTON_HIGHER);
        Serial.println("speed_up");
        break;
    }
  }
}
