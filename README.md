# Centrale Meteorologica

> **Piattaforma di monitoraggio meteorologico con indice di qualità dell'aria in tempo reale** basata su **Arduino UNO R4**, backend dedicato e pagina sul [Sito Web](https://github.com/DazeForFuture/SitoDazeForFuture)

---

## 📌 Panoramica del Progetto

La **Centrale Meteorologica di Daze For Future** nasce con l’obiettivo di monitorare e divulgare i dati in modo trasparente e accessibile.

Il sistema raccoglie dati da sensori collegati a **Arduino UNO R4**, li invia a un **server backend in python**, che li distribuisce in **tempo reale** e li salva in un database per visualizzarli in una pagina web sul nostro sito.

---

## 🧩 Architettura del Sistema

| Livello       | Componente        | Descrizione                 |
| ------------- | ----------------- | --------------------------- |
| Hardware      | Arduino UNO R4    | Microcontrollore principale |
| Sensori       | Temp / Umidità / Qualità dell'aria    | Raccolta dati               |
| Comunicazione | WiFi  | Invio dati al server        |
| Backend       | Server Python (Flask) | API, storico, streaming dati     |
| Frontend      | Pagina web     | Visualizzazione e grafici   |

---

## 🔧 Hardware Utilizzato

| Componente    | Modello             | Funzione                 |
| ------------- | ------------------- | ------------------------ |
| MCU           | Arduino UNO R4      | Controllo e acquisizione |
| Sensore T/H   | DHT22               | Temperatura e umidità    |
| Sensori di qualità dell'aria | Vari (non ancora installati) | Qualità dell'aria
| Alimentazione | USB-C / 5V            | Alimentazione sistema    |

---

## 🧠 Software

| Livello  | Tecnologia                    |
| -------- | ----------------------------- |
| Firmware | Arduino IDE (C++)           |
| Backend  | Python (Flask) |
| Frontend | HTML, CSS, JavaScript         |

---

## 🌡️ Dati Monitorati

| Parametro    | Unità | Stato            |
| ------------ | ----- | ---------------- |
| Temperatura  | °C    | ✅ Attivo         |
| Umidità      | %     | ✅ Attivo         |
| Qualità dell'Aria | /   | ❌ Non ancora installato |

---

## 🌐 Dashboard Web

La pagina (file: `centrale_meteo.html`), nel [sito](https://github.com/DazeForFuture/SitoDazeForFuture) offre:

* Visualizzazione dati **in tempo reale**
* Grafici storici dinamici
* Intervalli selezionabili (30 min – 24 ore)

---

## 🔌 Backend & API

### Endpoint principali

| Metodo | Endpoint           | Descrizione                |
| ------ | ------------------ | -------------------------- |
| GET    | `/sensor`          | Ultima lettura disponibile |
| GET    | `/history?hours=X` | Storico ultime X ore       |
| GET    | `/stream`          | Stream dati realtime        |

---

## 🛠️ Manutenzione

| Attività               | Frequenza   |
| ---------------------- | ----------- |
| Verifica sensori       | Periodicamente     |
| Backup dati            | Periodicamente |
| Aggiornamenti software | Periodicamente   |

---

## 🚀 Sviluppi Futuri

* Sensori qualità dell’aria (PM2.5 / CO₂)
* Esportazione CSV
---

## 📬 Contatti

* 🌐 Sito web: [Open source su GitHub](https://github.com/DazeForFuture/SitoDazeForFuture)
* 📧 Email: [dazeforfuture@liceodazeglio.edu.it](mailto:dazeforfuture@liceodazeglio.edu.it)
