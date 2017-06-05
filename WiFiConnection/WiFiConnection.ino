#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//Add WiFi Name/Password of your local network
char* ssid = "WIFI_NAME";
char* pass = "WIFI_PASSWORD";

ESP8266WebServer server(80);

void setup()
{
	Serial.begin(115200);

	pinMode(D0, OUTPUT);
	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D4, OUTPUT);
	digitalWrite(D1, LOW);
	digitalWrite(D0, HIGH); //Turns the on board LED off

	connect();
	web_server();
}

void loop()
{
	server.handleClient();
}

void connect()
{
	Serial.print("Connecting to: ");
	Serial.print(ssid);

	//WiFi connection
	WiFi.hostname("ESP8266");
	WiFi.begin(ssid, pass);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println("Wifi Connected!");

	//Displays connection
	Serial.println();
	Serial.println();
	Serial.print("Connect to me at: ");
	Serial.println(WiFi.localIP());
}

String webPage;
void web_server()
{
	//HEAD
	webPage += "<html>";
	webPage += "<head>";
	webPage += "<meta name=""viewport"" content=""width = device - width, height = device - height, initial - scale = 1.0""/>";
	webPage += "<title>Test</title>";
	webPage += "<style type=""text/css"">";
	webPage += "html {text-align:center; max-height: 10%; background-color: grey;}";
	webPage += ".button {font-size: 30px; width: 500px; height: 10%;}";
	webPage += "</style>";
	webPage += "</head>";

	//BODY
	webPage += "<body>";
	webPage += "<div>";
	webPage += "<h1> Web Server </h1>";
	webPage += "<p><a href = \"left\"><button class=""button"">LEFT</button></a></p>";
	webPage += "<p><a href = \"right\"><button class=""button"">RIGHT</button></a></p>";
	webPage += "<p><a href = \"up\"><button class=""button"">UP</button></a></p>";
	webPage += "<p><a href = \"down\"><button class=""button"">DOWN</button></a></p>";
	webPage += "</div>";
	webPage += "</body>";
	webPage += "</html>";

	server.on("/", []() {
		server.send(200, "text/html", webPage);
	});

	server.on("/left", []() {
		server.send(200, "text/html", webPage);
		left();
		delay(500);
	});
	server.on("/right", []() {
		server.send(200, "text/html", webPage);
		right();
		delay(500);
	});
	server.on("/up", []() {
		server.send(200, "text/html", webPage);
		up();
		delay(500);
	});
	server.on("/down", []() {
		server.send(200, "text/html", webPage);
		down();
		delay(500);
	});

	//Starts the server
	server.begin();
}

//Blinks the on board led a set amount of times
void blink(int Blink_Count)
{
	for (size_t i = 0; i < Blink_Count; i++)
	{
		digitalWrite(D0, LOW);
		delay(50);
		digitalWrite(D0, HIGH);
	}
}

void left()
{
	digitalWrite(D3, HIGH);
	blink(3);
	digitalWrite(D3, LOW);
}

void right()
{
	digitalWrite(D4, HIGH);
	blink(4);
	digitalWrite(D4, LOW);
}

void down()
{
	digitalWrite(D2, HIGH);
	blink(2);
	digitalWrite(D2, LOW);
}

void up()
{
	digitalWrite(D1, HIGH);
	blink(1);
	digitalWrite(D1, LOW);
}

