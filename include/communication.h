#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <WiFi.h>
#include <AsyncTCP.h>
// #include <ESPAsyncTCP.h> // for ESP8266, but not compatible with ESP32, so we use AsyncTCP instead which is compatible with both ESP8266 and ESP32
#include <ESPAsyncWebServer.h>
#include "config.h"

extern AsyncWebServer server;
extern AsyncWebSocket ws;

static void onWsEvent(AsyncWebSocket *server,
                AsyncWebSocketClient *client,
                AwsEventType type,
                void *arg,
                uint8_t *data,
                size_t len);
void connect_to_Wifi_nd_start_server(const char* ssid, const char* password);
void send_data_to_websocket(const int angle, const float distance);

#endif // COMMUNICATION_H