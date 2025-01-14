# FT_PRINTF

## 42 PROJECT

![note](img/ftprintf.png)

Le projet `FT_PRINTF` a pour but de nous faire découvrir la fonction `printf()`.

`int printf(const char* format, ...);`

Selon le sujet, la fonction `FT_PRINTF` ne doit que gérer les formats suivants :

`%c` Ecrit un char.

`%s` Ecrit un char*.

`%p` Ecrit une adresse de pointeur en format héxadécimal (minuscule).

`%d` Ecrit une valeur décimal avec une base de 10 (int).

`%i` Ecrit un entier avec une base de 10 (int).

`%u` Ecrit une valeur décimal non signé (positif) avec une base de 10.

`%x` Ecrit un nombre en format héxadécimal (minuscule).

`%X` Ecrit un nombre en format héxadécimal (majuscule).

`%%` Ecrit le caractère %.

# INSTALL

`make` permet de télécharger la librairie `LIBFT` (présente sur mon github) et d'en compiler le contenue afin d'obtenir l'archive `libft.a`, permettant de compiler `ft_printf.c`.

`make clean` permet de supprimer tout les fichiers objets.

`make fclean` reprends le principe de `make clean` en supprimant en plus l'archive `libft.a` et `libftprintf.a`.

`make re` reprends le principe de `make fclean` en compilant de nouveau ma librairie.