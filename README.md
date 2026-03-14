<div align="center">

# 📖 C Contact Management System (Agenda Telefonica)

Un sistem interactiv de gestionare a contactelor direct din linia de comandă (CLI), scris în **C**. Acest proiect demonstrează manipularea șirurilor de caractere, lucrul cu structuri (`struct`) și implementarea algoritmilor de sortare și căutare.

<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C" />
<img src="https://img.shields.io/badge/CLI-Terminal-4D4D4D?style=for-the-badge&logo=gnu-bash&logoColor=white" alt="CLI" />
<img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" alt="Status" />

</div>

---

## ✨ Funcționalități Principale

Aplicația oferă un meniu interactiv din care utilizatorul poate selecta următoarele opțiuni:

- **➕ Adăugare Contacte:** Permite salvarea unui contact nou incluzând Nume, Număr de telefon și Adresă de Email.
- **📋 Listare Alfabetică:** Afișează toate contactele din agendă, sortate automat în ordine alfabetică după nume.
- **🔍 Căutare după Număr:** Găsește și afișează detaliile unui contact bazat pe numărul de telefon exact.
- **🔍 Căutare după Nume:** Găsește rapid informațiile unei persoane după numele introdus.
- **🔄 Meniu Interactiv:** Programul rulează într-o buclă continuă, permițând multiple operațiuni până când utilizatorul decide să iasă (`Y/N`).

---

## 🛠️ Detalii Tehnice (Sub capotă)

Proiectul folosește bibliotecile standard din C (`stdio.h`, `string.h`, `stdlib.h`, `ctype.h`). Datele sunt stocate temporar într-un array de structuri limitat la 20 de intrări.

### Structura de date folosită:
```c
struct agenda {
    char nume[51];
    char numar[11];
    char adresa[51];
};
