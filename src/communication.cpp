/*  Author: TSOKPO Komlan Freedom
    Date: 2026-03-19
    This header file defines the function to connect to WiFi and start the server, 
    which is called from the main setup function. It includes the necessary libraries for WiFi and AsyncWebServer, 
    and declares the function prototype for connecting to WiFi and starting the server.
*/
#include "communication.h"
#include "display.h"

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");


// (optional) callback for incoming websocket messages, if needed in the future
static void onWsEvent(AsyncWebSocket *server,
                AsyncWebSocketClient *client,
                AwsEventType type,
                void *arg,
                uint8_t *data,
                size_t len) {
    if (type == WS_EVT_CONNECT) {
        Serial.printf("[WS] client #%u connected\n", client->id());
    } 
    else if (type == WS_EVT_DISCONNECT) {
            Serial.printf("[WS] client #%u disconnected\n", client->id());
        }
        else if (type == WS_EVT_DATA) {
            // Lire une commande si besoin, sinon ignorer
        }
}

void connect_to_Wifi_nd_start_server(const char* ssid, const char* password) {
    // Code to connect to WiFi using the provided SSID and password
    // This function can be called from a task to establish a WiFi connection
    WiFi.mode(WIFI_STA);
    WiFi.setSleep(false);
    WiFi.begin(ssid, password);
    String text_to_send_to_screen = "Connecting to WiFi: " + String(ssid) + ".";
    sendTextToDisplay(text_to_send_to_screen.c_str());
    Serial.print(text_to_send_to_screen.c_str());
    uint32_t startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED) {
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1000 ms before checking again
        text_to_send_to_screen = text_to_send_to_screen + ".";
        Serial.print(".");
        sendTextToDisplay(text_to_send_to_screen.c_str());
        // Timeout after 20 seconds if connection is not established
        if (millis() - startAttemptTime > 20000) {
            Serial.println("\nFailed to connect to WiFi.");
            sendTextToDisplay("Failed to connect.");
            break;
        }
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConnection established. IP address: " + WiFi.localIP().toString());
        text_to_send_to_screen = "Connection established! \nIP: " + WiFi.localIP().toString();
        sendTextToDisplay(text_to_send_to_screen.c_str());
        vTaskDelay(10000/ portTICK_PERIOD_MS); // Delay for 10 seconds to read the IP address on the display before starting the server
    }
    // Code to start the server after successful WiFi connection
    ws.onEvent(onWsEvent);
    server.addHandler(&ws);
    server.begin();
    sendTextToDisplay("Server started!");
    Serial.println("Server started!");
}

void send_data_to_websocket(const int angle, const float distance) {
    // Code to send data to connected WebSocket clients
    // This function can be called from a task to send data to the WebSocket clients
    
    static uint32_t last=0; if (millis()-last < 50) return; last=millis();
    char buf[32];
    snprintf(buf, sizeof(buf), "%d;%.0f", angle, distance);
    ws.textAll(buf); // Send text data to all connected WebSocket clients
    ws.cleanupClients(); // Clean up disconnected clients
}