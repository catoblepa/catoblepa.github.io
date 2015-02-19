Mappatura Barriere Architettoniche - Alessandria
================================================

Nome del progetto e finalità: *(da fare)*

Durata del progetto: .....

Persone impiegate:

  * 4 censitori
  * 2 addetti inserimento dati



Area di intervento
------------------

Area all'interno degli spalti della città di Alessandria:

[Mappa area di intervento](http://umap.openstreetmap.fr/it/map/mdma-area-di-intervento_27512#)


Oggetto della mappatura
-----------------------

  * bar/tavole calde/pub
    - http://wiki.openstreetmap.org/wiki/Tag:amenity%3Dbar
    - http://wiki.openstreetmap.org/wiki/Tag:amenity%3Dcafe
    - http://wiki.openstreetmap.org/wiki/Tag:amenity%3Dpub
  * edifici di pubblica utilità (uffici pubblici, musei, caf, camera di commercio, ecc..)
  * ristoranti
    - http://wiki.openstreetmap.org/wiki/Tag:amenity%3Drestaurant
  * hotel
  * supermercati e negozi di generi alimnetari
  * tabaccai
  * farmacie
  * uffici postali
  * banche (compresi bancomat)
  * parcheggi riservati ai disabili
    - http://wiki.openstreetmap.org/wiki/Tag:amenity%3Dparking
  * parcheggi asseganti a disabili (compreso il numero di riferimento) che non dovranno essere riportati su OSM (DA DECIDERE)
  * stazione (anche se non situata all'interno degli spalti)
  * cinema
  * aree gioco
  * parchi
  * attraversamenti pedonali
    - http://wiki.openstreetmap.org/wiki/IT:Tag:footway%3Dcrossing

Durante la mappatura di bar, ristoranti e locali pubblici verrà valutata l'accessibilità anche dei servizi igienici.

Alcune gravi situazioni riscontrate in luoghi ed uffici pubblici, verranno documentate fotograficamente.


Strumenti utilizzati
--------------------

### Censimento

  * tracker GPS (es: data-logger con chipset MTK [bt747])
  * smartphone con tracking app (es: [MyTrack] su android)
  * macchina fotografica o smartphone con geolocalizzazione foto
  * pc con [JOSM] per editare la mappa
  * bloc-notes


### Inserimento dati

  * 1 PC
  * ...
  * ...

### Software

  * [JOSM]
  * osmctools
  * osmosis


Modalità di lavoro
-------------------

### Censimento

I censitori percorreranno le vie della zona a loro assegnata ed avranno il compito di:

  * inserire un segnaposto per ogni punto di interesse
  * annotare (su MyTrack o su bloc-notes in caso di data logger) il nome, il tipo e i dati relativi all'accessibilità motoria
  * dare informazioni sul progetto ad eventuali esercenti o cittadini interessati (anche tramite volantino o altro materiale informativo)
  * restituire i dati raccolti

### Inserimento dati

Le persone addette all'inserimento dati dovranno:

  * importare i dati su JOSM e verificare se eventuali punti di interesse sono già presenti su OSM
  * annotare i nuovi POI su layer dedicato
  * aggiungere i dati relativi all'accessibilità ai POI già presenti sul layer OSM

Licenze utilizzate:

  * Mappe: Open Data Commons Open Database License - [ODbL]
  * Immagini, contenuti: Creative Commons by-sa 3.0 [CC by-sa] 
  * Software: dove possibile [GPLv3]


### Pubblicazione dati

  * esportazione dei dati per visualizzazione su mappe personalizzate per mettere in evidenza lo stato dell'accessibilità (es: [uMap])
  * esportazione su OSM dei dati previa verifica


Formato dei dati
----------------

Mappe:

  * XML in formato [OSM File Format]
    * principali tag utilizzati:
      * http://wiki.openstreetmap.org/wiki/IT:Map_Features
      * http://wiki.openstreetmap.org/wiki/IT:Editing_Standards_and_Conventions
      * http://wiki.openstreetmap.org/wiki/Category:Disabilities
      * http://wiki.openstreetmap.org/wiki/Key:wheelchair
      * ...
      * ...

### Licenze utilizzate:

  * Mappe: Open Data Commons Open Database License - [ODbL]
  * Immagini, contenuti: Creative Commons by-sa 3.0 [CC by-sa] 
  * Software: dove possibile [GPLv3]


Demo / Rappresentazione dei dati
--------------------------

*(da fare)*


---

ToDo
----

  * presentazione del progetto
  * creare documentazione relativa ai tag OSM da utilizzare
  * pagina facebook di riferimento
  * mail di riferimento
  * attivare hosting per mappe
  * attivare repository pubblico Mercurial/Git del progetto


Proposte
--------

  * mettere a disposizione un form per segnalazioni esterne
  * iscrivere il progetto al [mappathon] (Piemonte Visual Contest) - **SCADE IL 22 FEBBRAIO**


---

[CC by-sa]: http://creativecommons.org/licenses/by-sa/3.0/it/legalcode
[GPLv3]: http://www.gnu.org/licenses/gpl.html
[JOSM]: https://josm.openstreetmap.de/
[MyTrack]: https://play.google.com/store/apps/details?id=com.google.android.maps.mytracks
[ODbL]: http://opendatacommons.org/licenses/odbl/
[OSM File Format]: http://wiki.openstreetmap.org/wiki/OSM_file_formats
[bt747]: http://www.bt747.org/
[mappathon]: http://www.piemontevisualcontest.eu/ultimo-mese-pe-presentare-i-progetti-al-mappathon/
[uMap]: http://umap.openstreetmap.fr/it/
