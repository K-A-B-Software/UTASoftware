Proceso SistemaAcademico
	Definir rep Como Entero
	Definir N, i Como Entero
	Definir nombre, paralelo, categoria Como Caracter
	Definir n1, n2, n3, asistencia, promedio Como Real
	// Acumuladores
	Definir totalA, totalB, totalC Como Entero
	Definir contExcelente, contMuyBueno, contBueno, contRiesgo, contReprobado Como Entero
	Definir reprobadosNota, reprobadosAsistencia Como Entero
	Definir sumaPromedios Como Real
	Definir sumaA, sumaB, sumaC Como Real
	Definir mayorProm, menorProm Como Real
	Definir nombreMayor, nombreMenor Como Caracter
	Definir estables, inestables, aprobados Como Entero
	Repetir
		// Inicialización
		totalA <- 0; totalB <- 0; totalC <- 0
		contExcelente <- 0; contMuyBueno <- 0; contBueno <- 0
		contRiesgo <- 0; contReprobado <- 0
		reprobadosNota <- 0; reprobadosAsistencia <- 0
		sumaPromedios <- 0
		sumaA <- 0; sumaB <- 0; sumaC <- 0
		estables <- 0; inestables <- 0; aprobados <- 0
		
		mayorProm <- -1
		menorProm <- 11
		
		// Validar N
		N <- ValidarEntero("Ingrese cantidad de estudiantes: ", 1, 10)
		
		Para i <- 1 Hasta N Hacer
			
			Escribir "Estudiante ", i
			
			Escribir "Nombre: "
			Leer nombre
			
			paralelo <- ValidarParalelo(0)
			
			n1 <- ValidarReal("Nota 1: ", 0, 10)
			n2 <- ValidarReal("Nota 2: ", 0, 10)
			n3 <- ValidarReal("Prácticas: ", 0, 10)
			asistencia <- ValidarReal("Asistencia: ", 0, 100)
			
			promedio <- CalcularPromedio(n1, n2, n3)
			categoria <- Clasificar(promedio)
			
			// Validación asistencia
			Si asistencia < 70 Entonces
				categoria <- "Reprobado por asistencia"
				reprobadosAsistencia <- reprobadosAsistencia + 1
			FinSi
			
			// Reprobado por nota
			Si promedio < 6 Entonces
				reprobadosNota <- reprobadosNota + 1
			Sino
				aprobados <- aprobados + 1
			FinSi
			
			// Alertas
			Si promedio >= 9 Entonces
				Si asistencia < 80 Entonces
					Escribir "ALERTA: Inconsistencia academica"
				FinSi
			FinSi
			
			// Rendimiento estable
			Si n1 = n2 y n1 = n3 y n2 = n3 Entonces
				estables <- estables + 1
			FinSi
			
			// Rendimiento inestable
			Si (Maximo(n1,n2,n3) - Minimo(n1,n2,n3)) > 4 Entonces
				inestables <- inestables + 1
			FinSi
			
			// Contadores por paralelo
			Segun paralelo Hacer
				"A":
					totalA <- totalA + 1
					sumaA <- sumaA + promedio
				"B":
					totalB <- totalB + 1
					sumaB <- sumaB + promedio
				"C":
					totalC <- totalC + 1
					sumaC <- sumaC + promedio
			FinSegun
			
			// Categorías
			Si categoria = "Excelente" Entonces
				contExcelente <- contExcelente + 1
			Sino
				Si categoria = "Muy bueno" Entonces
					contMuyBueno <- contMuyBueno + 1
				Sino
					Si categoria = "Bueno" Entonces
						contBueno <- contBueno + 1
					Sino
						Si categoria = "En riesgo" Entonces
							contRiesgo <- contRiesgo + 1
						Sino
							contReprobado <- contReprobado + 1
						FinSi
					FinSi
				FinSi
			FinSi
			
			sumaPromedios <- sumaPromedios + promedio
			
			// Mayor y menor
			Si promedio > mayorProm Entonces
				mayorProm <- promedio
				nombreMayor <- nombre
			FinSi
			
			Si promedio < menorProm Entonces
				menorProm <- promedio
				nombreMenor <- nombre
			FinSi
			
		FinPara
		
		// REPORTES
		Escribir "===== REPORTE GENERAL ====="
		Escribir "Total estudiantes: ", N
		Escribir "Paralelo A: ", totalA
		Escribir "Paralelo B: ", totalB
		Escribir "Paralelo C: ", totalC
		
		Escribir "Excelente: ", contExcelente
		Escribir "Muy bueno: ", contMuyBueno
		Escribir "Bueno: ", contBueno
		Escribir "En riesgo: ", contRiesgo
		Escribir "Reprobados: ", contReprobado
		
		Escribir "Reprobados por nota: ", reprobadosNota
		Escribir "Reprobados por asistencia: ", reprobadosAsistencia
		
		Escribir "Promedio general: ", sumaPromedios / N
		
		Si totalA > 0 Entonces
			Escribir "Promedio A: ", sumaA / totalA
		FinSi
		
		Si totalB > 0 Entonces
			Escribir "Promedio B: ", sumaB / totalB
		FinSi
		Si totalC > 0 Entonces
			Escribir "Promedio C: ", sumaC / totalC
		FinSi
		Escribir "Mejor estudiante: ", nombreMayor, " ", mayorProm
		Escribir "Peor estudiante: ", nombreMenor, " ", menorProm
		Escribir "% Aprobados: ", (aprobados / N) * 100
		Escribir "% Estables: ", (estables / N) * 100
		Escribir "% Inestables: ", (inestables / N) * 100
		
		Escribir "¿Desea repetir? (1.Si o 2.N0)"
		Leer rep
		Hasta Que rep = 2
FinProceso
// FUNCIONES
Funcion promedio <- CalcularPromedio(n1, n2, n3)
    promedio <- n1*0.3 + n2*0.3 + n3*0.4
FinFuncion
Funcion categoria <- Clasificar(prom)
    Si prom >= 9 Entonces
        categoria <- "Excelente"
    Sino
        Si prom >= 8 Entonces
            categoria <- "Muy bueno"
        Sino
            Si prom >= 7 Entonces
                categoria <- "Bueno"
            Sino
                Si prom >= 6 Entonces
                    categoria <- "En riesgo"
                Sino
                    categoria <- "Reprobado"
                FinSi
            FinSi
        FinSi
    FinSi
FinFuncion

Funcion num <- ValidarReal(msg, min, max)
    Repetir
        Escribir msg
        Leer num
    Hasta Que num >= min Y num <= max
FinFuncion

Funcion num <- ValidarEntero(msg, min, max)
    Repetir
        Escribir msg
        Leer num
    Hasta Que num >= min Y num <= max
FinFuncion

Funcion p <- ValidarParalelo(dummy)
    Definir p Como Caracter
    Repetir
        Escribir "Paralelo (A/B/C): "
        Leer p
    Hasta Que p = "A" O p = "B" O p = "C"
FinFuncion

Funcion m <- Maximo(a,b,c)
    m <- a
    Si b > m Entonces
        m <- b
    FinSi
    Si c > m Entonces
        m <- c
    FinSi
FinFuncion

Funcion m <- Minimo(a,b,c)
    m <- a
    Si b < m Entonces
        m <- b
    FinSi
    Si c < m Entonces
        m <- c
    FinSi
FinFuncion