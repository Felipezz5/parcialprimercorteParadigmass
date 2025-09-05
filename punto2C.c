#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 100
#define MAX_NOTAS 10

typedef struct {
    int id;
    char nombre[30];
    char apellido[30];
    int edad;
    float notas[MAX_NOTAS];
    int num_notas;
} Estudiante;

Estudiante estudiantes[MAX_ESTUDIANTES];
int total_estudiantes = 0;

void agregar_estudiante(int id, const char *nombre, const char *apellido, int edad, float notas[], int num_notas) {
    if (total_estudiantes >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar más estudiantes.\n");
        return;
    }

    Estudiante *e = &estudiantes[total_estudiantes];
    e->id = id;
    strcpy(e->nombre, nombre);
    strcpy(e->apellido, apellido);
    e->edad = edad;
    e->num_notas = num_notas;

    for (int i = 0; i < num_notas; i++) {
        e->notas[i] = notas[i];
    }

    total_estudiantes++;
}


float promedio(Estudiante *e) {
    if (e->num_notas == 0) return 0.0f;
    float suma = 0;
    for (int i = 0; i < e->num_notas; i++) {
        suma += e->notas[i];
    }
    return suma / e->num_notas;
}


void mostrar_estudiantes() {
    if (total_estudiantes == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }

    for (int i = 0; i < total_estudiantes; i++) {
        Estudiante *e = &estudiantes[i];
        printf("%d | %s %s | Edad: %d | Promedio: %.2f\n",
               e->id, e->nombre, e->apellido, e->edad, promedio(e));
    }
}


void eliminar_estudiante(int id) {
    int pos = -1;

    for (int i = 0; i < total_estudiantes; i++) {
        if (estudiantes[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("No existe ese ID, sea serio %d.\n", id);
        return;
    }


    for (int i = pos; i < total_estudiantes - 1; i++) {
        estudiantes[i] = estudiantes[i + 1];
    }

    total_estudiantes--;
    printf("Estudiante con ID %d eliminado.\n", id);
}

int main() {
    float notas1[] = {4.5, 3.8, 4.0};
    agregar_estudiante(1001, "Marcela", "Gomez", 20, notas1, 3);

    float notas2[] = {4.0, 4.2, 4.5, 5.0};
    agregar_estudiante(1002, "Camila", "Perez", 19, notas2, 2);

    float notas3[] = {5.0, 4.8, 4.9, 5.0};
    agregar_estudiante(1003, "Felipe", "Sandoval", 18, notas3, 4);

    printf(" Estudiantes registrados \n");
    mostrar_estudiantes();

    printf("\n Eliminando ID 1002 \n");
    eliminar_estudiante(1002);

    printf("\n Estudiantes restantes \n");
    mostrar_estudiantes();

    return 0;
}
