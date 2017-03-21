1. Mealy- Automaten
	- Ein Mealy - Automaten ist eine 6-Tuplel $\Omega = (E,A,Z,\sigma,\lambda,Z_0)$
2. Vraianten von Automaten
	- Mealy-Automat
    - Automat mit Spontanübergängen
    - Transitionsystem
    - Automat mit Variablen(Erweitere Endliche Automaten)
    - DEA/NEA
    - Gekopplte Automaten(asynchrone und synchrone Kopplung)
    - Timed Automat
3. Transitionsystem
4. Kopplung von Automaten

|                        | Asychron| sychron           |
|------------------------|---------|-------------------|
|Kanal Kapazität         |0        |begrenzt/unbegrenzt|
|Zwischenspeichern       |Nein     |Ja                 |
|Sychronisationszeitpunkt|Exsitiert|Keine              |

5. Zustandexploration von Automaten
	- Erreichbarkeit Analyse
		- Erreichbarkeitsbaum / Erreichbarkeitsgraph
		- Exploration Schema
			- vollständige Exploratin
			- partielle Exploratin (Bit-State Algrithsmus)
6. Protokollfeher
	- Nicht ausführbarer Code
	- Nicht spezifizierter Empfang
	- Statischer Deadlock
	- Dynamischer Deadlock (live deadlock, nicht-produktiver Zyklus)
	- Kanalüberlauf
7. Timed Automata
	- **synchrone** Kopplung
	- **Variablen** für Daten und Uhren
		- globale und lockale Variablen
	- Bedingungen für Ausführen von Transition
	- Attribulte für Zustand
		- **Initial** *Startzustand*
		- **Urgent** *Ohne Aufenthalf bei einem Zustand*
		  (wenn keine Transitionen ausführbar sind, wird zum Deadlock)
        - **Committed** *Nächste Transition besitzt höchste Priorität vor allen auszuführenden Transitionen*
8. Sychronisation Channel
	- binary ( notify();)
	- broadcast ( notifyAll();)
9. $\varphi \to \psi \Leftrightarrow A[\;] (\varphi \; imply \; A<> \psi)$
10. Eigenschaften beim Model Checking
	- **Reachablity properties**
		- E< > Reachable P
	- **Safety properties** *Something bad will never happen*
		- A[ ] Invariatly P
		- E[ ] potentially always P
	- **Liveness properties** *Something will eventually happen*
		- A< > Invetiable P
		- p -> p lead to q
11. Ablaufmodell und Fortschrittsmodell

|Ablaufmodell                   |Fortschrittsmodell                 |
|-------------------------------|-----------------------------------|
|ausführbare Anweisungen        |tatsächlich ausgeführte Anweisungen|
|Verzweigungen möglich          |keine Verzweigungen                |
|Schleifen möglich              |keine Schleifen                    |
|Unabhängig von den Eingabedaten|abhängig von den Eingabedaten      |

12. Reihenfolge von Aktionen
	- **A vor B**
	- alternative **A alt B**
	  *können nicht gleichzeitig ausgeführt werden*
	- Schreibkonflik **A LK B**
	  *A LK B ist symmetrisch*
	- Lesekonflik **A SK B**
	  *A SK B ist symmetrisch*
	- Datenabhängigkeit **A abh B**
	  *A abh B ist nicht symmetrisch*
	- sequentiell **A sequ B**
	  *A vor B oder B vor A oder A alt B*
	  *A sequ B ist symmetrisch, aber nicht transitiv *
	- nebenläufig **A neb B**  = nicht A sequ B
	- rein nebenläufig **A rein B**
	  *keine Schreibkonflikte und keine Datenabhängigkeit*
13. Eigenschften von Programm
	- **deterministisch**
	  *in jedem Zustand kann höchstens eine Aktion begonnen bzw. beendet werden*
    - **Indeterminismus**
      *es gibt eine Auswahl über den nächsten auszuführenden Schritt*
    - **determiniert**
      *Ein-Ausgabe-Relation ist rechts eindeutig*
    - **nicht determiniert**
      *Gleiches Programm mit gleichen Eingaben zweimal gestartet ⇒ verschiedene Ergebnisse möglich !*
14. Prozess
    - Eine Menge von Aktionen ist squentiell
15. Wechselwirkung zwischen Prozessen
    - Sychronisation-Aufgabe
        - einseitiges / gegenseitiges Warten
        - warten auf einen Zeitpunkt
    - Kommunikation-Aufgaben
        - einfache Nachricht
        - Rundspruch-Nachricht
        - Sammel-Nachricht
        - Zugriff auf gemeinsame Variablen
16. Verwaltung von Prozessen
	- Prozessplaner(Scheduler)
	- Prozessumschalter(Dispatcher)
17. Zustände eines Prozesses
	- blockiert
	- rechnend
	- rechnenbereit
18. Thread
	- mit Priorität
	- mit yield()
	- mit zufällige Arbeitszeiten
	- mit gemainsamen Variablen arbeiten
	- mit join()
	- mit sleep()
	- mit interrupt()
	- mit sychronized in Monitor
	- mit sychronized(syncObj){}
	- Produzent-Konsument Modell
	- mit wait() und notify()
	- mit wait()- Schleife // while(Bedingungen){wait();}
	- mit notify() in Schleife
	- mit notifyAll()
	- mit separaten Monitoren
	- Verklemmung zeigen
	- semaphor.acquire(), semaphor.release()
	- lock.lock(), lock.unlock(), condition.await(), condition.signal()
	- Implementierung von Kanälen
	- Broadcast / Collect
19. Maßnahmen gegen Verklemmungen
	- keine Wartezyklen
		- Betriebsmittel / Ereignisse ordnen
		- Puffer-Prozesse einführen
	- Zyklen aufbrechen
		- Einen Prozess vernichten
		- Einen Prozess in einen früheren Zustand zurücksetzen
		- Prozesssystem neu starten
