#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int up[1000];	// Tablica posortowana rosnaco
int down[1000]; // Tablica posorotwana malejaco
int random_array[1000];  // Tablica posortowana losowo

void wypelnij_tablice() {
    
    for (int i = 0; i < 1000; i++) {
        up[i] = i;
    }

    for (int i = 0; i < 1000; i++) {
        down[i] = 1000 - i;
    }

    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        random_array[i] = rand() % 1000;  
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *tab, int lewy, int prawy) {
    if (prawy <= lewy) return;

    int i = lewy - 1, j = prawy + 1;
    
    int pivot_index = lewy + rand() % (prawy - lewy + 1); // pivot ustawiamy losowo
    int pivot = tab[pivot_index];

    //int pivot = tab[lewy];  // pivot ustawiany na poczatek tablicy
    //int pivot = tab[(lewy + prawy) / 2]; // pivot ustawiany na srodek tablicy
    //int pivot = tab[prawy]; // pivot ustawiamy na koniec tablicy

    while (1) {
        // Szukamy elementu większego lub równego pivotowi po prawej stronie
        while (tab[++i] < pivot);

        // Szukamy elementu mniejszego lub równego pivotowi po lewej stronieS
        while (tab[--j] > pivot);

        // Jeśli liczniki się nie minęły zamieniamy elementy
        if (i <= j)
            swap(&tab[i], &tab[j]);  // Poprawione wywołanie funkcji swap
        else
            break;
    }

    // Rekurencyjnie sortujemy obie części
    if (j > lewy)
        quick_sort(tab, lewy, j);
    if (i < prawy)
        quick_sort(tab, i, prawy);
}

void funkcja() {
	wypelnij_tablice();

    // Wywolujemy quick_sort na roznych tablicach
    //quick_sort(up, 0, 999);  // Wywolanie dla tablic posortowanej rosnaco
    quick_sort(down, 0, 999); // Wywolanie dla tablicy posorotwanej malejaco
    //quick_sort(random_array, 0, 999); // Wywolanie dla tablicy posorotwanej rosnaco
}



