Skirtingo dydžio failų greičio testavimas

1) 1 000 studentų:

failas stud1000.txt sukurtas per 0.0061536 s

Rušiuota pagal pazymi:
Nuskaitymas is failo:     0.0043911 s
Padalinimas i 2 grupes:   0.0007459 s
Rusiavimas:               0.0005057 s
Isvedimas i 2 failus:     0.0020982 s

Rušiuota pagal varda:
Nuskaitymas is failo:     0.004455 s
Padalinimas i 2 grupes:   0.000682 s
Rusiavimas:               0.0012671 s
Isvedimas i 2 failus:     0.0020074 s

2)10 000

failas stud10000.txt sukurtas per 0.0617456 s

Rušiuota pagal pažymi:
Nuskaitymas is failo:     0.04175 s
Padalinimas i 2 grupes:   0.0068809 s
Rusiavimas:               0.0043464 s
Isvedimas i 2 failus:     0.0129712 s

Rušiuota pagal varda:
Nuskaitymas is failo:     0.0416413 s
Padalinimas i 2 grupes:   0.0071444 s
Rusiavimas:               0.0181238 s
Isvedimas i 2 failus:     0.0144808 s

3)100 000

failas stud100000.txt sukurtas per 0.615046 s

Rušiuota pagal pažymi:
Nuskaitymas is failo:     0.420011 s
Padalinimas i 2 grupes:   0.0556487 s
Rusiavimas:               0.047497 s
Isvedimas i 2 failus:     0.122031 s

Rušiuota pagal varda:
Nuskaitymas is failo:     0.416573 s
Padalinimas i 2 grupes:   0.0551836 s
Rusiavimas:               0.233483 s
Isvedimas i 2 failus:     0.12439 s

4)1 000 000

failas stud1000000.txt sukurtas per 6.13564 s

Rušiuota pagal pažymi:
Nuskaitymas is failo:     4.36448 s
Padalinimas i 2 grupes:   0.650982 s
Rusiavimas:               0.503053 s
Isvedimas i 2 failus:     1.23643 s

Rušiuota pagal varda:
Nuskaitymas is failo:     4.26378 s
Padalinimas i 2 grupes:   0.610411 s
Rusiavimas:               2.84906 s
Isvedimas i 2 failus:     1.22292 s

5)10 000 000

failas stud10000000.txt sukurtas per 60.1798 s

Rušiuota pagal pažymi:
Nuskaitymas is failo:     46.4639 s
Padalinimas i 2 grupes:   6.80058 s
Rusiavimas:               4.37822 s
Isvedimas i 2 failus:     12.2048 s

Rušiuota pagal varda:
Nuskaitymas is failo:     41.8066 s
Padalinimas i 2 grupes:   6.60121 s
Rusiavimas:               33.5641 s
Isvedimas i 2 failus:     11.8341 s

Įrašų kiekiui padidėjus 10 kartų, beveik visų žingsnių laikas taip pat padidėja apie 10 kartų, o lėčiausias žingsnis yra duomenų nuskaitymas iš failo (su 10 mln. įrašų apie 42–46 s). Rūšiavimas pagal vardą yra apie 7,5 karto lėtesnis nei pagal pažymį (33,6 s ir 4,4 s su 10 mln. įrašų), nes tekstą palyginti sudėtingiau nei skaičius. Padalinimas į dvi grupes ir išvedimas į du failus yra greiti ir didėja tolygiai su duomenų kiekiu.