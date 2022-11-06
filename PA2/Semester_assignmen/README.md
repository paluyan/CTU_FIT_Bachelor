Název: Where I am?
=========================
Autor: Yana Paluyan

== Popis hry Where I am?

Uživatel hru spustí a může pomocí jednoduchých příkazů do konzole ovládat hru.

Možné příkazy jsou zobrazeny v hranatých závorkách, například:
- [new] vytvoří novou hru
- [load] načte hru ze souboru
- [save] uloží hru do souboru
- [profile] zobrazí aktuální stav playera
- [open] zobrazí inventář playera
- [exit] ukončí program

Nová nebo uložená hra bude načtená ze xml souboru.
Kniha obsahuje umístění, nepřátele a položky. Každé místo může mít
popis a nabízí výběr akcí, ze kterých si může uživatel vybrat.
Tyto akce mohou být např. přestěhování na jiné místo nebo boj s nepřítelem.
Během hry hráč může obdržet další položky.

Každý nepřítel, sam hráč a položka mají své vlastnosti. Pro nepřátele a hráče je to síla (která
určuje sílu útoku tvora), obratnost (která určuje sílu obrany bytosti) a zdraví.
Položky zvyšují sílu nebo obratnost hráče při nošení.

Po načtení nového světa z knihy si hráč vytvoří svého hrdinu. Bude sdílet herní body mezi zdravím, silou a obranou. 
Hra pak začíná. Hra končí, když hrdina zemře nebo dosáhne koncové polohy. Progress lze uložit do ukládacího souboru.


--------------------------------------

== Použití

Spusťte `make compile` pro kompilaci zdroje,` make doc` pro vygenerování
dokumentaci, nebo `make all` /` make` pro obojí.

Spusťte `make run` pro spuštění programu. Zvolte "new", zadejte název souboru
knihy, kterou chcete hrát, a postupujte podle herních pokynů.

Pokud jste již vytvořili hru, můžete načíst existující hru výběrem
„load“ v hlavní nabídce.

Spusťte `make clean` pro smazání všech vygenerovaných souborů.

Spusťte příkaz `make compile` pro kompilaci,` make doc` pro remake dokumentaci, nebo
`make all` /` make` udělat obojí.

== Knihovny

In addition to the standard C/C++ libraries, `libxml2` is used.


