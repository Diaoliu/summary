## Zusammenfassung

### 3.Informationsdarstellung
* Zweierkomplement
* Gleitkommazahlen
 - Zahlenbereich
 - Darstellung
 - Addition

### 4. Schaltnetze
* Minterm, Maxterm
* VHDL

```
entity schlatung is
    port( x, y : in  bit;
          o    : out bit );
end entiy

architecture gatter is
signal a, b : bit;
begin
    ...
    some_process : process(takt)
    begin
        ...
    end process
end architectue;
```

* KV-Diagramme
* Quine und McClusky (QMC)
* Mealy- und Moore-Automat
 - Mealy: $E \times Z \to A$
 - Moore: $E \to A$
* RS-, JK-, D- und T-Flipflop

### 7. Konzepte der Rechnerarchitektur
* Feste und variable Befehlslängen
* CISC und RISC
* Leistungssteigerung eines Prozessors
    - Speizielle Register: Daten Pointer, Stack Pointer...
    - Cache Speicher
* Pipelining
    - Voraussetzung: Schnitte müssen unabhängig voneinander ausführbar sein
    - Struktureller Pipeline-Hazard, Steurungs-Hazard, Daten-Hazard

### 8. Unterbrechungsmechanismen

### 9. Peripheriegeräte und ihre Ankopplung
* Daten zum EA-Betrieb
    - Eingabe-Puffer
    - Ausgabe-Puffer
    - Geräte-Status
* Steurung der Ein- und Ausgabe
* Anpassung der Geschwindigkeit
    - Prozess schneller: EA-Ereignisse vollständig steuern oder in Schleifen abfragen
    - EA Schneller: stäkere Pufferung
    - synchronisiert: EA-Operation im Programm
    - nicht synchronisiert: EA-Operationen in Unterbrechnungs-Programm

### 11. Prozesse und Threads
* Prozess
 - Prozessabbild ( PCB, Stack, Gap, Data, Text )
 - Prozesskontrollblock
 - Prozesszustände
 - Prozesswechsel
  - Interrupt bei Ereignis ( I/O )
  - Trap bei Fehler ( Missing Page )
  - System call
* Thread
 - Gemeinsame Resourcen
  - Prozessor
  - Speicher
  - Dateien
- User Threads vs. kernel Threads
 - User Threads : Ohne Unterstüzung des Kernel
 - Kernel Threads : Direckt vom BS verwaltet

### 12. Scheduling
* Arten
    - Short Term : Prozessorzuteilung
    - Mid Term : Swapping
    - Long Term : Prozesserzeugung
* Scheduling Algorithmen
**Non-Preeption**
    - First-Come-First-Serve (FCFS)
    - Shortest-Job-First (SJF)
    - Shortest-Process-Next (SPN)
    - Highest-Response-Ratio-Next (HRN)
**Preeption**
    - Shortest-Remaining-Time-First (SRTF)
    - Round-Robin (RR)
    - Multilevel Queue (MQ)
    - Multilevel Feedback Queue (MFQ)

### 13-14. Synchronisation
* Wechselseitiger Ausschluss / Mutex / Mutual Exclusion
    - **Aktives Warten (Busy-wating)** ist ein fortwährendes Polling auf eine Mutex-Freigabe
    - **Spinlock** ist die Kombination von Lock mit Polling
    - Dekker's algorithm
    - Peterson's algorithm
    - Hardware-Lösungen
        - Interrupts ausschalten
        - Primitive atomic instructions ( atomic read-write, test-and-set Lock )
* Semaphore
    - mutex: Gemeinsamer Zugriff auf Variable count
    - full: Steuerung des Konsumenten
    - empty: Steurung des Produzenten
* Monitor
* Signal

### 15. IPC
* Typen von IPC
    - Signals: A means of receiving notice of a software or hardware event, asynchronously.
    - Shared memory: A way to create a segment of memory that is mapped into the address space of two or more processes, each of which can access and alter the memory contents.
    - Semaphores: Software objects used to coordinate access to countable resources.
    - Locks, Mutexes, and Condition Variables: Software objects used to ensure exclusive use of single resources or code sequences.
    - Barriers: Software objects used to ensure that all processes in a group are ready before any of them proceed.
    - Message Queues: Software objects used to exchange an ordered sequence of messages.
    - File Locks: A means of gaining exclusive use of all or part of a file.
    - Sockets: Virtual data connections between processes that may be in different systems.
* IPC Persistenz
    - Prozess Persistenz
    - Kernel Persistenz
    - Dateisystem Persistenz
* File API
    - file descriptor: STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO
    - open, creat, read, close, Iseed, unlink
* File Management Structures
    - descriptor table pro process
    - file table on system side
    - v-node table on Disk
* Message Passing
    - PIPE und FIFO ( named Pipe )
    - Message Queue
    - Socket
* Shared Memory

### 16. Deadlock
* Voraussetzungen
    - Wechselseitiger Ausschluss ( Mutual Exclusion )
    - Warte-und-Halt-Fest-Bedingung ( Hold and wait )
    - Nichtentziehbarkeit ( no Preemption )
    - Mehrfachanforderung ( Circualr wait )
* Bankier-Verfahren
* Deadlock-Erkennung

### 17. Speichermanagement
* Adressräume
    - Swapping : Auslagerung des kompletten Primärspeichers auf Sekundärspeicher
    - Statische Relokation : Umrechnung der Speicheradressen zum Ladezeitpunkt
    - Basis- und Limit-Register : bestimmen Start und Länge des Speicherbereichs einens Programms
    - Festlegung der (phys.) Speicheradresse
        - Zum Programmierzeitpunkt : Symbolic, Symbol table
        - Zum Kompilierzeitpunkt: Relative Adress
        - Zum Laufzeit : Absolute Adresse
    - Memory-Management Unit ( MMU )
* Speicherverwaltung
    - Zusammenhängend
        - Fixed Partitionierung
            - Interne Fragmentierung
        - Variable Partitionierung
            - Externe Fragmentierung
            - Zeitintensive Verdichtung
        - Buddy-Partitionierung
            - Geringe interne Fragmentierung
            - Leichter auflösbare externe Fragmentierung
        - Bitmap, verkettete Liste
        - Zuteilungsalgorithmen
            - First Fit
            - Next Fit
            - Best Fit
            - Worst Fit
    - Nicht-Zusammenhängend ( erfordern Relokation zur Laufzeit )
        - Segmentierung ( .text, .data ) : Speicherbereich nicht logisch zusammenhängend
        - Paging : Speicherbereich logisch zusammenhängend
        - Kombination : Jede Segment hat eigene Seitentabelle
    - Seitenersetzung
        - First-In-First-Out-Algorithmus
        - Least-Recently-Used-Algorithmus
        - Not-Frequently-Used-Algorithmus
        - Aging ( modified NFU )
        - Not-Recently-Used-Algorithmus ( referenced bit = 0, modified bit = 0 )
        - Second-Chance-Algorithmus
        - Clock-Algorithmus

### 18.    Massenspeicher
* HDD Performance
    - Durchscnittliche I/O Zeit = Zugriffsgeschwindigkeit(seek time + rotational latency) + (Datenmenge/ Transferrate) + controller overhead
* SSD
    - MLC, SLC
    - Wear Leveling
* Disk Scheduling für HDD
    - First Come First Server
    - Shortest Seek Time First
    - SCAN, C-SCAN
    - LOOk, C-LOOK
    - Completely Fair Queuing : eigene Liste für jeden Prozess, beliebig I/O in Zeitperiode, Listen durchlaufen
* Disk mangagement
    - physische Formatierung - Disk in Sektoren einteilen
    - logische Formatierung - ein Dateisystem erstellen
    - Partitionierung, Cluster
    - Bootstrap loader
    - Swap Space
    - RAID

### 19. File System Interface
* Linux Dateitype : Normale Dateien, Symbolische Links, Ordner, device, named Pipe, Socket
* Datei Attribute : name, identifier, poiner, size, protection, time, user

### 20. Dateisystem Implementierung
* Dateinsystem Schichten
 * **Gerätetreiber** verwaltet IO Geräte
 * **Basic File System** übersetzt Befehle für die Gerätetreiber
 * **File Organization Module** arbeitet mit Datein, Blöcken
 * **Das logische Dateisystem** verwaltet Metadaten
* Dateisystem Implementierung
 * Boot Control Block
 * Volume Control Block
 * File Control Block

``` c
struct stat{
    dev_t   st_dev; // device
    ino_t   st_ino; // inode
    mode_t  st_mode; // protection
    nlink_t st_nlink; // number of hard links
    uid_t   st_uid; // userID of owner
    gid_t   st_gid; // groupID of owner
    dev_t   st_rdev; // device type
    off_t   st_size; // total size
    blksize_t  st_blksize; // block size for file system
    blkcnt_t   st_blocks; // number of blocks allocated
    time_t     st_atime; // time of last access
    time_t     st_mtime; // time of last modification
    time_t     st_ctime; // time of last status
};
```

### 21. Protektion
* Specherung von Zugriffsrechten
 * Zugriffskontrolllist speichert Rechte pro Datai
 * Capabillites speichert Rechte pro Domäne
