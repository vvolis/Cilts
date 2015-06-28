###Cilts

#####Uzdevuma formulējums

3014 gadā vēsturnieki nolēma izpētīt iepriekšējā gadu tūkstotī dzīvojošo kādas valsts iedzīvotāju radnieciskās saites. Viņiem izdevās arhīvos atrast vecās datubāzes uz magnētiskajiem informācijas nesējiem. Diemžēl laika gaitā šie nesēji bija bojāti un daļēji zaudējuši informāciju.
Tomēr vēsturniekiem izdevās atjaunot daudzus ierakstus par personām. Ieraksts par personu saturēja personas kodu, dzimumu, vārdu, uzvārdu, vecāku personas kodus. Personas kods ir 9-ciparu vesels skaitlis. Ja personai nav zināms kāds no vecākiem, tad to apzīmē ar 0. Ir zināms, ka par katru personu ir tikai viens ieraksts, bet viena un tā pati persona var būt par vecāku vairākām citām personām.
Vēsturnieki nolēma atrast vislielāko cilti starp atjaunotajiem datiem. Cilti nosaka pēc kāda personas (saknes persona jeb ciltstēvs vai ciltsmāte), par kuru ir pilns ieraksts, t.i. ir zināms tās dzimums, vārds un uzvārds. Par saknes personu netiek ņemta persona, par kuru mēs tikai zinām, ka tā ir vecāks kādai citai personai. Ciltī tiek iekļauta saknes persona un pilnīgi visi tās pēcnācēji. Vēsturnieki vēlējās uzzināt šīs lielākās cilts saknes personas vārdu un uzvārdu.
Ja vairākas ciltis pēc lieluma ir vienādas, tad jādrukā tās saknes personas vārds un uzvārds starp šīm atrastajām ciltīm, kurai personas kods ir vismazākais.
Dati ieejas failā ir patvaļīgā secībā, ieraksti nekādi nav sakārtoti. Dati ir korekti atbilstoši specifikācijai. Personu radnieciskās saites ciklus neveido. Bērna vecāku dzimumi netiek stingri noteikti.
Risinājums, kas efektīvi apstrādā tikai 100 ierakstus tiek vērtēts ar 8 punktiem. Maksimālam vērtējumam atbilst risinājums, kas efektīvi apstrādā aptuveni 10’000 ierakstus ( ~O(n2) ). Risinājums ar ~O(n2), bet samērā neefektīvu apstrādi, tiek vērtēts ar 9 punktiem.

 

#####Failu vārdi
 
cilts.c vai cilts.cpp, vai cilts.pas - programmas tekstam
cilts.in - ieejas dati
cilts.out - izpildes rezultāts
 
#####Ieeja:
 

Katra ieejas datu rinda, izņemot pēdējo, ir sekojošā formātā:
```sh
<PK> <Dzimums> <Vards> <Uzvards> <Vecaks1_PK> <Vecaks2_PK>
 ```
 
```<PK> ``` nosaka personas kodu [1..999’999’999]. Šajā pozīcijā esošie personas kodi neatkārtojas. Skaitlis 0 nozīmē, ka ieejas dati ir beigušies.```<Dzimums>``` nosaka personas dzimumu {‘S’, ‘V’}.
```<Vards>``` nosaka personas vārdu garumā [1..30], pieļaujamie simboli: latīņu burti [a..z, A..Z] un cipari [0..9].
```<Uzvards>``` nosaka personas uzvārdu garumā [1..30], pieļaujamie simboli: latīņu burti [a..z, A..Z] un cipari [0..9].
```<Vecaks1_PK>``` nosaka personas pirmo vecāku, t.i. dots personas kods [0..999’999’999]. ‘0’ nozīmē, ka nav ziņu par vecāku.
```<Vecaks2_PK>``` nosaka personas otro vecāku, t.i. dots personas kods [0..999’999’999]. ‘0’ nozīmē, ka nav ziņu par vecāku.
 

Ieejas datu pēdējā rinda satur skaitli 0.

 
#####Izeja:
Atbilstoši ieejas failam tiek izdrukāts vislielākās atrastās cilts lielums (personu skaits tajā) un tās saknes personas „tituls”, vārds un uzvārds:
```sh
<Skaits> <Tituls> <Vards> <Uzvards>
 ```
```<Skaits>``` nosaka vislielākās atrastās cilts lielumu.
```<Tituls>``` Atbilstoši saknes personas dzimumam vārds ‘Ciltsmate’ vai ‘Ciltstevs’.
```<Vards>``` nosaka personas vārdu garumā [1..30], pieļaujamie simboli: latīņu burti [a..z, A..Z] un cipari [0..9].
```<Uzvards>``` nosaka personas uzvārdu garumā [1..30], pieļaujamie simboli: latīņu burti [a..z, A..Z] un cipari [0..9].
 
#####Piemērs:
Ieejas faila cilts.in saturs:
 ```
10 S Vienigais PirmaCilts 11 12
21 V Pirmais OtraCilts 0 13
33 V Tresais OtraCilts 15 42
42 V Otrais OtraCilts 21 14
0
```
 
Izejas faila cilts.out saturs:
 
```
3 Ciltstevs Pirmais OtraCilts
```
 

