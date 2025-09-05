def ordenar_estudiantes(estudiantes):
    
    return sorted(estudiantes, key=lambda e: (-e[1], e[0]))


estudiantes = [
    ("Felipe", 4.5),
    ("LebronJames", 4.3),
    ("Piroberta", 3.8),
    ("Camila,", 5.0)
]

print(" Lista normal ")
print(estudiantes)

print("\nLista organizada")
print(ordenar_estudiantes(estudiantes))