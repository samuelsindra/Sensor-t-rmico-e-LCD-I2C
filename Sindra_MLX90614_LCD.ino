// ---------------------------------------------------------------------------------------------------------
// Samuel Sindra - 07/2017 - Teste display LCD 16X2 - I2C e sensor térmico MLX90614
// Placa controladora utilizada: Arduino UNO
// Portas utilizadas: GND | VCC=5V | SDA | SCL 
// Módulo LCD I2C - Configuração 0x3f (Cada módulo pode apresentar endereço diferente e é configurável na placa.
// Múdulo MLX90614 - Configuração padrão
// ---------------------------------------------------------------------------------------------------------

// Carregar biblioteca do módulo I2C para o display
#include <LiquidCrystal_I2C.h>

// Carregar biblioteca MLX90614 
#include <Adafruit_MLX90614.h>

// Carregar biblioteca de comunicação I2C
#include <Wire.h>

// Inicializando o LCD conforme endereço I2C do módulo
LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);

Adafruit_MLX90614 sensor = Adafruit_MLX90614();  // Cria objeto
 
// Função SETUP - Configurações gerais
void setup()
{
  Serial.begin(57600);  // Inicializa porta serial
  lcd.begin (16,2); // Informa o padrão do LCD: (16,2) ou (20,4)
  lcd.setBacklight(HIGH);  // Habilita o backlight do display, se disponível
  sensor.begin();  // Inicializa o sensor MLX90614
  Serial.println("Avaliacao de temperatura com o MLX90614");
  Serial.println("Temperatura ambiente e objeto a frente do sensor");
  Serial.println("Apresentacao em display LCD 16X2 via I2C");
}
 
// Função LOOP - Execução contínua
void loop()
{
  // Apresentação dos dados no display
  lcd.clear();  // Apaga o display
  lcd.setCursor(0,0);  // Posicionar o cursor na esquerda, em cima (X,Y) ou (coluna X linha)
  lcd.print("Ambiente:");  // Mostra texto na primeira linha
  lcd.setCursor(10,0);
  lcd.print(sensor.readAmbientTempC());  // Mostra temperatura do ambiente em ºC
  lcd.setCursor(0,1);  // Posicionar o cursor na esquerda, em cima (X,Y) ou (coluna X linha)
  lcd.print("Objeto:");  // Mostra texto na segunda linha
  lcd.setCursor(10,1);
  lcd.print(sensor.readObjectTempC());  // Mostra temperatura do objeto em ºC

  // Apresentação dos dados na porta serial
  Serial.print("Ambiente = ");
  Serial.print(sensor.readAmbientTempC()); 
  Serial.print("C\tObjeto = ");
  Serial.print(sensor.readObjectTempC());
  Serial.println("C");
  delay(200);
}
