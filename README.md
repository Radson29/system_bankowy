
# System Bankowy

Rozbudowany system bankowy wspierający wielu użytkowników oraz operacje finansowe. Aplikacja umożliwia zarządzanie kontami bankowymi, czekami, zadaniami pracowników oraz logowaniem i rejestracją użytkowników.

---

## Spis treści

- [Funkcje](#funkcje)
- [Rodzaje użytkowników i komendy](#rodzaje-użytkowników-i-komendy)
  - [Klient](#klient)
  - [Pracownik banku](#pracownik-banku)
  - [Pracownik zewnętrzny](#pracownik-zewnętrzny)
- [Ogólne komendy](#ogólne-komendy)
- [Przykładowe użycie komend](#przykładowe-użycie-komend)
- [Wymagania systemowe](#wymagania-systemowe)
- [Struktura projektu](#struktura-projektu)
- [Wykorzystane technologie](#wykorzystane-technologie)

---

## Funkcje

- ✅ Tworzenie banków i kont
- ✅ Obsługa czeków i ich realizacja
- ✅ Weryfikacja i przenoszenie kont między bankami
- ✅ System zadań dla pracowników
- ✅ Przechowywanie danych

---

## Rodzaje użytkowników i komendy

### Klient

- `check_avl [nazwa_banku] [numer_konta]` – sprawdzenie dostępnych środków
- `open [nazwa_banku]` – żądanie otwarcia konta
- `close [nazwa_banku] [numer_konta]` – żądanie zamknięcia konta
- `redeem [nazwa_banku] [numer_konta] [kod]` – realizacja czeku
- `change [nowy_bank] [obecny_bank] [numer_konta]` – przeniesienie konta do innego banku
- `list [nazwa_banku]` – wyświetlenie wszystkich kont w danym banku
- `messages` – wyświetlenie wiadomości

### Pracownik banku

- `tasks` – lista przypisanych zadań
- `view [id_zadania]` – podgląd szczegółów zadania
- `approve [id_zadania]` – zatwierdzenie zadania
- `disapprove [id_zadania] [wiadomość]` – odrzucenie zadania z komentarzem
- `validate [id_zadania]` – zatwierdzenie danych klienta

### Pracownik zewnętrzny

- `send_check [kwota] [kod] [id_klienta]` – wystawienie czeku

---

## Ogólne komendy

- `logIn [hasło] [id]` – logowanie do systemu
- `signUp [imię] [nazwisko] [hasło] [rola] [id] [wiek]` – rejestracja nowego użytkownika
- `create_bank [nazwa_banku]` – utworzenie nowego banku
- `whoami` – informacje o aktualnym użytkowniku
- `exit` – wylogowanie

---

## Przykładowe użycie komend

```
create_bank PKO
signUp Jan Kowalski haslo123 Client 12345 30
logIn haslo123 12345

open PKO
check_avl PKO 1001
redeem PKO 1001 abcd1234
change ING PKO 1001
list PKO
messages

// Pracownik banku
logIn pracownik123 55555
tasks
view 1
approve 1
disapprove 2 Konto już istnieje
validate 3

// Pracownik zewnętrzny
logIn zewn_haslo 77777
send_check 1000.50 kodABC123 12345
```

---

## Wymagania systemowe

- Kompilator zgodny z C++14 lub nowszy
- CMake + Ninja (np. przez CLion)
- System operacyjny: Windows / Linux

---

## Struktura projektu

```
Bank/
├── cpp/ – logika bankowa: Bank, Check, Klienci, Pracownicy

Commands/
├── CommandFactory.cpp – tworzenie komend
├── CommandFromClient/ – komendy klientów
├── CommandsFromEmployee/ – komendy pracowników banku
├── CommandFromThirdPartyEmployee/ – komendy pracownika zewnętrznego

Helpers/
├── MyString – klasa string
├── Vector, Queue – struktury danych
├── Polymorphic_Ptr – inteligentny wskaźnik

Login/
├── logika logowania i rejestracji

Users/
├── cpp/ – klasy użytkowników
├── Tasks/ – klasy zadań przypisanych do pracowników

System.cpp 
main.cpp – punkt wejścia
```

---

## Wykorzystane technologie

- ✅ Programowanie obiektowe (dziedziczenie, polimorfizm)
- ✅ Polimorficzne wskaźniki (`Polymorphic_Ptr`)
- ✅ Obsługa wyjątków (`try-catch`)
- ✅ Struktury danych (Vector, Queue)
- ✅ Serializacja do pliku (`userDataBase.txt`)

---

Projekt stworzony jako edukacyjna symulacja systemu bankowego w języku C++.
