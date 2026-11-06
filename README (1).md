# Studentų galutinio balo skaičiuoklė (v1.0)

Programa nuskaito studentų duomenis (ranka arba iš failo), apskaičiuoja galutinį balą, padalina studentus į **vargšiukus** (galutinis < 5.0) ir **kietiakius** (galutinis ≥ 5.0), išveda juos į du failus ir matuoja kiekvieno žingsnio trukmę. Programa veikia su dviem konteineriais: `std::vector` ir `std::list`.

---

## Įdiegimas ir paleidimas

### Su CMake (bet kokia OS)

```
mkdir build
cd build
cmake ..
cmake --build .
```

Paleidimas: `./studentai` (Linux/macOS) arba `studentai.exe` (Windows, `build/` arba `build/Debug/` aplanke).

### Su make (Unix OS)

```
make
./studentai
```

`make clean` ištrina sukompiliuotą programą.

---

## Naudojimosi instrukcija

1. Paleidus programą pasirenkamas konteineris: `1` – vector, `2` – list.
2. Meniu:

| Meniu | Veiksmas |
|---|---|
| 1 | Studento įvedimas ranka (išvedamas ir objekto adresas atmintyje) |
| 2 | Studentų lentelė su vidurkiu, mediana ir adresu atmintyje |
| 3 | Programos pabaiga |
| 4 | Atsitiktinių studentų failų generavimas (matuojamas kūrimo laikas) |
| 5 | Duomenų nuskaitymas iš failo |
| 6 | Nuskaitymas, padalinimas pasirinkta strategija, rūšiavimas ir išvedimas į `vargsiukai.txt` ir `kietiakiai.txt` (matuojamas kiekvienas žingsnis) |
| 7 | Galutinių balų išvedimas į `galutinis.txt` |
| 8 | 6 punkto testas, kartojamas kelis kartus, su laikų vidurkiu |

3. 6 ir 8 punktuose dar pasirenkama:
   - rūšiavimas: `1` – pagal pažymį, `2` – pagal vardą,
   - dalijimo strategija: `1`, `2` arba `3` (žr. žemiau).

Failo formatas: pirma eilutė – antraštė, toliau `Vardas Pavarde ND1 ... NDn Egz`.

---

## Versijų (release) aprašymas

- **v.pradinė** – studentų įvedimas ranka, galutinis balas pagal vidurkį arba medianą.
- **v0.1** – atsitiktinis pažymių generavimas, nuskaitymas iš failo, rūšiavimas pagal pavardę ir išvedimas į failą.
- **v0.2** – atsitiktinių studentų failų generavimas, padalinimas į vargšiukus ir kietiakius, išvedimas į du failus, kodas išskaidytas į header failus, spartos analizė.
- **v0.3** – programa veikia su `std::vector` ir `std::list`, išvedamas studento adresas atmintyje, testų laikų vidurkis.
- **v1.0** – trys dalijimo strategijos, optimizavimas su `std::stable_partition`, `CMakeLists.txt` ir `Makefile`, išsami dokumentacija.

---

## v0.2 rezultatai (std::vector, vienas pažymys studentui)

| Įrašų kiekis | Failo kūrimas (s) | Nuskaitymas (s) | Padalinimas (s) | Rūšiavimas pagal pažymį (s) | Rūšiavimas pagal vardą (s) | Išvedimas (s) |
|---:|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.006 | 0.004 | 0.0007 | 0.0005 | 0.0013 | 0.002 |
| 10 000 | 0.062 | 0.042 | 0.007 | 0.004 | 0.018 | 0.013 |
| 100 000 | 0.615 | 0.420 | 0.056 | 0.047 | 0.233 | 0.122 |
| 1 000 000 | 6.136 | 4.364 | 0.651 | 0.503 | 2.849 | 1.236 |
| 10 000 000 | 60.180 | 46.464 | 6.801 | 4.378 | 33.564 | 12.205 |

**Komentaras:** įrašų kiekiui padidėjus 10 kartų, beveik visų žingsnių laikas taip pat padidėja apie 10 kartų. Lėčiausias žingsnis yra nuskaitymas iš failo. Rūšiavimas pagal vardą apie 7,5 karto lėtesnis nei pagal pažymį, nes tekstą palyginti sudėtingiau nei skaičius.

---

## Dalijimo strategijos

| Strategija | Kaip veikia | Atmintis |
|---|---|---|
| **1** | Studentai nukopijuojami į du naujus konteinerius: `vargsiukai` ir `kietiakiai`. Bendras `studentai` lieka nepakeistas. | Kiekvienas studentas laikomas 2 kartus |
| **2** | Vargšiukas perkeliamas į `vargsiukai` ir **po vieną** ištrinamas iš `studentai` (`erase`). `studentai` lieka tik kietiakiai. | Efektyvu |
| **3** | `std::stable_partition` vienu perėjimu sustato kietiakius į priekį, o vargšiukus į galą. Tada visi vargšiukai perkeliami ir ištrinami **vienu kartu**. `list` atveju naudojamas `splice()`, kuris perkabina elementus nieko nekopijuodamas. | Efektyvu |

---

## Testavimo sistemos parametrai

- **CPU:** Intel Core i5-13420H
- **RAM:** 16 GB
- **Diskas:** SSD, 500 GB
- **GPU:** NVIDIA GeForce RTX 4050 (programa jos nenaudoja)

Testuota su tais pačiais anksčiau sugeneruotais failais (1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų). Kiekvienas matavimas – 8 meniu punktas, **3 testų vidurkis**, rūšiuojant pagal pažymį.

---

## Rezultatai: padalinimo į 2 grupes trukmė (s)

### std::vector

| Įrašų kiekis | 1 strategija | 2 strategija | 3 strategija |
|---:|---:|---:|---:|
| 1 000 | ... | ... | ... |
| 10 000 | ... | ... | ... |
| 100 000 | ... | ... | ... |
| 1 000 000 | ... | netestuota* | ... |
| 10 000 000 | ... | netestuota* | ... |

\* `vector` su 2 strategija kiekvienas `erase()` pastumia visus po ištrinto esančius elementus. Laikas auga kvadratiškai: įrašų 10 kartų daugiau – laikas apie 80–100 kartų ilgesnis. Su 1 000 000 įrašų tai užtruktų kelias valandas, todėl testuota tik iki 100 000.

### std::list

| Įrašų kiekis | 1 strategija | 2 strategija | 3 strategija |
|---:|---:|---:|---:|
| 1 000 | ... | ... | ... |
| 10 000 | ... | ... | ... |
| 100 000 | ... | ... | ... |
| 1 000 000 | ... | ... | ... |
| 10 000 000 | ... | ... | ... |

### Visų žingsnių trukmė su greičiausia strategija (s)

| Įrašų kiekis | Konteineris | Nuskaitymas | Padalinimas | Rūšiavimas | Išvedimas |
|---:|---|---:|---:|---:|---:|
| 1 000 000 | vector | ... | ... | ... | ... |
| 1 000 000 | list | ... | ... | ... | ... |
| 10 000 000 | vector | ... | ... | ... | ... |
| 10 000 000 | list | ... | ... | ... | ... |

---

## Ekrano nuotraukos

![vector, 3 strategija, 1 000 000 įrašų](nuotraukos/vector_strategija3.png)

![list, 2 strategija, 1 000 000 įrašų](nuotraukos/list_strategija2.png)

![Studento adresas atmintyje](nuotraukos/adresas.png)

---

## Išvados

- **1 strategija** veikia panašiai su abiem konteineriais, bet naudoja dvigubai daugiau atminties, nes kiekvienas studentas yra ir bendrame, ir viename iš naujų konteinerių.
- **2 strategija** su `list` yra greita, nes ištrinti elementą iš sąrašo vidurio reikia tik perjungti nuorodas. Su `vector` ji labai lėta, nes kiekvienas `erase()` perstumia visus likusius elementus.
- **3 strategija** greita su abiem konteineriais, nes elementai perstatomi vienu perėjimu (`stable_partition`) ir ištrinami vienu kartu. Su `vector` tai greičiausias būdas.
- (Įrašyk savo pastebėjimus pagal gautus skaičius: kuris konteineris greitesnis nuskaitant, rūšiuojant ir pan.)
