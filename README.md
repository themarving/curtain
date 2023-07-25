------------------------------------------------------
Vorwort
------------------------------------------------------
Herzlich Willkommen zu unserem Produkt, der selbstständig öffnenden und schließenden Gardinenstange!
Das Produkt unterstützt Sie darin, die Gardine automatisch zu öffnen und zu schließen.
Die automatischen Funktionen hängen von dem Zustand des Wetters am eingestellten Ort ab.
Mit diesen Funktionen unterstützt das Produkt Sie darin eine zu hohe Helligkeit durch das Wetter zu vermeiden.
Neben praktischem Nutzen während Sie im Haus sind, kann das Produkt auch genutzt werden um rationales Handeln einer Person zu simulieren.

------------------------------------------------------
Erstnutzung
------------------------------------------------------
Das automatische Gardinenöffnungs und -schließungssystem benötigt ein W-LAN-Netzwerk, mit dem es sich verbinden kann und eine Stromquelle.
Bevor eine Stromverbindung hergestellt wird, müssen einige Daten an ihr Heim angepasst werden.

In der Datei HardwareInterface.ino finden Sie den Programmcode, bei dem Daten an ihr W-LAN-Netzwerk und Ort angepasst werden müssen.
In Zeile 7 und 8 müssen die W-LAN-Netzwerk Daten angepasst werden, wobei in den Anführungszeichen in Zeile 7 Ihr Netzwerkname und in Zeile 8 Ihr Netzwerkpasswort muss.
In Zeile 29 und 30 muss die Information für die Open-Weather-Map (https://openweathermap.org/) an Ihre Daten angepasst werden.
Zeile 29 benötigt in den Anführungszeichen den Ortsnamen ihres Standpunktes, wie er in Open-Weather-Map verfügbar ist.
Zeile 30 benötigt einen gültigen Wetter-API-Schlüssel, den sie kostenlos bei der zugehörigen Website beantragen können.

Die Gardine wird bei Stromzufuhr testweise geöffnet und geschlossen, stellen Sie sicher dass die Gardine im geschlossenen Zustand vor dem nächsten Schritt ist.
Schließen Sie ihr Endgerät an das Produkt an und lassen Sie die Gardine testweise öffnen und schließen. 
Laden Sie danach die veränderte Datei, mittels z.B. Arduino IDE, an das Produkt und überprüfen Sie anhand der Seriellen Konsole, 
ob die Internetverbindung und Wetterzustandsabrufe funktionieren.
Wenn die Internetverbindung und der Wetterzustandabruf problemlos funktionieren, können Sie die Stromzufuhr abbrechen.
Das Produkt ist somit an Ihre Zustände angepasst und muss bei wechselndem Netzwerknamen, -passwort oder Ablauf des Wetter-API-Schlüssels angepasst werden.

------------------------------------------------------
Weitere Nutzungen
------------------------------------------------------
Für die Stromzufuhr können Sie eine Stromverbindung mit dem USB-C Kabel am Gerät mit z.B. einer mobilen Ladestation verbinden. 
Bitte achten Sie darauf die Gardine im geschlossenen Zustand zu haben, wenn die Stromverbindung erneut angesetzt wird und
die initiale Öffnung und Schließung nach Problemen zu überprüfen.
Falls keine Probleme gefunden werden können, überlassen Sie es dem Produkt, eine zu hohe Helligkeit vom Wetter zu vermeiden.

------------------------------------------------------
Anpassbarkeit
------------------------------------------------------
Falls Sie der Meinung sind, dass bei bestimmten Wetterzuständen anders vom Produkt gehandelt werden sollte, können im Programmcode
von Zeile 67 bis 106 Anpassungen vorgenommen werden, wann die Gardine geschlossen werden soll und wann diese geöffnet werden soll.
Für die Zustände werden die IDs der Open-Weather-Map (https://openweathermap.org/weather-conditions) verwendet.
