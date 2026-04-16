#ifndef TWILIO_HANDLER_H
#define TWILIO_HANDLER_H

#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include "config.h"

WiFiClientSecure client;

String base64Encode(String input);

void sendSMS(String message) {
  HTTPClient https;

  String url = "https://api.twilio.com/2010-04-01/Accounts/" + String(ACCOUNT_SID) + "/Messages.json";

  String postData = "To=" + String(TO_NUMBER) +
                    "&From=" + String(FROM_NUMBER) +
                    "&Body=" + message;

  client.setInsecure();
  https.begin(client, url);

  String auth = base64Encode(String(ACCOUNT_SID) + ":" + String(AUTH_TOKEN));
  https.addHeader("Authorization", "Basic " + auth);
  https.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = https.POST(postData);

  Serial.print("SMS Status: ");
  Serial.println(httpCode);

  https.end();
}

void makeCall() {
  HTTPClient https;

  String url = "https://api.twilio.com/2010-04-01/Accounts/" + String(ACCOUNT_SID) + "/Calls.json";

  String postData = "To=" + String(TO_NUMBER) +
                    "&From=" + String(FROM_NUMBER) +
                    "&Url=http://demo.twilio.com/docs/voice.xml";

  client.setInsecure();
  https.begin(client, url);

  String auth = base64Encode(String(ACCOUNT_SID) + ":" + String(AUTH_TOKEN));
  https.addHeader("Authorization", "Basic " + auth);
  https.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = https.POST(postData);

  Serial.print("Call Status: ");
  Serial.println(httpCode);

  https.end();
}

String base64Encode(String input) {
  const char* base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  String output = "";
  int val = 0, valb = -6;

  for (uint8_t c : input) {
    val = (val << 8) + c;
    valb += 8;
    while (valb >= 0) {
      output += base64_chars[(val >> valb) & 0x3F];
      valb -= 6;
    }
  }
  if (valb > -6) output += base64_chars[((val << 8) >> (valb + 8)) & 0x3F];
  while (output.length() % 4) output += '=';

  return output;
}

#endif
