Pràctica 1

PROBLEMA 1
Per compilar els 4 programes, hem d'escriure per terminal:
gcc -o ex1bsimple -g -Wall ex1bsimple.c -lm
gcc -o ex1bdoble -g -Wall ex1bdoble.c -lm
gcc -o ex1csimple -g -Wall ex1csimple.c -lm
gcc -o ex1cdoble -g -Wall ex1cdoble.c -lm

Per executar-los, hi escrivim:
./ex1bsimple
./ex1bdoble
./ex1csimple
./ex1cdoble

Ens demanarà que introduïm un valor, és el nombre al qual li volem calcular f(x).
Ens tornarà per pantalla el valor de la funció en el punt que li hem donat.


PROBLEMA 2
Per compilar els programes, els codis són:
gcc -o ex2simple -g -Wall ex2simple.c -lm
gcc -o ex2doble -g -Wall ex2doble.c -lm

Per executar-los:
./ex2simple
./ex2doble

Ens demanarà entrar-hi 3 coeficients (a, b i c), l'ordre en introduïr-los ha de ser c, b i a.
Ens escriurà per pantalla les dues solucions de la fórmula estàndard i les dues solucions obtingudes de la nostra nova fórmula.


PROBLEMA 3
Per compilar els programes, introduïm a la terminal:
gcc -o ex3simple -g -Wall ex3simple.c -lm
gcc -o ex3doble -g -Wall ex3doble.c -lm

Per executar-los escrivim: (./"nom del programa" "nom de l'arxiu amb el vector a entrar")
./ex3simple prova3.txt
./ex3doble prova3.txt
./ex3simple prova100.txt
./ex3doble prova100.txt

Els programes ens imprimeixen per pantalla les variançes calculades amb 2 i 1 bucles corresponentment.


PROBLEMA 4


