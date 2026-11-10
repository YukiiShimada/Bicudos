#define PINO_BOMBA 21      // Usando o GPIO 21
#define TEMPO_REGA 4000    // 2 segundos ligada (2000 ms)
#define TEMPO_SLEEP 60000  // Tempo em milissegundos para o sleep
#define LED 2              // LED integrado (geralmente GPIO 2)

void setup() {
  // Configuração dos pinos como saída
  pinMode(PINO_BOMBA, OUTPUT);
  pinMode(LED, OUTPUT);

  // Garante que iniciam desligados por segurança
  digitalWrite(PINO_BOMBA, LOW);
  digitalWrite(LED, LOW);
  delay(100);

  // --- LIGA A BOMBA E O LED ---
  digitalWrite(PINO_BOMBA, HIGH);
  digitalWrite(LED, HIGH);
  
  // Mantém ligado pelo tempo determinado
  delay(TEMPO_REGA);

  // --- DESLIGA A BOMBA E O LED ---
  digitalWrite(PINO_BOMBA, LOW);
  digitalWrite(LED, LOW);

  // --- DEEP SLEEP ---
  // Converte segundos/milisegundos para microssegundos para o ESP32
  esp_sleep_enable_timer_wakeup((uint64_t)TEMPO_SLEEP * 1000ULL);
  esp_deep_sleep_start();
}

void loop() {
  // Nada aqui, o ESP32 estará em Deep Sleep
}