# PedelHack
Arduino Projekt mit dem man die 25 KM/h Grenze bei E-Bikes umgehen kann 






# Schaltplan:
Die Schaltung besteht neben dem Arduino aus zwei Spulen, einem Spannungsteiler und einem NPN-Transistor in Emitterschaltung



Für meinen Versuch habe ich die folgenden Werte benutzt es können aber beliebige gewählt werden.


![alt text](https://raw.githubusercontent.com/yurnam/PedelHack/master/Schaltplan.png)
 

# Funktion :

L1 nimmt das Signal des Tachomagneten auf und gibt es an den Mikrocontroller weiter, dieser gibt aber nur jeden 2. Impuls an L2 weiter 
somit zeigt der Tacho nur mehr die Hälfte der tatsächlichen Geschwindigkeit an zb. Bei angezeigten 25 KM/h handelt es sich um 50 KM/h

