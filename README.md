# AskSin++ HM-ES-TX-WM SML

Eine angepasste Version des SML-Energiezaehlers basierend auf [diesem Projekt](https://github.com/novag/HM-ES-TX-WM).



## Features

Es erfolgten Anpassungen an der SML-Auswertung, um die von der urspruenglichen Implementierung abweichenden SML-Nachrichten des [Lepus-Zaehlers](https://www.apator.com/de/produkte/strom/strommessung/moderne-messeinrichtung/lepus) verarbeiten zu koennen.

Zudem wurde in Kanal 2 der Energie-Datenpunkt mit der eingespeisten Energie belegt. Der Leistungsdatenpunkt dieses Kanals wird nicht genutzt, da der Zaehler nur die Absolutleistung ausgibt, die in Kanal 1 angezeigt wird. Es werden also drei OBIS-Kennziffern ausgewertet:  
* 1-0:1.8.0: Wirkenergie Bezug gesamt 
* 1-0:2.8.0: Wirkenergie Einspeisung gesamt 
* 1-0:1.7.0: momentane Gesamtwirkleistung (Absolutwert ohne Vorzeichen)

Ausserdem wurde eine CRC-Pruefung ergaenzt, da ohne diese trotz der implementierten inhaltlichen Checks gelegentlich fehlerhafte Daten geliefert wurden. 

Letztlich wird das Funkmodul nach jedem Senden in den Idle-Modus versetzt, um den Ruhestrom auf ca. 4mA zu reduzieren.



## Voraussetzungen und Einschraenkungen

-  Zaehler muss freigeschaltet sein (ggf. PIN ueber das jeweilige EVU beziehen)
-  Geraeteeinstellungen der CCU werden ignoriert
-  Geraet ist fuer Netzbetrieb ausgelegt
-  A.G. der implementierten inhaltlichen Pruefungen bspw. bzgl. Datenfeldlaenge und Vorzeichenbehaftung oder noch groesserer SML-Nachrichtenlaenge sind fuer andere Zaehler ggf. Anpassungen am Code notwendig



## Hardware
Es wird zunaechst ein Lesekopf mit seriellem Ausgang benoetigt, bspw. [Hichi IR v1.1](https://www.photovoltaikforum.com/thread/141332-neue-lesekopf-baus%C3%A4tze-ohne-smd-l%C3%B6ten/).

Fuer den eigentlichen Zaehler wurde eine [Platine](https://github.com/HMSteve/PCBs/tree/master/AskSinPP_DinRailBoard) fuer das [Camdenboss-Hutschienengehaeuse mit 2 TE](https://www.reichelt.de/leergehaeuse-58-x-36-x-90-mm-2-te-cb-hutkit-2-p133936.html) entworfen, das als praktisches Kit aus Gehaeuse, vorgestanzten Klemmenabdeckungen, Bodenplatte und Deckel erhaeltlich ist.

Der Prototyp v1.0 der Platine enthaelt leider einen Fehler, der jedoch fuer das vorliegende Projekt sehr leicht durch Auftrennen einer Leiterbahn vor Bestuecken der Klemmenleiste sowie Einloeten einer Drahtbruecke behoben werden kann, siehe Bilder.

![](https://github.com/HMSteve/PCBs/blob/master/AskSinPP_DinRailBoard/images/HM-ES-TX-WM_1.jpg)
![](https://github.com/HMSteve/PCBs/blob/master/AskSinPP_DinRailBoard/images/HM-ES-TX-WM_2.jpg)


## Software
Der Sketch wird ohne weitere Besonderheiten bspw. in der Arduino-IDE kompiliert. Es sind neben der AskSinPP die ueber den Bibliotheksmanager einbindbaren Bibliotheken
* SoftSerial
* FastCRC


erforderlich sowie die dem Projekt beiliegende RadioSleep.h.


## Nuetzliche Links

[Infos zum SML-Protokoll](http://www.stefan-weigert.de/php_loader/sml.php)

[Onlinerechner fuer verschiedene CRC-Verfahren](https://crccalc.com/)

[www.bsi.bund.de](https://www.bsi.bund.de/SharedDocs/Downloads/DE/BSI/Publikationen/TechnischeRichtlinien/TR03109/TR-03109-1_Anlage_Feinspezifikation_Drahtgebundene_LMN-Schnittstelle_Teilb.pdf?__blob=publicationFile)

## Lizenz

 [Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License](https://creativecommons.org/licenses/by-nc-sa/3.0/).
